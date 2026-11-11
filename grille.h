#ifndef GRILLE_H
#define GRILLE_H

/* Enum pour les éléments du jardin */
typedef enum {
    HERBE,     /*  Sol vide */
    HAIE,      /*  Mur */
    JARDINIER, /* Joueur */
    FLEUR,     /* récolter */
    RONCE,     /* Piège */
    SORTIE     /*  Sortie (s’ouvre si toutes les fleurs sont prises) */
} Element;

/*Structure de la grille*/

typedef struct {
    int n; /* lignes */
    int m; /* colonnes */ 
    Element **cases; /* tableau à 2 dimensions d’éléments */
} Grille; 


/* L'allocation de la grille  */
Grille* Grille_initialiser(int n, int m);
/* désallocation de la grille */
void Grille_desallouer(Grille* grille);
/* Fonction pour mettre l’élément RIEN partout dans la grille*/
void Grille_vider(Grille* grille);
/* Fonction qui dessine à l’écran ce qui est codé dans le tableau de la Grille*/
void Grille_redessiner(Grille* grille);
/* Fonctio pour remplir la grille */
void Grille_placer_element(Grille* grille, int x, int y, Element e);
/* charger une grille depuis un fichier texte */
Grille* Grille_charger_fichier(const char* nom_fichier);

#endif

