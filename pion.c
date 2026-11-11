#include <stdlib.h>
#include <stdio.h>
#include "pion.h"

/* Fonction qui alloue un pion */
Jardinier* Jardinier_allouer(int x, int y)
{
    Jardinier* j = malloc(sizeof(Jardinier));
    if ( j == NULL){
        /* si l'allocation échoue, afficher un message d'erreur */
        perror(" echec de l'allocation mémoire pour le jardinier !");
        return NULL;
    }
   
    j->x = x;
    j->y = y;
    j->x_old = x;
    j->y_old = y;
   
    return j;
}

/* Fonction qui désalloue un pion */
void Jardinier_desallouer(Jardinier* j)
{
    if (j != NULL)
    free(j);
}

/* Fonction qui place un pion à une case donnée */
void Jardinier_placer(Jardinier* j, int x, int y)
{
    j->x = x;
    j->y = y;
    j->x_old = x;
    j->y_old = y;

}

/* Fonction pour déplacer le pion dans une direction indiquée,
tout en sauvegardant la position précédente  */

void Jardinier_deplacer(Jardinier* j, Direction dir)
{
    /* sauvegarder l'ancienne position */
    j->x_old = j->x;
    j->y_old = j->y;

    /* déplacer le pion dans une direction indiquée */
    switch (dir) {
        case HAUT:
            j->x--;
            break;
        case BAS:
            j->x++;
            break;
        case GAUCHE:
            j->y--;
            break;
        case DROITE:
            j->y++;
            break;
    }
}


/* Fonction qui effectue un déplacement du jardinier et gère les collisions */
int deplacer_jardinier(Jardinier* jardinier, Grille* grille, Direction dir) {
    /* Sauvegarder la position précédente */
    int x_old = jardinier->x;
    int y_old = jardinier->y;

    /* Déplacer le jardinier */
    Jardinier_deplacer(jardinier, dir);

    /* Vérifier les limites de la grille */
    if (jardinier->x < 0 || jardinier->x >= grille->n || jardinier->y < 0 || jardinier->y >= grille->m)
    {
        jardinier->x = x_old;
        jardinier->y = y_old;
        return 0;
    }

    Element e = grille->cases[jardinier->x][jardinier->y];

    if (e == HAIE) {
        jardinier->x = x_old;
        jardinier->y = y_old;
        return 0;
    }

    grille->cases[x_old][y_old] = HERBE;

    if (e == RONCE)
    {
        grille->cases[jardinier->x][jardinier->y] = JARDINIER;
        return -1; /*Game over*/
    }

    if (e == FLEUR)
    {
        grille->cases[jardinier->x][jardinier->y] = JARDINIER;
        return 1; /*Fleur récoltée*/
    }

    if (e == SORTIE)
{
    /* Vérifie si toutes les fleurs ont été récoltées */
    for (int i = 0; i < grille->n; i++)
    {
        for (int j = 0; j < grille->m; j++)
        {
            if (grille->cases[i][j] == FLEUR)
            {
                return -1; /* Perdu, il reste des fleurs à récolter */
            }
        }
    }

    /* Si toutes les fleurs ont été récoltées, remplacer la SORTIE par le JARDINIER */
    grille->cases[jardinier->x][jardinier->y] = JARDINIER;
    return 2; /* Victoire ! */
}

/* Si ce n'est pas une sortie, mettre la case actuelle à HERBE */
grille->cases[jardinier->x][jardinier->y] = HERBE;

/* Marquer la nouvelle position du jardinier */
grille->cases[jardinier->x][jardinier->y] = JARDINIER;

return 1; /* Déplacement normal */
}
