#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
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

    // Connexions
    void addConnexion(QObject *c);
    void suppConnexion(QObject *c);

    //Ordre recu par la presentation
    void majAffichage(ChifoumiModele::UnCoup coupJoueur,ChifoumiModele::UnCoup coupMachine);

private:
    Ui::ChifoumiVue *ui;
};
#endif // CHIFOUMIVUE_H
