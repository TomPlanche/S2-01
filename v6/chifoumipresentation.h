#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include <QTimer>

#include "chifoumimodele.h"

class ChifoumiVue;

class ChifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    explicit ChifoumiPresentation(ChifoumiModele *m, QObject *parent = nullptr);

    enum UnEtat {etatInitial, partieEnCours, partieEnPause, finDePartie};

    ChifoumiModele *getModele();
    ChifoumiVue *getVue();
    ChifoumiPresentation::UnEtat getEtat();

    uint16_t getTemps();

    void setModele(ChifoumiModele *m);
    void setVue(ChifoumiVue *v);
    void setEtat(ChifoumiPresentation::UnEtat e);




public slots:
    void lancerPartie();

    void jouePierre();
    void jouePapier();
    void joueCiseau();
    void aProposDe();
    void parametrer();

    void updaterTimer();
    void pauseTimer();
    void reprendreTimer();


    void pauseButtonClicked();



private:
    ChifoumiModele *_leModele;
    ChifoumiVue *_laVue;
    UnEtat _etat;


    QTimer *timer;
    const uint16_t DELAIS = 1000;
    const uint16_t TEMPS = _leModele->getTemps();


    void finPartie();

};

#endif // CHIFOUMIPRESENTATION_H
