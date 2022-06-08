#include "chifoumivue.h"
#include "chifoumipresentation.h"
#include "dialogconnexion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DialogConnexion *conn = new DialogConnexion();

    ChifoumiModele *m = new ChifoumiModele();
    ChifoumiPresentation *p = new ChifoumiPresentation(m,conn->getDatabase());
    ChifoumiVue w(p);
    p->setVue(&w);
    p->getVue()->majInterface(p->getEtat());

    conn->getDatabase()->openDataBase();
    conn->exec();

    if(conn->getEstConnecte())
    {
        w.show();
        return a.exec();
    }

    conn->getDatabase()->closeDataBase();
    return 0;
}
