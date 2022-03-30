/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe m�tier (= mod�le) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MOD�LE ---------------------------

Chifoumi::Chifoumi()
{
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

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur � retourner

	valeurGeneree = rien;
    return valeurGeneree;
}

        /// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
}

void Chifoumi::majScores(char p_gagnant) {
}

void Chifoumi::initScores() {
}

void Chifoumi::initCoups() {
}
