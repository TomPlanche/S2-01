#include "chifoumivue.h"
#include "ui_chifoumivue.h"

chifoumiVue::chifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chifoumiVue)
{
    ui->setupUi(this);
}

chifoumiVue::~chifoumiVue()
{
    delete ui;
}

// Connexions
void chifoumiVue::addConnexion(QObject *c)
{
    connect(ui->bNewPartie,SIGNAL(clicked()),this,SLOT(lancerPartie()));
    connect(ui->pierre,SIGNAL(clicked()),this,SLOT(jouePierre()));
    connect(ui->papier,SIGNAL(clicked()),this,SLOT(jouePapier()));
    connect(ui->ciseau,SIGNAL(clicked()),this,SLOT(joueCiseau()));
}
void chifoumiVue::suppConnexion(QObject *c)
{
    disconnect(ui->bNewPartie,SIGNAL(clicked()),this,SLOT(lancerPartie()));
    disconnect(ui->pierre,SIGNAL(clicked()),this,SLOT(jouePierre()));
    disconnect(ui->papier,SIGNAL(clicked()),this,SLOT(jouePapier()));
    disconnect(ui->ciseau,SIGNAL(clicked()),this,SLOT(joueCiseau()));
}

//Ordre recu par la presentation
void chifoumiVue::majAffichage(Chifoumi::UnCoup coup)
{

}
