#include "chifoumivue.h"
#include "ui_chifoumivue.h"

/* ********** CONSTRUCTEUR ********** */

ChifoumiVue::ChifoumiVue(ChifoumiPresentation *p,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
    , _laPresentation(p)
{
    ui->setupUi(this);

    ui->pointsMax->setText(QString::number(_laPresentation->getModele()->getScorePourGagner()));

    //Préparation Boutons
    ui->gbBoutonsCoups->setDisabled(true);
    ui->boutonPause->setDisabled(true);

    //Connexion
    //Boutons
    connect(ui->bNewPartie, SIGNAL(clicked()), p, SLOT(lancerPartie()));
    connect(ui->boutonPause, SIGNAL(clicked()), p, SLOT(pauseButtonClicked()));
    connect(ui->pierre, SIGNAL(clicked()), p, SLOT(jouePierre()));
    connect(ui->papier, SIGNAL(clicked()), p, SLOT(jouePapier()));
    connect(ui->ciseau, SIGNAL(clicked()) ,p, SLOT(joueCiseau()));

    //Menus
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()), p, SLOT(aProposDe()));
    connect(ui->action_Parametrer, SIGNAL(triggered()), p, SLOT(parametrer()));
}



ChifoumiVue::~ChifoumiVue()
{
    delete ui;
}


/* ********** GETTERS ********** */

ChifoumiPresentation *ChifoumiVue::getPresentation()
{
    return _laPresentation;
}


/* ********** SETTERS ********** */

void ChifoumiVue::setPresentation(ChifoumiPresentation *p)
{
    _laPresentation = p;
}

void ChifoumiVue::setPseudoJoueur(QString s)
{
    ui->lJoueur->setText(s);
}

void ChifoumiVue::setNbMaxPoints(int pts)
{
    ui->pointsMax->setText(QString::number(pts));
}

void ChifoumiVue::setTempsMax(int temps)
{
    updaterTimerLabel(temps);
    _laPresentation->getModele()->setTemps(temps);
}

/* ********** PROCEDURES ********** */

void ChifoumiVue::majInterface(ChifoumiPresentation::UnEtat e)
{
    switch (e) {
    case ChifoumiPresentation::etatInitial:
        ui->bNewPartie->setText("Jouer");
        _laPresentation->getModele()->initCoups();
        _laPresentation->getModele()->initScores();
        break;
    case ChifoumiPresentation::partieEnCours:
        //Maj des labels scoreJoueur et scoreMachine
        ui->scoreJoueur->setText(QString::number(_laPresentation->getModele()->getScoreJoueur()));
        ui->scoreMachine->setText(QString::number(_laPresentation->getModele()->getScoreMachine()));

        //Maj image label coupJoueur
        switch (_laPresentation->getModele()->getCoupJoueur())
        {
            case ChifoumiModele::pierre: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png")); break;
            case ChifoumiModele::ciseau: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
            case ChifoumiModele::papier: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/papier_115.png")); break;
            case ChifoumiModele::rien: ui->coupJoueur->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
        }

        //Maj image label coupMachine
        switch (_laPresentation->getModele()->getCoupMachine())
        {
            case ChifoumiModele::pierre: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/pierre_115.png")); break;
            case ChifoumiModele::ciseau: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/ciseau_115.png")); break;
            case ChifoumiModele::papier: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/papier_115.png")); break;
            case ChifoumiModele::rien: ui->coupMachine->setPixmap(QPixmap(":/chifoumi/images/rien_115.png")); break;
        }
        break;
    case ChifoumiPresentation::partieEnPause:
        desactiverBoutons();
        break;
    case ChifoumiPresentation::finDePartie:
        ui->scoreJoueur->setText(QString::number(_laPresentation->getModele()->getScoreJoueur()));
        ui->scoreMachine->setText(QString::number(_laPresentation->getModele()->getScoreMachine()));

        desactiverBoutons();
        updaterTimerLabel(0);
        break;
    default:
        break;
    }
}

void ChifoumiVue::activerBoutons()
{
    switch (_laPresentation->getEtat()) {
    case ChifoumiPresentation::etatInitial:break;
    case ChifoumiPresentation::partieEnCours:
        ui->gbBoutonsCoups->setEnabled(true);
        ui->bNewPartie->setText("Nouvelle Partie");
        ui->boutonPause->setEnabled(true);
        break;
    case ChifoumiPresentation::partieEnPause:break;
    case ChifoumiPresentation::finDePartie:break;
    default:break;
    }
}

void ChifoumiVue::desactiverBoutons()
{
    switch (_laPresentation->getEtat()) {
    case ChifoumiPresentation::etatInitial:break;
    case ChifoumiPresentation::partieEnCours:break;
    case ChifoumiPresentation::partieEnPause:
        ui->gbBoutonsCoups->setDisabled(true);
        ui->bNewPartie->setText("Reprendre");
        ui->boutonPause->setDisabled(true);
        break;
    case ChifoumiPresentation::finDePartie:
        ui->gbBoutonsCoups->setDisabled(true);
        ui->boutonPause->setDisabled(true);
        break;
    default:break;
   }
}

void ChifoumiVue::activerTableauScores()
{
    switch (_laPresentation->getEtat()) {
    case ChifoumiPresentation::etatInitial:break;
    case ChifoumiPresentation::partieEnCours:
        ui->lJoueur->setStyleSheet("color: blue;");
        ui->lMachine->setStyleSheet("color: blue;");
        ui->scoreJoueur->setStyleSheet("color: blue;");
        ui->scoreMachine->setStyleSheet("color: blue;");
        break;
    case ChifoumiPresentation::partieEnPause:break;
    case ChifoumiPresentation::finDePartie:break;
    default:break;
    }
}

void ChifoumiVue::updaterTimerLabel(int temps)
{
    ui->labelTemps->setText(QString("Temps Restant : ").append(QString::number(temps)).append("s."));
}

