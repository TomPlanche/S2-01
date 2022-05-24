#include "chifoumivue.h"
#include "ui_chifoumivue.h"

/* ********** CONSTRUCTEUR ********** */

ChifoumiVue::ChifoumiVue(ChifoumiPresentation *p,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
    , _laPresentation(p)
{
    ui->setupUi(this);

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


/* ********** PROCEDURES ********** */

void ChifoumiVue::majInterface(ChifoumiPresentation::UnEtat e)
{
    switch (e) {
    case ChifoumiPresentation::etatInitial: break;
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
    case ChifoumiPresentation::finDePartie:
        desactiverBoutons();
        updaterTimerLabel(0);





        break;
    default:break;
    }
}

void ChifoumiVue::activerBoutons()
{
    ui->gbBoutonsCoups->setEnabled(true);
    ui->bNewPartie->setText("Nouvelle Partie");
    ui->boutonPause->setEnabled(true);
}

void ChifoumiVue::desactiverBoutons()
{
    ui->gbBoutonsCoups->setDisabled(true);
    ui->bNewPartie->setText("Reprendre");
    ui->boutonPause->setDisabled(true);
}

void ChifoumiVue::activerTableauScores()
{
    ui->lJoueur->setStyleSheet("color: blue;");
    ui->lMachine->setStyleSheet("color: blue;");
    ui->scoreJoueur->setStyleSheet("color: blue;");
    ui->scoreMachine->setStyleSheet("color: blue;");
}

void ChifoumiVue::updaterTimerLabel(int temps)
{
    ui->labelTemps->setText(QString("Temps Restant : ").append(QString::number(temps)).append("s."));
}

