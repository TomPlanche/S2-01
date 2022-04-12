#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include "chifoumimodele.h"

class chifoumiVue;
class chifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    explicit chifoumiPresentation(chifoumiModele *m, QObject *parent = nullptr);

    chifoumiModele* getModele();
    chifoumiVue* getVue();
    void setModele(chifoumiModele *m);
    void setVue(chifoumiVue *v);

private:
    chifoumiModele *_leModele;
    chifoumiVue *_laVue;
};

#endif // CHIFOUMIPRESENTATION_H
