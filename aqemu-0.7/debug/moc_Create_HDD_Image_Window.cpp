/****************************************************************************
** Meta object code from reading C++ file 'Create_HDD_Image_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Create_HDD_Image_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Create_HDD_Image_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Create_HDD_Image_Window_t {
    QByteArrayData data[8];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Create_HDD_Image_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Create_HDD_Image_Window_t qt_meta_stringdata_Create_HDD_Image_Window = {
    {
QT_MOC_LITERAL(0, 0, 23), // "Create_HDD_Image_Window"
QT_MOC_LITERAL(1, 24, 35), // "on_Button_Browse_Base_Image_c..."
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 34), // "on_Button_Browse_New_Image_cl..."
QT_MOC_LITERAL(4, 96, 32), // "on_CB_Format_currentIndexChanged"
QT_MOC_LITERAL(5, 129, 4), // "text"
QT_MOC_LITERAL(6, 134, 24), // "on_Button_Create_clicked"
QT_MOC_LITERAL(7, 159, 29) // "on_Button_Format_Help_clicked"

    },
    "Create_HDD_Image_Window\0"
    "on_Button_Browse_Base_Image_clicked\0"
    "\0on_Button_Browse_New_Image_clicked\0"
    "on_CB_Format_currentIndexChanged\0text\0"
    "on_Button_Create_clicked\0"
    "on_Button_Format_Help_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Create_HDD_Image_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Create_HDD_Image_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Create_HDD_Image_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_Browse_Base_Image_clicked(); break;
        case 1: _t->on_Button_Browse_New_Image_clicked(); break;
        case 2: _t->on_CB_Format_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_Button_Create_clicked(); break;
        case 4: _t->on_Button_Format_Help_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Create_HDD_Image_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Create_HDD_Image_Window.data,
    qt_meta_data_Create_HDD_Image_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Create_HDD_Image_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Create_HDD_Image_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Create_HDD_Image_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Create_HDD_Image_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
