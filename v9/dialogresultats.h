/**\
  * @file dialogresultats.h
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Présentation du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/
#ifndef DIALOGRESULTATS_H
#define DIALOGRESULTATS_H

#include <QDialog>
#include <QtWidgets>
#include <QSqlQuery>

#include "database.h"

namespace Ui {
class DialogResultats; // Déclaration de la classe DialogResultats dans le namespace Ui
}

class DialogResultats : public QDialog
{
    Q_OBJECT

public:
    /**\
      * @brief Constructeur de la boite de dialogue de résultats
      * 
      * @param db Base de données
      * @param parent Fenêtre parent de la boite de dialogue
    \**/
    explicit DialogResultats(Database *db,QWidget *parent = nullptr);
    ~DialogResultats();

private:
    Ui::DialogResultats *ui; // Interface graphique de la boite de dialogue de résultats
    Database *_db; // Base de données
};

#endif // DIALOGRESULTATS_H
