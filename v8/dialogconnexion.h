#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QtWidgets>
#include <QDialog>
#include "database.h"
#include <QSqlQuery>

namespace Ui {
class DialogConnexion;
}

class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnexion(QWidget *parent = nullptr);
    ~DialogConnexion();

    bool getEstConnecte();
    Database* getDatabase();

public slots:
    void demandeConnexion();

private:
    Ui::DialogConnexion *ui;
    Database *db;

    bool estConnecte = false;
};

#endif // DIALOGCONNEXION_H
