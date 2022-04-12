#include "chifoumipresentation.h"

chifoumiPresentation::chifoumiPresentation(chifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{

}

chifoumiModele *chifoumiPresentation::getModele()
{
    return _leModele;
}

chifoumiVue *chifoumiPresentation::getVue()
{
    return _laVue;
}

void chifoumiPresentation::setModele(chifoumiModele *m)
{
    _leModele = m;
}

void chifoumiPresentation::setVue(chifoumiVue *v)
{
    _laVue = v;
}
