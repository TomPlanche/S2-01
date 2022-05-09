#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <QtWidgets>

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
    /* BUT : au début d'une partie ou à la fin d'une manche,
     *       permet de modifier l'affichage en fonction du vainqueur
     *       de la manche (met a jour les images coupJoueur,
     *       coupMachine, label des scores)
     */

    void majBoutons();
    /* BUT : si etat = etatInitial et qu'on veut lancer une partie,
     *       alors on va rendre les boutons actifs
     *       si etat = partieEnCours et qu'on veut relancer une partie,
     *       alors rien ne se passera (les boutons sont dejà activés)
     */

    void majTableauScores();
    /* BUT : si etat = etatInitial et qu'on veut lancer une partie,
     *       alors on va mettre les labels en bleu
     *       si etat = partieEnCours et qu'on veut relancer une partie,
     *       alors rien ne se passera (les labels sont déjà bleus)
     */

    ChifoumiPresentation::UnEtat getEtat();
    void setEtat(ChifoumiPresentation::UnEtat e);

public slots:
    void demandeNouvellePartie();
    void demandePierre();
    void demandeCiseaux();
    void demandePapier();

private:
    Ui::ChifoumiVue *ui;
    ChifoumiPresentation *_laPresentation;
    ChifoumiPresentation::UnEtat _etat;

};
#endif // CHIFOUMIVUE_H
