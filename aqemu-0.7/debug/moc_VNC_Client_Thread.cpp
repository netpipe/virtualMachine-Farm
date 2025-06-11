/****************************************************************************
** Meta object code from reading C++ file 'VNC_Client_Thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VNC_Client_Thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VNC_Client_Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VncClientThread_t {
    QByteArrayData data[19];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VncClientThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VncClientThread_t qt_meta_stringdata_VncClientThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "VncClientThread"
QT_MOC_LITERAL(1, 16, 12), // "imageUpdated"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "x"
QT_MOC_LITERAL(4, 32, 1), // "y"
QT_MOC_LITERAL(5, 34, 1), // "w"
QT_MOC_LITERAL(6, 36, 1), // "h"
QT_MOC_LITERAL(7, 38, 6), // "gotCut"
QT_MOC_LITERAL(8, 45, 4), // "text"
QT_MOC_LITERAL(9, 50, 15), // "passwordRequest"
QT_MOC_LITERAL(10, 66, 18), // "outputErrorMessage"
QT_MOC_LITERAL(11, 85, 7), // "message"
QT_MOC_LITERAL(12, 93, 10), // "mouseEvent"
QT_MOC_LITERAL(13, 104, 10), // "buttonMask"
QT_MOC_LITERAL(14, 115, 8), // "keyEvent"
QT_MOC_LITERAL(15, 124, 3), // "key"
QT_MOC_LITERAL(16, 128, 7), // "pressed"
QT_MOC_LITERAL(17, 136, 9), // "clientCut"
QT_MOC_LITERAL(18, 146, 23) // "checkOutputErrorMessage"

    },
    "VncClientThread\0imageUpdated\0\0x\0y\0w\0"
    "h\0gotCut\0text\0passwordRequest\0"
    "outputErrorMessage\0message\0mouseEvent\0"
    "buttonMask\0keyEvent\0key\0pressed\0"
    "clientCut\0checkOutputErrorMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VncClientThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,
       7,    1,   63,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,
      10,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    3,   70,    2, 0x0a /* Public */,
      14,    2,   77,    2, 0x0a /* Public */,
      17,    1,   82,    2, 0x0a /* Public */,
      18,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   15,   16,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void VncClientThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VncClientThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->gotCut((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->passwordRequest(); break;
        case 3: _t->outputErrorMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->mouseEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->keyEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->clientCut((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->checkOutputErrorMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VncClientThread::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VncClientThread::imageUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VncClientThread::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VncClientThread::gotCut)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VncClientThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VncClientThread::passwordRequest)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VncClientThread::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VncClientThread::outputErrorMessage)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VncClientThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_VncClientThread.data,
    qt_meta_data_VncClientThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VncClientThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VncClientThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VncClientThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int VncClientThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void VncClientThread::imageUpdated(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VncClientThread::gotCut(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VncClientThread::passwordRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VncClientThread::outputErrorMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
