#include "printjob.h"


Printjob::Printjob()
{
    _costumer = "";
    _orderReference = 0;

    _stlFile = "";
    _gcodeFile = "";

}
Printjob::Printjob(const Printjob &other)
{
    *this = other;
}

Printjob::~Printjob()
{

}

QString Printjob::costumer()
{
    return _costumer;
}
unsigned int Printjob::orderReference()
{
    return _orderReference;
}
QDate Printjob::date()
{
    return _date;
}

QString Printjob::stlFile()
{
    return _stlFile;
}
QString Printjob::gcodeFile()
{
    return _gcodeFile;
}
Infill Printjob::infill()
{
    return _infill;
}
Filament Printjob::filament()
{
    return _filament;
}
Printjob &Printjob::operator=(const Printjob &other)
{
    this->_costumer         = other._costumer;
    this->_orderReference   = other._orderReference;
    this->_date             = other._date;

    this->_stlFile          = other._stlFile;
    this->_gcodeFile        = other._gcodeFile;
    this->_infill           = other._infill;
    this->_filament         = other._filament;
}
bool Printjob::operator==(const Printjob &other)
{
    if(this->_costumer          == other._costumer &&
       this->_orderReference    == other._orderReference &&
       this->_date              == other._date &&
       this->_stlFile           == other._stlFile &&
       this->_gcodeFile         == other._gcodeFile &&
       this->_infill            == other._infill &&
       this->_filament          == other._filament)
        return true;
    else
        return false;
}

void Printjob::costumer(QString costumer)
{
    if(_costumer == costumer)
        return;
    _costumer = costumer;
    emit costumerChanged(_costumer);
}
void Printjob::orderReference(unsigned int orderReference)
{
    if(_orderReference == orderReference)
        return;
    _orderReference = orderReference;
    emit orderReferenceChanged(_orderReference);
}
void Printjob::date(QDate date)
{
    if(_date == date)
        return;
    _date = date;
    emit dateChanged(_date);
}

void Printjob::stlFile(QString stlFile)
{
    if(_stlFile == stlFile)
        return;
    _stlFile = stlFile;
    emit stlFileChanged(_stlFile);
}
void Printjob::gcodeFile(QString gcodeFile)
{
    if(_gcodeFile == gcodeFile)
        return;
    _gcodeFile = gcodeFile;
    emit gcodeFileChanged(_gcodeFile);
}
void Printjob::infill(Infill infill)
{
    if(_infill == infill)
        return;
    _infill = infill;
    emit infillChanged(_infill);
}
void Printjob::filament(Filament filament)
{
    if(_filament == filament)
        return;
    _filament = filament;
    emit filamentChanged(_filament);
}
