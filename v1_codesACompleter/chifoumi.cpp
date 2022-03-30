/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe m�tier (= mod�le) Chifoumi-v1
 **************************************************************/
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
    if (scoreJoueur < scoreMachine) {
        return 'M';
    } else if (scoreJoueur > scoreMachine) {
        return 'J';
    } else {
        return 'N';
    }
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
        default:
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
