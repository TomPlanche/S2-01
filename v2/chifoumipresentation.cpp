
#include "chifoumipresentation.h"
#include "ui_chifoumivue.h"

ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{

}

ChifoumiModele *ChifoumiPresentation::getModele()
{
    return _leModele;
}

ChifoumiPresentation *ChifoumiPresentation::getVue()
{
    return _laVue;
}

void ChifoumiPresentation::setModele(ChifoumiModele *m)
{
    _leModele = m;
}

void ChifoumiPresentation::setVue(ChifoumiPresentation *v)
{
    _laVue = v;
}
