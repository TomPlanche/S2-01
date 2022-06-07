#include "database.h"

Database::Database()
{

}

bool Database::openDataBase()
{
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName(DATABASE_NAME);
    return mydb.open();
}

void Database::closeDataBase()
{
    mydb.close();
}
