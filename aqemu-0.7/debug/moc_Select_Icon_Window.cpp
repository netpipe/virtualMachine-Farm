/****************************************************************************
** Meta object code from reading C++ file 'Select_Icon_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Select_Icon_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Select_Icon_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Select_Icon_Window_t {
    QByteArrayData data[11];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Select_Icon_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Select_Icon_Window_t qt_meta_stringdata_Select_Icon_Window = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Select_Icon_Window"
QT_MOC_LITERAL(1, 19, 20), // "on_Button_OK_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 24), // "on_Button_Browse_clicked"
QT_MOC_LITERAL(4, 66, 27), // "on_GB_Default_Icons_toggled"
QT_MOC_LITERAL(5, 94, 2), // "on"
QT_MOC_LITERAL(6, 97, 23), // "on_GB_All_Icons_toggled"
QT_MOC_LITERAL(7, 121, 25), // "on_GB_Other_Icons_toggled"
QT_MOC_LITERAL(8, 147, 35), // "on_All_Icons_List_itemDoubleC..."
QT_MOC_LITERAL(9, 183, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 200, 4) // "item"

    },
    "Select_Icon_Window\0on_Button_OK_clicked\0"
    "\0on_Button_Browse_clicked\0"
    "on_GB_Default_Icons_toggled\0on\0"
    "on_GB_All_Icons_toggled\0"
    "on_GB_Other_Icons_toggled\0"
    "on_All_Icons_List_itemDoubleClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Select_Icon_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       7,    1,   52,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void Select_Icon_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Select_Icon_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_OK_clicked(); break;
        case 1: _t->on_Button_Browse_clicked(); break;
        case 2: _t->on_GB_Default_Icons_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_GB_All_Icons_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_GB_Other_Icons_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_All_Icons_List_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Select_Icon_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Select_Icon_Window.data,
    qt_meta_data_Select_Icon_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Select_Icon_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Select_Icon_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Select_Icon_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Select_Icon_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
