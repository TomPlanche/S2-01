#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <QtWidgets>
#include "chifoumimodele.h"


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
        // Getters
        ChifoumiModele::UnCoup getCoupJoueur();
        /* retourne le dernier coup jou� par le joueur */
        ChifoumiModele::UnCoup getCoupMachine();
        /* retourne le dernier coup jou� par le joueur */
        unsigned int getScoreJoueur();
        /* retourne le score du joueur */
        unsigned int getScoreMachine();
        /* retourne le score de la machine */
        char determinerGagnant();
        /* d�termine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
        en fonction du dernier coup jou� par chacun d'eux */

        ///* M�thodes utilitaires du Mod�le
    private:
        ChifoumiModele::UnCoup genererUnCoup();
        /* retourne une valeur al�atoire = pierre, papier ou ciseau.
        Utilis�e pour faire jouer la machine */

        // Setters
    public:
        void setCoupJoueur(ChifoumiModele::UnCoup p_coup);
        /* initialise l'attribut coupJoueur avec la valeur
        du param�tre p_coup */
        void setCoupMachine(ChifoumiModele::UnCoup p_coup);
        /* initialise l'attribut coupmachine avec la valeur
        du param�tre p_coup */
        void setScoreJoueur(unsigned int p_score);
        /* initialise l'attribut scoreJoueur avec la valeur
        du param�tre p_score */
        void setScoreMachine(unsigned int p_score);
        /* initialise l'attribut coupMachine avec la valeur
        du param�tre p_score */

        // Autres modificateurs
        void majScores(char p_gagnant);
        /* Mise � jour des scores en fonction des r�gles de gestion actuelles :
                - 1 point pour le gagnant lorsqu'il y a un gagnant
                - 0 point en cas de match nul
        */
        void initScores();
        /* initialise � 0 les attributs scoreJoueur et scoreMachine
        NON indispensable */
        void initCoups();
        /* initialise � rien les attributs coupJoueur et coupMachine
        NON indispensable */

        ///* Attributs du Mod�le
    private:
        unsigned int scoreJoueur;   // score actuel du joueur
        unsigned int scoreMachine;  // score actuel de la Machine
        ChifoumiModele::UnCoup coupJoueur;          // dernier coup jou� par le joueur
        ChifoumiModele::UnCoup coupMachine;         // dernier coup jou� par la machine
};
#endif // CHIFOUMIVUE_H
