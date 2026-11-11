#include "grille.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

Grille* Grille_initialiser(int n, int m) {
    Grille* g = malloc(sizeof(Grille));
    if (!g) return NULL;

    g->n = n;
    g->m = m;
    g->cases = malloc(n * sizeof(Element*));
    if (!g->cases) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        g->cases[i] = malloc(m * sizeof(Element));
        if (!g->cases[i]) {
            // Libérer ce qui a déjà été alloué
            for (int j = 0; j < i; j++) free(g->cases[j]);
            free(g->cases);
            free(g);
            return NULL;
        }
    }
    return g;
}

void Grille_desallouer(Grille* grille) {
    for (int i = 0; i < grille->n; i++) {
        free(grille->cases[i]);
    }
    free(grille->cases);
    free(grille);
}

void Grille_vider(Grille* grille) {
    for (int i = 0; i < grille->n; i++) {
        for (int j = 0; j < grille->m; j++) {
            grille->cases[i][j] = HERBE;
        }
    }
}

void Grille_placer_element(Grille* grille, int x, int y, Element e) {
    if (x >= 0 && x < grille->n && y >= 0 && y < grille->m)
        grille->cases[x][y] = e;
}
void Grille_redessiner(Grille *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->m; j++) {
            switch (g->cases[i][j]) {
                case HERBE:
                    attron(COLOR_PAIR(1));  /* Couleur pour HERBE */
                    mvprintw(i, j*2, "  ");   /* Afficher un espace à la position (i, j) */
                    attroff(COLOR_PAIR(1)); /* Désactiver la couleur */
                    break;
                case HAIE:
                    attron(COLOR_PAIR(2));  /* Couleur pour HAIE */
                    mvprintw(i, j*2, "  ");   /* Afficher un espace à la position (i, j) */
                    attroff(COLOR_PAIR(2)); /* Désactiver la couleur */
                    break;
                case JARDINIER:
                    attron(COLOR_PAIR(3));  /* Couleur pour JARDINIER */
                    mvprintw(i, j*2, "  ");   /* Afficher un espace à la position (i, j) */
                    attroff(COLOR_PAIR(3)); /* Désactiver la couleur */
                    break;
                case FLEUR:
                    attron(COLOR_PAIR(4));  /* Couleur pour FLEUR */
                    mvprintw(i, j*2, "  ");   /* Afficher un espace à la position (i, j) */
                    attroff(COLOR_PAIR(4)); /* Désactiver la couleur */
                    break;
                case RONCE:
                    attron(COLOR_PAIR(5));  /* Couleur pour RONCE */
                    mvprintw(i, j*2, "  ");   /* Afficher un espace à la position (i, j) */
                    attroff(COLOR_PAIR(5)); /* Désactiver la couleur */
                    break;
                case SORTIE:
                    attron(COLOR_PAIR(6));  /* Couleur pour SORTIE */
                    mvprintw(i, j*2, "  ");   /* Afficher un espace à la position (i, j) */
                    attroff(COLOR_PAIR(6)); /* Désactiver la couleur */
                    break;
                default:
                    mvprintw(i, j*2, "  ");   /* Afficher un espace si aucune condition ne correspond */
                    break;
            }
        }
    }
}




Grille* Grille_charger_fichier(const char* nom_fichier) {
    FILE* f = fopen(nom_fichier , "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return NULL;
    }

    int n, m;
    if (fscanf(f, "%d %d\n", &n, &m) != 2 || n <= 0 || m <= 0) {
      fprintf(stderr, "Erreur : dimensions invalides dans le fichier (n=%d, m=%d).\n", n, m);
      fclose(f);
     return NULL;
    }
    Grille* g = Grille_initialiser(n, m);
    if (!g) {
      fprintf(stderr, "Erreur : impossible d’allouer la grille.\n");
      fclose(f);
      return NULL;
    }

    char ligne[102];  // max 100 + \n + \0
    for (int i = 0; i < n; i++) {
        if (fgets(ligne, sizeof(ligne), f) == NULL) break;
        for (int j = 0; j < m; j++) {
            switch (ligne[j]) {
                case 'M': g->cases[i][j] = HAIE; break;
                case 'P': g->cases[i][j] = JARDINIER; break;
                case 'F': g->cases[i][j] = FLEUR; break;
                case 'Q': g->cases[i][j] = RONCE; break;
                case 'S': g->cases[i][j] = SORTIE; break;
                case ' ': g->cases[i][j] = HERBE; break;
                default: g->cases[i][j] = HERBE; break;  // valeur par défaut
            }
        }
    }

    fclose(f);
    return g;
}
