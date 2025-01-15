/****************************************************************************
** Meta object code from reading C++ file 'searchlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "searchlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchList_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchList_t qt_meta_stringdata_SearchList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SearchList"
QT_MOC_LITERAL(1, 11, 18), // "sig_jump_chat_item"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 27), // "std::shared_ptr<SearchInfo>"
QT_MOC_LITERAL(4, 59, 2), // "si"
QT_MOC_LITERAL(5, 62, 17), // "slot_item_clicked"
QT_MOC_LITERAL(6, 80, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 97, 4), // "item"
QT_MOC_LITERAL(8, 102, 16) // "slot_user_search"

    },
    "SearchList\0sig_jump_chat_item\0\0"
    "std::shared_ptr<SearchInfo>\0si\0"
    "slot_item_clicked\0QListWidgetItem*\0"
    "item\0slot_user_search"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x08 /* Private */,
       8,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void SearchList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_jump_chat_item((*reinterpret_cast< std::shared_ptr<SearchInfo>(*)>(_a[1]))); break;
        case 1: _t->slot_item_clicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slot_user_search((*reinterpret_cast< std::shared_ptr<SearchInfo>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchList::*)(std::shared_ptr<SearchInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchList::sig_jump_chat_item)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SearchList::staticMetaObject = { {
    &QListWidget::staticMetaObject,
    qt_meta_stringdata_SearchList.data,
    qt_meta_data_SearchList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SearchList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchList.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int SearchList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SearchList::sig_jump_chat_item(std::shared_ptr<SearchInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
