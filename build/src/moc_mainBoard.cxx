/****************************************************************************
** Meta object code from reading C++ file 'mainBoard.h'
**
** Created: Mon May 4 22:10:49 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/mainBoard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainBoard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      35,   10,   10,   10, 0x05,
      64,   10,   10,   10, 0x05,
      88,   10,   10,   10, 0x05,
     115,   10,   10,   10, 0x05,
     153,  144,   10,   10, 0x05,
     176,  144,   10,   10, 0x05,
     208,  199,   10,   10, 0x05,
     237,   10,   10,   10, 0x05,
     259,  254,   10,   10, 0x05,
     287,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     318,   10,   10,   10, 0x08,
     329,   10,   10,   10, 0x08,
     348,   10,   10,   10, 0x08,
     367,   10,   10,   10, 0x08,
     392,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mainBoard[] = {
    "mainBoard\0\0showMeshSettingSignal()\0"
    "showFilteringSettingSignal()\0"
    "hideMeshSettingSignal()\0"
    "hideOctomapSettingSignal()\0"
    "hideFilteringSettingSignal()\0fullPath\0"
    "savePlySignal(QString)\0savePcdSignal(QString)\0"
    "filename\0addPointCloudSignal(QString)\0"
    "newPanelSignal()\0text\0writeLogFileSignal(QString)\0"
    "startOctomapConvertingSignal()\0"
    "openSlot()\0convertToPcdSlot()\0"
    "convertToPlySlot()\0showOctomapSettingSlot()\0"
    "octomapParamSetted()\0"
};

void mainBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mainBoard *_t = static_cast<mainBoard *>(_o);
        switch (_id) {
        case 0: _t->showMeshSettingSignal(); break;
        case 1: _t->showFilteringSettingSignal(); break;
        case 2: _t->hideMeshSettingSignal(); break;
        case 3: _t->hideOctomapSettingSignal(); break;
        case 4: _t->hideFilteringSettingSignal(); break;
        case 5: _t->savePlySignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->savePcdSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->addPointCloudSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->newPanelSignal(); break;
        case 9: _t->writeLogFileSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->startOctomapConvertingSignal(); break;
        case 11: _t->openSlot(); break;
        case 12: _t->convertToPcdSlot(); break;
        case 13: _t->convertToPlySlot(); break;
        case 14: _t->showOctomapSettingSlot(); break;
        case 15: _t->octomapParamSetted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData mainBoard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mainBoard::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainBoard,
      qt_meta_data_mainBoard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainBoard))
        return static_cast<void*>(const_cast< mainBoard*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mainBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void mainBoard::showMeshSettingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void mainBoard::showFilteringSettingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void mainBoard::hideMeshSettingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void mainBoard::hideOctomapSettingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void mainBoard::hideFilteringSettingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void mainBoard::savePlySignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void mainBoard::savePcdSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void mainBoard::addPointCloudSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void mainBoard::newPanelSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void mainBoard::writeLogFileSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void mainBoard::startOctomapConvertingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}
QT_END_MOC_NAMESPACE
