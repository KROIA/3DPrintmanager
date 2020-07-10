#ifndef PRINTJOB_H
#define PRINTJOB_H

#include <QString>
#include <QObject>
#include <QColor>
#include <QDate>

#include "infill.h"
#include "filament.h"



class Printjob : public QObject
{
    Q_OBJECT
    public:
        Printjob();
        Printjob(const Printjob &other);

        ~Printjob();

        QString costumer();
        unsigned int orderReference();
        QDate date();

        QString stlFile();
        QString gcodeFile();
        Infill infill();
        Filament filament();

        Printjob &operator=(const Printjob &other);
        bool operator==(const Printjob &other);

    public slots:
        void costumer(QString costumer);
        void orderReference(unsigned int orderReference);
        void date(QDate date);

        void stlFile(QString stlFile);
        void gcodeFile(QString gcodeFile);
        void infill(Infill infill);
        void filament(Filament filament);

    private slots:

    signals:
        void costumerChanged(QString costumer);
        void orderReferenceChanged(unsigned int orderReference);
        void dateChanged(QDate date);

        void stlFileChanged(QString stlFile);
        void gcodeFileChanged(QString gcodeFile);
        void infillChanged(Infill infill);
        void filamentChanged(Filament filament);


    private:
        QString _costumer;
        unsigned int _orderReference;
        QDate _date;

        QString  _stlFile;
        QString  _gcodeFile;
        Infill   _infill;
        Filament _filament;


};

#endif // PRINTJOB_H
