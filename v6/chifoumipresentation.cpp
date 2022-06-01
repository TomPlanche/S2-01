#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include "ui_chifoumivue.h"

/* ********** CONSTRUCTEUR ********** */

ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{

}


/* ********** GETTERS ********** */

ChifoumiModele *ChifoumiPresentation::getModele()
{
    return this->_leModele;
}

ChifoumiVue *ChifoumiPresentation::getVue()
{
    return this->_laVue;
}

ChifoumiPresentation::UnEtat ChifoumiPresentation::getEtat()
{
    return _etat;
}


/* ********** SETTERS ********** */

void ChifoumiPresentation::setModele(ChifoumiModele *m)
{
    this->_leModele = m;
}

void ChifoumiPresentation::setVue(ChifoumiVue *v)
{
    this->_laVue = v;
}

void ChifoumiPresentation::setEtat(ChifoumiPresentation::UnEtat e)
{
    this->_etat = e;
}


/* ********** SLOTS ********** */

void ChifoumiPresentation::lancerPartie() {
    switch (_etat) {
    case ChifoumiPresentation::etatInitial:
        setEtat(ChifoumiPresentation::partieEnCours);
        _laVue->activerBoutons();
        _laVue->activerTableauScores();
        break;
    case ChifoumiPresentation::partieEnCours:
        _leModele->initCoups();
        _leModele->initScores();
        break;
    case ChifoumiPresentation::finDePartie:
        setEtat(ChifoumiPresentation::partieEnCours);
        _laVue->activerBoutons();
        _leModele->initCoups();
        _leModele->initScores();
        break;
    default: break;
    }
    _laVue->majInterface(_etat);
}

void ChifoumiPresentation::jouePierre()
{
    //Maj du coupJoueur
    _leModele->setCoupJoueur(ChifoumiModele::pierre);
    //Génération aléatoire du coupMachine
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    //On determine le gagnant de la manche afin de mettre à jour le score
    _leModele->majScores(getModele()->determinerGagnant());
    //Check si le score max est atteint
    if (_leModele->maxScore()){
        setEtat(ChifoumiPresentation::finDePartie);
    }
    //Maj de l'affichage
    _laVue->majInterface(_etat);
}

void ChifoumiPresentation::jouePapier()
{
    _leModele->setCoupJoueur(ChifoumiModele::papier);
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    _leModele->majScores(_leModele->determinerGagnant());
    if (_leModele->maxScore()){
        setEtat(ChifoumiPresentation::finDePartie);
    }
    _laVue->majInterface(_etat);
}

void ChifoumiPresentation::joueCiseau()
{
    _leModele->setCoupJoueur(ChifoumiModele::ciseau);
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    _leModele->majScores(_leModele->determinerGagnant());
    if (_leModele->maxScore()){
        setEtat(ChifoumiPresentation::finDePartie);
    }
    _laVue->majInterface(_etat);
}

void ChifoumiPresentation::aProposDe()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setWindowTitle("A propos de l'application");
    msgBox->setText("Tom, Angel, Matis -> gros bgs \nVersion 4 du Chifoumi (11/05/2022) ");
    msgBox->exec();
}

void ChifoumiPresentation::parametrer()
{

    QMessageBox *msgBox = new QMessageBox;
    DialogParametres * mesParam= new DialogParametres;
    bool pseudoOk = false;

    switch (_etat) {
    case ChifoumiPresentation::etatInitial:
        mesParam->exec();

        // Saisie pseudo
        if (mesParam->getPseudo() != "")
        {
            pseudoOk=true;
        }

        if (pseudoOk)
        {
            //Changer le label en fonction du pseudo saisi
            _laVue->setPseudoJoueur(mesParam->getPseudo());
        }

        // Modifier le nb max de points
        _laVue->setNbMaxPoints(mesParam->getNbPoints());
        //Modifier le temps max

        break;
    case ChifoumiPresentation::partieEnCours:
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setWindowTitle("A propos des paramètres");
        msgBox->setText("Vous pouvez modifier les paramètres \nuniquement avant le début de la partie !");
        msgBox->exec();
        break;
    case ChifoumiPresentation::finDePartie: break;
    default: break;
    }

}




