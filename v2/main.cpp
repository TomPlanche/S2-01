#include "chifoumivue.h"
#include "chifoumipresentation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ChifoumiModele *m = new ChifoumiModele();
    ChifoumiPresentation *p = new ChifoumiPresentation(m);
    ChifoumiVue w(p);
    p->setVue(&w);
    p->getVue()->majInterface(p->getEtat());
    w.show();
    return a.exec();
}
