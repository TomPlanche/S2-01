#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "chifoumi.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    connect(ui->boutonPierre,SIGNAL(clicked()),this,SLOT(joue_pierre()));
    connect(ui->boutonFeuille,SIGNAL(clicked()),this,SLOT(joue_papier()));
    connect(ui->boutonCiseau,SIGNAL(clicked()),this,SLOT(joue_ciseau()));

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::joue_pierre(){
    unJeu.setCoupJoueur(Chifoumi::pierre);
    ui->imgCoupJoueur->setPixmap(QPixmap(":/v2/images/pierre_115.png"));
}

void GameWindow::joue_papier(){
    unJeu.setCoupJoueur(Chifoumi::papier);
    ui->imgCoupJoueur->setPixmap(QPixmap(":/v2/images/papier_115.png"));
}


void GameWindow::joue_ciseau(){
    unJeu.setCoupJoueur(Chifoumi::ciseau);
    ui->imgCoupJoueur->setPixmap(QPixmap(":/v2/images/ciseau_115.png"));
}
