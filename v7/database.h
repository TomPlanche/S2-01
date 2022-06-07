#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>

#define DATABASE_NAME "bd_s2.01"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
