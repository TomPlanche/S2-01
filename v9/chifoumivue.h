/**\
  * @file chifoumivue.h
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Présentation du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <QtWidgets>

#include "dialogparametres.h"
#include "chifoumipresentation.h"



QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; } //namespace Ui
QT_END_NAMESPACE

/**\
  * @brief Notre vue du jeu Chifoumi
  *
\**/
class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    /**\
      * @brief Constructeur de la vue
      *
      * @param parent Parent de la vue
    \**/
    ChifoumiVue(ChifoumiPresentation *p, QWidget *parent = nullptr);

    /**\
      * @brief Destructeur de la vue
      *
    \**/
    ~ChifoumiVue();

    //.  =======================================================================
    //.                                GETTERS
    //.  =======================================================================

    /**\
      * @brief Retourne la présentation du jeu
      *
      * @return ChifoumiModele* Présentation du jeu
    \**/
    ChifoumiPresentation *getPresentation();

    /**\
     * @brief Retourne le psuedo du joueur
     *
     * @return QString pseudoJoueur
    \**/
    QString getPseudoJoueur();


    //.  =======================================================================
    //.                                SETTERS
    //.  =======================================================================
    /**\
      * @brief Définit la présentation du jeu
      *
      * @param p Présentation à définir
    \**/
    void setPresentation(ChifoumiPresentation *p);

    /**\
      * @brief Définit le pseudo du joueur
      *
      * @param s Pseudo à définir
    \**/
    void setPseudoJoueur(QString s);

    /**\
      * @brief Définit le nombre de points à atteindre
      *
      * @param pts Points à définir
    \**/
    void setNbMaxPoints(int pts);

    /**\
      * @brief Définit le temps de jeu
      *
      * @param temps Temps à définir
    \**/
    void setTempsMax(int temps);

    //.  =======================================================================
    //.                                METHODES
    //.  =======================================================================

    /**\
      * @brief Mise à jour de la vue en fonction de l'état de la partie
      *
      * @param e etat de la partie
    \**/
    void majInterface(ChifoumiPresentation::UnEtat e);

    /**\
      * @brief Rend les boutons de la vue actifs
      * si etatInitial
      *
    \**/
    void activerBoutons();

    /**\
      * @brief Rend les boutons de la vue inactifs
      * si non etatInitial
      *
    \**/
    void desactiverBoutons();

    /**\
      * @brief Active le tableau des scores
      * si etatInitial
    \**/
    void activerTableauScores();

    /**\
      * @brief Met à jour le label du timer.
      *
    \**/
    void updaterTimerLabel(int);


private:
    Ui::ChifoumiVue *ui;  // interface graphique

    ChifoumiPresentation *_laPresentation;  // présentation du jeu
};
#endif  // CHIFOUMIVUE_H
