#ifndef MAINWINDOW_H
#define MAINWINDOW_H
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include "base.h"
#include <QgraphicsView>
#include <QList>
#include "mes_fourmies.h"
#include "ressource.h"
#include "base.h"
#include <QtWidgets>
#include <QPushButton>
#include <QGraphicsPixmapItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QPushButton *bouton;
    QGraphicsScene * scene = new QGraphicsScene();              //Creation de la scene


    ~MainWindow();
public slots:
    //void spawn_fourmie(QKeyEvent * event);
    void boutonclic();
private slots:
    void on_frame_customContextMenuRequested(const QPoint &pos);
    void on_Boutton_jouer_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
