#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include "ui_chifoumivue.h"

/* ********** CONSTRUCTEUR ********** */

ChifoumiPresentation::ChifoumiPresentation(ChifoumiModele *m, QObject *parent):
    QObject{parent}, _leModele(m)
{
    _etat = etatInitial;
    timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updaterTimer()));
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

        timer->start(DELAIS);
        _laVue->updaterTimerLabel(TEMPS);

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
        timer->start(1000);
        _laVue->updaterTimerLabel(_leModele->getTemps());
        _leModele->setTemps(TEMPS);
    case ChifoumiPresentation::partieEnPause:
        setEtat(ChifoumiPresentation::UnEtat::partieEnCours);
        _laVue->activerBoutons();
        reprendreTimer();
        break;
    default:
        break;
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
    //Maj de l'affichage
    _laVue->majInterface(_etat);
}

void ChifoumiPresentation::jouePapier()
{
    _leModele->setCoupJoueur(ChifoumiModele::papier);
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    _leModele->majScores(_leModele->determinerGagnant());
    _laVue->majInterface(_etat);
}

void ChifoumiPresentation::joueCiseau()
{
    _leModele->setCoupJoueur(ChifoumiModele::ciseau);
    _leModele->setCoupMachine(_leModele->genererUnCoup());
    _leModele->majScores(_leModele->determinerGagnant());
    _laVue->majInterface(_etat);
}

void ChifoumiPresentation::aProposDe()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setWindowTitle("A propos de l'application");
    msgBox->setText("Tom, Angel, Matis -> gros bgs \nVersion 3 du Chifoumi (24/05/2022) ");
    msgBox->exec();
}



void ChifoumiPresentation::updaterTimer()
{
    uint16_t temps = _leModele->getTemps();
    if (temps > 0) {
        _leModele->setTemps(temps - 1);
        _laVue->updaterTimerLabel(temps);
    } else {
        timer->stop();
        setEtat(ChifoumiPresentation::finDePartie);
        _laVue->majInterface(_etat);
        finPartieTemps();
    }
}

void ChifoumiPresentation::pauseTimer()
{
    timer->stop();
}

void ChifoumiPresentation::reprendreTimer()
{
    timer->start(DELAIS);
}

void ChifoumiPresentation::pauseButtonClicked()
{
    switch (getEtat()) {
    case UnEtat::partieEnCours:
        setEtat(UnEtat::partieEnPause);
        _laVue->desactiverBoutons();
        pauseTimer();

    break;
    default:
        break;
    }
}



void ChifoumiPresentation::finPartieTemps()
{
    QMessageBox *msgBox = new QMessageBox;

    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setWindowTitle("Fin de partie !");

    uint16_t scoreJoueur = _leModele->getScoreJoueur();
    uint16_t scoreMachine = _leModele->getScoreMachine();

    char gagnant;

    if (scoreJoueur > scoreMachine) {
        gagnant = 'J';
    } else if (scoreJoueur < scoreMachine) {
        gagnant = 'M';
    } else {
        gagnant = 'N';
    }

    if (gagnant == 'J' || gagnant == 'M') {
        QString g = gagnant == 'J' ? "Vous terminez" : "La machine termine";
        int score = gagnant == 'J' ? _leModele->getScoreJoueur() : _leModele->getScoreMachine();
        msgBox->setText(QString("Hélas chers joueurs, temps de jeu fini !\n").append(g).append(" toutefois mieux, avec ").append(QVariant(score).toString()).append("."));

    } else  {
        msgBox->setText(QString("Hélas chers joueurs, temps de jeu fini ! C'est une égalité."));
    }

    msgBox->exec();


}
