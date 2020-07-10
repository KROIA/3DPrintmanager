#include "infill.h"



Infill::Infill()
{
    this->structure(InfillStructure::grid);
    this->volume(30);
}
Infill::Infill(const Infill &other)
{
    *this = other;
}
Infill::Infill(InfillStructure structure)
{
    this->structure(structure);
    this->volume(30);
}
Infill::Infill(InfillStructure structure, unsigned int volumePercent)
{
    this->structure(structure);
    this->volume(volumePercent);
}

Infill::~Infill()
{

}

InfillStructure Infill::structure()
{
    return _structure;
}
QString Infill::structureName()
{
    return _structureName;
}

unsigned int Infill::volume()
{
    return _volumePercent;
}
QString Infill::toString()
{
    return "Infill: Structure = "+this->structureName()+
           " Volume = "+QString::number(_volumePercent)+"%";
}
Infill &Infill::operator=(const Infill &other)
{
    this->structure(other._structure);
    this->volume(other._volumePercent);
    return *this;
}
bool Infill::operator==(const Infill &other)
{
    if(_structure       == other._structure &&
       _volumePercent   == other._volumePercent)
        return true;
    else
        return false;
}

//Slots
void Infill::structure(InfillStructure structure)
{
    if(_structure == structure)
        return;
    if(structure >= infillStructureAmount || structure < 0)
    {
        qDebug() << "Error: Infill::structure(InfillStructure structure = ["<<structure
                 <<"]) structure out of range. Min is: 0, Max is: "<<infillStructureAmount-1;
        structure = InfillStructure::linear;
    }
    _structure = structure;
    _structureName = infillName[_structure];
    emit structureChanged(_structure);
}
void Infill::volume(unsigned int volumePercent)
{
    if(_volumePercent == volumePercent)
        return;
    if(volumePercent > 100)
        volumePercent = 100;
    _volumePercent = volumePercent;
    emit volumePercentChanged(_volumePercent);
}


