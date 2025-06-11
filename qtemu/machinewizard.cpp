/****************************************************************************
**
** Copyright (C) 2006-2008 Urs Wolfer <uwolfer @ fwo.ch>
**
** This file is part of QtEmu.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU Library General Public License
** along with this library; see the file COPYING.LIB.  If not, write to
** the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
** Boston, MA 02110-1301, USA.
**
****************************************************************************/

#include "machinewizard.h"

#include "config.h"

#include <QProcess>
#include <QMessageBox>
#include <QFile>
#include <QDoubleSpinBox>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDir>
#include <QIcon>
#include <QComboBox>
#include <QTextStream>
#include <QSettings>
#include <QPushButton>
#include <QFileDialog>
#include <QDomElement>
#include <QCheckBox>
#include <qapplication.h>
#include <qDebug>

MachineWizard::MachineWizard(const QString &myMachinesPathParent, QWidget *parent)
    : QWizard(parent)
    , myMachinesPath(myMachinesPathParent)
{
    addPage(new ChooseSystemPage(this));
    addPage(new LocationPage(this));
    addPage(new ImagePage(this));

    setWindowTitle(tr("Create a new Machine"));

    QSettings settings("QtEmu", "QtEmu");
    QString iconTheme = settings.value("iconTheme", "oxygen").toString();
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/" + iconTheme + "/qtemu.png"));
}

QString MachineWizard::newMachine(const QString &myMachinesPath, QWidget *parent)
{
    MachineWizard wizard(myMachinesPath, parent);

    QString result;
    bool accepted = (wizard.exec() == QDialog::Accepted);

    if (accepted)
        result = wizard.field("path").toString()+'/'+wizard.field("name").toString().replace(' ', '_')+".qte";

    return result;
}

