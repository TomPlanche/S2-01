#include "chifoumivue.h"
#include "chifoumipresentation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChifoumiVue w;
    ChifoumiModele m;
    ChifoumiPresentation p;
    //p.setModele(m);
    //p.setVue(w);
    w.show();
    return a.exec();
}
