#include "chifoumipresentation.h"
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

void ChifoumiPresentation::jouePierre()
{
    //Maj du coupJoueur
    ChifoumiPresentation::getModele->setCoupJoueur(ChifoumiModele::pierre);
    //Génération aléatoire du coupMachine
    setCoupMachine(genererUnCoup());
    //On determine le gagnant de la manche afin de mettre à jour le score
    majScores(determinerGagnant());
    //Maj de l'affichage
    _laPresentation->majAffichage();
}

void ChifoumiPresentation::jouePapier()
{
    setCoupJoueur(ChifoumiModele::papier);
    setCoupMachine(genererUnCoup());
    majScores(determinerGagnant());
    _laPresentation->getVue()->majAffichage();

}

void ChifoumiPresentation::joueCiseau()
{
    setCoupJoueur(ChifoumiModele::ciseau);
    setCoupMachine(genererUnCoup());
    majScores(determinerGagnant());
    _laPresentation->getVue()->majAffichage();
}
