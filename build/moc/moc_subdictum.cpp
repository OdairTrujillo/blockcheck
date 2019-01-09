/****************************************************************************
** Meta object code from reading C++ file 'subdictum.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/core/subdictum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subdictum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SubDictumForm_t {
    QByteArrayData data[9];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SubDictumForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SubDictumForm_t qt_meta_stringdata_SubDictumForm = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SubDictumForm"
QT_MOC_LITERAL(1, 14, 16), // "processSubDictum"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "setAllMeetsCheckboxes"
QT_MOC_LITERAL(4, 54, 1), // "i"
QT_MOC_LITERAL(5, 56, 20), // "setNoMeetsCheckboxes"
QT_MOC_LITERAL(6, 77, 18), // "setMeetsCheckboxes"
QT_MOC_LITERAL(7, 96, 21), // "updateSubDictumAction"
QT_MOC_LITERAL(8, 118, 13) // "saveSubDictum"

    },
    "SubDictumForm\0processSubDictum\0\0"
    "setAllMeetsCheckboxes\0i\0setNoMeetsCheckboxes\0"
    "setMeetsCheckboxes\0updateSubDictumAction\0"
    "saveSubDictum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SubDictumForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    1,   51,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SubDictumForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SubDictumForm *_t = static_cast<SubDictumForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processSubDictum(); break;
        case 1: _t->setAllMeetsCheckboxes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setNoMeetsCheckboxes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMeetsCheckboxes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateSubDictumAction(); break;
        case 5: _t->saveSubDictum(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SubDictumForm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_SubDictumForm.data,
    qt_meta_data_SubDictumForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SubDictumForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubDictumForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SubDictumForm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::subDictumForm"))
        return static_cast< Ui::subDictumForm*>(this);
    return QDialog::qt_metacast(_clname);
}

int SubDictumForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
