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

void ChifoumiPresentation::finPartieScore()
{
    _leModele->majScores(getModele()->determinerGagnant());
    _laVue->desactiverBoutons();

    QString gagnant;
    int scoreMax;

    scoreMax = getModele()->getScorePourGagner();

    if(getModele()->determinerGagnant() == 'J'){
        gagnant = "Le Joueur";
    }
    else{
        gagnant = "La Machine";
    }

    QMessageBox *msgBox = new QMessageBox;
    //msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setWindowTitle("Fin de partie");
    msgBox->setText(QString("Bravo ").append(QVariant(gagnant).toString()).append("! Vous gagnez en ").append(QVariant(scoreMax).toString()).append(" points."));
    msgBox->exec();
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
    switch(_etat){
        case ChifoumiPresentation::etatInitial:
            break;
        case ChifoumiPresentation::partieEnCours:
            //Maj du coupJoueur
            _leModele->setCoupJoueur(ChifoumiModele::pierre);
            //G??n??ration al??atoire du coupMachine
            _leModele->setCoupMachine(_leModele->genererUnCoup());
            //On determine le gagnant de la manche afin de mettre ?? jour le score
            _leModele->majScores(getModele()->determinerGagnant());
            //Maj de l'affichage
            _laVue->majInterface(_etat);
            //Check si le score max est atteint
            if (_leModele->maxScore()){
                setEtat(ChifoumiPresentation::finDePartie);
                finPartieScore();
            }
            break;
        case ChifoumiPresentation::finDePartie:
            break;
        default: break;

    }
}

void ChifoumiPresentation::jouePapier()
{
    switch(_etat){
        case ChifoumiPresentation::etatInitial:
            break;
        case ChifoumiPresentation::partieEnCours:
            _leModele->setCoupJoueur(ChifoumiModele::papier);
            _leModele->setCoupMachine(_leModele->genererUnCoup());
            _leModele->majScores(_leModele->determinerGagnant());
            _laVue->majInterface(_etat);
            if (_leModele->maxScore()){
                setEtat(ChifoumiPresentation::finDePartie);
                finPartieScore();
            }
            break;
        case ChifoumiPresentation::finDePartie:
            break;
        default : break;
    }

}

void ChifoumiPresentation::joueCiseau()
{
    switch(_etat){
        case ChifoumiPresentation::etatInitial:
            break;
        case ChifoumiPresentation::partieEnCours:
            _leModele->setCoupJoueur(ChifoumiModele::ciseau);
            _leModele->setCoupMachine(_leModele->genererUnCoup());
            _leModele->majScores(_leModele->determinerGagnant());
            _laVue->majInterface(_etat);
            if (_leModele->maxScore()){
                setEtat(ChifoumiPresentation::finDePartie);
                finPartieScore();
            }
            break;
        case ChifoumiPresentation::finDePartie:
            break;
        default : break;
    }

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

