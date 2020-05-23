/****************************************************************************
** Meta object code from reading C++ file 'dictum.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/core/dictum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dictum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DictumForm_t {
    QByteArrayData data[15];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DictumForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DictumForm_t qt_meta_stringdata_DictumForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DictumForm"
QT_MOC_LITERAL(1, 11, 13), // "processDictum"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "setAllMeetsCheckboxes"
QT_MOC_LITERAL(4, 48, 1), // "i"
QT_MOC_LITERAL(5, 50, 20), // "setNoMeetsCheckboxes"
QT_MOC_LITERAL(6, 71, 18), // "setMeetsCheckboxes"
QT_MOC_LITERAL(7, 90, 13), // "getSubDictums"
QT_MOC_LITERAL(8, 104, 18), // "updateDictumAction"
QT_MOC_LITERAL(9, 123, 10), // "saveDictum"
QT_MOC_LITERAL(10, 134, 12), // "newSubDictum"
QT_MOC_LITERAL(11, 147, 11), // "goSubDictum"
QT_MOC_LITERAL(12, 159, 13), // "previewDictum"
QT_MOC_LITERAL(13, 173, 16), // "launchUsesFilter"
QT_MOC_LITERAL(14, 190, 18) // "changeFilterRegExp"

    },
    "DictumForm\0processDictum\0\0"
    "setAllMeetsCheckboxes\0i\0setNoMeetsCheckboxes\0"
    "setMeetsCheckboxes\0getSubDictums\0"
    "updateDictumAction\0saveDictum\0"
    "newSubDictum\0goSubDictum\0previewDictum\0"
    "launchUsesFilter\0changeFilterRegExp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DictumForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    1,   75,    2, 0x0a /* Public */,
       5,    1,   78,    2, 0x0a /* Public */,
       6,    1,   81,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    1,   90,    2, 0x0a /* Public */,
      14,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void DictumForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DictumForm *_t = static_cast<DictumForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processDictum(); break;
        case 1: _t->setAllMeetsCheckboxes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setNoMeetsCheckboxes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMeetsCheckboxes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getSubDictums(); break;
        case 5: _t->updateDictumAction(); break;
        case 6: _t->saveDictum(); break;
        case 7: _t->newSubDictum(); break;
        case 8: _t->goSubDictum(); break;
        case 9: _t->previewDictum(); break;
        case 10: _t->launchUsesFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->changeFilterRegExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DictumForm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DictumForm.data,
    qt_meta_data_DictumForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DictumForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DictumForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DictumForm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::dictumForm"))
        return static_cast< Ui::dictumForm*>(this);
    return QDialog::qt_metacast(_clname);
}

int DictumForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
