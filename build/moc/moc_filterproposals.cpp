/****************************************************************************
** Meta object code from reading C++ file 'filterproposals.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/userlib/filterproposals.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterproposals.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterProposalsForm_t {
    QByteArrayData data[12];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterProposalsForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterProposalsForm_t qt_meta_stringdata_FilterProposalsForm = {
    {
QT_MOC_LITERAL(0, 0, 19), // "FilterProposalsForm"
QT_MOC_LITERAL(1, 20, 15), // "setPropIdRegExp"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "RegExp"
QT_MOC_LITERAL(4, 44, 13), // "setDateRegExp"
QT_MOC_LITERAL(5, 58, 17), // "setInstNameRegExp"
QT_MOC_LITERAL(6, 76, 14), // "setScopeRegExp"
QT_MOC_LITERAL(7, 91, 13), // "setNameRegExp"
QT_MOC_LITERAL(8, 105, 14), // "setValueRegExp"
QT_MOC_LITERAL(9, 120, 14), // "setStateRegExp"
QT_MOC_LITERAL(10, 135, 13), // "setUserRegExp"
QT_MOC_LITERAL(11, 149, 12) // "sendAndClose"

    },
    "FilterProposalsForm\0setPropIdRegExp\0"
    "\0RegExp\0setDateRegExp\0setInstNameRegExp\0"
    "setScopeRegExp\0setNameRegExp\0"
    "setValueRegExp\0setStateRegExp\0"
    "setUserRegExp\0sendAndClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterProposalsForm[] = {

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
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       5,    1,   65,    2, 0x0a /* Public */,
       6,    1,   68,    2, 0x0a /* Public */,
       7,    1,   71,    2, 0x0a /* Public */,
       8,    1,   74,    2, 0x0a /* Public */,
       9,    1,   77,    2, 0x0a /* Public */,
      10,    1,   80,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,

 // slots: parameters
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

void FilterProposalsForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterProposalsForm *_t = static_cast<FilterProposalsForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPropIdRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setDateRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setInstNameRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setScopeRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setNameRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setValueRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setStateRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setUserRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sendAndClose(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilterProposalsForm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_FilterProposalsForm.data,
    qt_meta_data_FilterProposalsForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterProposalsForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterProposalsForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterProposalsForm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::filterProposalsForm"))
        return static_cast< Ui::filterProposalsForm*>(this);
    return QDialog::qt_metacast(_clname);
}

int FilterProposalsForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
