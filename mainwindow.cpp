#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "base.h"
#include "Commandes.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QTimer>
#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap ecran_acceuil(":/images/ecran_acceuil.png");
    ecran_acceuil = ecran_acceuil.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, ecran_acceuil);
    this->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_frame_customContextMenuRequested(const QPoint &pos)
{}

void MainWindow::on_Boutton_jouer_clicked()
{
    //Reine * ma_reine = new Reine();
    Commandes * carte = new Commandes();                        //Creation du fond de la carte
    carte->setRect(0,0,800,600);
    scene->addItem(carte);
    carte->setFlag(QGraphicsItem::ItemIsFocusable);

    carte->setFocus();
    Base * base = new Base();                                   //Creation de l'instance de la base
    scene->addItem(base);                                       //Imcorporation de la base a la scene
    base->setFlag(QGraphicsItem::ItemIsFocusable);              //La base peut maintenant interagir
    base->setFocus();                                           //On interagit actuellement avec la base
    QGraphicsView * view = new QGraphicsView(scene);            //Creation d'une vue pour pouvoir voir la scene
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //La vue de la scene ne vas pas suivre horizontalement l'objet que l'on focus
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //La vue de la scene ne vas pas suivre verticalement l'objet que l'on focus
    view->setBackgroundBrush(QBrush(QImage(":/images/fond.png").scaled(scene->width(), scene->height(), Qt::IgnoreAspectRatio, Qt::FastTransformation)));   //Fond d'ecran en jeu
    view->show();                                               //Affichage de la vue
    view->setFixedSize(800,600);                                //Dimensions de la fenetre d'affichage
    scene->setSceneRect(0,0,800,600);                           //Dimensions de la scene
    base->setPos(350,0);     //La base est dans le coin inferieur gauche de la fenetre
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/musique.mp3"));
    music->play();
}

void MainWindow::boutonclic()

{
    qDebug()<<"Wesh le bouton il marche";
}
