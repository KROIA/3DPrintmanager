#ifndef PRINTJOB_H
#define PRINTJOB_H

#include <QString>
#include <QObject>
#include <QColor>
#include <QDate>
#include <QTime>
#include <QDir>
#include <QDateTime>

#include <QDebug>

#include "infill.h"
#include "filament.h"
#include "config.h"



class Printjob : public QObject
{
    Q_OBJECT
    public:
        Printjob();
        Printjob(const Printjob &other);

        ~Printjob();

        const QString costumer();
        unsigned int orderReference();
        const QDate date();
        const QTime time();

        const QString stlFile();
        const QString gcodeFile();
        Infill infill();
        Filament filament();
        unsigned int amount();


        void saveToStorage(QString path);

        Printjob &operator=(const Printjob &other);
        bool operator==(const Printjob &other);

    public slots:
        void costumer(QString costumer);
        void orderReference(unsigned int orderReference);
        void date(QDate date);
        void time(QTime time);

        void stlFile(QString stlFile);
        void gcodeFile(QString gcodeFile);
        void infill(Infill infill);
        void filament(Filament filament);
        void amount(unsigned int amount);

        void loadFromStorage(QString path,unsigned int orderReference);


    private slots:

    signals:
        void costumerChanged(QString costumer);
        void orderReferenceChanged(unsigned int orderReference);
        void dateChanged(QDate date);
        void timeChanged(QTime time);

        void stlFileChanged(QString stlFile);
        void gcodeFileChanged(QString gcodeFile);
        void infillChanged(Infill infill);
        void filamentChanged(Filament filament);
        void amountChanged(unsigned int amount);

    private:
        QString _costumer;
        unsigned int _orderReference;
        QDate _date;
        QTime _time;

        QString  _stlFileSourcePath;
        QString  _stlFile;
        QString  _gcodeFileSourcePath;
        QString  _gcodeFile;
        Infill   _infill;
        Filament _filament;
        unsigned int _amount;

        Config _configFile;
};

#endif // PRINTJOB_H
