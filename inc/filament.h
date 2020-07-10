#ifndef FILAMENT_H
#define FILAMENT_H

#include <QString>
#include <QObject>
#include <QDebug>
#include <QColor>


class Filament : public QObject
{
    Q_OBJECT
    public:
        Filament();
        Filament(const Filament &other);
        Filament(QString material);
        Filament(QString material, QColor color);
        Filament(QString material, QColor color, double diameter);
        Filament(QString material, QColor color,
                 double diameter, unsigned int temperature);

        ~Filament();

        QString material();
        QColor color();
        double diameter();
        unsigned int temperature();

        QString toString();

    public slots:
        void material(QString material);
        void color(QColor color);
        void diameter(double diameter);
        void temperature(unsigned int temperature);
    private slots:

    signals:
        void materialChanged(QString material);
        void colorChanged(QColor color);
        void diameterChanged(double diameter);
        void temperatureChanged(unsigned int temperature);
    private:
        QString     _material;
        QColor      _color;
        double       _diameter; // mm
        unsigned int _temperature; //grad Celsius


};

#endif // FILAMENT_H
