#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <QtWidgets>

#include "chifoumimodele.h"
#include "chifoumipresentation.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();


    void majAffichage();

public slots:
    void lancerPartie();
    void jouePierre();
    void jouePapier();
    void joueCiseau();

private:
    Ui::ChifoumiVue *ui;

    ///* ---- PARTIE MOD�LE ---------------------------


            ///* M�thodes du Mod�le
    public:

        ///* M�thodes utilitaires du Mod�le
    private:
        ChifoumiModele::UnCoup genererUnCoup();
        /* retourne une valeur al�atoire = pierre, papier ou ciseau.
        Utilis�e pour faire jouer la machine */

        // Setters
    public:


        ///* Attributs du Mod�le
    private:

        ChifoumiPresentation *_laPresentation;


    private slots:
        void demandeNouvellePartie();

        void demandePierre();
        void demandeCiseaux();
        void demandePapier();

};
#endif // CHIFOUMIVUE_H