void MachineWizard::accept()
{
    QString osName = field("name").toString();
    QString osPath = field("path").toString();
    QString osType = field("operatingSystem").toString();

    QDir *dir = new QDir();
    dir->mkpath(osPath);

    QDomDocument domDocument("qtemu");
    QDomProcessingInstruction process = domDocument.createProcessingInstruction(
                              "xml", "version=\"1.0\" encoding=\"UTF-8\"");
    domDocument.appendChild(process);

    QDomElement root = domDocument.createElement("qtemu");
    root.setAttribute("version", "1.0");
    domDocument.appendChild(root);

    QDomElement machine = domDocument.createElement("machine");
    root.appendChild(machine);

    QDomElement domElement;
    QDomText domText;

    domElement = domDocument.createElement("name");
    machine.appendChild(domElement);
    domText = domDocument.createTextNode(osName);
    domElement.appendChild(domText);

    domElement = domDocument.createElement("operatingSystem");
    machine.appendChild(domElement);
    domText = domDocument.createTextNode(osType);
    domElement.appendChild(domText);

    domElement = domDocument.createElement("hdd");
    machine.appendChild(domElement);
    if(field("format").toInt()==0)
        domText = domDocument.createTextNode(osPath+'/'+osName.replace(' ', '_')+".qcow");
    else if(field("format").toInt()==1)
    domText = domDocument.createTextNode(osPath+'/'+osName.replace(' ', '_')+".img");
    else
        domText = domDocument.createTextNode(osPath+'/'+osName.replace(' ', '_')+".vmdk");
    
    domElement.appendChild(domText);

    domElement = domDocument.createElement("memory");
    machine.appendChild(domElement);
    domText = domDocument.createTextNode("128");
    domElement.appendChild(domText);

    domElement = domDocument.createElement("notes");
    machine.appendChild(domElement);
    domText = domDocument.createTextNode(tr("Click here to write down some notes "
                                            "about this machine."));
    domElement.appendChild(domText);

    domElement = domDocument.createElement("snapshot");
    machine.appendChild(domElement);
#ifdef DEVELOPER
    domText = domDocument.createTextNode("true");
#else
    domText = domDocument.createTextNode("false");
#endif
    domElement.appendChild(domText);
    
    QDomElement netElement = domDocument.createElement("net-guest");
    QDomElement element = domDocument.createElement("guest0");
    netElement.appendChild(element);
    root.appendChild(netElement);

    domElement = domDocument.createElement("name");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("Interface 0");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("nic");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("rtl8139");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("nic");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("rtl8139");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("randomize");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("false");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("host");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("Interface 0");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("enabled");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("true");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("mac");
    element.appendChild(domElement);
    QString mac="52:54:00:";
        for (int i=1;i<=6;i++)
        {
            mac.append(QString().setNum(qrand() % 16, 16));
            if(i%2 == 0 && i != 6)
                mac.append(":");
        }
    domText = domDocument.createTextNode(mac);
    domElement.appendChild(domText); 
    
    netElement = domDocument.createElement("net-host");
    element = domDocument.createElement("host0");
    netElement.appendChild(element);
    root.appendChild(netElement);

    domElement = domDocument.createElement("name");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("Interface 0");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("type");
    element.appendChild(domElement);
    domText = domDocument.createTextNode("User Mode");
    domElement.appendChild(domText);
    
    domElement = domDocument.createElement("hostname");
    element.appendChild(domElement);
    domText = domDocument.createTextNode(osName);
    domElement.appendChild(domText);
    
    QFile file(osPath+'/'+osName.replace(' ', '_')+".qte");
    if (!file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QMessageBox::critical(this, tr("Error"), tr("Image NOT created!"));
        return;
    }

    QTextStream out(&file);
    domDocument.save(out, 4);

    QProcess *imageCreateProcess = new QProcess(this);
    imageCreateProcess->setWorkingDirectory(osPath);
    QStringList arguments;

 arguments << "-c";
           arguments <<  QApplication::applicationDirPath() + "/qemu-img";

    if(field("format").toInt()==0)
    {
    arguments << "create" << "-f" << "qcow2"
              << osName.replace(' ', '_')+".qcow";
    }
    else if(field("format").toInt()==1)
    {
    arguments << "create" << "-f" << "raw"
              << osName.replace(' ', '_')+".img";
    }
    else
    {
    arguments << "create" << "-f" << "vmdk"
              << osName.replace(' ', '_')+".vmdk";
    }

    arguments << QString::number(field("size").toDouble()*1024)+'M';

#ifndef Q_OS_WIN32
    imageCreateProcess->start("/bin/bash", arguments);
 qDebug() <<  arguments;
   // imageCreateProcess->start("qemu-img", arguments);
    imageCreateProcess->waitForFinished();
    if(imageCreateProcess->error() != QProcess::UnknownError)
    {
        //we may be on a system that uses "kvm-img" instead
        imageCreateProcess->start("kvm-img", arguments);
        imageCreateProcess->waitForFinished();
    }
    qDebug() << imageCreateProcess->readAllStandardOutput();
    qDebug() << imageCreateProcess->readAllStandardError();
#elif defined(Q_OS_WIN32)
    imageCreateProcess->start("qemu/qemu-img", arguments);
#endif
    if(imageCreateProcess->error() == QProcess::UnknownError)
        QMessageBox::information(this, tr("Finished"), tr("Image created"));
    else
#ifndef Q_OS_WIN32
        QMessageBox::warning(this, tr("Finished"), tr("Image NOT created!<br> You may be missing either qemu-img or kvm-img, or they are not executable!"));
#elif defined(Q_OS_WIN32)
        QMessageBox::warning(this, tr("Finished"), tr("Image NOT created!<br> You may be missing qemu/qemu-img.exe!"));
#endif

    QDialog::accept();
}

ChooseSystemPage::ChooseSystemPage(MachineWizard *wizard)
    : QWizardPage(wizard)
{
    comboSystem = new QComboBox;
    registerField("system", comboSystem, "currentText");
    comboSystem->addItem(tr("Select a System..."));
    comboSystem->addItem(tr("Linux"));
    comboSystem->addItem(tr("Windows 98"));
    comboSystem->addItem(tr("Windows 2000"));
    comboSystem->addItem(tr("Windows XP"));
    comboSystem->addItem(tr("Windows Vista"));
    comboSystem->addItem(tr("ReactOS"));
    comboSystem->addItem(tr("BSD"));
    comboSystem->addItem(tr("Other"));

    registerField("operatingSystem", comboSystem, "currentText");
    connect(comboSystem, SIGNAL(activated(int)), this, SIGNAL(completeChanged()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(comboSystem);
    layout->addStretch();
    setLayout(layout);

    setTitle(tr("Select the operating system you want to install"));
}

bool ChooseSystemPage::isComplete() const
{
    return !(comboSystem->currentText()==tr("Select a System..."));
}


LocationPage::LocationPage(MachineWizard *wizard)
    : QWizardPage(wizard)
{
    QLineEdit *pathHidden = new QLineEdit(wizard->myMachinesPath, this);
    pathHidden->setVisible(false);
    registerField("myMachinesPath", pathHidden);

    QLabel *nameLabel = new QLabel(tr("&Name:"));
    nameLineEdit = new QLineEdit;
    registerField("name", nameLineEdit);
    nameLabel->setBuddy(nameLineEdit);
    connect(nameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updatePath()));

    QLabel *pathLabel = new QLabel(tr("&Path:"));
    pathLineEdit = new QLineEdit;
    registerField("path", pathLineEdit);
    pathLabel->setBuddy(pathLineEdit);

    QSettings settings("QtEmu", "QtEmu");
    QString iconTheme = settings.value("iconTheme", "oxygen").toString();

    QPushButton *pathSelectButton = new QPushButton(QIcon(":/images/" + iconTheme + "/open.png"), QString(), this);
    connect(pathSelectButton, SIGNAL(clicked()), this, SLOT(setNewPath()));

    QHBoxLayout *pathLayout = new QHBoxLayout;
    pathLayout->addWidget(pathLineEdit);
    pathLayout->addWidget(pathSelectButton);

    connect(nameLineEdit, SIGNAL(textChanged(QString)), this, SIGNAL(completeChanged()));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nameLabel, 1, 0);
    layout->addWidget(nameLineEdit, 1, 1);
    layout->addWidget(pathLabel, 2, 0);
    layout->addLayout(pathLayout, 2, 1);
    layout->setRowStretch(3, 1);
    setLayout(layout);

    setTitle(tr("Choose name and location for the new machine"));
}

