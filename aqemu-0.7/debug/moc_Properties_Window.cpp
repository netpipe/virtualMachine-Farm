/****************************************************************************
** Meta object code from reading C++ file 'Properties_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Properties_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Properties_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Properties_Window_t {
    QByteArrayData data[13];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Properties_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Properties_Window_t qt_meta_stringdata_Properties_Window = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Properties_Window"
QT_MOC_LITERAL(1, 18, 20), // "on_Button_OK_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "on_Button_Cancel_clicked"
QT_MOC_LITERAL(4, 65, 29), // "on_Button_Update_Info_clicked"
QT_MOC_LITERAL(5, 95, 29), // "on_TB_FD_Image_Browse_clicked"
QT_MOC_LITERAL(6, 125, 32), // "on_TB_CDROM_Image_Browse_clicked"
QT_MOC_LITERAL(7, 158, 30), // "on_TB_HDD_Image_Browse_clicked"
QT_MOC_LITERAL(8, 189, 25), // "on_Button_HDD_New_clicked"
QT_MOC_LITERAL(9, 215, 28), // "on_Button_HDD_Format_clicked"
QT_MOC_LITERAL(10, 244, 21), // "on_RB_FD_Host_toggled"
QT_MOC_LITERAL(11, 266, 2), // "on"
QT_MOC_LITERAL(12, 269, 24) // "on_RB_CDROM_Host_toggled"

    },
    "Properties_Window\0on_Button_OK_clicked\0"
    "\0on_Button_Cancel_clicked\0"
    "on_Button_Update_Info_clicked\0"
    "on_TB_FD_Image_Browse_clicked\0"
    "on_TB_CDROM_Image_Browse_clicked\0"
    "on_TB_HDD_Image_Browse_clicked\0"
    "on_Button_HDD_New_clicked\0"
    "on_Button_HDD_Format_clicked\0"
    "on_RB_FD_Host_toggled\0on\0"
    "on_RB_CDROM_Host_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Properties_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void Properties_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Properties_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_OK_clicked(); break;
        case 1: _t->on_Button_Cancel_clicked(); break;
        case 2: _t->on_Button_Update_Info_clicked(); break;
        case 3: _t->on_TB_FD_Image_Browse_clicked(); break;
        case 4: _t->on_TB_CDROM_Image_Browse_clicked(); break;
        case 5: _t->on_TB_HDD_Image_Browse_clicked(); break;
        case 6: _t->on_Button_HDD_New_clicked(); break;
        case 7: _t->on_Button_HDD_Format_clicked(); break;
        case 8: _t->on_RB_FD_Host_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_RB_CDROM_Host_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Properties_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Properties_Window.data,
    qt_meta_data_Properties_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Properties_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Properties_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Properties_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Properties_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
