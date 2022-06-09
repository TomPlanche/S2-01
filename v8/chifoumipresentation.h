#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QtWidgets>
#include <QObject>
#include <QTimer>
#include <QSqlQuery>

#include "database.h"
#include "chifoumimodele.h"
#include "dialogconnexion.h"

class ChifoumiVue;

class ChifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    explicit ChifoumiPresentation(ChifoumiModele *m,Database *db,QObject *parent = nullptr);

    enum UnEtat {etatInitial, partieEnCours, partieEnPause, finDePartie};

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

    void finPartie();
    Database *_db;
};

#endif // CHIFOUMIPRESENTATION_H
