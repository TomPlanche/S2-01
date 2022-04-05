#include "chifoumi.h"


    ///* ---- PARTIE MOD�LE ---------------------------

Chifoumi::Chifoumi() {
    //ctor
    // partie mod�le
}

Chifoumi::~Chifoumi()
{
    //dtor
}

        /// Getters

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
