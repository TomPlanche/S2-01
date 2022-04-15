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

void ChifoumiVue::lancerPartie()
{
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

void ChifoumiVue::majAffichage()
{
    //Maj des labels scoreJoueur et scoreMachine
    ui->scoreJoueur->setText(QString::number(getScoreJoueur()));
    ui->scoreMachine->setText(QString::number(getScoreMachine()));

    //Maj image label coupJoueur
    switch (getCoupJoueur())
    {
        case ChifoumiModele::pierre: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));  break;
        case ChifoumiModele::ciseau: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case ChifoumiModele::papier: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));break;
        case ChifoumiModele::rien: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }

    //Maj image label coupMachine
    switch (getCoupMachine())
    {
        case ChifoumiModele::pierre: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png")); break;
        case ChifoumiModele::ciseau: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case ChifoumiModele::papier: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png")); break;
        case ChifoumiModele::rien: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }
}

ChifoumiModele::UnCoup ChifoumiVue::getCoupJoueur() {
    return this->coupJoueur;
}

ChifoumiModele::UnCoup ChifoumiVue::getCoupMachine() {
    return this->coupMachine;
}

unsigned int ChifoumiVue::getScoreJoueur() {
    return this->scoreJoueur;
}

unsigned int ChifoumiVue::getScoreMachine() {
    return this->scoreMachine;
}

char ChifoumiVue::determinerGagnant() {
    char gagnantARetourner;
    // avant de commencer : match nul
    gagnantARetourner = 'N';

    // il sera modifi� dans l'un des cas suivants

    // si le joueur a choisi pierre
    if (getCoupJoueur() == ChifoumiModele::pierre) {
        // si la machine a choisi pierre
        if (getCoupMachine() == ChifoumiModele::pierre) {
            // match nul
            gagnantARetourner = 'N';
        }
        // si la machine a choisi papier
        else if (getCoupMachine() == ChifoumiModele::papier) {
            // le joueur gagne
            gagnantARetourner = 'M';
        }
        // si la machine a choisi ciseau
        else if (getCoupMachine() == ChifoumiModele::ciseau) {
            // la machine gagne
            gagnantARetourner = 'J';
        }
    }
    // si le joueur a choisi papier
    else if (getCoupJoueur() == ChifoumiModele::papier) {
        // si la machine a choisi pierre
        if (getCoupMachine() == ChifoumiModele::pierre) {
            // la machine gagne
            gagnantARetourner = 'J';
        }
        // si la machine a choisi papier
        else if (getCoupMachine() == ChifoumiModele::papier) {
            // match nul
            gagnantARetourner = 'N';
        }
        // si la machine a choisi ciseau
        else if (getCoupMachine() == ChifoumiModele::ciseau) {
            // le joueur gagne
            gagnantARetourner = 'M';
        }
    }
    // si le joueur a choisi ciseau
    else if (getCoupJoueur() == ChifoumiModele::ciseau) {
        // si la machine a choisi pierre
        if (getCoupMachine() == ChifoumiModele::pierre) {
            // le joueur gagne
            gagnantARetourner = 'M';
        }
        // si la machine a choisi papier
        else if (getCoupMachine() == ChifoumiModele::papier) {
            // la machine gagne
            gagnantARetourner = 'J';
        }
        // si la machine a choisi ciseau
        else if (getCoupMachine() == ChifoumiModele::ciseau) {
            // match nul
            gagnantARetourner = 'N';
        }
    }

    return gagnantARetourner;
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

        /// Setters
void ChifoumiVue::setCoupJoueur(ChifoumiModele::UnCoup p_coup) {
    this->coupJoueur=p_coup;
}

void ChifoumiVue::setCoupMachine(ChifoumiModele::UnCoup p_coup) {
    this->coupMachine=p_coup;
}

void ChifoumiVue::setScoreJoueur(unsigned int p_score) {
    this->scoreJoueur=p_score;
}

void ChifoumiVue::setScoreMachine(unsigned int p_score) {
    this->scoreMachine=p_score;
}

void ChifoumiVue::majScores(char p_gagnant) {
    if(p_gagnant=='J'){
        this->scoreJoueur++;
    }
    else if (p_gagnant=='M'){
        this->scoreMachine++;
    }
}

void ChifoumiVue::initScores() {
    this->scoreJoueur=0;
    this->scoreMachine=0;
}

void ChifoumiVue::initCoups() {
    this->coupJoueur=ChifoumiModele::rien;
    this->coupMachine=ChifoumiModele::rien;
}
