#include "chifoumipresentation.h"

ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{

}

ChifoumiModele *ChifoumiPresentation::getModele()
{
    return _leModele;
}

ChifoumiVue *ChifoumiPresentation::getVue()
{
    return _laVue;
}

void ChifoumiPresentation::setModele(ChifoumiModele *m)
{
    _leModele = m;
}

void ChifoumiPresentation::setVue(ChifoumiVue *v)
{
    _laVue = v;
}
