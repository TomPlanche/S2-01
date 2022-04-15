#ifndef CHIFOUMIMODELE_H
#define CHIFOUMIMODELE_H

#include <QObject>

class ChifoumiModele : public QObject
{
    Q_OBJECT
public:
    enum UnCoup {pierre, papier, ciseau, rien };

    explicit ChifoumiModele(UnCoup coupJoueur=rien,
                            UnCoup coupMachine=rien,
                            QObject *parent = nullptr);

    UnCoup getCoupJoueur();
    UnCoup getCoupMachine();

private:
    UnCoup _coupJoueur;
    UnCoup _coupMachine;
};

#endif // CHIFOUMIMODELE_H
