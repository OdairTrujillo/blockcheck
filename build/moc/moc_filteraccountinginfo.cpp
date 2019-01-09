/****************************************************************************
** Meta object code from reading C++ file 'filteraccountinginfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/userlib/filteraccountinginfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filteraccountinginfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterAccountingInfoForm_t {
    QByteArrayData data[11];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterAccountingInfoForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterAccountingInfoForm_t qt_meta_stringdata_FilterAccountingInfoForm = {
    {
QT_MOC_LITERAL(0, 0, 24), // "FilterAccountingInfoForm"
QT_MOC_LITERAL(1, 25, 13), // "setSoIdRegExp"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 6), // "RegExp"
QT_MOC_LITERAL(4, 47, 16), // "setMovTypeRegExp"
QT_MOC_LITERAL(5, 64, 21), // "setMovDocummentRegExp"
QT_MOC_LITERAL(6, 86, 16), // "setMovDateRegExp"
QT_MOC_LITERAL(7, 103, 16), // "setMovNameRegExp"
QT_MOC_LITERAL(8, 120, 15), // "setMovNitRegExp"
QT_MOC_LITERAL(9, 136, 24), // "setMovObservationsRegExp"
QT_MOC_LITERAL(10, 161, 12) // "sendAndClose"

    },
    "FilterAccountingInfoForm\0setSoIdRegExp\0"
    "\0RegExp\0setMovTypeRegExp\0setMovDocummentRegExp\0"
    "setMovDateRegExp\0setMovNameRegExp\0"
    "setMovNitRegExp\0setMovObservationsRegExp\0"
    "sendAndClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterAccountingInfoForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x0a /* Public */,
       5,    1,   60,    2, 0x0a /* Public */,
       6,    1,   63,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x0a /* Public */,
       8,    1,   69,    2, 0x0a /* Public */,
       9,    1,   72,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void FilterAccountingInfoForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterAccountingInfoForm *_t = static_cast<FilterAccountingInfoForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSoIdRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setMovTypeRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setMovDocummentRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setMovDateRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setMovNameRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setMovNitRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setMovObservationsRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendAndClose(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilterAccountingInfoForm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_FilterAccountingInfoForm.data,
    qt_meta_data_FilterAccountingInfoForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterAccountingInfoForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterAccountingInfoForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterAccountingInfoForm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::filterAccountingInfoForm"))
        return static_cast< Ui::filterAccountingInfoForm*>(this);
    return QDialog::qt_metacast(_clname);
}

int FilterAccountingInfoForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
