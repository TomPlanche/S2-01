#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include "chifoumimodele.h"
#include "chifoumivue.h"

class ChifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    explicit ChifoumiPresentation(ChifoumiModele *m, QObject *parent = nullptr);

    ChifoumiModele* getModele();
    ChifoumiVue* getVue();
    void setModele(ChifoumiModele *m);
    void setVue(ChifoumiVue *v);

private:
    ChifoumiModele *_leModele;
    ChifoumiVue *_laVue;
};

#endif // CHIFOUMIPRESENTATION_H
