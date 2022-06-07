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
        //qDebug() << getTemps();
        _laVue->updaterTimerLabel(_leModele->getTempsConst());
        _leModele->setTempsTimer(_leModele->getTempsConst());


        break;
    case ChifoumiPresentation::partieEnCours:
        pauseTimer();
        _leModele->initCoups();
        _leModele->initScores();
        setEtat(ChifoumiPresentation::etatInitial);
        _laVue->majInterface(ChifoumiPresentation::etatInitial);
        break;
    case ChifoumiPresentation::partieEnPause:
        setEtat(ChifoumiPresentation::UnEtat::partieEnCours);
        _laVue->activerBoutons();
        reprendreTimer();
        break;
    case ChifoumiPresentation::finDePartie:
        setEtat(ChifoumiPresentation::etatInitial);
        _laVue->updaterTimerLabel(0);
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
    //Check si le score max est atteint
    if (_leModele->maxScore()){
        setEtat(ChifoumiPresentation::finDePartie);
        _leModele->setFinPartie(ChifoumiModele::UneFinDePartie::Score);
        finPartie();
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
        _leModele->setFinPartie(ChifoumiModele::UneFinDePartie::Score);
        finPartie();
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
        _leModele->setFinPartie(ChifoumiModele::UneFinDePartie::Score);
        finPartie();
    }
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
        _leModele->setScorePourGagner(mesParam->getNbPoints());

        //Modifier le temps max
        _laVue->setTempsMax(mesParam->getTemps());
        _leModele->setTempsTimer(mesParam->getTemps());
        _leModele->setTempsConst(mesParam->getTemps());
        break;
    default:
        pauseTimer();
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setWindowTitle("A propos des paramètres");
        msgBox->setText("Vous pouvez modifier les paramètres \nuniquement avant le début de la partie !");
        msgBox->exec();
        reprendreTimer();
        break;
    }
}



void ChifoumiPresentation::updaterTimer()
{
    uint16_t temps = _leModele->getTempsTimer();
    if (temps > 0) {
        _leModele->setTempsTimer(temps - 1);
        _laVue->updaterTimerLabel(temps);
    } else {
        timer->stop();
        setEtat(ChifoumiPresentation::finDePartie);
        _leModele->setFinPartie(ChifoumiModele::UneFinDePartie::Temps);
        _laVue->majInterface(getEtat());
        finPartie();
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
    default:break;
    }
}



void ChifoumiPresentation::finPartie()
{
    _laVue->majInterface(getEtat());
    pauseTimer();

    QMessageBox *msgBox = new QMessageBox;

    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Ok);

    uint16_t scoreJoueur = _leModele->getScoreJoueur();
    uint16_t scoreMachine = _leModele->getScoreMachine();

    char g;
    QString gagnant;

    switch (_leModele->getFinPartie()) {
    case ChifoumiModele::UneFinDePartie::Score:
        g = _leModele->determinerGagnant();
        gagnant = g == 'J' ? "le joueur" : "la machine";

        msgBox->setWindowTitle("Fin de partie gagnant !");
        msgBox->setText(QString("Bravo ").append(gagnant).append(". Vous gagnez avec ").append(QString::number(_leModele->getScorePourGagner())).append(" point(s) en ").append(QString::number(_leModele->getTempsConst() - _leModele->getTempsTimer())).append(" secondes."));
        break;
    case ChifoumiModele::UneFinDePartie::Temps:

        if (scoreJoueur > scoreMachine) {
            g = 'J';
        } else if (scoreJoueur < scoreMachine) {
            g = 'M';
        } else {
            g = 'N';
        }

        if (g == 'J' || g == 'M') {
            gagnant = g == 'J' ? "Vous terminez" : "La machine termine";
            int score = g == 'J' ? _leModele->getScoreJoueur() : _leModele->getScoreMachine();
            msgBox->setText(QString("Hélas chers joueurs, temps de jeu fini !\n").append(gagnant).append(" toutefois mieux, avec ").append(QVariant(score).toString()).append("."));

        } else  {
            msgBox->setText(QString("Hélas chers joueurs, temps de jeu fini ! C'est une égalité."));
        }
        break;
    }
    msgBox->exec();
}
