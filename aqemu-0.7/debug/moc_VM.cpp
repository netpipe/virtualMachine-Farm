/****************************************************************************
** Meta object code from reading C++ file 'VM.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VM.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VM.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Virtual_Machine_t {
    QByteArrayData data[28];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Virtual_Machine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Virtual_Machine_t qt_meta_stringdata_Virtual_Machine = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Virtual_Machine"
QT_MOC_LITERAL(1, 16, 13), // "State_Changet"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "Virtual_Machine*"
QT_MOC_LITERAL(4, 48, 2), // "vm"
QT_MOC_LITERAL(5, 51, 12), // "VM::VM_State"
QT_MOC_LITERAL(6, 64, 1), // "s"
QT_MOC_LITERAL(7, 66, 11), // "Ready_StdIn"
QT_MOC_LITERAL(8, 78, 4), // "text"
QT_MOC_LITERAL(9, 83, 12), // "Ready_StdOut"
QT_MOC_LITERAL(10, 96, 12), // "Ready_StdErr"
QT_MOC_LITERAL(11, 109, 10), // "QEMU_Start"
QT_MOC_LITERAL(12, 120, 16), // "Loading_Complete"
QT_MOC_LITERAL(13, 137, 8), // "QEMU_End"
QT_MOC_LITERAL(14, 146, 13), // "Clean_Console"
QT_MOC_LITERAL(15, 160, 12), // "Parse_StdErr"
QT_MOC_LITERAL(16, 173, 12), // "Parse_StdOut"
QT_MOC_LITERAL(17, 186, 12), // "QEMU_Started"
QT_MOC_LITERAL(18, 199, 13), // "QEMU_Finished"
QT_MOC_LITERAL(19, 213, 8), // "exitCode"
QT_MOC_LITERAL(20, 222, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(21, 243, 10), // "exitStatus"
QT_MOC_LITERAL(22, 254, 15), // "Resume_Finished"
QT_MOC_LITERAL(23, 270, 13), // "neturned_text"
QT_MOC_LITERAL(24, 284, 16), // "Suspend_Finished"
QT_MOC_LITERAL(25, 301, 15), // "Started_Booting"
QT_MOC_LITERAL(26, 317, 23), // "Execute_Emu_Ctl_Command"
QT_MOC_LITERAL(27, 341, 3) // "com"

    },
    "Virtual_Machine\0State_Changet\0\0"
    "Virtual_Machine*\0vm\0VM::VM_State\0s\0"
    "Ready_StdIn\0text\0Ready_StdOut\0"
    "Ready_StdErr\0QEMU_Start\0Loading_Complete\0"
    "QEMU_End\0Clean_Console\0Parse_StdErr\0"
    "Parse_StdOut\0QEMU_Started\0QEMU_Finished\0"
    "exitCode\0QProcess::ExitStatus\0exitStatus\0"
    "Resume_Finished\0neturned_text\0"
    "Suspend_Finished\0Started_Booting\0"
    "Execute_Emu_Ctl_Command\0com"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Virtual_Machine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       7,    1,   99,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,
      10,    1,  105,    2, 0x06 /* Public */,
      11,    0,  108,    2, 0x06 /* Public */,
      12,    0,  109,    2, 0x06 /* Public */,
      13,    0,  110,    2, 0x06 /* Public */,
      14,    1,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  114,    2, 0x08 /* Private */,
      16,    0,  115,    2, 0x08 /* Private */,
      17,    0,  116,    2, 0x08 /* Private */,
      18,    2,  117,    2, 0x08 /* Private */,
      22,    1,  122,    2, 0x08 /* Private */,
      24,    1,  125,    2, 0x08 /* Private */,
      25,    1,  128,    2, 0x08 /* Private */,
      26,    1,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 20,   19,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   27,

       0        // eod
};

void Virtual_Machine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Virtual_Machine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->State_Changet((*reinterpret_cast< Virtual_Machine*(*)>(_a[1])),(*reinterpret_cast< VM::VM_State(*)>(_a[2]))); break;
        case 1: _t->Ready_StdIn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->Ready_StdOut((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->Ready_StdErr((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->QEMU_Start(); break;
        case 5: _t->Loading_Complete(); break;
        case 6: _t->QEMU_End(); break;
        case 7: _t->Clean_Console((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->Parse_StdErr(); break;
        case 9: _t->Parse_StdOut(); break;
        case 10: _t->QEMU_Started(); break;
        case 11: _t->QEMU_Finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 12: _t->Resume_Finished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->Suspend_Finished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->Started_Booting((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->Execute_Emu_Ctl_Command((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Virtual_Machine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Virtual_Machine::*)(Virtual_Machine * , VM::VM_State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::State_Changet)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Virtual_Machine::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::Ready_StdIn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Virtual_Machine::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::Ready_StdOut)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Virtual_Machine::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::Ready_StdErr)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Virtual_Machine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::QEMU_Start)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Virtual_Machine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::Loading_Complete)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Virtual_Machine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::QEMU_End)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Virtual_Machine::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Virtual_Machine::Clean_Console)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Virtual_Machine::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Virtual_Machine.data,
    qt_meta_data_Virtual_Machine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Virtual_Machine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Virtual_Machine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Virtual_Machine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Virtual_Machine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Virtual_Machine::State_Changet(Virtual_Machine * _t1, VM::VM_State _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Virtual_Machine::Ready_StdIn(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Virtual_Machine::Ready_StdOut(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Virtual_Machine::Ready_StdErr(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Virtual_Machine::QEMU_Start()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Virtual_Machine::Loading_Complete()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Virtual_Machine::QEMU_End()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Virtual_Machine::Clean_Console(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
