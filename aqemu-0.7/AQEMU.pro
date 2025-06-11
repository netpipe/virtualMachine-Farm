######################################################################
# AQEMU QMAKE Project File
######################################################################

TEMPLATE = app
TARGET = AQEMU
DEPENDPATH += .
INCLUDEPATH += .

# Intallation
install_scrips.path = /usr/
unix:install_scrips.extra = ./install_script.sh
INSTALLS += install_scrips

# Input
HEADERS += About_Window.h \
           Add_New_Device_Window.h \
           Advanced_Settings_Window.h \
           Convert_HDD_Image_Window.h \
           VM_Wizard_Window.h \
           Copy_VM_Window.h \
           Create_HDD_Image_Window.h \
           Create_Template_Window.h \
           Device_Manager_Widget.h \
           Emulator_Control_Window.h \
           Error_Log_Window.h \
           Machine_View.h \
           Main_Window.h \
           Monitor_Window.h \
           Ports_Tab_Widget.h \
           Properties_Window.h \
           QEMU_Binary_Window.h \
           Remote_View.h \
           Screenshot_Options_Window.h \
           Select_Icon_Window.h \
           Settings_Window.h \
           Snapshot_Properties_Window.h \
           Snapshots_Window.h \
           System_Info.h \
           Utils.h \
           VM.h \
           VM_Devices.h \
           VNC_Client_Thread.h \
           VNC_Password_Window.h \
           VNC_View.h

FORMS += About_Window.ui \
         Add_New_Device_Window.ui \
         Advanced_Settings_Window.ui \
         Convert_HDD_Image_Window.ui \
         Copy_VM_Window.ui \
         Create_HDD_Image_Window.ui \
         Create_Template_Window.ui \
         Device_Manager_Widget.ui \
         Emulator_Control_Window.ui \
         Error_Log_Window.ui \
         Main_Window.ui \
         Monitor_Window.ui \
         Ports_Tab_Widget.ui \
         Properties_Window.ui \
         QEMU_Binary_Window.ui \
         Screenshot_Options_Window.ui \
         Select_Icon_Window.ui \
         Settings_Window.ui \
         Snapshot_Properties_Window.ui \
         Snapshots_Window.ui \
         VM_Wizard_Window.ui \
         VNC_Password_Window.ui

SOURCES += About_Window.cpp \
           Add_New_Device_Window.cpp \
           Advanced_Settings_Window.cpp \
           Convert_HDD_Image_Window.cpp \
           Copy_VM_Window.cpp \
           VM_Wizard_Window.cpp \
           Create_HDD_Image_Window.cpp \
           Create_Template_Window.cpp \
           Device_Manager_Widget.cpp \
           Emulator_Control_Window.cpp \
           Error_Log_Window.cpp \
           Machine_View.cpp \
           main.cpp \
           Main_Window.cpp \
           Monitor_Window.cpp \
           Ports_Tab_Widget.cpp \
           Properties_Window.cpp \
           QEMU_Binary_Window.cpp \
           Remote_View.cpp \
           Screenshot_Options_Window.cpp \
           Select_Icon_Window.cpp \
           Settings_Window.cpp \
           Snapshot_Properties_Window.cpp \
           Snapshots_Window.cpp \
           System_Info.cpp \
           Utils.cpp \
           VM.cpp \
           VM_Devices.cpp \       
           VNC_Client_Thread.cpp \
           VNC_Password_Window.cpp \
           VNC_View.cpp

RESOURCES += aqemu_images.qrc
TRANSLATIONS += Russian.ts
CONFIG += qtestlib debug_and_release
QT += xml core gui widgets network
DEFINES += VNC_DISPLAY
LIBS += -lvncclient

# For 32Bit Build
#LIBS += -L/usr/lib32/
#QMAKE_CFLAGS = -m32
#QMAKE_CXXFLAGS = -m32
#QMAKE_LFLAGS = -m32

# For Static Qt Build
#CONFIG += staticlib

LIBS += -L/Users/macbook2015/Desktop/brew/lib -ltesseract -lleptonica

INCLUDEPATH += /Users/macbook2015/Desktop/brew/include /Users/macbook2015/Desktop/brew/lib
