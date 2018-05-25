/****************************************************************************
** Meta object code from reading C++ file 'clean.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clean.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clean.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Clean_t {
    QByteArrayData data[12];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Clean_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Clean_t qt_meta_stringdata_Clean = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Clean"
QT_MOC_LITERAL(1, 6, 10), // "open_check"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "open_process"
QT_MOC_LITERAL(4, 31, 13), // "open_setmdole"
QT_MOC_LITERAL(5, 45, 17), // "open_setparameter"
QT_MOC_LITERAL(6, 63, 10), // "close_self"
QT_MOC_LITERAL(7, 74, 19), // "on_pushSetp_clicked"
QT_MOC_LITERAL(8, 94, 20), // "on_pushCheck_clicked"
QT_MOC_LITERAL(9, 115, 19), // "on_pushSetm_clicked"
QT_MOC_LITERAL(10, 135, 22), // "on_pushProcess_clicked"
QT_MOC_LITERAL(11, 158, 7) // "show_me"

    },
    "Clean\0open_check\0\0open_process\0"
    "open_setmdole\0open_setparameter\0"
    "close_self\0on_pushSetp_clicked\0"
    "on_pushCheck_clicked\0on_pushSetm_clicked\0"
    "on_pushProcess_clicked\0show_me"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Clean[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Clean::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Clean *_t = static_cast<Clean *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open_check(); break;
        case 1: _t->open_process(); break;
        case 2: _t->open_setmdole(); break;
        case 3: _t->open_setparameter(); break;
        case 4: _t->close_self(); break;
        case 5: _t->on_pushSetp_clicked(); break;
        case 6: _t->on_pushCheck_clicked(); break;
        case 7: _t->on_pushSetm_clicked(); break;
        case 8: _t->on_pushProcess_clicked(); break;
        case 9: _t->show_me(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Clean::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Clean::open_check)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Clean::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Clean::open_process)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Clean::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Clean::open_setmdole)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Clean::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Clean::open_setparameter)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Clean::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Clean::close_self)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Clean::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Clean.data,
      qt_meta_data_Clean,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Clean::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Clean::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Clean.stringdata0))
        return static_cast<void*>(const_cast< Clean*>(this));
    return QWidget::qt_metacast(_clname);
}

int Clean::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Clean::open_check()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Clean::open_process()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Clean::open_setmdole()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Clean::open_setparameter()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Clean::close_self()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
