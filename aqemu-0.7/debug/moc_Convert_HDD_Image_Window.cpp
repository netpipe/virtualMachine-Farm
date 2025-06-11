/****************************************************************************
** Meta object code from reading C++ file 'Convert_HDD_Image_Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Convert_HDD_Image_Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Convert_HDD_Image_Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Convert_HDD_Thread_t {
    QByteArrayData data[4];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Convert_HDD_Thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Convert_HDD_Thread_t qt_meta_stringdata_Convert_HDD_Thread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Convert_HDD_Thread"
QT_MOC_LITERAL(1, 19, 19), // "Conversion_Complete"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 2) // "ok"

    },
    "Convert_HDD_Thread\0Conversion_Complete\0"
    "\0ok"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Convert_HDD_Thread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void Convert_HDD_Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Convert_HDD_Thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Conversion_Complete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Convert_HDD_Thread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Convert_HDD_Thread::Conversion_Complete)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Convert_HDD_Thread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_Convert_HDD_Thread.data,
    qt_meta_data_Convert_HDD_Thread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Convert_HDD_Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Convert_HDD_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Convert_HDD_Thread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Convert_HDD_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Convert_HDD_Thread::Conversion_Complete(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Convert_HDD_Image_Window_t {
    QByteArrayData data[11];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Convert_HDD_Image_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Convert_HDD_Image_Window_t qt_meta_stringdata_Convert_HDD_Image_Window = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Convert_HDD_Image_Window"
QT_MOC_LITERAL(1, 25, 29), // "on_Button_Browse_Base_clicked"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 31), // "on_Button_Browse_Output_clicked"
QT_MOC_LITERAL(4, 88, 39), // "on_CB_Output_Format_currentIn..."
QT_MOC_LITERAL(5, 128, 4), // "text"
QT_MOC_LITERAL(6, 133, 25), // "on_Button_Convert_clicked"
QT_MOC_LITERAL(7, 159, 26), // "on_Button_Identify_clicked"
QT_MOC_LITERAL(8, 186, 15), // "Conversion_Done"
QT_MOC_LITERAL(9, 202, 2), // "ok"
QT_MOC_LITERAL(10, 205, 17) // "Cancel_Convertion"

    },
    "Convert_HDD_Image_Window\0"
    "on_Button_Browse_Base_clicked\0\0"
    "on_Button_Browse_Output_clicked\0"
    "on_CB_Output_Format_currentIndexChanged\0"
    "text\0on_Button_Convert_clicked\0"
    "on_Button_Identify_clicked\0Conversion_Done\0"
    "ok\0Cancel_Convertion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Convert_HDD_Image_Window[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,

       0        // eod
};

void Convert_HDD_Image_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Convert_HDD_Image_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_Browse_Base_clicked(); break;
        case 1: _t->on_Button_Browse_Output_clicked(); break;
        case 2: _t->on_CB_Output_Format_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_Button_Convert_clicked(); break;
        case 4: _t->on_Button_Identify_clicked(); break;
        case 5: _t->Conversion_Done((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->Cancel_Convertion(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Convert_HDD_Image_Window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Convert_HDD_Image_Window.data,
    qt_meta_data_Convert_HDD_Image_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Convert_HDD_Image_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Convert_HDD_Image_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Convert_HDD_Image_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Convert_HDD_Image_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
