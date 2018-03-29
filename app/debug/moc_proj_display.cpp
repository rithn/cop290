/****************************************************************************
** Meta object code from reading C++ file 'proj_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../proj_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proj_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Proj_display_t {
    QByteArrayData data[10];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Proj_display_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Proj_display_t qt_meta_stringdata_Proj_display = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Proj_display"
QT_MOC_LITERAL(1, 13, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "checked"
QT_MOC_LITERAL(4, 42, 21), // "on_checkBox_2_toggled"
QT_MOC_LITERAL(5, 64, 21), // "on_checkBox_3_toggled"
QT_MOC_LITERAL(6, 86, 21), // "on_checkBox_4_toggled"
QT_MOC_LITERAL(7, 108, 21), // "on_checkBox_5_toggled"
QT_MOC_LITERAL(8, 130, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(9, 153, 24) // "on_radioButton_2_clicked"

    },
    "Proj_display\0on_checkBox_toggled\0\0"
    "checked\0on_checkBox_2_toggled\0"
    "on_checkBox_3_toggled\0on_checkBox_4_toggled\0"
    "on_checkBox_5_toggled\0on_radioButton_clicked\0"
    "on_radioButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Proj_display[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       5,    1,   55,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       7,    1,   61,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Proj_display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Proj_display *_t = static_cast<Proj_display *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_checkBox_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_checkBox_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_checkBox_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_radioButton_clicked(); break;
        case 6: _t->on_radioButton_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Proj_display::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Proj_display.data,
      qt_meta_data_Proj_display,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Proj_display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Proj_display::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Proj_display.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Proj_display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
