/****************************************************************************
** Meta object code from reading C++ file 'engineering.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/core/engineering.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engineering.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EngineeringForm_t {
    QByteArrayData data[18];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EngineeringForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EngineeringForm_t qt_meta_stringdata_EngineeringForm = {
    {
QT_MOC_LITERAL(0, 0, 15), // "EngineeringForm"
QT_MOC_LITERAL(1, 16, 16), // "findServiceOrder"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "showCheckFolderForm"
QT_MOC_LITERAL(4, 54, 13), // "checkEngState"
QT_MOC_LITERAL(5, 68, 17), // "processInspection"
QT_MOC_LITERAL(6, 86, 17), // "setInspectionCity"
QT_MOC_LITERAL(7, 104, 9), // "newDictum"
QT_MOC_LITERAL(8, 114, 10), // "goToDictum"
QT_MOC_LITERAL(9, 125, 10), // "getDictums"
QT_MOC_LITERAL(10, 136, 22), // "updateInspectionAction"
QT_MOC_LITERAL(11, 159, 21), // "saveInspectionChanges"
QT_MOC_LITERAL(12, 181, 17), // "listServiceOrders"
QT_MOC_LITERAL(13, 199, 13), // "editDesigners"
QT_MOC_LITERAL(14, 213, 16), // "editConstructors"
QT_MOC_LITERAL(15, 230, 12), // "editAuditors"
QT_MOC_LITERAL(16, 243, 13), // "endInspection"
QT_MOC_LITERAL(17, 257, 21) // "changeInspectionState"

    },
    "EngineeringForm\0findServiceOrder\0\0"
    "showCheckFolderForm\0checkEngState\0"
    "processInspection\0setInspectionCity\0"
    "newDictum\0goToDictum\0getDictums\0"
    "updateInspectionAction\0saveInspectionChanges\0"
    "listServiceOrders\0editDesigners\0"
    "editConstructors\0editAuditors\0"
    "endInspection\0changeInspectionState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EngineeringForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    1,   98,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EngineeringForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EngineeringForm *_t = static_cast<EngineeringForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findServiceOrder(); break;
        case 1: _t->showCheckFolderForm(); break;
        case 2: _t->checkEngState(); break;
        case 3: _t->processInspection(); break;
        case 4: _t->setInspectionCity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->newDictum(); break;
        case 6: _t->goToDictum(); break;
        case 7: _t->getDictums(); break;
        case 8: _t->updateInspectionAction(); break;
        case 9: _t->saveInspectionChanges(); break;
        case 10: _t->listServiceOrders(); break;
        case 11: _t->editDesigners(); break;
        case 12: _t->editConstructors(); break;
        case 13: _t->editAuditors(); break;
        case 14: _t->endInspection(); break;
        case 15: _t->changeInspectionState(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EngineeringForm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_EngineeringForm.data,
    qt_meta_data_EngineeringForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EngineeringForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EngineeringForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EngineeringForm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::engineeringForm"))
        return static_cast< Ui::engineeringForm*>(this);
    return QDialog::qt_metacast(_clname);
}

int EngineeringForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
