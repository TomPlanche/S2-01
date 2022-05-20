#include "dialogscoremax.h"
#include "ui_dialogscoremax.h"

DialogScoreMax::DialogScoreMax(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogScoreMax)
{
    ui->setupUi(this);
}

DialogScoreMax::~DialogScoreMax()
{
    delete ui;
}
