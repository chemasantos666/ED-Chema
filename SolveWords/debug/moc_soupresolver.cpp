/****************************************************************************
** Meta object code from reading C++ file 'soupresolver.h'
**
** Created: Wed 8. Jun 12:50:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../soupresolver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soupresolver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SoupResolver[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   13,   36,   13, 0x0a,
      60,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SoupResolver[] = {
    "SoupResolver\0\0pintar(QList<QPoint>)\0"
    "QStringList\0solveSoup()\0loadSoup(QString)\0"
};

const QMetaObject SoupResolver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SoupResolver,
      qt_meta_data_SoupResolver, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SoupResolver::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SoupResolver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SoupResolver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoupResolver))
        return static_cast<void*>(const_cast< SoupResolver*>(this));
    return QObject::qt_metacast(_clname);
}

int SoupResolver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pintar((*reinterpret_cast< QList<QPoint>(*)>(_a[1]))); break;
        case 1: { QStringList _r = solveSoup();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 2: loadSoup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SoupResolver::pintar(QList<QPoint> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
