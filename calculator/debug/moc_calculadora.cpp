/****************************************************************************
** Meta object code from reading C++ file 'calculadora.h'
**
** Created: Mon 20. Jun 11:58:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calculadora.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculadora.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Calculadora[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   12,   13,   12, 0x08,
      47,   44,   13,   12, 0x08,
      77,   12,   73,   12, 0x08,
     100,   12,   95,   12, 0x08,
     127,  125,  118,   12, 0x08,
     149,  125,  118,   12, 0x08,
     181,   44,  118,   12, 0x08,
     211,   12,   95,   12, 0x08,
     231,  125,   13,   12, 0x08,
     256,   12,   13,   12, 0x08,
     285,   12,   13,   12, 0x0a,
     318,   12,  306,   12, 0x0a,
     333,   12,  118,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Calculadora[] = {
    "Calculadora\0\0QString\0meterVariable(QString)\0"
    ",,\0tokens(QString,int&,bool)\0int\0"
    "priority(QString)\0bool\0validate(QString)\0"
    "double\0,\0evaluar(QString,bool)\0"
    "calcularUnarios(double,QString)\0"
    "calcular(double,double,QChar)\0"
    "isOperator(QString)\0toPostFijo(QString,bool)\0"
    "realizarOperaciones(QString)\0"
    "parseComand(QString)\0QStringList\0"
    "getVariables()\0getValorVariable(QString)\0"
};

const QMetaObject Calculadora::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Calculadora,
      qt_meta_data_Calculadora, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Calculadora::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Calculadora::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Calculadora::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Calculadora))
        return static_cast<void*>(const_cast< Calculadora*>(this));
    return QObject::qt_metacast(_clname);
}

int Calculadora::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = meterVariable((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { QString _r = tokens((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { int _r = priority((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { bool _r = validate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { double _r = evaluar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: { double _r = calcularUnarios((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: { double _r = calcular((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QChar(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { bool _r = isOperator((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { QString _r = toPostFijo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = realizarOperaciones((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = parseComand((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { QStringList _r = getVariables();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 12: { double _r = getValorVariable((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
