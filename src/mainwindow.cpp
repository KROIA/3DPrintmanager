#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bool loadSaveTest = false;

    if(loadSaveTest)
    {
        _printjob.costumer("Alex");
        QDateTime dateTime = QDateTime::currentDateTime();
        qDebug() << "dateTime: "<<dateTime.toString("yyMMddHHmm");
        _printjob.orderReference(dateTime.toString("yyMMddHHmm").toUInt());
        _printjob.date(dateTime.date());
        _printjob.time(dateTime.time());
        _printjob.stlFile("C:/Users/AlexKrieg/Documents/QT/Projects/3DPrintmanager/bin/build-Release/test.stl");
        //_printjob.gcodeFile("test_gcode.gcode");
        _printjob.infill(Infill(InfillStructure::gyroid,25));
        _printjob.filament(Filament(Material::PLA,QColor(10,50,100),1.78,206));
        _printjob.amount(15);

        _printjob.saveToStorage("C:/Users/AlexKrieg/Documents/QT/Projects/3DPrintmanager/bin/build-Release/jobs");
    }
    else {
        _printjob.loadFromStorage("C:/Users/AlexKrieg/Documents/QT/Projects/3DPrintmanager/bin/build-Release/jobs",2007101604);
    }



    qDebug() << "Costumer:     "<<_printjob.costumer();
    qDebug() << "Reference:    "<<_printjob.orderReference();
    qDebug() << "Date:         "<<_printjob.date().toString("dd.MM.yyyy");
    qDebug() << "Time:         "<<_printjob.time().toString("HH:mm:ss");
    qDebug() << "StlFile:      "<<_printjob.stlFile();
    qDebug() << "GcodeFile     "<<_printjob.gcodeFile();
    qDebug() << "Infill:       "<<_printjob.infill().toString();
    qDebug() << "Filament:     "<<_printjob.filament().toString();
    qDebug() << "Amount:       "<<_printjob.amount();
    displayJob(_printjob);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayJob(Printjob &job)
{
    ui->costumer_label->setText(job.costumer());
    ui->orderReference_label->setText(QString::number(job.orderReference()));
    ui->date_label->setText(job.date().toString("dd.MM.yyyy"));
    ui->time_label->setText(job.time().toString("HH:mm:ss"));
    ui->stlFile_label->setText(job.stlFile());
    ui->gcodeFile_label->setText(job.gcodeFile());
    ui->infillStructureName_label->setText(job.infill().structureName());
    ui->infillVolumenPercent_label->setText(QString::number(job.infill().volume()));
    ui->filamentMaterialName_label->setText(job.filament().materialName());

    QPalette pal = ui->filamentColor_label->palette();
    pal.setColor(ui->filamentColor_label->backgroundRole(),job.filament().color());
    ui->filamentColor_label->setPalette(pal);
    ui->filamentColor_label->setAutoFillBackground(true); // rem this to see the difference

    ui->filamenDiameter_label->setText(QString::number(job.filament().diameter(),'g',2));
    ui->filamentTemperature_label->setText(QString::number(job.filament().temperature()));
    ui->amount_label->setText(QString::number(job.amount()));
}
