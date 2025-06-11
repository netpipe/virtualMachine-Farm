/****************************************************************************
** Meta object code from reading C++ file 'Machine_View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Machine_View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Machine_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MachineView_t {
    QByteArrayData data[18];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MachineView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MachineView_t qt_meta_stringdata_MachineView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MachineView"
QT_MOC_LITERAL(1, 12, 17), // "fullscreenToggled"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "enabled"
QT_MOC_LITERAL(4, 39, 9), // "Full_Size"
QT_MOC_LITERAL(5, 49, 5), // "width"
QT_MOC_LITERAL(6, 55, 6), // "height"
QT_MOC_LITERAL(7, 62, 9), // "Connected"
QT_MOC_LITERAL(8, 72, 11), // "newViewSize"
QT_MOC_LITERAL(9, 84, 1), // "w"
QT_MOC_LITERAL(10, 86, 1), // "h"
QT_MOC_LITERAL(11, 88, 10), // "fullscreen"
QT_MOC_LITERAL(12, 99, 6), // "enable"
QT_MOC_LITERAL(13, 106, 8), // "initView"
QT_MOC_LITERAL(14, 115, 10), // "reinitView"
QT_MOC_LITERAL(15, 126, 16), // "VNC_Connected_OK"
QT_MOC_LITERAL(16, 143, 9), // "reinitVNC"
QT_MOC_LITERAL(17, 153, 13) // "disconnectVNC"

    },
    "MachineView\0fullscreenToggled\0\0enabled\0"
    "Full_Size\0width\0height\0Connected\0"
    "newViewSize\0w\0h\0fullscreen\0enable\0"
    "initView\0reinitView\0VNC_Connected_OK\0"
    "reinitVNC\0disconnectVNC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MachineView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    2,   67,    2, 0x06 /* Public */,
       7,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   73,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,
      14,    0,   82,    2, 0x0a /* Public */,
      15,    0,   83,    2, 0x0a /* Public */,
      16,    0,   84,    2, 0x0a /* Public */,
      17,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MachineView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MachineView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fullscreenToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->Full_Size((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->Connected(); break;
        case 3: _t->newViewSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->fullscreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->initView(); break;
        case 6: _t->reinitView(); break;
        case 7: _t->VNC_Connected_OK(); break;
        case 8: _t->reinitVNC(); break;
        case 9: _t->disconnectVNC(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MachineView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineView::fullscreenToggled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MachineView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineView::Full_Size)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MachineView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineView::Connected)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MachineView::staticMetaObject = { {
    &QScrollArea::staticMetaObject,
    qt_meta_stringdata_MachineView.data,
    qt_meta_data_MachineView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MachineView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MachineView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MachineView.stringdata0))
        return static_cast<void*>(this);
    return QScrollArea::qt_metacast(_clname);
}

int MachineView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MachineView::fullscreenToggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MachineView::Full_Size(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MachineView::Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
