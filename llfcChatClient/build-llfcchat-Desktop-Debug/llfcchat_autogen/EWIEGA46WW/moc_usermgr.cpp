/****************************************************************************
** Meta object code from reading C++ file 'usermgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "usermgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserMgr_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserMgr_t qt_meta_stringdata_UserMgr = {
    {
QT_MOC_LITERAL(0, 0, 7), // "UserMgr"
QT_MOC_LITERAL(1, 8, 16), // "SlotAddFriendRsp"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 24), // "std::shared_ptr<AuthRsp>"
QT_MOC_LITERAL(4, 51, 3), // "rsp"
QT_MOC_LITERAL(5, 55, 17), // "SlotAddFriendAuth"
QT_MOC_LITERAL(6, 73, 25), // "std::shared_ptr<AuthInfo>"
QT_MOC_LITERAL(7, 99, 4) // "auth"

    },
    "UserMgr\0SlotAddFriendRsp\0\0"
    "std::shared_ptr<AuthRsp>\0rsp\0"
    "SlotAddFriendAuth\0std::shared_ptr<AuthInfo>\0"
    "auth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMgr[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       5,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void UserMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SlotAddFriendRsp((*reinterpret_cast< std::shared_ptr<AuthRsp>(*)>(_a[1]))); break;
        case 1: _t->SlotAddFriendAuth((*reinterpret_cast< std::shared_ptr<AuthInfo>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserMgr::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_UserMgr.data,
    qt_meta_data_UserMgr,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserMgr.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<UserMgr>"))
        return static_cast< Singleton<UserMgr>*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<UserMgr>"))
        return static_cast< std::enable_shared_from_this<UserMgr>*>(this);
    return QObject::qt_metacast(_clname);
}

int UserMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
