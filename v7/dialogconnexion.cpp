#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent)
    , ui(new Ui::DialogConnexion)
    , db(new Database())
{
    ui->setupUi(this);
    connect(ui->bConnexion,SIGNAL(clicked()),this,SLOT(demandeConnexion()));
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}

void DialogConnexion::demandeConnexion()
{
    QString user = ui->inputId->text();
    QString mdp = ui->inputPasswd->text();

    bool trouve = false;

    db->openDataBase();

    QSqlQuery maRqt;
    maRqt.exec("SELECT identification.login,identification.passwd FROM identification;");

    for(int i = 0; maRqt.next(); i++){
        if (maRqt.value(0).toString()==user && maRqt.value(1).toString()==mdp)
        {
            trouve = true;
            break;
        }
    }

    if (trouve)
    {
        QMessageBox::information(this, "Connexion", "Connexion réussie");
    }
    else
    {
        QMessageBox::information(this, "Connexion", "Connexion erronée");
    }
}
