/****************************************************************************
** Meta object code from reading C++ file 'handler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TPFinal/handler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Handler_t {
    QByteArrayData data[23];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Handler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Handler_t qt_meta_stringdata_Handler = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Handler"
QT_MOC_LITERAL(1, 8, 18), // "clearListCPPSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "clearShowMailCPPSignal"
QT_MOC_LITERAL(4, 51, 26), // "addItemToListViewCPPSignal"
QT_MOC_LITERAL(5, 78, 2), // "id"
QT_MOC_LITERAL(6, 81, 4), // "from"
QT_MOC_LITERAL(7, 86, 2), // "to"
QT_MOC_LITERAL(8, 89, 4), // "date"
QT_MOC_LITERAL(9, 94, 7), // "subject"
QT_MOC_LITERAL(10, 102, 7), // "content"
QT_MOC_LITERAL(11, 110, 6), // "isRead"
QT_MOC_LITERAL(12, 117, 17), // "addNewMailCPPSlot"
QT_MOC_LITERAL(13, 135, 12), // "sortedByDate"
QT_MOC_LITERAL(14, 148, 27), // "setMailsDateIntervalCPPSlot"
QT_MOC_LITERAL(15, 176, 5), // "since"
QT_MOC_LITERAL(16, 182, 17), // "sortByDateCPPSlot"
QT_MOC_LITERAL(17, 200, 19), // "sortBySenderCPPSlot"
QT_MOC_LITERAL(18, 220, 20), // "searchByQueryCPPSlot"
QT_MOC_LITERAL(19, 241, 5), // "query"
QT_MOC_LITERAL(20, 247, 21), // "searchBySenderCPPSlot"
QT_MOC_LITERAL(21, 269, 6), // "sender"
QT_MOC_LITERAL(22, 276, 17) // "deleteMailCPPSlot"

    },
    "Handler\0clearListCPPSignal\0\0"
    "clearShowMailCPPSignal\0"
    "addItemToListViewCPPSignal\0id\0from\0"
    "to\0date\0subject\0content\0isRead\0"
    "addNewMailCPPSlot\0sortedByDate\0"
    "setMailsDateIntervalCPPSlot\0since\0"
    "sortByDateCPPSlot\0sortBySenderCPPSlot\0"
    "searchByQueryCPPSlot\0query\0"
    "searchBySenderCPPSlot\0sender\0"
    "deleteMailCPPSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Handler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    7,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    6,   81,    2, 0x0a /* Public */,
      14,    2,   94,    2, 0x0a /* Public */,
      16,    0,   99,    2, 0x0a /* Public */,
      17,    0,  100,    2, 0x0a /* Public */,
      18,    1,  101,    2, 0x0a /* Public */,
      20,    1,  104,    2, 0x0a /* Public */,
      22,    2,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    5,    6,    7,    8,    9,   10,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    6,    7,    8,    9,   10,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    5,   13,

       0        // eod
};

void Handler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Handler *_t = static_cast<Handler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clearListCPPSignal(); break;
        case 1: _t->clearShowMailCPPSignal(); break;
        case 2: _t->addItemToListViewCPPSignal((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4])),(*reinterpret_cast< QVariant(*)>(_a[5])),(*reinterpret_cast< QVariant(*)>(_a[6])),(*reinterpret_cast< QVariant(*)>(_a[7]))); break;
        case 3: _t->addNewMailCPPSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const bool(*)>(_a[6]))); break;
        case 4: _t->setMailsDateIntervalCPPSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->sortByDateCPPSlot(); break;
        case 6: _t->sortBySenderCPPSlot(); break;
        case 7: _t->searchByQueryCPPSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->searchBySenderCPPSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->deleteMailCPPSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Handler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Handler::clearListCPPSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Handler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Handler::clearShowMailCPPSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Handler::*_t)(QVariant , QVariant , QVariant , QVariant , QVariant , QVariant , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Handler::addItemToListViewCPPSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Handler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Handler.data,
      qt_meta_data_Handler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Handler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Handler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Handler.stringdata0))
        return static_cast<void*>(const_cast< Handler*>(this));
    return QObject::qt_metacast(_clname);
}

int Handler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Handler::clearListCPPSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Handler::clearShowMailCPPSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Handler::addItemToListViewCPPSignal(QVariant _t1, QVariant _t2, QVariant _t3, QVariant _t4, QVariant _t5, QVariant _t6, QVariant _t7)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE