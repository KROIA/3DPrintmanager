#include "filament.h"


Filament::Filament()
{
    Filament("PLA");
}
Filament::Filament(const Filament &other)
{
    *this = other;
}
Filament::Filament(QString material)
{
    Filament(material,QColor(255,255,255));
}
Filament::Filament(QString material, QColor color)
{
    Filament(material,color,1.75);
}
Filament::Filament(QString material, QColor color, double diameter)
{
    Filament(material,color,diameter,205);
}
Filament::Filament(QString material, QColor color, double diameter, unsigned int temperature)
{
    this->material(material);
    this->color(color);
    this->diameter(diameter);
    this->temperature(temperature);
}

Filament::~Filament()
{

}

QString Filament::material()
{
    return _material;
}
QColor Filament::color()
{
    return _color;
}
double Filament::diameter()
{
    return _diameter;
}
unsigned int Filament::temperature()
{
    return _temperature;
}
QString Filament::toString()
{
    return "Filament: Material = "+material()+
           " Color = { r="+QString::number(_color.red())+
           " g="+QString::number(_color.green())+
           " b="+QString::number(_color.blue())+" }"+
           " Diameter = "+QString::number(_diameter)+"mm"+
           " Temperature = "+QString::number(_temperature)+"°C";
}
Filament &Filament::operator=(const Filament &other)
{
    this->material(other._material);
    this->color(other._color);
    this->diameter(other._diameter);
    this->temperature(other._temperature);
    return *this;
}
bool Filament::operator==(const Filament &other)
{
    if(_material    == other._material &&
       _color       == other._color    &&
       std::fabs(_diameter - other._diameter) < std::numeric_limits<double>::epsilon() &&
       _temperature == other._temperature)
        return true;
    else
        return false;
}

//Slots
void Filament::material(QString material)
{
    if(_material == material)
        return;
    _material = material;
    emit materialChanged(_material);
}
void Filament::color(QColor color)
{
    if(_color == color)
        return;
    _color = color;
    emit colorChanged(_color);
}
void Filament::diameter(double diameter)
{
    if(diameter <= 0)
    {
        qDebug() << "Error: Filament::diameter(double diameter = ["<< diameter <<"]) diameter out of Range. Min: 0.5mm";
        diameter = 0.5;
    }
    if((_diameter - diameter) < 0.01)
        return;
    _diameter = diameter;
    emit diameterChanged(_diameter);
}
void Filament::temperature(unsigned int temperature)
{
    if(_temperature == temperature)
        return;
    _temperature = temperature;
    emit temperatureChanged(_temperature);
}
