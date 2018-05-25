#ifndef ENEMY_H
#define ENEMY_H
#include "mes_fourmies.h"

class Ennemi: public Creature
{
public:
    void spawn();
};

class Tamanoir: public Ennemi
{
protected:
    int Froce = 100;
    QString Nom = "Richard";
};

class Fourmie_ennemi: public Ennemi
{
    int Points_de_vie;
    int Force;
    les_mechants(){}
};
#endif // ENEMY_H
