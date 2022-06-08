#ifndef DIALOGRESULTATS_H
#define DIALOGRESULTATS_H

#include <QDialog>
#include <QtWidgets>
#include <QSqlQuery>

#include "database.h"

namespace Ui {
class DialogResultats;
}

class DialogResultats : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResultats(Database *db,QWidget *parent = nullptr);
    ~DialogResultats();

private:
    Ui::DialogResultats *ui;
    Database *_db;
};

#endif // DIALOGRESULTATS_H
