#include "base.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include <QGraphicsView>
#include <QObject>
#include "mainwindow.h"
#include "mes_fourmies.h"

Base::Base(QGraphicsPixmapItem *parent):
    QObject(),
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/base.png").scaled(QSize(100,150)));
    setPos(400, 300);
}
QList<Guerriere *> Base::getLes_guerrieres() const
{
    return les_guerrieres;
}

QList<Recolteuse *> Base::getLes_recolteuses() const
{
    return les_recolteuses;
}

QList<Super_Guerriere *> Base::getLes_super_guerrieres() const
{
    return les_super_guerrieres;
}

void Base::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
    {
        les_guerrieres << new Guerriere(10,10,10,0,0,5);
        scene()->addItem(les_guerrieres.last());
        qDebug()<<"Creation d'une fourmie guerriere";
        les_guerrieres.last()->setFlag(QGraphicsItem::ItemIsFocusable);
        les_guerrieres.last()->setFocus();
   }

   else if (event->key() == Qt::Key_E)
   {
        les_super_guerrieres << new Super_Guerriere(30,30,30,0,0,15);
        scene()->addItem(les_super_guerrieres.last());
        qDebug()<<"Creation d'une fourmie super guerriere";
        les_super_guerrieres.last()->setFlag(QGraphicsItem::ItemIsFocusable);
        les_super_guerrieres.last()->setFocus();
   }
    else if (event->key() == Qt::Key_Z)
    {
         les_recolteuses << new Recolteuse(0);
         scene()->addItem(les_recolteuses.last());
         qDebug()<<"Creation d'une fourmie recolteuse";
         les_recolteuses.last()->setFlag(QGraphicsItem::ItemIsFocusable);
         les_recolteuses.last()->setFocus();
    }
}

/*

    */
Base::~Base()
{

}
