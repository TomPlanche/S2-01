#include "dialogresultats.h"
#include "ui_dialogresultats.h"

DialogResultats::DialogResultats(Database *db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResultats),_db(db)
{
    ui->setupUi(this);

    connect(ui->bQuitter, SIGNAL(clicked()), this, SLOT(close()));

    QSqlQuery maRqt;
    maRqt.exec("SELECT * FROM resultat ORDER BY scoreJoueurHumain DESC");

    for(int i = 0; maRqt.next(); i++){
        ui->tableau->insertRow(i);
        ui->tableau->setItem(i,0,new QTableWidgetItem(maRqt.value(0).toString()));
        ui->tableau->setItem(i,1,new QTableWidgetItem(maRqt.value(1).toString()));
        ui->tableau->setItem(i,2,new QTableWidgetItem(maRqt.value(2).toString()));
        ui->tableau->setItem(i,3,new QTableWidgetItem(maRqt.value(3).toString()));
        ui->tableau->setItem(i,4,new QTableWidgetItem(maRqt.value(4).toString()));

        if(i==9)
        {
            break;
        }
    }
}

DialogResultats::~DialogResultats()
{
    delete ui;
}
