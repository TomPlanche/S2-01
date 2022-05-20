#ifndef DIALOGSCOREMAX_H
#define DIALOGSCOREMAX_H

#include <QDialog>

namespace Ui {
class DialogScoreMax;
}

class DialogScoreMax : public QDialog
{
    Q_OBJECT

public:
    explicit DialogScoreMax(QWidget *parent = nullptr);
    ~DialogScoreMax();

private:
    Ui::DialogScoreMax *ui;
};

#endif // DIALOGSCOREMAX_H
