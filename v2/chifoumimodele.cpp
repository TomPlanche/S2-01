#include "chifoumimodele.h"

chifoumiModele::chifoumiModele(Chifoumi::UnCoup coupJoueur,Chifoumi::UnCoup coupMachine,QObject *parent):
    QObject{parent},_coupJoueur(coupJoueur),_coupMachine(coupMachine)
{
}

Chifoumi::UnCoup chifoumiModele::getCoupJoueur()
{
    return _coupJoueur;
}

Chifoumi::UnCoup chifoumiModele::getCoupMachine()
{
    return _coupMachine;
}
