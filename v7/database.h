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

#include <QtSql/QSqlDatabase>

#define DATABASE_NAME "bd_s2.01"  // Nom de la base de données
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

   private:
    QSqlDatabase mydb; // Base de données
};

#endif  // DATABASE_H
