#ifndef DATABASE_H
#define DATABASE_H

#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

#define DATABASE_NAME "bd_s2.01"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();

    bool insertResult(QString nomJoueur,int scoreJoueur, QString nomMachine,int scoreMachine);

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
