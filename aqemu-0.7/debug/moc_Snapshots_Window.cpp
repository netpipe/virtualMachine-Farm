/****************************************************************************
** Meta object code from reading C++ file 'Snapshots_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Snapshots_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Snapshots_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Snapshots_Window_t {
    QByteArrayData data[8];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Snapshots_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Snapshots_Window_t qt_meta_stringdata_Snapshots_Window = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Snapshots_Window"
QT_MOC_LITERAL(1, 17, 38), // "on_Snapshots_Tree_itemSelecti..."
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 24), // "on_Button_Create_clicked"
QT_MOC_LITERAL(4, 82, 24), // "on_Button_Delete_clicked"
QT_MOC_LITERAL(5, 107, 23), // "on_Button_Start_clicked"
QT_MOC_LITERAL(6, 131, 28), // "on_Button_Properties_clicked"
QT_MOC_LITERAL(7, 160, 24) // "on_Button_Update_clicked"

    },
    "Snapshots_Window\0"
    "on_Snapshots_Tree_itemSelectionChanged\0"
    "\0on_Button_Create_clicked\0"
    "on_Button_Delete_clicked\0"
    "on_Button_Start_clicked\0"
    "on_Button_Properties_clicked\0"
    "on_Button_Update_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Snapshots_Window[] = {

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
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Snapshots_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Snapshots_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Snapshots_Tree_itemSelectionChanged(); break;
        case 1: _t->on_Button_Create_clicked(); break;
        case 2: _t->on_Button_Delete_clicked(); break;
        case 3: _t->on_Button_Start_clicked(); break;
        case 4: _t->on_Button_Properties_clicked(); break;
        case 5: _t->on_Button_Update_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Snapshots_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Snapshots_Window.data,
    qt_meta_data_Snapshots_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Snapshots_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Snapshots_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Snapshots_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Snapshots_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
