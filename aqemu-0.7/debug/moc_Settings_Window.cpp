/****************************************************************************
** Meta object code from reading C++ file 'Settings_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Settings_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Settings_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_Window_t {
    QByteArrayData data[14];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_Window_t qt_meta_stringdata_Settings_Window = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Settings_Window"
QT_MOC_LITERAL(1, 16, 41), // "on_Button_Create_Template_fro..."
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 23), // "on_TB_VM_Folder_clicked"
QT_MOC_LITERAL(4, 83, 21), // "on_Button_Box_clicked"
QT_MOC_LITERAL(5, 105, 16), // "QAbstractButton*"
QT_MOC_LITERAL(6, 122, 6), // "button"
QT_MOC_LITERAL(7, 129, 34), // "on_CB_Language_currentIndexCh..."
QT_MOC_LITERAL(8, 164, 5), // "index"
QT_MOC_LITERAL(9, 170, 38), // "on_Button_Screenshots_Setting..."
QT_MOC_LITERAL(10, 209, 29), // "on_Button_QEMU_Binary_clicked"
QT_MOC_LITERAL(11, 239, 35), // "on_Button_Advanced_Settings_c..."
QT_MOC_LITERAL(12, 275, 42), // "on_CH_Show_Emulator_Control_W..."
QT_MOC_LITERAL(13, 318, 7) // "checked"

    },
    "Settings_Window\0"
    "on_Button_Create_Template_from_VM_clicked\0"
    "\0on_TB_VM_Folder_clicked\0on_Button_Box_clicked\0"
    "QAbstractButton*\0button\0"
    "on_CB_Language_currentIndexChanged\0"
    "index\0on_Button_Screenshots_Settings_clicked\0"
    "on_Button_QEMU_Binary_clicked\0"
    "on_Button_Advanced_Settings_clicked\0"
    "on_CH_Show_Emulator_Control_Window_toggled\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    1,   56,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    0,   64,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void Settings_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_Create_Template_from_VM_clicked(); break;
        case 1: _t->on_TB_VM_Folder_clicked(); break;
        case 2: _t->on_Button_Box_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: _t->on_CB_Language_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_Button_Screenshots_Settings_clicked(); break;
        case 5: _t->on_Button_QEMU_Binary_clicked(); break;
        case 6: _t->on_Button_Advanced_Settings_clicked(); break;
        case 7: _t->on_CH_Show_Emulator_Control_Window_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Settings_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Settings_Window.data,
    qt_meta_data_Settings_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Settings_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Settings_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
