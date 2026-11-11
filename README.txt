Mini-Projet – Programmation Impérative 2  
Jeux de déplacement – Partie A et Partie B

AUTEURES :
- SAHEL Lysa  
- KADI Sara

⚠️ **REMARQUE IMPORTANTE – BONUS "UNDO" :**  
La fonctionnalité bonus permettant de revenir en arrière (UNDO) a été implémentée dans **le jeu du labyrinthe** (Partie B).
 Cette option permet au joueur d’annuler son dernier déplacement.

================================================
PARTIE A – Jeu de déplacement : Le Jardin Secret
================================================

DESCRIPTION DU PROGRAMME :

Ce programme implémente un jeu de déplacement minimaliste dans une grille. 
Le joueur incarne un jardinier qui explore un jardin enchanté à la recherche de fleurs à récolter. Il se déplace à l’aide des flèches directionnelles du clavier.

ÉLÉMENTS DE LA GRILLE :
- HERBE    : espace vide (zone de déplacement)
- HAIE     : mur infranchissable
- JARDINIER: le joueur
- FLEUR    : élément à récolter
- RONCE    : piège mortel (provoque la fin du jeu)
- SORTIE   : devient accessible uniquement après avoir récolté toutes les fleurs

OBJECTIF :
Récolter toutes les fleurs du jardin et atteindre la sortie sans tomber dans une ronce.

FICHIERS FOURNIS :
- main.c              : boucle principale du jeu
- Grille.c / Grille.h : gestion de la grille et chargement depuis un fichier texte
- Pion.c / Pion.h     : gestion du pion joueur (le jardinier)
- Makefile            : pour compiler facilement le projet
- facile.txt          : exemple de grille de départ

UTILISATION :

1. Compilation :
   make

2. Exécution du jeu :
   ./jeu facile.txt

3. Commandes clavier :
   → ↑ ← ↓ : déplacements du jardinier  
   q ou Q  : quitter le jeu

CARACTÉRISTIQUES TECHNIQUES :
- Affichage coloré dans le terminal (séquences ANSI)
- Utilisation de la bibliothèque ncurses pour la gestion du clavier
- Chargement de la grille depuis un fichier texte externe
- Gestion des collisions, pièges et condition de victoire
- Code structuré et modulaire (séparé en fichiers .c / .h)

===============================
PARTIE B – Autres jeux réalisés
===============================

Dans la seconde partie du projet, nous avons choisi de développer deux jeux supplémentaires :

- Un jeu de **labyrinthe**
- Un jeu de **snake**

Chacun de ces jeux est accompagné de son propre fichier `README.txt`, qui détaille les règles, les commandes et les fichiers sources spécifiques.


