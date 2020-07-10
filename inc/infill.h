#ifndef INFILL_H
#define INFILL_H

#include <QString>
#include <QObject>
#include <QDebug>


const int infillStructureAmount = 10;
enum InfillStructure
{
    linear = 0,
    grid   = 1,
    triangle = 2,
    star = 3,
    cubic = 4,
    line = 5,
    concentric = 6,
    honeycomb = 7,
    honeycomb3D = 8,
    gyroid = 9
};

const QString infillName[]
{
    "Gradlinig",
    "Gitternetz",
    "Dreiecke",
    "Sterne",
    "Kubisch",
    "Linie",
    "Konzentrisch",
    "Bienenwabe",
    "3D Bienenwabe",
    "Gyroid",
};


class Infill : public QObject
{
    Q_OBJECT
    public:

        Infill();
        Infill(const Infill &other);
        Infill(InfillStructure structure);
        Infill(InfillStructure structure, unsigned int volumePercent);

        ~Infill();

        InfillStructure structure();
        const QString structureName();

        unsigned int volume();

        const QString toString();

        Infill &operator=(const Infill &other);
        bool operator==(const Infill &other);


    public slots:
        void structure(InfillStructure structure);
        void volume(unsigned int volumePercent);

    private slots:

    signals:
        void structureChanged(int structure);
        void volumePercentChanged(unsigned int volumePercent);

    private:
        InfillStructure _structure;
        QString _structureName;
        unsigned int _volumePercent;
};


#endif // INFILL_H
