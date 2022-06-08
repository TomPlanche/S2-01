#include "database.h"

Database::Database() {
}

bool Database::openDataBase() {
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName(DATABASE_NAME);
    return mydb.open();
}

void Database::closeDataBase() {
    mydb.close();
}

bool Database::insertResult(QString nomJoueur, int scoreJoueur, QString nomMachine, int scoreMachine) {
    QSqlQuery nvResultat;

    QLocale locale = QLocale(QLocale::French, QLocale::France);
    QString date_auj = locale.toString(QDate::currentDate()) + " " + QString::number(QTime::currentTime().hour()) + ":" + (QString::number(QTime::currentTime().minute()).length() == 1 ? "0" + QString::number(QTime::currentTime().minute()) : QString::number(QTime::currentTime().minute())) + ":" + (QString::number(QTime::currentTime().second()).length() == 1 ? "0" + QString::number(QTime::currentTime().second()) : QString::number(QTime::currentTime().second()));

    // Requête d'insertion paramètrée
    nvResultat.prepare("INSERT INTO resultat VALUES (?, ?, ?, ?, ?)");

    // Insertion des données dans la requête
    QVariantList date;
    date << date_auj;
    nvResultat.addBindValue(date);

    QVariantList nomJ;
    nomJ << nomJoueur;
    nvResultat.addBindValue(nomJ);

    QVariantList scoreJ;
    scoreJ << scoreJoueur;
    nvResultat.addBindValue(scoreJ);

    QVariantList nomM;
    nomM << nomMachine;
    nvResultat.addBindValue(nomM);

    QVariantList scoreM;
    scoreM << scoreMachine;
    nvResultat.addBindValue(scoreM);

    // Exécution de la requête
    if (!nvResultat.execBatch()) return false;
    return true;
}
