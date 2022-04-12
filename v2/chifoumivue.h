#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include "chifoumimodele.h"
#include "chifoumi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class chifoumiVue; }
QT_END_NAMESPACE

class chifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    chifoumiVue(QWidget *parent = nullptr);
    ~chifoumiVue();

    // Connexions
    void addConnexion(QObject *c);
    void suppConnexion(QObject *c);

    //Ordre recu par la presentation
    void majAffichage(Chifoumi::UnCoup coupJoueur,Chifoumi::UnCoup coupMachine);

private:
    Ui::chifoumiVue *ui;
};
#endif // CHIFOUMIVUE_H
