/****************************************************************************
** Meta object code from reading C++ file 'Advanced_Settings_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Advanced_Settings_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Advanced_Settings_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Advanced_Settings_Window_t {
    QByteArrayData data[10];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Advanced_Settings_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Advanced_Settings_Window_t qt_meta_stringdata_Advanced_Settings_Window = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Advanced_Settings_Window"
QT_MOC_LITERAL(1, 25, 20), // "on_Button_OK_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 27), // "on_TB_Browse_Before_clicked"
QT_MOC_LITERAL(4, 75, 26), // "on_TB_Browse_After_clicked"
QT_MOC_LITERAL(5, 102, 22), // "on_TB_Log_File_clicked"
QT_MOC_LITERAL(6, 125, 29), // "on_TB_QEMU_IMG_Browse_clicked"
QT_MOC_LITERAL(7, 155, 36), // "on_CH_Check_Version_on_Start_..."
QT_MOC_LITERAL(8, 192, 2), // "on"
QT_MOC_LITERAL(9, 195, 33) // "on_RB_QEMU_Version_Manual_tog..."

    },
    "Advanced_Settings_Window\0on_Button_OK_clicked\0"
    "\0on_TB_Browse_Before_clicked\0"
    "on_TB_Browse_After_clicked\0"
    "on_TB_Log_File_clicked\0"
    "on_TB_QEMU_IMG_Browse_clicked\0"
    "on_CH_Check_Version_on_Start_toggled\0"
    "on\0on_RB_QEMU_Version_Manual_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Advanced_Settings_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void Advanced_Settings_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Advanced_Settings_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_OK_clicked(); break;
        case 1: _t->on_TB_Browse_Before_clicked(); break;
        case 2: _t->on_TB_Browse_After_clicked(); break;
        case 3: _t->on_TB_Log_File_clicked(); break;
        case 4: _t->on_TB_QEMU_IMG_Browse_clicked(); break;
        case 5: _t->on_CH_Check_Version_on_Start_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_RB_QEMU_Version_Manual_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Advanced_Settings_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Advanced_Settings_Window.data,
    qt_meta_data_Advanced_Settings_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Advanced_Settings_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Advanced_Settings_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Advanced_Settings_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Advanced_Settings_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
