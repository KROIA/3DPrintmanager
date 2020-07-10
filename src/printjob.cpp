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

const QString Printjob::costumer()
{
    return _costumer;
}
unsigned int Printjob::orderReference()
{
    return _orderReference;
}
const QDate Printjob::date()
{
    return _date;
}
const QTime Printjob::time()
{
    return _time;
}

const QString Printjob::stlFile()
{
    return _stlFile;
}
const QString Printjob::gcodeFile()
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
unsigned int Printjob::amount()
{
    return _amount;
}

void Printjob::saveToStorage(QString path)
{
    qDebug() << "Printjob::saveToStorage(QString path = \""+path+"\") begin";
    QDir directory(path);
    if(!directory.exists())
    {
        qDebug() << "Make directory: "<<directory.path();
        if(!directory.mkdir(directory.path()))
        {

            qDebug() << "Error: can't create directory: "<<directory.path();
        }
    }

    directory.setPath(directory.path()+"/"+QString::number(_orderReference));
    qDebug() << "Make directory: "<<directory.path();
    if(!directory.mkdir(directory.path()))
    {
        qDebug() << "Error: can't create directory: "<<directory.path();
    }

    _configFile.filename(directory.path()+"/"+QString::number(_orderReference)+".txt");
    //_configFile.fileHead({"Auftrag: "+QString::number(_orderReference)
                       //   +_date.toString("dd.MM.yyyy")});
    _configFile.parameter("Kunde",_costumer,"w");
    _configFile.parameterUInt("Auftrag",_orderReference,"w");
    _configFile.parameter("Datum",_date.toString("dd.MM.yyyy"));
    _configFile.parameter("Zeit",_time.toString("hh:mm:ss"));
    _configFile.parameter("stlDatei",_stlFile,"w");
    _configFile.parameter("gcodeDatei",_gcodeFile,"w");

    _configFile.parameter("infill_struktur",QString::number(int(_infill.structure())));
    _configFile.parameter("infill_strukturName",_infill.structureName());
    _configFile.parameter("infill_volumenProzent",QString::number(_infill.volume()));

    _configFile.parameter("filament_material",QString::number(int(_filament.material())));
    _configFile.parameter("filament_materialName",_filament.materialName());
    _configFile.parameter("filament_farbe",_filament.toColorString(_filament.color()));
    _configFile.parameter("filament_durchmesser",QString::number(_filament.diameter()));
    _configFile.parameter("filament_temperature",QString::number(_filament.temperature()));

    _configFile.parameterUInt("stuckzahl",_amount,"w");

    _configFile.save();

    if(_stlFile != "")
    {
        QFile file(_stlFileSourcePath+"/"+_stlFile);
        qDebug() << "copy: "<<file.fileName() << " to: "<<directory.path()+"/"+_stlFile;

        if(!file.copy(directory.path()+"/"+_stlFile))
        {
            qDebug() << "can't copy file: "<<file.fileName();
        }
    }
    if(_gcodeFile != "")
    {
        QFile file(_gcodeFileSourcePath+"/"+_stlFile);
        qDebug() << "copy: "<<file.fileName() << " to: "<<directory.path()+"/"+_gcodeFile;

        if(!file.copy(directory.path()+"/"+_stlFile))
        {
            qDebug() << "can't copy file: "<<file.fileName();
        }
    }

    qDebug() << "Printjob::saveToStorage(QString path = \""+path+"\") end";
}
Printjob &Printjob::operator=(const Printjob &other)
{
    this->_costumer         = other._costumer;
    this->_orderReference   = other._orderReference;
    this->_date             = other._date;
    this->_time             = other._time;

    this->_stlFile          = other._stlFile;
    this->_gcodeFile        = other._gcodeFile;
    this->_infill           = other._infill;
    this->_filament         = other._filament;
    this->_amount           = other._amount;

    this->_configFile       = other._configFile;

}
bool Printjob::operator==(const Printjob &other)
{
    if(this->_costumer          == other._costumer &&
       this->_orderReference    == other._orderReference &&
       this->_date              == other._date &&
       this->_time              == other._time &&
       this->_stlFile           == other._stlFile &&
       this->_gcodeFile         == other._gcodeFile &&
       this->_infill            == other._infill &&
       this->_filament          == other._filament &&
       this->_amount            == other._amount)
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
void Printjob::time(QTime time)
{
    if(_time == time)
        return;
    _time = time;
    emit timeChanged(_time);
}

void Printjob::stlFile(QString stlFile)
{
    stlFile.replace("\\","/");
    QString fileName;
    QString oldPath = _stlFileSourcePath;
    if(stlFile.indexOf("/") != -1)
    {
        fileName = stlFile.mid(stlFile.lastIndexOf("/")+1);
        _stlFileSourcePath = stlFile.mid(0,stlFile.lastIndexOf("/"));
    }else {
        fileName = stlFile;
        _stlFileSourcePath = "";
    }

    if(_stlFile == fileName && oldPath == _stlFileSourcePath)
        return;
    _stlFile = fileName;
    emit stlFileChanged(_stlFile);
}
void Printjob::gcodeFile(QString gcodeFile)
{
    gcodeFile.replace("\\","/");
    QString fileName;
    QString oldPath = _gcodeFileSourcePath;
    if(gcodeFile.indexOf("/") != -1)
    {
        fileName = gcodeFile.mid(gcodeFile.lastIndexOf("/")+1);
        _gcodeFileSourcePath = gcodeFile.mid(0,gcodeFile.lastIndexOf("/"));
    }else {
        fileName = gcodeFile;
        _gcodeFileSourcePath = "";
    }

    if(_stlFile == fileName && oldPath == _gcodeFileSourcePath)
        return;
    _gcodeFile = fileName;
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
void Printjob::amount(unsigned int amount)
{
    if(_amount == amount)
        return;
    _amount = amount;
    emit amountChanged(_amount);
}

void Printjob::loadFromStorage(QString path,unsigned int orderReference)
{
    qDebug() << "Printjob::loadFromStorage(QString path = \""+path+"\") begin";
    _configFile.filename(path+"/"+QString::number(orderReference)+"/"+QString::number(orderReference)+".txt");
    _configFile.read();

    _configFile.parameter("Kunde",_costumer,"r");
    _configFile.parameterUInt("Auftrag",_orderReference,"r");
    QString dateStr = "";
    _configFile.parameter("Datum",dateStr,"r");
    int day   = dateStr.mid(0,dateStr.indexOf(".")).toInt(); dateStr = dateStr.mid(dateStr.indexOf(".")+1);
    int month = dateStr.mid(0,dateStr.indexOf(".")).toInt(); dateStr = dateStr.mid(dateStr.indexOf(".")+1);
    int year  = dateStr.toInt();
    _date.setDate(year,month,day);

    QString timeStr = "";
    _configFile.parameter("Zeit",timeStr,"r");
    int hour     = timeStr.mid(0,timeStr.indexOf(":")).toInt(); timeStr = timeStr.mid(timeStr.indexOf(":")+1);
    int minutes  = timeStr.mid(0,timeStr.indexOf(":")).toInt(); timeStr = timeStr.mid(timeStr.indexOf(":")+1);
    int seconds  = timeStr.toInt();
    _time.setHMS(hour,minutes,seconds);

    _configFile.parameter("stlDatei",_stlFile,"r");
    _configFile.parameter("gcodeDatei",_gcodeFile,"r");

    int infillStructure = 0;
    _configFile.parameterInt("infill_struktur",infillStructure,"r");
    _infill.structure(InfillStructure(infillStructure));

    QString structureName = "";
    _configFile.parameter("infill_strukturName",structureName,"r");
    if(structureName != _infill.structureName())
        qDebug() << "diffrent infill structure name!";

    unsigned int percent = 0;
    _configFile.parameterUInt("infill_volumenProzent",percent,"r");
    _infill.volume(percent);

    int material = 0;
    _configFile.parameterInt("filament_material",material,"r");
    _filament.material(material);

    QString materialName = "";
    _configFile.parameter("filament_materialName",materialName,"r");
    if(materialName != _filament.materialName())
        qDebug() << "diffrent material name!";

    QString colorStr = "";
    _configFile.parameter("filament_farbe",colorStr,"r");
    _filament.color(_filament.toColor(colorStr));

    double diameter = 0.0;
    _configFile.parameterDouble("filament_durchmesser",diameter,"r");
    _filament.diameter(diameter);

    unsigned int temp = 0;
    _configFile.parameterUInt("filament_temperature",temp,"r");
    _filament.temperature(temp);

    _configFile.parameterUInt("stuckzahl",_amount,"r");
    qDebug() << "Printjob::loadFromStorage(QString path = \""+path+"\") end";
}
