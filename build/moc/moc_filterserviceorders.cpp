/****************************************************************************
** Meta object code from reading C++ file 'filterserviceorders.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/userlib/filterserviceorders.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterserviceorders.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterServiceOrdersForm_t {
    QByteArrayData data[14];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterServiceOrdersForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterServiceOrdersForm_t qt_meta_stringdata_FilterServiceOrdersForm = {
    {
QT_MOC_LITERAL(0, 0, 23), // "FilterServiceOrdersForm"
QT_MOC_LITERAL(1, 24, 13), // "setSoIdRegExp"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 6), // "RegExp"
QT_MOC_LITERAL(4, 46, 13), // "setDateRegExp"
QT_MOC_LITERAL(5, 60, 17), // "setInstNameRegExp"
QT_MOC_LITERAL(6, 78, 14), // "setScopeRegExp"
QT_MOC_LITERAL(7, 93, 13), // "setNameRegExp"
QT_MOC_LITERAL(8, 107, 14), // "setValueRegExp"
QT_MOC_LITERAL(9, 122, 19), // "setAssignDateRegExp"
QT_MOC_LITERAL(10, 142, 18), // "setProcessedRegExp"
QT_MOC_LITERAL(11, 161, 21), // "setDocProcessedRegExp"
QT_MOC_LITERAL(12, 183, 21), // "setEngProcessedRegExp"
QT_MOC_LITERAL(13, 205, 12) // "sendAndClose"

    },
    "FilterServiceOrdersForm\0setSoIdRegExp\0"
    "\0RegExp\0setDateRegExp\0setInstNameRegExp\0"
    "setScopeRegExp\0setNameRegExp\0"
    "setValueRegExp\0setAssignDateRegExp\0"
    "setProcessedRegExp\0setDocProcessedRegExp\0"
    "setEngProcessedRegExp\0sendAndClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterServiceOrdersForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    1,   72,    2, 0x0a /* Public */,
       5,    1,   75,    2, 0x0a /* Public */,
       6,    1,   78,    2, 0x0a /* Public */,
       7,    1,   81,    2, 0x0a /* Public */,
       8,    1,   84,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      10,    1,   90,    2, 0x0a /* Public */,
      11,    1,   93,    2, 0x0a /* Public */,
      12,    1,   96,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
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

void FilterServiceOrdersForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterServiceOrdersForm *_t = static_cast<FilterServiceOrdersForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSoIdRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setDateRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setInstNameRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setScopeRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setNameRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setValueRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setAssignDateRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setProcessedRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setDocProcessedRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setEngProcessedRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->sendAndClose(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilterServiceOrdersForm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_FilterServiceOrdersForm.data,
    qt_meta_data_FilterServiceOrdersForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterServiceOrdersForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterServiceOrdersForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterServiceOrdersForm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::filterServiceOrdersForm"))
        return static_cast< Ui::filterServiceOrdersForm*>(this);
    return QDialog::qt_metacast(_clname);
}

int FilterServiceOrdersForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
