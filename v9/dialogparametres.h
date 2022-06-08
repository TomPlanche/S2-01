/**\
  * @file dialogparametres.h
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Présentation du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/
#ifndef DIALOGPARAMETRES_H
#define DIALOGPARAMETRES_H

#include <QDialog>

namespace Ui {
class DialogParametres; // Déclaration de la classe DialogParametres dans le namespace Ui
}

/**\
  * @brief Notre boite de dialogue de paramètres
  *
\**/
class DialogParametres : public QDialog
{
    Q_OBJECT

public:
    /**\
      * @brief Constructeur de la boite de dialogue de paramètres
      *
      * @param parent Fenêtre parent de la boite de dialogue
      *
    \**/
    explicit DialogParametres(QWidget *parent = nullptr);
    /**\
      * @brief Destructeur de la boite de dialogue de paramètres
      *
    \**/
    ~DialogParametres();

    /**\
      * @brief Retourne le pseudo de l'utilisateur
      *
      * @return QString Pseudo de l'utilisateur
    \**/
    QString getPseudo();

    /**\
      * @brief Retourne le nombres de points nécessaires pour gagner
      *
      * @return int Nombres de points nécessaires pour gagner
    \**/
    int getNbPoints();

    /**\
      * @brief Retourne le temps d'une partie
      *
      * @return int Temps d'une partie
    \**/
    int getTemps();


public slots:
    /**\
      * @brief Gère l'appuie sur le bouton OK
      *
    \**/
    void gererBouton();

    /**\
      * @brief Gère le changement de la valeur du slider
      *
      * @param value Valeur du slider
    \**/
    void sliderMoved(int value);


private:
    Ui::DialogParametres *ui; // Interface graphique de la boite de dialogue de paramètres
};

#endif // DIALOGPARAMETRES_H
