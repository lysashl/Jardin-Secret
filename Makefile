all: jeu 

jeu : main.o grille.o pion.o
	gcc -o jeu main.o grille.o pion.o -lncurses


main.o : main.c grille.h pion.h
	gcc -c main.c

grille.o : grille.c grille.h
	gcc -c grille.c

pion.o : pion.c pion.h grille.h
	gcc -c pion.c

clean :
	rm -f *.o jeu makefile 
