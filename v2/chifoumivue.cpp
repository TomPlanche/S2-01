#include "chifoumivue.h"
#include "ui_chifoumivue.h"

ChifoumiVue::ChifoumiVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
{
    ui->setupUi(this);

    //Préparation Boutons
    ui->pierre->setDisabled(true);
    ui->papier->setDisabled(true);
    ui->ciseau->setDisabled(true);

    //Connexion
    //Boutons
    connect(ui->bNewPartie,SIGNAL(clicked()),this,SLOT(lancerPartie()));
    connect(ui->pierre,SIGNAL(clicked()),this,SLOT(demandePierre()));
    connect(ui->papier,SIGNAL(clicked()),this,SLOT(demandePapier()));
    connect(ui->ciseau,SIGNAL(clicked()),this,SLOT(demandeCiseaux()));
}



ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}



void ChifoumiVue::majAffichage()
{
    //Maj des labels scoreJoueur et scoreMachine
    ui->scoreJoueur->setText(QString::number(_laPresentation->getModele()->getCoupJoueur()));
    ui->scoreMachine->setText(QString::number(_laPresentation->getModele()->getCoupMachine()));

    //Maj image label coupJoueur
    switch (_laPresentation->getModele()->getCoupJoueur())
    {
        case ChifoumiModele::pierre: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));  break;
        case ChifoumiModele::ciseau: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case ChifoumiModele::papier: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));break;
        case ChifoumiModele::rien: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }

    //Maj image label coupMachine
    switch (_laPresentation->getModele()->getCoupMachine())
    {
        case ChifoumiModele::pierre: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png")); break;
        case ChifoumiModele::ciseau: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case ChifoumiModele::papier: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png")); break;
        case ChifoumiModele::rien: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }
}

void ChifoumiVue::lancerPartie()
{
    ui->pierre->setEnabled(true);
    ui->papier->setEnabled(true);
    ui->ciseau->setEnabled(true);

    majAffichage();

    //On met les labels en bleu
    ui->lJoueur->setStyleSheet("color: blue;");
    ui->lMachine->setStyleSheet("color: blue;");
    ui->scoreJoueur->setStyleSheet("color: blue;");
    ui->scoreMachine->setStyleSheet("color: blue;");
}




void ChifoumiVue::demandeNouvellePartie()
{
    _laPresentation->demandeNouvellePartie();
}

void ChifoumiVue::demandePierre()
{
    _laPresentation->demandePierre();
}


void ChifoumiVue::demandePapier()
{
    _laPresentation->demandePapier();
}

void ChifoumiVue::demandeCiseaux()
{
    _laPresentation->demandeCiseaux();
}


