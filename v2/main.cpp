#include "chifoumivue.h"
#include "chifoumimodele.h"
#include "chifoumipresentation.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // créer le modèle
    chifoumiModele *m = new chifoumiModele();
    // créer la présentation et lui associer le modèle
    chifoumiPresentation *p = new chifoumiPresentation(m);
    // créer la vue
    chifoumiVue w;
    // associer la vue à la présentation
    p->setVue(&w);
    // initialiser la vue en conformité avec l'état initial du modèle
    p->getVue()->majAffichage(m->getCoupJoueur(),m->getCoupMachine());
    // connexion des signaux de la vue avec les slots de la présentation
    w.addConnexion(p);
    // afficher la vue et démarrer la boucle d'attente des messages
    return a.exec();
}
