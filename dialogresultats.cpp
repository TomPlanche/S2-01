/**\
  * @file dialogresultats.cpp
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Présentation du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/
#include "dialogresultats.h"

#include "ui_dialogresultats.h"

DialogResultats::DialogResultats(Database *db, QWidget *parent) : QDialog(parent),
                                                                  ui(new Ui::DialogResultats),
                                                                  _db(db) {
    ui->setupUi(this);

    // Fermeture de la fenêtre lors du clic sur le bouton "Quitter"
    connect(ui->bQuitter, SIGNAL(clicked()), this, SLOT(close()));

    QSqlQuery maRqt;                                                       // Requête SQL
    maRqt.exec("SELECT * FROM resultat ORDER BY scoreJoueurHumain DESC");  // Tout selectionner dans la table resultat

    // Affichage des 10 meilleurs résultats
    for (int i = 0; maRqt.next(); i++) {
        ui->tableau->insertRow(i);
        ui->tableau->setItem(i, 0, new QTableWidgetItem(maRqt.value(0).toString()));
        ui->tableau->setItem(i, 1, new QTableWidgetItem(maRqt.value(1).toString()));
        ui->tableau->setItem(i, 2, new QTableWidgetItem(maRqt.value(2).toString()));
        ui->tableau->setItem(i, 3, new QTableWidgetItem(maRqt.value(3).toString()));
        ui->tableau->setItem(i, 4, new QTableWidgetItem(maRqt.value(4).toString()));

        if (i == 9) {
            break;
        }
    }
}

DialogResultats::~DialogResultats() {
    delete ui;
}
