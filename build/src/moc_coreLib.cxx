/****************************************************************************
** Meta object code from reading C++ file 'coreLib.h'
**
** Created: Mon May 4 22:10:48 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/coreLib.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coreLib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_coreLib[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,    9,    8,    8, 0x05,
      68,   59,    8,    8, 0x05,
     104,   59,    8,    8, 0x05,
     133,   59,    8,    8, 0x05,
     161,   59,    8,    8, 0x05,
     183,    9,    8,    8, 0x05,
     247,   59,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     274,   59,    8,    8, 0x08,
     301,    8,    8,    8, 0x08,
     322,    8,    8,    8, 0x08,
     349,  343,    8,    8, 0x08,
     391,    8,    8,    8, 0x08,
     429,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_coreLib[] = {
    "coreLib\0\0,filename\0"
    "firstOctomapShowSignal(OcTree*,QString)\0"
    "filename\0refreshOctomapWindowSignal(QString)\0"
    "fileSletectedSignal(QString)\0"
    "writeLogFileSignal(QString)\0"
    "reshowSignal(QString)\0"
    "firstShowSignal(pcl::PointCloud<pcl::PointXYZRGB>::Ptr,QString)\0"
    "addFileNameSignal(QString)\0"
    "addPointCloudSlot(QString)\0"
    "savePlySlot(QString)\0savePcdSlot(QString)\0"
    "item,\0pclIndexChangedSlot(QTreeWidgetItem*,int)\0"
    "setOctomapParamSlot(octmapParamType*)\0"
    "setFilteringParamSlot()\0"
};

void coreLib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        coreLib *_t = static_cast<coreLib *>(_o);
        switch (_id) {
        case 0: _t->firstOctomapShowSignal((*reinterpret_cast< OcTree*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->refreshOctomapWindowSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fileSletectedSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->writeLogFileSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->reshowSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->firstShowSignal((*reinterpret_cast< pcl::PointCloud<pcl::PointXYZRGB>::Ptr(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->addFileNameSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->addPointCloudSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->savePlySlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->savePcdSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->pclIndexChangedSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->setOctomapParamSlot((*reinterpret_cast< octmapParamType*(*)>(_a[1]))); break;
        case 12: _t->setFilteringParamSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData coreLib::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject coreLib::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_coreLib,
      qt_meta_data_coreLib, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &coreLib::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *coreLib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *coreLib::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_coreLib))
        return static_cast<void*>(const_cast< coreLib*>(this));
    return QObject::qt_metacast(_clname);
}

int coreLib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void coreLib::firstOctomapShowSignal(OcTree * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void coreLib::refreshOctomapWindowSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void coreLib::fileSletectedSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void coreLib::writeLogFileSignal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void coreLib::reshowSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void coreLib::firstShowSignal(pcl::PointCloud<pcl::PointXYZRGB>::Ptr _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void coreLib::addFileNameSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
