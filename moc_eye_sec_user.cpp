/****************************************************************************
** Meta object code from reading C++ file 'eye_sec_user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "eye_sec_user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eye_sec_user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_eye_sec_user_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_eye_sec_user_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_eye_sec_user_t qt_meta_stringdata_eye_sec_user = {
    {
QT_MOC_LITERAL(0, 0, 12), // "eye_sec_user"
QT_MOC_LITERAL(1, 13, 17), // "on_submit_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "std::vector<Person>"
QT_MOC_LITERAL(4, 52, 6), // "people"
QT_MOC_LITERAL(5, 59, 10), // "eyeLibrary"
QT_MOC_LITERAL(6, 70, 3), // "lib"
QT_MOC_LITERAL(7, 74, 22) // "on_exit_button_clicked"

    },
    "eye_sec_user\0on_submit_clicked\0\0"
    "std::vector<Person>\0people\0eyeLibrary\0"
    "lib\0on_exit_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_eye_sec_user[] = {

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
       1,    2,   24,    2, 0x08 /* Private */,
       7,    0,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

       0        // eod
};

void eye_sec_user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        eye_sec_user *_t = static_cast<eye_sec_user *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_submit_clicked((*reinterpret_cast< std::vector<Person>(*)>(_a[1])),(*reinterpret_cast< eyeLibrary(*)>(_a[2]))); break;
        case 1: _t->on_exit_button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject eye_sec_user::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_eye_sec_user.data,
      qt_meta_data_eye_sec_user,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *eye_sec_user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *eye_sec_user::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_eye_sec_user.stringdata0))
        return static_cast<void*>(const_cast< eye_sec_user*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int eye_sec_user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
