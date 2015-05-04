/****************************************************************************
** Meta object code from reading C++ file 'octmapParamWidget.h'
**
** Created: Mon May 4 22:10:49 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/octmapParamWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'octmapParamWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_octmapParamWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x05,
      64,   52,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     105,   18,   18,   18, 0x08,
     125,  120,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_octmapParamWidget[] = {
    "octmapParamWidget\0\0text\0"
    "writeLogFileSignal(QString)\0octmapParam\0"
    "setCoreLibOctMapSignal(octmapParamType*)\0"
    "setParamSlot()\0type\0rePaintPanelSlot(int)\0"
};

void octmapParamWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        octmapParamWidget *_t = static_cast<octmapParamWidget *>(_o);
        switch (_id) {
        case 0: _t->writeLogFileSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setCoreLibOctMapSignal((*reinterpret_cast< octmapParamType*(*)>(_a[1]))); break;
        case 2: _t->setParamSlot(); break;
        case 3: _t->rePaintPanelSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData octmapParamWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject octmapParamWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_octmapParamWidget,
      qt_meta_data_octmapParamWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &octmapParamWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *octmapParamWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *octmapParamWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_octmapParamWidget))
        return static_cast<void*>(const_cast< octmapParamWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int octmapParamWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void octmapParamWidget::writeLogFileSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void octmapParamWidget::setCoreLibOctMapSignal(octmapParamType * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
