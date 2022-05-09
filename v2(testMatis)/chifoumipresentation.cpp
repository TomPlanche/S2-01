#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include "ui_chifoumivue.h"

ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{

}

ChifoumiModele *ChifoumiPresentation::getModele()
{
    return this->_leModele;
}

ChifoumiVue *ChifoumiPresentation::getVue()
{
    return this->_laVue;
}

void ChifoumiPresentation::setModele(ChifoumiModele *m)
{
    this->_leModele = m;
}

void ChifoumiPresentation::setVue(ChifoumiVue *v)
{
    this->_laVue = v;
}

void ChifoumiPresentation::lancerPartie() {
    switch (_laVue->getEtat()) {
    case ChifoumiPresentation::etatInitial:
        _laVue->majTableauScores();
        _laVue->majBoutons();
        break;
    case ChifoumiPresentation::partieEnCours:
        //On remet à 0 le jeu
        _leModele->initCoups();
        _leModele->initScores();

        _laVue->majAffichage();
        break;
    default:break;
    }
}

void ChifoumiPresentation::jouePierre()
{
    //Maj du coupJoueur
    _leModele->setCoupJoueur(ChifoumiModele::pierre);
    //Génération aléatoire du coupMachine
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    //On determine le gagnant de la manche afin de mettre à jour le score
    _leModele->majScores(getModele()->determinerGagnant());
    //Maj de l'affichage
    _laVue->majAffichage();
}

void ChifoumiPresentation::jouePapier()
{
    _leModele->setCoupJoueur(ChifoumiModele::papier);
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    _leModele->majScores(_leModele->determinerGagnant());
    _laVue->majAffichage();

}

void ChifoumiPresentation::joueCiseau()
{
    _leModele->setCoupJoueur(ChifoumiModele::ciseau);
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    _leModele->majScores(_leModele->determinerGagnant());
    _laVue->majAffichage();
}
