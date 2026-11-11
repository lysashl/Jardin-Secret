#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "grille.h"
#include "pion.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s fichier_grille.txt\n", argv[0]);
        return 1;
    }

    /* Charger la grille depuis un fichier */
    Grille* grille = Grille_charger_fichier(argv[1]);
    if (!grille) {
        return 1;
    }

    /* Trouver la position initiale du jardinier */
    Jardinier* jardinier = NULL;
    for (int i = 0; i < grille->n; i++) {
        for (int j = 0; j < grille->m; j++) {
            if (grille->cases[i][j] == JARDINIER) {
                jardinier = Jardinier_allouer(i, j);
                break;
            }
        }
        if (jardinier) break;
    }

    if (!jardinier) {
        fprintf(stderr, "Erreur : Jardinier non trouvé dans la grille.\n");
        Grille_desallouer(grille);
        return 1;
    }

    /* Choisir le mode */
    int mode = 0;
    printf("Choisissez le mode de jeu :\n");
    printf("1 - Mode pas-à-pas (vous appuyez sur une touche pour chaque déplacement)\n");
    printf("2 - Mode continu (le jardinier avance automatiquement)\n");
    printf("Votre choix : ");
    scanf("%d", &mode);
    if (mode != 1 && mode != 2) {
        printf("Mode invalide. Fin du programme.\n");
        Grille_desallouer(grille);
        Jardinier_desallouer(jardinier);
        return 1;
    }

    /* Initialisation de ncurses */
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    halfdelay(1);  /* getch attend 0.1s max (100ms) */

    /* Initialiser les couleurs */
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);     /* HERBE */
    init_pair(2, COLOR_BLACK, COLOR_BLUE);      /* HAIE (mur) */
    init_pair(3, COLOR_BLACK, COLOR_BLACK);     /* JARDINIER */
    init_pair(4, COLOR_BLACK, COLOR_MAGENTA);   /* FLEUR */
    init_pair(5, COLOR_WHITE, COLOR_YELLOW);    /* RONCE */
    init_pair(6, COLOR_BLACK, COLOR_RED);       /* SORTIE */

    int continuer = 1;
    Direction direction_actuelle = GAUCHE;

    while (continuer)
    {
        clear();
        Grille_redessiner(grille);
        refresh();

        int touche = getch();

        // Mettre à jour la direction si une touche est pressée
        if (touche != ERR) {
            switch (touche) {
                case KEY_UP:    direction_actuelle = HAUT;    break;
                case KEY_DOWN:  direction_actuelle = BAS;     break;
                case KEY_LEFT:  direction_actuelle = GAUCHE;  break;
                case KEY_RIGHT: direction_actuelle = DROITE;  break;
                case 'q': case 'Q':
                    continuer = 0;
                    break;
                default:
                    break;
            }
        }

        if (mode == 1 && touche != ERR) {
            // Mode pas-à-pas : déplacer uniquement si touche directionnelle
            if (touche == KEY_UP || touche == KEY_DOWN || touche == KEY_LEFT || touche == KEY_RIGHT) {
                int res = deplacer_jardinier(jardinier, grille, direction_actuelle);
                if (res == -1) {
                    Grille_redessiner(grille);
                    mvprintw(grille->n + 2, 0, " Vous avez perdu ! Game Over !");
                    refresh();
                    sleep(2);
                    continuer = 0;
                } else if (res == 2) {
                    Grille_redessiner(grille);
                    mvprintw(grille->n + 2, 0, "Bravo ! Vous avez trouvé la sortie !");
                    refresh();
                    sleep(2);
                    continuer = 0;
                }
            }
        }
        else if (mode == 2) {
            // Mode continu : toujours déplacer, même sans appuyer
            int res = deplacer_jardinier(jardinier, grille, direction_actuelle);
            if (res == -1) {
                Grille_redessiner(grille);
                mvprintw(grille->n + 2, 0, " Vous avez perdu ! Game Over !");
                refresh();
                sleep(2);
                continuer = 0;
            } else if (res == 2) {
                Grille_redessiner(grille);
                mvprintw(grille->n + 2, 0, "Bravo ! Vous avez trouvé la sortie !");
                refresh();
                sleep(2);
                continuer = 0;
            }
        }
    }

    /* Fin de ncurses */
    endwin();

    /* Libération mémoire */
    Jardinier_desallouer(jardinier);
    Grille_desallouer(grille);

    return 0;
}

