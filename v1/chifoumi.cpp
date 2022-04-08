#include "chifoumi.h"
#include "ui_chifoumi.h"

Chifoumi::Chifoumi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Chifoumi)
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

    //Menus
    //connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    //connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(aProposDe()));
}

void Chifoumi::lancerPartie()
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

void Chifoumi::jouePierre()
{
    //Maj du coupJoueur
    setCoupJoueur(Chifoumi::pierre);
    //Génération aléatoire du coupMachine
    setCoupMachine(genererUnCoup());
    //On determine le gagnant de la manche afin de mettre à jour le score
    majScores(determinerGagnant());
    //Maj de l'affichage
    majAffichage();
}

void Chifoumi::jouePapier()
{
    setCoupJoueur(Chifoumi::papier);
    setCoupMachine(genererUnCoup());
    majScores(determinerGagnant());
    majAffichage();

}

void Chifoumi::joueCiseau()
{
    setCoupJoueur(Chifoumi::ciseau);
    setCoupMachine(genererUnCoup());
    majScores(determinerGagnant());
    majAffichage();
}




void Chifoumi::aProposDe()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setWindowTitle("A propos de l'application");
    msgBox->setText("Tom, Angel, Matis -> gros bgs");
    msgBox->exec();
}

Chifoumi::~Chifoumi()
{
    delete ui;
}

void Chifoumi::majAffichage()
{
    //Maj des labels scoreJoueur et scoreMachine
    ui->scoreJoueur->setText(QString::number(getScoreJoueur()));
    ui->scoreMachine->setText(QString::number(getScoreMachine()));

    //Maj image label coupJoueur
    switch (getCoupJoueur())
    {
        case pierre: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png"));  break;
        case ciseau: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case papier: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/papier_115.png"));break;
        case rien: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }

    //Maj image label coupMachine
    switch (getCoupMachine())
    {
        case pierre: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png")); break;
        case ciseau: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
        case papier: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png")); break;
        case rien: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
    }
}

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return this->coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return this->coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return this->scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return this->scoreMachine;
}

char Chifoumi::determinerGagnant() {
    char gagnantARetourner;
    // avant de commencer : match nul
    gagnantARetourner = 'N';

    // il sera modifi� dans l'un des cas suivants

    // si le joueur a choisi pierre
    if (getCoupJoueur() == pierre) {
        // si la machine a choisi pierre
        if (getCoupMachine() == pierre) {
            // match nul
            gagnantARetourner = 'N';
        }
        // si la machine a choisi papier
        else if (getCoupMachine() == papier) {
            // le joueur gagne
            gagnantARetourner = 'M';
        }
        // si la machine a choisi ciseau
        else if (getCoupMachine() == ciseau) {
            // la machine gagne
            gagnantARetourner = 'J';
        }
    }
    // si le joueur a choisi papier
    else if (getCoupJoueur() == papier) {
        // si la machine a choisi pierre
        if (getCoupMachine() == pierre) {
            // la machine gagne
            gagnantARetourner = 'J';
        }
        // si la machine a choisi papier
        else if (getCoupMachine() == papier) {
            // match nul
            gagnantARetourner = 'N';
        }
        // si la machine a choisi ciseau
        else if (getCoupMachine() == ciseau) {
            // le joueur gagne
            gagnantARetourner = 'M';
        }
    }
    // si le joueur a choisi ciseau
    else if (getCoupJoueur() == ciseau) {
        // si la machine a choisi pierre
        if (getCoupMachine() == pierre) {
            // le joueur gagne
            gagnantARetourner = 'M';
        }
        // si la machine a choisi papier
        else if (getCoupMachine() == papier) {
            // la machine gagne
            gagnantARetourner = 'J';
        }
        // si la machine a choisi ciseau
        else if (getCoupMachine() == ciseau) {
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

Chifoumi::UnCoup Chifoumi::genererUnCoup() {
    Chifoumi::UnCoup valeurGeneree;  // valeur � retourner
    unsigned int nbAleatoire;
    nbAleatoire = rand() % (4 - 1) + 1;
    switch (nbAleatoire) {
        case 1:
            valeurGeneree = Chifoumi::pierre;
            break;
        case 2:
            valeurGeneree = Chifoumi::papier;
            break;
        case 3:
            valeurGeneree = Chifoumi::ciseau;
            break;
    }
    return valeurGeneree;
}

        /// Setters
void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    this->coupJoueur=p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    this->coupMachine=p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    this->scoreJoueur=p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    this->scoreMachine=p_score;
}

void Chifoumi::majScores(char p_gagnant) {
    if(p_gagnant=='J'){
        this->scoreJoueur++;
    }
    else if (p_gagnant=='M'){
        this->scoreMachine++;
    }
}

void Chifoumi::initScores() {
    this->scoreJoueur=0;
    this->scoreMachine=0;
}

void Chifoumi::initCoups() {
    this->coupJoueur=rien;
    this->coupMachine=rien;
}
