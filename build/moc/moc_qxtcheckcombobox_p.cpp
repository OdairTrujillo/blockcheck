/****************************************************************************
** Meta object code from reading C++ file 'qxtcheckcombobox_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/userlib/qxtcheckcombobox_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtcheckcombobox_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QxtCheckComboModel_t {
    QByteArrayData data[3];
    char stringdata[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QxtCheckComboModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QxtCheckComboModel_t qt_meta_stringdata_QxtCheckComboModel = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 17),
QT_MOC_LITERAL(2, 37, 0)
    },
    "QxtCheckComboModel\0checkStateChanged\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QxtCheckComboModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void QxtCheckComboModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QxtCheckComboModel *_t = static_cast<QxtCheckComboModel *>(_o);
        switch (_id) {
        case 0: _t->checkStateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QxtCheckComboModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QxtCheckComboModel::checkStateChanged)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QxtCheckComboModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_QxtCheckComboModel.data,
      qt_meta_data_QxtCheckComboModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *QxtCheckComboModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtCheckComboModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtCheckComboModel.stringdata))
        return static_cast<void*>(const_cast< QxtCheckComboModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int QxtCheckComboModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QxtCheckComboModel::checkStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
struct qt_meta_stringdata_QxtCheckComboBoxPrivate_t {
    QByteArrayData data[5];
    char stringdata[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QxtCheckComboBoxPrivate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QxtCheckComboBoxPrivate_t qt_meta_stringdata_QxtCheckComboBoxPrivate = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 18),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 16),
QT_MOC_LITERAL(4, 61, 5)
    },
    "QxtCheckComboBoxPrivate\0updateCheckedItems\0"
    "\0toggleCheckState\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QxtCheckComboBoxPrivate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void QxtCheckComboBoxPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QxtCheckComboBoxPrivate *_t = static_cast<QxtCheckComboBoxPrivate *>(_o);
        switch (_id) {
        case 0: _t->updateCheckedItems(); break;
        case 1: _t->toggleCheckState((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QxtCheckComboBoxPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtCheckComboBoxPrivate.data,
      qt_meta_data_QxtCheckComboBoxPrivate,  qt_static_metacall, 0, 0}
};


const QMetaObject *QxtCheckComboBoxPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtCheckComboBoxPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxtCheckComboBoxPrivate.stringdata))
        return static_cast<void*>(const_cast< QxtCheckComboBoxPrivate*>(this));
    if (!strcmp(_clname, "QxtPrivate<QxtCheckComboBox>"))
        return static_cast< QxtPrivate<QxtCheckComboBox>*>(const_cast< QxtCheckComboBoxPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int QxtCheckComboBoxPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
