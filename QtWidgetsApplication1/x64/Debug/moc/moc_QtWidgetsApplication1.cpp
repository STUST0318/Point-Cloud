/****************************************************************************
** Meta object code from reading C++ file 'QtWidgetsApplication1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QtWidgetsApplication1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtWidgetsApplication1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtWidgetsApplication1_t {
    QByteArrayData data[17];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtWidgetsApplication1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtWidgetsApplication1_t qt_meta_stringdata_QtWidgetsApplication1 = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QtWidgetsApplication1"
QT_MOC_LITERAL(1, 22, 8), // "openFile"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "rSliderChanged"
QT_MOC_LITERAL(4, 47, 14), // "gSliderChanged"
QT_MOC_LITERAL(5, 62, 14), // "bSliderChanged"
QT_MOC_LITERAL(6, 77, 14), // "pSliderChanged"
QT_MOC_LITERAL(7, 92, 16), // "PointColorChange"
QT_MOC_LITERAL(8, 109, 21), // "BackgroundColorchagne"
QT_MOC_LITERAL(9, 131, 16), // "coordinateChange"
QT_MOC_LITERAL(10, 148, 5), // "value"
QT_MOC_LITERAL(11, 154, 10), // "consoleLog"
QT_MOC_LITERAL(12, 165, 9), // "operation"
QT_MOC_LITERAL(13, 175, 7), // "subname"
QT_MOC_LITERAL(14, 183, 8), // "filename"
QT_MOC_LITERAL(15, 192, 4), // "note"
QT_MOC_LITERAL(16, 197, 10) // "opencamera"

    },
    "QtWidgetsApplication1\0openFile\0\0"
    "rSliderChanged\0gSliderChanged\0"
    "bSliderChanged\0pSliderChanged\0"
    "PointColorChange\0BackgroundColorchagne\0"
    "coordinateChange\0value\0consoleLog\0"
    "operation\0subname\0filename\0note\0"
    "opencamera"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtWidgetsApplication1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      11,    4,   74,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,   15,
    QMetaType::Void,

       0        // eod
};

void QtWidgetsApplication1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtWidgetsApplication1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openFile(); break;
        case 1: _t->rSliderChanged(); break;
        case 2: _t->gSliderChanged(); break;
        case 3: _t->bSliderChanged(); break;
        case 4: _t->pSliderChanged(); break;
        case 5: _t->PointColorChange(); break;
        case 6: _t->BackgroundColorchagne(); break;
        case 7: _t->coordinateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->consoleLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->opencamera(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtWidgetsApplication1::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QtWidgetsApplication1.data,
    qt_meta_data_QtWidgetsApplication1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtWidgetsApplication1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtWidgetsApplication1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtWidgetsApplication1.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtWidgetsApplication1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
