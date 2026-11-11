#ifndef PION_H
#define PION_H
#include "grille.h"

typedef struct
{
    int x, y; /* L'emplacement actuel du pion */
    int x_old, y_old;   /* L'emplacement précédent du pion */
} Jardinier;


typedef enum {
    DROITE,
    GAUCHE,
    HAUT, 
    BAS
} Direction;

/* Fonction pour allouer un pion */
Jardinier* Jardinier_allouer(int x, int y);
/* Fonction pour désallouer un pion */
void Jardinier_desallouer(Jardinier* j);
/* Fonction qui place un pion à une case donnée */
void Jardinier_placer(Jardinier* j, int x, int y);
/* Fonction pour déplacer le pion dans une direction indiquée, 
tout en sauvegardant la position précédente  */
void Jardinier_deplacer(Jardinier* j, Direction dir);
/* Fonction qui effectue un déplacement du jardinier et gère les collisions */
int deplacer_jardinier(Jardinier* jardinier, Grille* grille, Direction dir);

#endif
