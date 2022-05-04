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
    connect(ui->pierre,SIGNAL(clicked()),this,SLOT(jouePierre()));
    connect(ui->papier,SIGNAL(clicked()),this,SLOT(jouePapier()));
    connect(ui->ciseau,SIGNAL(clicked()),this,SLOT(joueCiseau()));
}

void ChifoumiVue::lancerPartie() {
    ui->pierre->setEnabled(true);
    ui->papier->setEnabled(true);
    ui->ciseau->setEnabled(true);

    //On remet à 0 le jeu
    initCoups();
    initScores();
    majAffichage();

    //On met les labels en bleu
    ui->lJoueur->setStyleSheet("color: blue;");
    ui->lMachine->setStyleSheet("color: blue;");
    ui->scoreJoueur->setStyleSheet("color: blue;");
    ui->scoreMachine->setStyleSheet("color: blue;");
}

void ChifoumiVue::jouePierre()
{
    //Maj du coupJoueur
    setCoupJoueur(ChifoumiModele::pierre);
    //Génération aléatoire du coupMachine
    setCoupMachine(genererUnCoup());
    //On determine le gagnant de la manche afin de mettre à jour le score
    majScores(determinerGagnant());
    //Maj de l'affichage
    majAffichage();
}

void ChifoumiVue::jouePapier()
{
    setCoupJoueur(ChifoumiModele::papier);
    setCoupMachine(genererUnCoup());
    majScores(determinerGagnant());
    majAffichage();

}

void ChifoumiVue::joueCiseau()
{
    setCoupJoueur(ChifoumiModele::ciseau);
    setCoupMachine(genererUnCoup());
    majScores(determinerGagnant());
    majAffichage();
}

ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}



         ///* M�thodes utilitaires du Mod�le

int randMinMax(int min, int max){
    /* pr�-condition : min<max ;
       Le nbre al�atoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

ChifoumiModele::UnCoup ChifoumiVue::genererUnCoup() {
    ChifoumiModele::UnCoup valeurGeneree;  // valeur � retourner
    unsigned int nbAleatoire;
    nbAleatoire = rand() % (4 - 1) + 1;
    switch (nbAleatoire) {
        case 1:
            valeurGeneree = ChifoumiModele::pierre;
            break;
        case 2:
            valeurGeneree = ChifoumiModele::papier;
            break;
        case 3:
            valeurGeneree = ChifoumiModele::ciseau;
            break;
    }
    return valeurGeneree;
}



void ChifoumiVue::majAffichage()
{
    //Maj des labels scoreJoueur et scoreMachine
    ui->scoreJoueur->setText(QString::number(_leModele->getScoreJoueur()));
    ui->scoreMachine->setText(QString::number(_leModele->getScoreMachine()));

    //Maj image label coupJoueur
    switch (_leModele->getCoupJoueur())
    {
        case ChifoumiModele::pierre: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));  break;
        case ChifoumiModele::ciseau: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case ChifoumiModele::papier: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));break;
        case ChifoumiModele::rien: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }

    //Maj image label coupMachine
    switch (_leModele->getCoupMachine())
    {
        case ChifoumiModele::pierre: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png")); break;
        case ChifoumiModele::ciseau: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case ChifoumiModele::papier: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png")); break;
        case ChifoumiModele::rien: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }
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


