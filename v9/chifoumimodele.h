/**\
  * @file chifoumimodele.h
  * @author Tom Planche, Angel Garcia, Matis Chabanat
  * @brief Modèle du jeu Chifoumi
  * @date 08-06-2022
  *
  * @copyright Copyright (c) 2022
  *
\**/

#ifndef CHIFOUMIMODELE_H
#define CHIFOUMIMODELE_H

#include <QObject>

/**\
  * @brief Notre modèle du jeu Chifoumi
  *
\**/
class ChifoumiModele : public QObject
{
    Q_OBJECT
public:
    /**\
      * @brief Coups possibles
      *
    \**/
    enum UnCoup {pierre, papier, ciseau, rien};

    /**\
      * @brief Fin de parties possibles
      *
    \**/
    enum UneFinDePartie {Temps, Score};

    /**\
      * @brief Constructeur
      *
      * @param coupJoueur Coup joué par le joueur
      * @param coupMachine Coup joué par la machine
      * @param parent Fenêtre parent
    \**/
    explicit ChifoumiModele(UnCoup coupJoueur=rien,
                            UnCoup coupMachine=rien,
                            QObject *parent = nullptr);

    /**\
     * @brief Génère un coup aléatoire
     *
     * @return ChifoumiModele::UnCoup Coup aléatoire
    \**/
    ChifoumiModele::UnCoup genererUnCoup();

    //.  =======================================================================
    //.                                GETTERS
    //.  =======================================================================

    /**\
     * @brief Retourne le dernier coup joué par le joueur
     *
     * @return ChifoumiModele::UnCoup Dernier coup joué par le joueur
    \**/
    UnCoup getCoupJoueur();

    /**\
     * @brief Retourne le dernier coup joué par la machine
     *
     * @return ChifoumiModele::UnCoup Dernier coup joué par la machine
    \**/
    UnCoup getCoupMachine();

    /**\
     * @brief Retourne le score du joueur
     *
     * @return unsigned int Score du joueur
    \**/
    unsigned int getScoreJoueur();

    /**\
     * @brief Retourne le score de la machine
     *
     * @return unsigned short int Score de la machine
    \**/
    unsigned short int getScoreMachine();

    /**\
     * @brief Retourne le score nécessaire pour gagner
     *
     * @return int Score nécessaire pour gagner
    \**/
    int getScorePourGagner();

    /**\
     * @brief Retourne le type de la fin de partie
     *
     * @return ChifoumiModele::UneFinDePartie Type de fin de partie
    \**/
    UneFinDePartie getFinPartie();

    /**\
     * @brief Retourne le temps du timer
     *
     * @return unsigned short int Temps du timer
    \**/
    unsigned short int getTempsTimer();

    /**\
     * @brief Retourne le temps de la partie
     *
     * @return unsigned short int Temps de la partie
    \**/
    unsigned short int getTempsConst();


    //.  =======================================================================
    //.                                SETTERS
    //.  =======================================================================
    /**\
     * @brief Définit le temps du timer
     *
     * @param temps temps à définir
    \**/
    void setTempsTimer(unsigned short int);

    /**\
     * @brief Définit la constante du temps.
     *
     * @param temps temps à définir
    \**/
    void setTempsConst(unsigned short int);

    /**\
     * @brief Définit le coup joué par le joueur
     *
     * @param p_coup Coup à définir
    \**/
    void setCoupJoueur(ChifoumiModele::UnCoup p_coup);

    /**\
     * @brief Définit le coup joué par la machine
     *
     * @param p_coup Coup à définir
    \**/
    void setCoupMachine(ChifoumiModele::UnCoup p_coup);

    /**\
     * @brief Définit le score du joueur
     *
     * @param p_score Score à définir
    \**/
    void setScoreJoueur(unsigned int p_score);

    /**\
     * @brief Définit le score de la machine
     *
     * @param p_score Score à définir
    \**/
    void setScoreMachine(unsigned int p_score);

    /**\
     * @brief Définit le score nécessaire pour gagner
     *
     * @param score Score à définir
    \**/
    void setScorePourGagner(int score);

    /**\
     * @brief Définit le type de la fin de partie
     *
     * @param typeFinPartie Type de fin de partie à définir
    \**/
    void setFinPartie(UneFinDePartie);


    //.  =======================================================================
    //.                               METHODES
    //.  =======================================================================
    /**\
     * @brief Met a jour le score du gagant
     * 0 si match nul
     *
     * @param p_gagnant Gagnant du point
    \**/
    void majScores(char p_gagnant);

    /**\
     * @brief Initialise les scores
     *
    \**/
    void initScores();

    /**\
     * @brief Initialise les coups
     *
    \**/
    void initCoups();

    /**\
     * @brief Vérifie si un joueur a gagné la partie
     *
     * @return true Un joueur a gagné la partie
     * @return false Aucun joueur n'a atteint le score nécessaire pour gagner
    \**/
    bool maxScore();

    /**\
     * @brief Determine le gagnant de la partie
     *
     * @return char 'J' si le joueur a gagné sinon 'M'
    \**/
    char determinerGagnant();



    //.  =======================================================================
    //.                                 PRIVE
    //.  =======================================================================
   private:
    unsigned int _scoreJoueur;   // score actuel du joueur
    unsigned int _scoreMachine;  // score actuel de la Machine

    UnCoup _coupJoueur;   // dernier coup joué par le joueur
    UnCoup _coupMachine;  // dernier coup joué par la machine

    UneFinDePartie _finPartie;

    unsigned short int TEMPS_OUI_OUI = 7;

    unsigned short int _temps = TEMPS_OUI_OUI;
    unsigned short int _scorePourGagner = 5;
};

#endif  // CHIFOUMIMODELE_H
