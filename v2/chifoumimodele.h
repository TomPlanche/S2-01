#ifndef CHIFOUMIMODELE_H
#define CHIFOUMIMODELE_H

#include <QObject>
#include "chifoumi.h"

class chifoumiModele : public QObject
{
    Q_OBJECT
public:
    explicit chifoumiModele(Chifoumi::UnCoup coupJoueur=Chifoumi::rien,
                            Chifoumi::UnCoup coupMachine=Chifoumi::rien,
                            QObject *parent = nullptr);

    Chifoumi::UnCoup getCoupJoueur();
    Chifoumi::UnCoup getCoupMachine();

private:
    Chifoumi::UnCoup _coupJoueur;
    Chifoumi::UnCoup _coupMachine;
};

#endif // CHIFOUMIMODELE_H
