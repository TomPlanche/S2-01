/**\
  * @file database.h
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Présentation du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/
#ifndef DATABASE_H
#define DATABASE_H

#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

#define DATABASE_NAME "bd_s2.01"   // Nom de la base de données
#define CONNECT_TYPE "QODBC"      // Type de connexion

/**\
  * @brief Notre base de données
  *
\**/
class Database {
   public:
    /**\
      * @brief Constructeur de la base de données
      *
    \**/
    Database();

    /**\
      * @brief Ouvre la base de données
      *
      * @return true La base de données a été ouverte
      * @return false Erreur lors de l'ouverture de la base de données
    \**/
    bool openDataBase();

    /**\
      * @brief Ferme la base de données
      *
    \**/
    void closeDataBase();

    /**\
     * @brief Insert le nom et le score du joueur, le nom et le score de la machine et l'horodatage
     *
     * @return true L'insertion s'est faite correctement
     * @return false L'insertion a échoué
    \**/
    bool insertResult(QString nomJoueur,int scoreJoueur, QString nomMachine,int scoreMachine);

private:
    QSqlDatabase mydb; // Base de données
};

#endif // DATABASE_H
