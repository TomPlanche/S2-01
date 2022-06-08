/**\
  * @file dialogconnexion.h
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Présentation du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/
#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QtWidgets>
#include <QDialog>
#include "database.h"
#include <QSqlQuery>

namespace Ui {
class DialogConnexion; // Déclaration de la classe DialogConnexion dans le namespace Ui
}

/**\
  * @brief Notre boite de dialogue de connexion
  * 
\**/
class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    /**\
      * @brief Constructeur de la boite de dialogue de connexion
      * 
      * @param parent Fenêtre parent de la boite de dialogue
    \**/
    explicit DialogConnexion(QWidget *parent = nullptr);
    /**\
      * @brief Destructeur de la boite de dialogue de connexion
      * 
    \**/
    ~DialogConnexion();

public slots:
    /**\
      * @brief Demande la connexion de l'utilisateur
      * 
    \**/
    void demandeConnexion();

private:
    Ui::DialogConnexion *ui; // Interface graphique de la boite de dialogue de connexion
    Database *db; // Base de données
};

#endif // DIALOGCONNEXION_H
