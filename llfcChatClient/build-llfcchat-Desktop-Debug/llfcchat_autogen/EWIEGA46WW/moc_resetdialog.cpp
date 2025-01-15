/****************************************************************************
** Meta object code from reading C++ file 'resetdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "resetdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resetdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResetDialog_t {
    QByteArrayData data[12];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResetDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResetDialog_t qt_meta_stringdata_ResetDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ResetDialog"
QT_MOC_LITERAL(1, 12, 11), // "switchLogin"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "on_return_btn_clicked"
QT_MOC_LITERAL(4, 47, 21), // "on_varify_btn_clicked"
QT_MOC_LITERAL(5, 69, 21), // "slot_reset_mod_finish"
QT_MOC_LITERAL(6, 91, 5), // "ReqId"
QT_MOC_LITERAL(7, 97, 2), // "id"
QT_MOC_LITERAL(8, 100, 3), // "res"
QT_MOC_LITERAL(9, 104, 10), // "ErrorCodes"
QT_MOC_LITERAL(10, 115, 3), // "err"
QT_MOC_LITERAL(11, 119, 19) // "on_sure_btn_clicked"

    },
    "ResetDialog\0switchLogin\0\0on_return_btn_clicked\0"
    "on_varify_btn_clicked\0slot_reset_mod_finish\0"
    "ReqId\0id\0res\0ErrorCodes\0err\0"
    "on_sure_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResetDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    3,   42,    2, 0x08 /* Private */,
      11,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void,

       0        // eod
};

void ResetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ResetDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchLogin(); break;
        case 1: _t->on_return_btn_clicked(); break;
        case 2: _t->on_varify_btn_clicked(); break;
        case 3: _t->slot_reset_mod_finish((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ErrorCodes(*)>(_a[3]))); break;
        case 4: _t->on_sure_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ResetDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResetDialog::switchLogin)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ResetDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ResetDialog.data,
    qt_meta_data_ResetDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ResetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResetDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ResetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ResetDialog::switchLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
