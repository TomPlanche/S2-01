#include "chifoumimodele.h"

ChifoumiModele::ChifoumiModele(UnCoup coupJoueur,UnCoup coupMachine,QObject *parent):
    QObject{parent},_coupJoueur(coupJoueur),_coupMachine(coupMachine)
{
}


// GETTERS
ChifoumiModele::UnCoup ChifoumiModele::getCoupJoueur() {
    return this->_coupJoueur;
}

ChifoumiModele::UnCoup ChifoumiModele::getCoupMachine() {
    return this->_coupMachine;
}

unsigned int ChifoumiModele::getScoreJoueur() {
    return this->_scoreJoueur;
}

unsigned int ChifoumiModele::getScoreMachine() {
    return this->_scoreMachine;
}


/// Setters
void ChifoumiModele::setCoupJoueur(ChifoumiModele::UnCoup p_coup) {
    this->_coupJoueur=p_coup;
}

void ChifoumiModele::setCoupMachine(ChifoumiModele::UnCoup p_coup) {
    this->_coupMachine=p_coup;
}

void ChifoumiModele::setScoreJoueur(unsigned int p_score) {
    this->_scoreJoueur=p_score;
}

void ChifoumiModele::setScoreMachine(unsigned int p_score) {
    this->_scoreMachine=p_score;
}

void ChifoumiModele::majScores(char p_gagnant) {
    if(p_gagnant=='J'){
        this->_scoreJoueur++;
    }
    else if (p_gagnant=='M'){
        this->_scoreMachine++;
    }
}

void ChifoumiModele::initScores() {
    this->_scoreJoueur=0;
    this->_scoreMachine=0;
}

void ChifoumiModele::initCoups() {
    this->_coupJoueur=ChifoumiModele::rien;
    this->_coupMachine=ChifoumiModele::rien;
}


char ChifoumiModele::determinerGagnant() {
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


