#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "chifoumi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

public slots:
    void joue_pierre();
    void joue_papier();
    void joue_ciseau();
private:
    Ui::GameWindow *ui;
    Chifoumi unJeu;
};
#endif // GAMEWINDOW_H
