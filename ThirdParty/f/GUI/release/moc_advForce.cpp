/****************************************************************************
** Meta object code from reading C++ file 'advForce.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../advForce.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'advForce.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_advForce[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      29,    9,    9,    9, 0x08,
      48,    9,    9,    9, 0x08,
      67,    9,    9,    9, 0x08,
      83,    9,    9,    9, 0x08,
      91,    9,    9,    9, 0x08,
      99,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_advForce[] = {
    "advForce\0\0updateTableSize_()\0"
    "setadvForceFile_()\0setGeometryFile_()\0"
    "plotMonoPile_()\0save_()\0plot_()\0"
    "gridTypeChanged_()\0"
};

void advForce::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        advForce *_t = static_cast<advForce *>(_o);
        switch (_id) {
        case 0: _t->updateTableSize_(); break;
        case 1: _t->setadvForceFile_(); break;
        case 2: _t->setGeometryFile_(); break;
        case 3: _t->plotMonoPile_(); break;
        case 4: _t->save_(); break;
        case 5: _t->plot_(); break;
        case 6: _t->gridTypeChanged_(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData advForce::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject advForce::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_advForce,
      qt_meta_data_advForce, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &advForce::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *advForce::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *advForce::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_advForce))
        return static_cast<void*>(const_cast< advForce*>(this));
    return QWidget::qt_metacast(_clname);
}

int advForce::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
