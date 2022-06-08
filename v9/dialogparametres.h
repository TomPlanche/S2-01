#ifndef DIALOGPARAMETRES_H
#define DIALOGPARAMETRES_H

#include <QDialog>

namespace Ui {
class DialogParametres;
}

class DialogParametres : public QDialog
{
    Q_OBJECT

public:
    explicit DialogParametres(QWidget *parent = nullptr);
    ~DialogParametres();

    QString getPseudo();
    int getNbPoints();
    int getTemps();


public slots:
    void gererBouton();
    void sliderMoved(int);


private:
    Ui::DialogParametres *ui;
};

#endif // DIALOGPARAMETRES_H