void LocationPage::updatePath()
{
    pathLineEdit->setText(field("myMachinesPath").toString()+
                          '/'+nameLineEdit->text().replace(' ', '_'));
}

void LocationPage::setNewPath()
{
    QString newPath = QFileDialog::getExistingDirectory(this, tr("Select a folder for saving the hard disk image"),
                                                        field("myMachinesPath").toString());
    if (!newPath.isEmpty())
        pathLineEdit->setText(newPath);
}

void LocationPage::initializePage()
{
    nameLineEdit->setText(field("system").toString());
    updatePath();
}

bool LocationPage::isComplete() const
{
    return !(nameLineEdit->text().isEmpty());
}


ImagePage::ImagePage(MachineWizard *wizard)
    : QWizardPage(wizard)
{
    QLabel *sizeLabel = new QLabel(tr("&Disk image size:"));
    sizeSpinBox = new QDoubleSpinBox;
    registerField("size", sizeSpinBox, "value");
    sizeSpinBox->setFixedSize(sizeSpinBox->sizeHint());
    sizeSpinBox->setValue(2);
    sizeLabel->setBuddy(sizeSpinBox);
    QLabel *sizeGbLabel = new QLabel(tr("GB"));
    sizeGbLabel->setFixedSize(sizeGbLabel->sizeHint());
    sizeGbLabel->setBuddy(sizeSpinBox);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(completeChanged()));

    QLabel *formatLabel = new QLabel(tr("Disk image format:"));
    QComboBox *formatComboBox = new QComboBox;
    registerField("format", formatComboBox);
    formatComboBox->addItem(tr("Native image (qcow)"));
    formatComboBox->addItem(tr("Raw image (img)"));
    formatComboBox->addItem(tr("VMWare image (vmdk)"));
    
    //encryptionCheckBox = new QCheckBox;//qemu does not appear to support this very well, and kvm doesn't boot encrypted images at all...
    
    QLabel *formatInfoLabel = new QLabel(tr("The native image format enables<br>"
                                     "suspend/resume features, all other formats<br>"
                                     "lack suspend/resume. Use \"Native image (qcow)\"<br>"
                                     "unless you know what you are doing."));
    formatLabel->setBuddy(formatComboBox);
    connect(formatComboBox, SIGNAL(activated(int)), this, SIGNAL(completeChanged()));

    QVBoxLayout *layout = new QVBoxLayout;

    QHBoxLayout *sizeLayout = new QHBoxLayout;
    sizeLayout->addWidget(sizeLabel);
    sizeLayout->addWidget(sizeSpinBox);
    sizeLayout->addWidget(sizeGbLabel);

    QHBoxLayout *formatLayout = new QHBoxLayout;
    formatLayout->addWidget(formatLabel);
    formatLayout->addWidget(formatComboBox);

    layout->addLayout(sizeLayout);
    layout->addLayout(formatLayout);
    layout->addStretch();
    layout->addWidget(formatInfoLabel);
    layout->addStretch();
    setLayout(layout);

    setTitle(tr("Specify disk image details"));
}

void ImagePage::cleanupPage()
{
    sizeSpinBox->setValue(0);
}

bool ImagePage::isComplete() const
{
    return (sizeSpinBox->value()!=0);
}

/*void ImagePage::enableEncryption(int choice)
{
    if(choice == 0)
        encryptionCheckBox->setEnabled(true);
    else
        encryptionCheckBox->setEnabled(false);
}*/
