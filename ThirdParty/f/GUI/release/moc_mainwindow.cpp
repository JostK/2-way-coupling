/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      40,   29,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      96,   89,   11,   11, 0x08,
     132,  124,   11,   11, 0x08,
     149,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     256,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     289,   11,   11,   11, 0x08,
     300,   11,   11,   11, 0x08,
     309,   11,   11,   11, 0x08,
     324,   11,   11,   11, 0x08,
     350,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     383,   11,   11,   11, 0x08,
     395,   11,   11,   11, 0x08,
     412,   11,   11,   11, 0x08,
     433,   11,   11,   11, 0x08,
     450,   11,   11,   11, 0x08,
     469,   11,   11,   11, 0x08,
     487,   11,   11,   11, 0x08,
     504,   11,   11,   11, 0x08,
     521,   11,   11,   11, 0x08,
     532,   11,   11,   11, 0x08,
     547,   11,   11,   11, 0x08,
     578,   11,   11,   11, 0x08,
     593,   11,   11,   11, 0x08,
     618,   11,   11,   11, 0x08,
     636,   11,   11,   11, 0x08,
     663,   11,  658,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0writeInputFile()\0waveTheory\0"
    "on_waveTheoryChanged(int)\0"
    "on_waveTheoryChanged()\0nFiles\0"
    "on_outputWidgetChanged(int)\0checked\0"
    "storeASCII(bool)\0openFileDialog()\0"
    "openWorkDirDialog()\0selectPPfile()\0"
    "run()\0gnuplot()\0readKinematicFile()\0"
    "about_changed(int)\0convertTo_setup(int)\0"
    "convertTo()\0showGrid()\0smooth()\0"
    "generateGrid()\0geometryType_changed(int)\0"
    "nGridPoints_changed()\0openFile()\0"
    "clearCase()\0selectWaveFile()\0"
    "selectWaveFile_eta()\0selectGridFile()\0"
    "WaveTypeSelected()\0advancedMorison()\0"
    "constantWidget()\0breakingWidget()\0"
    "FDWidget()\0preconWidget()\0"
    "error_grid_checkDomainLength()\0"
    "error_matlab()\0errorMsgParameterCheck()\0"
    "errorMsgSFhZero()\0errorMsgUnknownFile()\0"
    "bool\0checkCase()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->writeInputFile(); break;
        case 1: _t->on_waveTheoryChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_waveTheoryChanged(); break;
        case 3: _t->on_outputWidgetChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->storeASCII((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->openFileDialog(); break;
        case 6: _t->openWorkDirDialog(); break;
        case 7: _t->selectPPfile(); break;
        case 8: _t->run(); break;
        case 9: _t->gnuplot(); break;
        case 10: _t->readKinematicFile(); break;
        case 11: _t->about_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->convertTo_setup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->convertTo(); break;
        case 14: _t->showGrid(); break;
        case 15: _t->smooth(); break;
        case 16: _t->generateGrid(); break;
        case 17: _t->geometryType_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->nGridPoints_changed(); break;
        case 19: _t->openFile(); break;
        case 20: _t->clearCase(); break;
        case 21: _t->selectWaveFile(); break;
        case 22: _t->selectWaveFile_eta(); break;
        case 23: _t->selectGridFile(); break;
        case 24: _t->WaveTypeSelected(); break;
        case 25: _t->advancedMorison(); break;
        case 26: _t->constantWidget(); break;
        case 27: _t->breakingWidget(); break;
        case 28: _t->FDWidget(); break;
        case 29: _t->preconWidget(); break;
        case 30: _t->error_grid_checkDomainLength(); break;
        case 31: _t->error_matlab(); break;
        case 32: _t->errorMsgParameterCheck(); break;
        case 33: _t->errorMsgSFhZero(); break;
        case 34: _t->errorMsgUnknownFile(); break;
        case 35: { bool _r = _t->checkCase();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
