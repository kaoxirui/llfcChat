/****************************************************************************
** Meta object code from reading C++ file 'tcpmgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tcpmgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpmgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpMgr_t {
    QByteArrayData data[26];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpMgr_t qt_meta_stringdata_TcpMgr = {
    {
QT_MOC_LITERAL(0, 0, 6), // "TcpMgr"
QT_MOC_LITERAL(1, 7, 15), // "sig_con_success"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "bsuccess"
QT_MOC_LITERAL(4, 33, 13), // "sig_send_data"
QT_MOC_LITERAL(5, 47, 5), // "ReqId"
QT_MOC_LITERAL(6, 53, 5), // "reqId"
QT_MOC_LITERAL(7, 59, 4), // "data"
QT_MOC_LITERAL(8, 64, 17), // "sig_swich_chatdlg"
QT_MOC_LITERAL(9, 82, 19), // "sig_load_apply_list"
QT_MOC_LITERAL(10, 102, 10), // "json_array"
QT_MOC_LITERAL(11, 113, 16), // "sig_login_failed"
QT_MOC_LITERAL(12, 130, 15), // "sig_user_search"
QT_MOC_LITERAL(13, 146, 27), // "std::shared_ptr<SearchInfo>"
QT_MOC_LITERAL(14, 174, 16), // "sig_friend_apply"
QT_MOC_LITERAL(15, 191, 31), // "std::shared_ptr<AddFriendApply>"
QT_MOC_LITERAL(16, 223, 19), // "sig_add_auth_friend"
QT_MOC_LITERAL(17, 243, 25), // "std::shared_ptr<AuthInfo>"
QT_MOC_LITERAL(18, 269, 12), // "sig_auth_rsp"
QT_MOC_LITERAL(19, 282, 24), // "std::shared_ptr<AuthRsp>"
QT_MOC_LITERAL(20, 307, 17), // "sig_text_chat_msg"
QT_MOC_LITERAL(21, 325, 28), // "std::shared_ptr<TextChatMsg>"
QT_MOC_LITERAL(22, 354, 3), // "msg"
QT_MOC_LITERAL(23, 358, 16), // "slot_tcp_connect"
QT_MOC_LITERAL(24, 375, 10), // "ServerInfo"
QT_MOC_LITERAL(25, 386, 14) // "slot_send_data"

    },
    "TcpMgr\0sig_con_success\0\0bsuccess\0"
    "sig_send_data\0ReqId\0reqId\0data\0"
    "sig_swich_chatdlg\0sig_load_apply_list\0"
    "json_array\0sig_login_failed\0sig_user_search\0"
    "std::shared_ptr<SearchInfo>\0"
    "sig_friend_apply\0std::shared_ptr<AddFriendApply>\0"
    "sig_add_auth_friend\0std::shared_ptr<AuthInfo>\0"
    "sig_auth_rsp\0std::shared_ptr<AuthRsp>\0"
    "sig_text_chat_msg\0std::shared_ptr<TextChatMsg>\0"
    "msg\0slot_tcp_connect\0ServerInfo\0"
    "slot_send_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpMgr[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    2,   77,    2, 0x06 /* Public */,
       8,    0,   82,    2, 0x06 /* Public */,
       9,    1,   83,    2, 0x06 /* Public */,
      11,    1,   86,    2, 0x06 /* Public */,
      12,    1,   89,    2, 0x06 /* Public */,
      14,    1,   92,    2, 0x06 /* Public */,
      16,    1,   95,    2, 0x06 /* Public */,
      18,    1,   98,    2, 0x06 /* Public */,
      20,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  104,    2, 0x0a /* Public */,
      25,    2,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 21,   22,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 24,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QByteArray,    6,    7,

       0        // eod
};

void TcpMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_con_success((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sig_send_data((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->sig_swich_chatdlg(); break;
        case 3: _t->sig_load_apply_list((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 4: _t->sig_login_failed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sig_user_search((*reinterpret_cast< std::shared_ptr<SearchInfo>(*)>(_a[1]))); break;
        case 6: _t->sig_friend_apply((*reinterpret_cast< std::shared_ptr<AddFriendApply>(*)>(_a[1]))); break;
        case 7: _t->sig_add_auth_friend((*reinterpret_cast< std::shared_ptr<AuthInfo>(*)>(_a[1]))); break;
        case 8: _t->sig_auth_rsp((*reinterpret_cast< std::shared_ptr<AuthRsp>(*)>(_a[1]))); break;
        case 9: _t->sig_text_chat_msg((*reinterpret_cast< std::shared_ptr<TextChatMsg>(*)>(_a[1]))); break;
        case 10: _t->slot_tcp_connect((*reinterpret_cast< ServerInfo(*)>(_a[1]))); break;
        case 11: _t->slot_send_data((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpMgr::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_con_success)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(ReqId , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_send_data)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_swich_chatdlg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(QJsonArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_load_apply_list)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_login_failed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(std::shared_ptr<SearchInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_user_search)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(std::shared_ptr<AddFriendApply> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_friend_apply)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(std::shared_ptr<AuthInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_add_auth_friend)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(std::shared_ptr<AuthRsp> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_auth_rsp)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TcpMgr::*)(std::shared_ptr<TextChatMsg> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpMgr::sig_text_chat_msg)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpMgr::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TcpMgr.data,
    qt_meta_data_TcpMgr,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpMgr.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<TcpMgr>"))
        return static_cast< Singleton<TcpMgr>*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<TcpMgr>"))
        return static_cast< std::enable_shared_from_this<TcpMgr>*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TcpMgr::sig_con_success(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpMgr::sig_send_data(ReqId _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpMgr::sig_swich_chatdlg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpMgr::sig_load_apply_list(QJsonArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpMgr::sig_login_failed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpMgr::sig_user_search(std::shared_ptr<SearchInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpMgr::sig_friend_apply(std::shared_ptr<AddFriendApply> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpMgr::sig_add_auth_friend(std::shared_ptr<AuthInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TcpMgr::sig_auth_rsp(std::shared_ptr<AuthRsp> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TcpMgr::sig_text_chat_msg(std::shared_ptr<TextChatMsg> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
