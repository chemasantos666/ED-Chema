/****************************************************************************
** Meta object code from reading C++ file 'diccionary.h'
**
** Created: Thu 9. Jun 23:12:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../diccionary.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diccionary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Diccionary[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   11,   12,   11, 0x0a,
      46,   11,   41,   11, 0x0a,
      64,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Diccionary[] = {
    "Diccionary\0\0QStringList\0getDiccionario()\0"
    "bool\0contains(QString)\0loadDicctionary(QString)\0"
};

const QMetaObject Diccionary::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Diccionary,
      qt_meta_data_Diccionary, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Diccionary::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Diccionary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Diccionary::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Diccionary))
        return static_cast<void*>(const_cast< Diccionary*>(this));
    return QObject::qt_metacast(_clname);
}

int Diccionary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QStringList _r = getDiccionario();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 1: { bool _r = contains((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: loadDicctionary((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
