#include "chifoumimodele.h"

ChifoumiModele::ChifoumiModele(UnCoup coupJoueur,UnCoup coupMachine,QObject *parent):
    QObject{parent},_coupJoueur(coupJoueur),_coupMachine(coupMachine)
{
}

ChifoumiModele::UnCoup ChifoumiModele::getCoupJoueur()
{
    return _coupJoueur;
}

ChifoumiModele::UnCoup ChifoumiModele::getCoupMachine()
{
    return _coupMachine;
}
