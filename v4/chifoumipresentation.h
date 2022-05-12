#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>

#include "chifoumimodele.h"

class ChifoumiVue;

class ChifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    explicit ChifoumiPresentation(ChifoumiModele *m, QObject *parent = nullptr);

    enum UnEtat {etatInitial,partieEnCours,finDePartie};

    ChifoumiModele *getModele();
    ChifoumiVue *getVue();
    ChifoumiPresentation::UnEtat getEtat();

    void setModele(ChifoumiModele *m);
    void setVue(ChifoumiVue *v);
    void setEtat(ChifoumiPresentation::UnEtat e);

public slots:
    void lancerPartie();
    void jouePierre();
    void jouePapier();
    void joueCiseau();
    void aProposDe();

private:
    ChifoumiModele *_leModele;
    ChifoumiVue *_laVue;
    UnEtat _etat;
};

#endif // CHIFOUMIPRESENTATION_H
