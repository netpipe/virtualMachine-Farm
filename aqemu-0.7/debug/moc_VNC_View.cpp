/****************************************************************************
** Meta object code from reading C++ file 'VNC_View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VNC_View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VNC_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VncView_t {
    QByteArrayData data[19];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VncView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VncView_t qt_meta_stringdata_VncView = {
    {
QT_MOC_LITERAL(0, 0, 7), // "VncView"
QT_MOC_LITERAL(1, 8, 9), // "reinit_me"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "scaleResize"
QT_MOC_LITERAL(4, 31, 1), // "w"
QT_MOC_LITERAL(5, 33, 1), // "h"
QT_MOC_LITERAL(6, 35, 11), // "updateImage"
QT_MOC_LITERAL(7, 47, 1), // "x"
QT_MOC_LITERAL(8, 49, 1), // "y"
QT_MOC_LITERAL(9, 51, 6), // "setCut"
QT_MOC_LITERAL(10, 58, 4), // "text"
QT_MOC_LITERAL(11, 63, 15), // "requestPassword"
QT_MOC_LITERAL(12, 79, 18), // "outputErrorMessage"
QT_MOC_LITERAL(13, 98, 7), // "message"
QT_MOC_LITERAL(14, 106, 10), // "mouseEvent"
QT_MOC_LITERAL(15, 117, 12), // "QMouseEvent*"
QT_MOC_LITERAL(16, 130, 5), // "event"
QT_MOC_LITERAL(17, 136, 25), // "clipboardSelectionChanged"
QT_MOC_LITERAL(18, 162, 20) // "clipboardDataChanged"

    },
    "VncView\0reinit_me\0\0scaleResize\0w\0h\0"
    "updateImage\0x\0y\0setCut\0text\0requestPassword\0"
    "outputErrorMessage\0message\0mouseEvent\0"
    "QMouseEvent*\0event\0clipboardSelectionChanged\0"
    "clipboardDataChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VncView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   60,    2, 0x0a /* Public */,
       6,    4,   65,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      11,    0,   77,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,
      17,    0,   84,    2, 0x08 /* Private */,
      18,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    4,    5,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VncView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VncView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reinit_me(); break;
        case 1: _t->scaleResize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->updateImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->setCut((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->requestPassword(); break;
        case 5: _t->outputErrorMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->mouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->clipboardSelectionChanged(); break;
        case 8: _t->clipboardDataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VncView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VncView::reinit_me)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VncView::staticMetaObject = { {
    &RemoteView::staticMetaObject,
    qt_meta_stringdata_VncView.data,
    qt_meta_data_VncView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VncView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VncView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VncView.stringdata0))
        return static_cast<void*>(this);
    return RemoteView::qt_metacast(_clname);
}

int VncView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RemoteView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void VncView::reinit_me()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
