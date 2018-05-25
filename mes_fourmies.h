#ifndef MES_FOURMIES_H
#define MES_FOURMIES_H
#include <QString>
#include <QGraphicsPixmapItem>
#include "ressource.h"
#include <QList>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>

class Creature : public QObject , public QGraphicsPixmapItem
{
    protected:
        int Points_de_vie;
        int Vie_max;
        int Force;
    public:
        Creature (int Points_de_vie, int Vie_max, int Force, QGraphicsPixmapItem *parent=0);
        int GetPV();
        int GetForce();
        void SetPV(int);
        void meurs();
        ~Creature();
};

class Ma_Fourmie: public Creature
{
    protected:
        int Experience;
        int Niveau;
        int Limite_de_niveau;
    public:
        Ma_Fourmie(int Points_de_vie, int Vie_max, int Force, int Experience, int Niveau, int Limite_de_niveau);
        void manger(Nouritture bouffe);
        void Attaquer(Creature &cible);
        void keyPressEvent(QKeyEvent * event);
};

class Guerriere: public Ma_Fourmie  //Les chapeaux bretons
{
    public:
        Guerriere(int Points_de_vie, int Vie_max, int Force, int Experience, int Niveau, int Limite_de_niveau);
        void furie();
        ~Guerriere();
};

class Super_Guerriere: public Guerriere //l'epagneul breton
{

public:
    Super_Guerriere(int Points_de_vie, int Vie_max, int Force, int Experience, int Niveau, int Limite_de_niveau);
    ~Super_Guerriere();
};

class Reine: public Ma_Fourmie
{

public:
    Reine();
};

class Recolteuse: public Ma_Fourmie //Becassine
{
protected:
    bool est_occupee;
public:
    Recolteuse(bool est_occupee);
    void ramasser(Ressource truc);
    void deposer(Ressource truc);
};
#endif // MES_FOURMIES_H
