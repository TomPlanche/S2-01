#include "chifoumimodele.h"

//.  ===========================================================================
//.                               CONSTRUCTEUR                                  
//.  ===========================================================================
ChifoumiModele::ChifoumiModele(UnCoup coupJoueur,UnCoup coupMachine,QObject *parent):
    QObject{parent},_coupJoueur(coupJoueur),_coupMachine(coupMachine)
{
    initCoups();
    initScores();
}

//.  ===========================================================================
//.                                  GETTERS                                    
//.  ===========================================================================
ChifoumiModele::UnCoup ChifoumiModele::getCoupJoueur() {
    return this->_coupJoueur;
}

ChifoumiModele::UnCoup ChifoumiModele::getCoupMachine() {
    return this->_coupMachine;
}

unsigned int ChifoumiModele::getScoreJoueur() {
    return this->_scoreJoueur;
}

uint16_t ChifoumiModele::getScoreMachine() {
    return this->_scoreMachine;
}


int ChifoumiModele::getScorePourGagner()
{
    return this->_scorePourGagner;
}



uint16_t ChifoumiModele::getTempsTimer()
{
    return _temps;
}


ChifoumiModele::UneFinDePartie ChifoumiModele::getFinPartie() {
    return _finPartie;
}



uint16_t ChifoumiModele::getTempsConst()
{
    return TEMPS_OUI_OUI;
}


//.  ===========================================================================
//.                                  SETTERS                                    
//.  ===========================================================================
void ChifoumiModele::setTempsTimer(uint16_t temps) {
    _temps = temps;
}

void ChifoumiModele::setTempsConst(uint16_t temps)
{
    TEMPS_OUI_OUI = temps;
}


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


void ChifoumiModele::setScorePourGagner(int score)
{
    _scorePourGagner=score;
}


void  ChifoumiModele::setFinPartie(UneFinDePartie typeFinPartie) {
    this->_finPartie = typeFinPartie;
}

//.  ===========================================================================
//.                                 M??THODES                                    
//.  ===========================================================================
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


bool ChifoumiModele::maxScore()
{
    bool finPartie = false;
    if(_scoreJoueur == _scorePourGagner || _scoreMachine == _scorePourGagner){
        finPartie = true;
   }
    return finPartie;
}


char ChifoumiModele::determinerGagnant() {
    char gagnantARetourner;
    // avant de commencer : match nul
    gagnantARetourner = 'N';

    // il sera modifi??? dans l'un des cas suivants

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

/**\
  * @brief Retourne un nombre al??atoire entre min et max
  * 
  * @param min Nouvelle valeur minimale
  * @param max Nouvelle valeur maximale
  * @return int Nombe al??atoire
\**/
int randMinMax(int min, int max){
    /* pr??-condition : min<max ;
       Le nbre al??atoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}


ChifoumiModele::UnCoup ChifoumiModele::genererUnCoup() {
    ChifoumiModele::UnCoup valeurGeneree;  // valeur ??? retourner
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
