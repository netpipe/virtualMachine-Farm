/****************************************************************************
** Meta object code from reading C++ file 'VM_Wizard_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VM_Wizard_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VM_Wizard_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VM_Wizard_Window_t {
    QByteArrayData data[21];
    char stringdata0[412];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VM_Wizard_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VM_Wizard_Window_t qt_meta_stringdata_VM_Wizard_Window = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VM_Wizard_Window"
QT_MOC_LITERAL(1, 17, 17), // "Load_OS_Templates"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "Create_New_VM"
QT_MOC_LITERAL(4, 50, 12), // "Find_OS_Icon"
QT_MOC_LITERAL(5, 63, 7), // "os_name"
QT_MOC_LITERAL(6, 71, 22), // "on_Button_Back_clicked"
QT_MOC_LITERAL(7, 94, 22), // "on_Button_Next_clicked"
QT_MOC_LITERAL(8, 117, 25), // "on_RB_VM_Template_toggled"
QT_MOC_LITERAL(9, 143, 2), // "on"
QT_MOC_LITERAL(10, 146, 25), // "on_RB_Generate_VM_toggled"
QT_MOC_LITERAL(11, 172, 33), // "on_CB_OS_Type_currentIndexCha..."
QT_MOC_LITERAL(12, 206, 5), // "index"
QT_MOC_LITERAL(13, 212, 39), // "on_CB_Computer_Type_currentIn..."
QT_MOC_LITERAL(14, 252, 37), // "on_CB_Relese_Date_currentInde..."
QT_MOC_LITERAL(15, 290, 26), // "on_Edit_VM_Name_textEdited"
QT_MOC_LITERAL(16, 317, 4), // "text"
QT_MOC_LITERAL(17, 322, 30), // "on_Check_Host_Mem_stateChanged"
QT_MOC_LITERAL(18, 353, 5), // "state"
QT_MOC_LITERAL(19, 359, 25), // "on_Button_New_HDD_clicked"
QT_MOC_LITERAL(20, 385, 26) // "on_Button_Existing_clicked"

    },
    "VM_Wizard_Window\0Load_OS_Templates\0\0"
    "Create_New_VM\0Find_OS_Icon\0os_name\0"
    "on_Button_Back_clicked\0on_Button_Next_clicked\0"
    "on_RB_VM_Template_toggled\0on\0"
    "on_RB_Generate_VM_toggled\0"
    "on_CB_OS_Type_currentIndexChanged\0"
    "index\0on_CB_Computer_Type_currentIndexChanged\0"
    "on_CB_Relese_Date_currentIndexChanged\0"
    "on_Edit_VM_Name_textEdited\0text\0"
    "on_Check_Host_Mem_stateChanged\0state\0"
    "on_Button_New_HDD_clicked\0"
    "on_Button_Existing_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VM_Wizard_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      11,    1,   97,    2, 0x08 /* Private */,
      13,    1,  100,    2, 0x08 /* Private */,
      14,    1,  103,    2, 0x08 /* Private */,
      15,    1,  106,    2, 0x08 /* Private */,
      17,    1,  109,    2, 0x08 /* Private */,
      19,    0,  112,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::QString, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VM_Wizard_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VM_Wizard_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->Load_OS_Templates();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->Create_New_VM();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->Find_OS_Icon((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_Button_Back_clicked(); break;
        case 4: _t->on_Button_Next_clicked(); break;
        case 5: _t->on_RB_VM_Template_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_RB_Generate_VM_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_CB_OS_Type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_CB_Computer_Type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_CB_Relese_Date_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_Edit_VM_Name_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_Check_Host_Mem_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_Button_New_HDD_clicked(); break;
        case 13: _t->on_Button_Existing_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VM_Wizard_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_VM_Wizard_Window.data,
    qt_meta_data_VM_Wizard_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VM_Wizard_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VM_Wizard_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VM_Wizard_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int VM_Wizard_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
