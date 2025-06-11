/****************************************************************************
** Meta object code from reading C++ file 'Remote_View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Remote_View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Remote_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoteView_t {
    QByteArrayData data[58];
    char stringdata0[572];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteView_t qt_meta_stringdata_RemoteView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RemoteView"
QT_MOC_LITERAL(1, 11, 10), // "changeSize"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "w"
QT_MOC_LITERAL(4, 25, 1), // "h"
QT_MOC_LITERAL(5, 27, 9), // "connected"
QT_MOC_LITERAL(6, 37, 12), // "disconnected"
QT_MOC_LITERAL(7, 50, 17), // "disconnectedError"
QT_MOC_LITERAL(8, 68, 12), // "errorMessage"
QT_MOC_LITERAL(9, 81, 5), // "title"
QT_MOC_LITERAL(10, 87, 7), // "message"
QT_MOC_LITERAL(11, 95, 13), // "statusChanged"
QT_MOC_LITERAL(12, 109, 24), // "RemoteView::RemoteStatus"
QT_MOC_LITERAL(13, 134, 1), // "s"
QT_MOC_LITERAL(14, 136, 21), // "showingPasswordDialog"
QT_MOC_LITERAL(15, 158, 1), // "b"
QT_MOC_LITERAL(16, 160, 17), // "mouseStateChanged"
QT_MOC_LITERAL(17, 178, 1), // "x"
QT_MOC_LITERAL(18, 180, 1), // "y"
QT_MOC_LITERAL(19, 182, 10), // "buttonMask"
QT_MOC_LITERAL(20, 193, 13), // "enableScaling"
QT_MOC_LITERAL(21, 207, 5), // "scale"
QT_MOC_LITERAL(22, 213, 11), // "setViewOnly"
QT_MOC_LITERAL(23, 225, 8), // "viewOnly"
QT_MOC_LITERAL(24, 234, 14), // "setGrabAllKeys"
QT_MOC_LITERAL(25, 249, 11), // "grabAllKeys"
QT_MOC_LITERAL(26, 261, 16), // "switchFullscreen"
QT_MOC_LITERAL(27, 278, 2), // "on"
QT_MOC_LITERAL(28, 281, 8), // "keyEvent"
QT_MOC_LITERAL(29, 290, 10), // "QKeyEvent*"
QT_MOC_LITERAL(30, 301, 5), // "event"
QT_MOC_LITERAL(31, 307, 11), // "scaleResize"
QT_MOC_LITERAL(32, 319, 7), // "Quality"
QT_MOC_LITERAL(33, 327, 7), // "Unknown"
QT_MOC_LITERAL(34, 335, 4), // "High"
QT_MOC_LITERAL(35, 340, 6), // "Medium"
QT_MOC_LITERAL(36, 347, 3), // "Low"
QT_MOC_LITERAL(37, 351, 14), // "DotCursorState"
QT_MOC_LITERAL(38, 366, 8), // "CursorOn"
QT_MOC_LITERAL(39, 375, 9), // "CursorOff"
QT_MOC_LITERAL(40, 385, 10), // "CursorAuto"
QT_MOC_LITERAL(41, 396, 12), // "RemoteStatus"
QT_MOC_LITERAL(42, 409, 10), // "Connecting"
QT_MOC_LITERAL(43, 420, 14), // "Authenticating"
QT_MOC_LITERAL(44, 435, 9), // "Preparing"
QT_MOC_LITERAL(45, 445, 9), // "Connected"
QT_MOC_LITERAL(46, 455, 13), // "Disconnecting"
QT_MOC_LITERAL(47, 469, 12), // "Disconnected"
QT_MOC_LITERAL(48, 482, 9), // "ErrorCode"
QT_MOC_LITERAL(49, 492, 4), // "None"
QT_MOC_LITERAL(50, 497, 8), // "Internal"
QT_MOC_LITERAL(51, 506, 10), // "Connection"
QT_MOC_LITERAL(52, 517, 8), // "Protocol"
QT_MOC_LITERAL(53, 526, 2), // "IO"
QT_MOC_LITERAL(54, 529, 4), // "Name"
QT_MOC_LITERAL(55, 534, 8), // "NoServer"
QT_MOC_LITERAL(56, 543, 13), // "ServerBlocked"
QT_MOC_LITERAL(57, 557, 14) // "Authentication"

    },
    "RemoteView\0changeSize\0\0w\0h\0connected\0"
    "disconnected\0disconnectedError\0"
    "errorMessage\0title\0message\0statusChanged\0"
    "RemoteView::RemoteStatus\0s\0"
    "showingPasswordDialog\0b\0mouseStateChanged\0"
    "x\0y\0buttonMask\0enableScaling\0scale\0"
    "setViewOnly\0viewOnly\0setGrabAllKeys\0"
    "grabAllKeys\0switchFullscreen\0on\0"
    "keyEvent\0QKeyEvent*\0event\0scaleResize\0"
    "Quality\0Unknown\0High\0Medium\0Low\0"
    "DotCursorState\0CursorOn\0CursorOff\0"
    "CursorAuto\0RemoteStatus\0Connecting\0"
    "Authenticating\0Preparing\0Connected\0"
    "Disconnecting\0Disconnected\0ErrorCode\0"
    "None\0Internal\0Connection\0Protocol\0IO\0"
    "Name\0NoServer\0ServerBlocked\0Authentication"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       4,  130, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,
       6,    0,   90,    2, 0x06 /* Public */,
       7,    0,   91,    2, 0x06 /* Public */,
       8,    2,   92,    2, 0x06 /* Public */,
      11,    1,   97,    2, 0x06 /* Public */,
      14,    1,  100,    2, 0x06 /* Public */,
      16,    3,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    1,  110,    2, 0x0a /* Public */,
      22,    1,  113,    2, 0x0a /* Public */,
      24,    1,  116,    2, 0x0a /* Public */,
      26,    1,  119,    2, 0x0a /* Public */,
      28,    1,  122,    2, 0x0a /* Public */,
      31,    2,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // enums: name, alias, flags, count, data
      32,   32, 0x0,    4,  150,
      37,   37, 0x0,    3,  158,
      41,   41, 0x0,    6,  164,
      48,   48, 0x0,    9,  176,

 // enum data: key, value
      33, uint(RemoteView::Unknown),
      34, uint(RemoteView::High),
      35, uint(RemoteView::Medium),
      36, uint(RemoteView::Low),
      38, uint(RemoteView::CursorOn),
      39, uint(RemoteView::CursorOff),
      40, uint(RemoteView::CursorAuto),
      42, uint(RemoteView::Connecting),
      43, uint(RemoteView::Authenticating),
      44, uint(RemoteView::Preparing),
      45, uint(RemoteView::Connected),
      46, uint(RemoteView::Disconnecting),
      47, uint(RemoteView::Disconnected),
      49, uint(RemoteView::None),
      50, uint(RemoteView::Internal),
      51, uint(RemoteView::Connection),
      52, uint(RemoteView::Protocol),
      53, uint(RemoteView::IO),
      54, uint(RemoteView::Name),
      55, uint(RemoteView::NoServer),
      56, uint(RemoteView::ServerBlocked),
      57, uint(RemoteView::Authentication),

       0        // eod
};

void RemoteView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RemoteView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->disconnectedError(); break;
        case 4: _t->errorMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->statusChanged((*reinterpret_cast< RemoteView::RemoteStatus(*)>(_a[1]))); break;
        case 6: _t->showingPasswordDialog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->mouseStateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->enableScaling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setViewOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setGrabAllKeys((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->switchFullscreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->keyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 13: _t->scaleResize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RemoteView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::changeSize)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RemoteView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::connected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RemoteView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::disconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RemoteView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::disconnectedError)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RemoteView::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::errorMessage)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (RemoteView::*)(RemoteView::RemoteStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::statusChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (RemoteView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::showingPasswordDialog)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (RemoteView::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteView::mouseStateChanged)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RemoteView::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_RemoteView.data,
    qt_meta_data_RemoteView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RemoteView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RemoteView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RemoteView::changeSize(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RemoteView::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RemoteView::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RemoteView::disconnectedError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void RemoteView::errorMessage(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RemoteView::statusChanged(RemoteView::RemoteStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RemoteView::showingPasswordDialog(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RemoteView::mouseStateChanged(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
