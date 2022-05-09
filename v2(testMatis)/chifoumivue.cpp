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

    //Iitialisation de l'état
    setEtat(ChifoumiPresentation::etatInitial);

    //Connexion
    //Boutons
    connect(ui->bNewPartie,SIGNAL(clicked()),this,SLOT(demandeNouvellePartie()));
    connect(ui->pierre,SIGNAL(clicked()),this,SLOT(demandePierre()));
    connect(ui->papier,SIGNAL(clicked()),this,SLOT(demandePapier()));
    connect(ui->ciseau,SIGNAL(clicked()),this,SLOT(demandeCiseaux()));
}



ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}

ChifoumiPresentation::UnEtat ChifoumiVue::getEtat()
{
    return this->_etat;
}

void ChifoumiVue::setEtat(ChifoumiPresentation::UnEtat e)
{
    this->_etat = e;
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

void ChifoumiVue::majBoutons()
{
    switch (_etat) {
    case ChifoumiPresentation::etatInitial:
        //On rend actifs les boutons
        ui->pierre->setEnabled(true);
        ui->papier->setEnabled(true);
        ui->ciseau->setEnabled(true);
        break;
    case ChifoumiPresentation::partieEnCours: break;
    default:break;
    }
}

void ChifoumiVue::majTableauScores()
{
    switch (_etat) {
    case ChifoumiPresentation::etatInitial:
        //On met les labels en bleu
        ui->lJoueur->setStyleSheet("color: blue;");
        ui->lMachine->setStyleSheet("color: blue;");
        ui->scoreJoueur->setStyleSheet("color: blue;");
        ui->scoreMachine->setStyleSheet("color: blue;");
        break;
    case ChifoumiPresentation::partieEnCours: break;
    default:break;
    }
}


void ChifoumiVue::demandeNouvellePartie()
{
    _laPresentation->lancerPartie();
}

void ChifoumiVue::demandePierre()
{
    _laPresentation->jouePierre();
}

void ChifoumiVue::demandePapier()
{
    _laPresentation->jouePapier();
}

void ChifoumiVue::demandeCiseaux()
{
    _laPresentation->joueCiseau();
}



