/****************************************************************************
** Meta object code from reading C++ file 'applyfriend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "applyfriend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applyfriend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ApplyFriend_t {
    QByteArrayData data[13];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApplyFriend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApplyFriend_t qt_meta_stringdata_ApplyFriend = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ApplyFriend"
QT_MOC_LITERAL(1, 12, 13), // "ShowMoreLabel"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "SlotLabelEnter"
QT_MOC_LITERAL(4, 42, 21), // "SlotRemoveFriendLabel"
QT_MOC_LITERAL(5, 64, 26), // "SlotChangeFriendLabelByTip"
QT_MOC_LITERAL(6, 91, 12), // "ClickLbState"
QT_MOC_LITERAL(7, 104, 19), // "SlotLabelTextChange"
QT_MOC_LITERAL(8, 124, 4), // "text"
QT_MOC_LITERAL(9, 129, 21), // "SlotLabelEditFinished"
QT_MOC_LITERAL(10, 151, 28), // "SlotAddFirendLabelByClickTip"
QT_MOC_LITERAL(11, 180, 13), // "SlotApplySure"
QT_MOC_LITERAL(12, 194, 15) // "SlotApplyCancel"

    },
    "ApplyFriend\0ShowMoreLabel\0\0SlotLabelEnter\0"
    "SlotRemoveFriendLabel\0SlotChangeFriendLabelByTip\0"
    "ClickLbState\0SlotLabelTextChange\0text\0"
    "SlotLabelEditFinished\0"
    "SlotAddFirendLabelByClickTip\0SlotApplySure\0"
    "SlotApplyCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApplyFriend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    1,   61,    2, 0x0a /* Public */,
       5,    2,   64,    2, 0x0a /* Public */,
       7,    1,   69,    2, 0x0a /* Public */,
       9,    0,   72,    2, 0x0a /* Public */,
      10,    1,   73,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    2,    2,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ApplyFriend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApplyFriend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowMoreLabel(); break;
        case 1: _t->SlotLabelEnter(); break;
        case 2: _t->SlotRemoveFriendLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SlotChangeFriendLabelByTip((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ClickLbState(*)>(_a[2]))); break;
        case 4: _t->SlotLabelTextChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->SlotLabelEditFinished(); break;
        case 6: _t->SlotAddFirendLabelByClickTip((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->SlotApplySure(); break;
        case 8: _t->SlotApplyCancel(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ApplyFriend::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ApplyFriend.data,
    qt_meta_data_ApplyFriend,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ApplyFriend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApplyFriend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ApplyFriend.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ApplyFriend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
