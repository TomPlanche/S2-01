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
    ChifoumiVue(ChifoumiPresentation *p,QWidget *parent = nullptr);
    ~ChifoumiVue();

    ChifoumiPresentation *getPresentation();
    void setPresentation(ChifoumiPresentation *p);

    void majInterface(ChifoumiPresentation::UnEtat e);
    /* BUT : au début d'une partie ou à la fin d'une manche,
     *       permet de modifier l'affichage en fonction du vainqueur
     *       de la manche (met a jour les images coupJoueur,
     *       coupMachine, label des scores)
     */

    void activerBoutons();
    /* BUT : si etat = etatInitial -> rendre les boutons actifs
     *       lorsqu'une nouvelle partie est demandée
     */

    void activerTableauScores();
    /* BUT : si etat = etatInitial et qu'on veut lancer une partie,
     *       alors on va mettre les labels en bleu
     */

private:
    Ui::ChifoumiVue *ui;

    ChifoumiPresentation *_laPresentation;
};
#endif // CHIFOUMIVUE_H
