#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <QtWidgets>

#include "chifoumimodele.h"



QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();


    void majAffichage();
    void lancerPartie();
private:
    Ui::ChifoumiVue *ui;

};
#endif // CHIFOUMIVUE_H
