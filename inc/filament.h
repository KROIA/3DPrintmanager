#ifndef FILAMENT_H
#define FILAMENT_H

#include <QString>
#include <QObject>
#include <QDebug>
#include <QColor>
#include <cmath>


const int materialAmount = 10;
enum Material
{
    PLA = 0,
    ABS = 1,
};

const QString __materialName[]
{
    "PLA",
    "ABS"
};

class Filament : public QObject
{
    Q_OBJECT
    public:
        Filament();
        Filament(const Filament &other);
        Filament(int material);
        Filament(int material, QColor color);
        Filament(int material, QColor color, double diameter);
        Filament(int material, QColor color,
                 double diameter, unsigned int temperature);

        ~Filament();

        int material();
        const QString materialName();
        const QColor color();
        double diameter();
        unsigned int temperature();

        const QString toString();
        const QString toColorString(QColor color);
        const QColor toColor(QString colorStr);

        Filament &operator=(const Filament &other);
        bool operator==(const Filament &other);

    public slots:
        void material(int material);
        void color(QColor color);
        void diameter(double diameter);
        void temperature(unsigned int temperature);
    private slots:

    signals:
        void materialChanged(int material);
        void colorChanged(QColor color);
        void diameterChanged(double diameter);
        void temperatureChanged(unsigned int temperature);
    private:
        int         _material;
        QString     _materialName;
        QColor      _color;
        double       _diameter; // mm
        unsigned int _temperature; //grad Celsius


};

#endif // FILAMENT_H
