#ifndef CHIFOUMIMODELE_H
#define CHIFOUMIMODELE_H

#include <QObject>


class ChifoumiModele : public QObject
{
    Q_OBJECT
public:
    enum UnCoup {pierre, papier, ciseau, rien };

    explicit ChifoumiModele(UnCoup coupJoueur=rien,
                            UnCoup coupMachine=rien,
                            QObject *parent = nullptr);

    // Getters
    UnCoup getCoupJoueur();
    /* retourne le dernier coup jou� par le joueur */

    UnCoup getCoupMachine();
    /* retourne le dernier coup jou� par le joueur */

    unsigned int getScoreJoueur();
    /* retourne le score du joueur */

    unsigned int getScoreMachine();
    /* retourne le score de la machine */

    char determinerGagnant();
    /* d�termine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
    en fonction du dernier coup jou� par chacun d'eux */

    void setCoupJoueur(ChifoumiModele::UnCoup p_coup);
    /* initialise l'attribut coupJoueur avec la valeur
    du param�tre p_coup */

    void setCoupMachine(ChifoumiModele::UnCoup p_coup);
    /* initialise l'attribut coupmachine avec la valeur
    du param�tre p_coup */

    void setScoreJoueur(unsigned int p_score);
    /* initialise l'attribut scoreJoueur avec la valeur
    du param�tre p_score */

    void setScoreMachine(unsigned int p_score);
    /* initialise l'attribut coupMachine avec la valeur
    du param�tre p_score */

    // Autres modificateurs
    void majScores(char p_gagnant);
    /* Mise � jour des scores en fonction des r�gles de gestion actuelles :
            - 1 point pour le gagnant lorsqu'il y a un gagnant
            - 0 point en cas de match nul
    */
    void initScores();
    /* initialise � 0 les attributs scoreJoueur et scoreMachine
    NON indispensable */

    void initCoups();
    /* initialise � rien les attributs coupJoueur et coupMachine
    NON indispensable */

    void lancerPartie();



private:

    unsigned int _scoreJoueur;   // score actuel du joueur
    unsigned int _scoreMachine;  // score actuel de la Machine

    ChifoumiModele::UnCoup _coupJoueur;          // dernier coup jou� par le joueur
    ChifoumiModele::UnCoup _coupMachine;         // dernier coup jou� par la machine

    ChifoumiModele::UnCoup genererUnCoup();
    /* retourne une valeur al�atoire = pierre, papier ou ciseau.
    Utilis�e pour faire jouer la machine */

};

#endif // CHIFOUMIMODELE_H
