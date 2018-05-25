#include "jeu.h"
#include "mes_fourmies.h"
#include"enemy.h"
#include<QDebug>

void Jeu :: initialisation()
    {

    }
void Jeu :: jeu_lance(Reine ma_reine)
{
    if (ma_reine.GetPV()<1)
    {
        qDebug()<<"GAME OVER"<<endl;
        //Supprimer toutes les creatures
        Jeu_qui_tourne =0;
    }
}
