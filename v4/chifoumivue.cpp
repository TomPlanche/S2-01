#include "chifoumivue.h"
#include "ui_chifoumivue.h"
#include <QMessageBox>
#include <QVariant>

/* ********** CONSTRUCTEUR ********** */

ChifoumiVue::ChifoumiVue(ChifoumiPresentation *p,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChifoumiVue)
    , _laPresentation(p)
{
    ui->setupUi(this);

    //Préparation Boutons
    ui->gbBoutonsCoups->setDisabled(true);

    //Connexion
    //Boutons
    connect(ui->bNewPartie,SIGNAL(clicked()),p,SLOT(lancerPartie()));
    connect(ui->pierre,SIGNAL(clicked()),p,SLOT(jouePierre()));
    connect(ui->papier,SIGNAL(clicked()),p,SLOT(jouePapier()));
    connect(ui->ciseau,SIGNAL(clicked()),p,SLOT(joueCiseau()));

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
        ui->scoreJoueur->setText(QString::number(_laPresentation->getModele()->getScoreJoueur()));
        ui->scoreMachine->setText(QString::number(_laPresentation->getModele()->getScoreMachine()));

        desactiverBoutons();

        QString gagnant;

        if(_laPresentation->getModele()->determinerGagnant() == 'J'){
            gagnant = "Le Joueur";
        }
        else{
            gagnant = "La Machine";
        }

        QMessageBox *msgBox = new QMessageBox;
        //msgBox->setIcon(QMessageBox::Information);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setWindowTitle("Fin de partie");
        msgBox->setText(QString("Bravo ").append(QVariant(gagnant).toString()).append("! Vous gagnez en 5 points."));
        msgBox->exec();
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
        break;
    case ChifoumiPresentation::finDePartie:break;
    default:break;
    }
}

void ChifoumiVue::desactiverBoutons()
{
    switch (_laPresentation->getEtat()) {
    case ChifoumiPresentation::etatInitial:break;
    case ChifoumiPresentation::partieEnCours:break;
    case ChifoumiPresentation::finDePartie:
        ui->gbBoutonsCoups->setDisabled(true);
        ui->bNewPartie->setText("Nouvelle Partie");
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
    case ChifoumiPresentation::finDePartie:break;
    default:break;
    }
}
