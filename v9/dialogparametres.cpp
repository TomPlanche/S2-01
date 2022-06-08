#include "dialogparametres.h"

#include "ui_dialogparametres.h"

DialogParametres::DialogParametres(QWidget *parent) : QDialog(parent),
                                                      ui(new Ui::DialogParametres) {
    ui->setupUi(this);

    setWindowTitle("Paramètres");

    ui->bConfirmer->setDisabled(true);
    connect(ui->inputPseudo, SIGNAL(textChanged(QString)), this, SLOT(gererBouton()));
    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(sliderMoved(int)));
    connect(ui->bConfirmer, SIGNAL(clicked()), this, SLOT(close()));
}

DialogParametres::~DialogParametres() {
    delete ui;
}

QString DialogParametres::getPseudo() {
    if (ui->inputPseudo->text().isEmpty()) {
        return "";
    } else {
        return ui->inputPseudo->text();
    }
}

int DialogParametres::getNbPoints() {
    return ui->inputPtsMax->value();
}

int DialogParametres::getTemps() {
    return ui->labelTempsMax->text().toInt();
}

void DialogParametres::gererBouton() {
    if (ui->inputPseudo->text().isEmpty()) {
        ui->bConfirmer->setDisabled(true);
    } else {
        ui->bConfirmer->setEnabled(true);
    }
}

void DialogParametres::sliderMoved(int valeur) {
    QString sliderValue;
    sliderValue.QString::setNum(valeur);
    ui->labelTempsMax->setText(sliderValue);
}
