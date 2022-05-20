# SAÉ 2.01 – Développement d’une application

Le but de cette SAÉ est de programmer une application (à l'aide de la bibliothèque graphique QT)
qui réalise une partie de Chifoumi entre un joueur et la machine.


## Auteurs

Ce projet a été réalisé par :

* **Tom Planche** alias [@TomPlanche](https://github.com/TomPlanche)
* **Angel Garcia** alias [@Angel0503](https://github.com/Angel0503)
* **Matis CHABANAT** alias [@mchabanat](https://github.com/mchabanat)


## Description

<table>
    <thead>
        <tr>
            <th align="center">Version</th>
            <th align="center">Description fonctionnelle</th>
            <th align="center">Références figures</th>
            <th>Avancement</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center">v0</td>
            <td align="left">Sources C++ de la classe Chifoumi dans un projet Non Qt</td>
            <td align="center"></td>
            <td align="center"><strong>FAIT</strong></td>
        </tr>
        <tr>
            <td align="center">v1</td>
            <td align="left">Version décrite dans le paragraphe §1 précédent.<br> La barre de menus est inactive.</td>
            <td align="center"></td>
            <td align="center"><strong>FAIT</strong></td>
        </tr>
        <tr>
            <td align="center">v2</td>
            <td align="left">L’application offre les mêmes fonctionnalités que la version v1.<br>
            Le code source est structuré selon le modèle MVC. <strong>--></strong> amélioration de l’organisation du code</td>
            <td align="center"></td>
            <td align="center"><strong></strong></td>
        </tr>
        <tr>
            <td align="center">v3</td>
            <td align="left">Le menu <a color="blue">Fichier >> Quitter</a> permet d’arrêter l’application.<br>
            Le menu <a color="blue">Aide >> A propos de...</a> ouvre une Boîte de Message donnant des informations sur :
            <br>
            - la version de l'application<br>
            - la date de création<br>
            - les auteurs<br>
            </td>
            <td align="center">
            Figure 5, Figure 6, Figure 7</td>
            <td align="center"><strong></strong></td>
        </tr><tr>
            <td align="center">v4</td>
            <td align="left">Le jeu se joue en X points, 5 par défaut. Le premier joueur dont le score a atteint ce maximum a gagné.</td>
            <td align="center">Figure 8, Figure 9</td>
            <td align="center"><strong></strong></td>
        </tr>
        <tr>
            <td align="center">v5</td>
            <td align="left">Le jeu se joue en temps limité, 30 secondes par défaut. A l’issue du temps imparti, il y a un joueur gagnant, ou bien il y a égalité entre les 2 joueurs.</td>
            <td align="center">De Figure 10 à Figure 14</td>
            <td align="center"><strong></strong></td>
        </tr>
        <tr>
            <td align="center">v6</td>
            <td align="left">Le menu <a color="blue">Fichier >> Paramétrer... </a>ouvre une fenêtre de Dialogue dans laquelle l’utilisateur peut modifier différents paramètres avant de commencer la partie :<br>
            - son nom<br>
            - le nombre max. de points<br>
            - le temps max. à jouer<br>
            Une fois la partie commencée il n'est plus possible de modifier les paramètres.
            </td>
            <td align="center"></td>
            <td align="center"><strong></strong></td>
        </tr>
        <tr>
            <td align="center">v7</td>
            <td align="left">v6+<br>
            Le nom du joueur est enregistré dans une base de données.</td>
            <td align="center"></td>
            <td align="center"><strong></strong></td>
        </tr>
        <tr>
            <td align="center">v8</td>
            <td align="left">v7 +<br>
            A la fin de la partie, le système enregistre dans la base de données le résultat de la partie :<br>
            Horodatage, nomJoueurHumain, scoreJoueurHumain, joueurMachine, scoreJoueurMachine</td>
            <td align="center"></td>
            <td align="center"><strong></strong></td>
        </tr>
        <tr>
            <td align="center">v9</td>
            <td align="left">Le menu <a color="blue">Fichier >> Réinitialiser...</a> permet de vider la base de données. Une boîte de message indique que l’action s’est bien terminée.</td>
            <td align="center"></td>
            <td align="center"><strong></strong></td>
        </tr>
        <tr>
            <td align="center">v10</td>
            <td align="left">A partir du menu <a color="blue">Fichier >> Résultats...</a>, l’application ouvre une fenêtre de Dialogue dans laquelle elle affiche tous les résultats enregistrés, classés par ordre alphabétique croissant sur le nom du joueur :<br>
            <strong>nomJoueurHumain1</strong> :<br>
            - [Horodatage optionnel], scoreJoueurHumain, joueurMachine, scoreJoueurMachine<br>
            - [Horodatage optionnel], scoreJoueurHumain, joueurMachine, scoreJoueurMachine<br>
            -...<br>
            <strong>nomJoueurHumain2</strong> :<br>
            - [Horodatage optionnel], scoreJoueurHumain, joueurMachine, scoreJoueurMachine<br>
            - [Horodatage optionnel], scoreJoueurHumain, joueurMachine, scoreJoueurMachine<br>
            -...</td>
            <td align="center"></td>
            <td align="center"><strong></strong></td>
        </tr>
    </tbody>
</table>

