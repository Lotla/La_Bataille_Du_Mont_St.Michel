#include "mainwindow.h"
#include "base.h"
#include "enemy.h"
#include"jeu.h"
#include"mainwindow.h"
#include"mes_fourmies.h"
#include"ressource.h"
#include"view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   MainWindow w;
    bool Jeu_qui_tourne;
    w.show();

    return a.exec();
}
