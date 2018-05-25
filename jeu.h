#ifndef JEU_H
#define JEU_H
#include "mes_fourmies.h"
class Jeu
{
    protected:
        bool Jeu_qui_tourne;
    public:
        void initialisation();
        void jeu_lance(Reine ma_reine);
};
#endif // JEU_H
