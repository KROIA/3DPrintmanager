#include "filament.h"


Filament::Filament()
{
    Filament(0);
}
Filament::Filament(const Filament &other)
{
    *this = other;
}
Filament::Filament(int material)
{
    Filament(material,QColor(255,255,255));
}
Filament::Filament(int material, QColor color)
{
    Filament(material,color,1.75);
}
Filament::Filament(int material, QColor color, double diameter)
{
    Filament(material,color,diameter,205);
}
Filament::Filament(int material, QColor color, double diameter, unsigned int temperature)
{
    this->material(material);
    this->color(color);
    this->diameter(diameter);
    this->temperature(temperature);
}

Filament::~Filament()
{

}

int Filament::material()
{
    return _material;
}
const QString Filament::materialName()
{
    return _materialName;
}
const QColor Filament::color()
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
const QString Filament::toString()
{
    return "Filament: Material = ["+QString::number(material())+"] -> "+materialName()+
           " Color = { r="+QString::number(_color.red())+
           " g="+QString::number(_color.green())+
           " b="+QString::number(_color.blue())+" }"+
           " Diameter = "+QString::number(_diameter)+"mm"+
           " Temperature = "+QString::number(_temperature)+"°C";
}
const QString Filament::toColorString(QColor color)
{
    return "r="+QString::number(color.red())+"g="+QString::number(color.green())+"b="+QString::number(color.blue());
}
const QColor Filament::toColor(QString colorStr)
{
    QColor color;
    colorStr = colorStr.mid(colorStr.indexOf("r=")+2);
    color.setRed(colorStr.mid(0,colorStr.indexOf("g=")).toInt());
    colorStr = colorStr.mid(colorStr.indexOf("g=")+2);
    color.setGreen(colorStr.mid(0,colorStr.indexOf("b=")).toInt());
    colorStr = colorStr.mid(colorStr.indexOf("b=")+2);
    color.setBlue(colorStr.toInt());
    return color;
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
void Filament::material(int material)
{
    if(_material == material)
        return;

    if(material >= materialAmount || material < 0)
    {
        qDebug() << "Error: Filament::material(int material = ["<<material
                 <<"]) material out of range. Min is: 0, Max is: "<<materialAmount-1;
        material = Material::PLA;
    }
    _material = material;
    _materialName = __materialName[_material];
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
    if(std::fabs(_diameter - diameter) < std::numeric_limits<double>::epsilon())
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
