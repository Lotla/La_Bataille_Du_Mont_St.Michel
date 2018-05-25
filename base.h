#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include "mes_fourmies.h"

class Base: public QObject ,public QGraphicsPixmapItem{
public:

    Base(QGraphicsPixmapItem *parent=0);
    QList<Guerriere *> les_guerrieres;
    QList<Guerriere *> getLes_guerrieres() const;
    QList<Recolteuse *> les_recolteuses;
    QList<Recolteuse *> getLes_recolteuses() const;
    QList<Super_Guerriere *> les_super_guerrieres;
    QList<Super_Guerriere *> getLes_super_guerrieres() const;

    void keyPressEvent(QKeyEvent * event);
    ~Base();


};
#endif // MYRECT_H
