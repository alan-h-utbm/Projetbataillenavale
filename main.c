#include <stdio.h>
#include "grille.h"
#include <stdlib.h>
#include <time.h>
#include"grille.h"
#include"fonctions_supplementaires.h"
#include "bateaux.h"
#include "inventaire.h"
#include"missile.h"
#include "sauvegarde.h"
int main() {

    int colonne;
    int ligne;
int* nbimpact;

    char grille[10][10]={0};
    char tableau[10][10];
    char level;
    char mode;
    int missile=5;
    int visible=0;
    inventaire NB_missile;
    boat Bateaux2;
    boat Bateaux3;
    boat Bateaux3_1;
    boat Bateaux4;
    boat Bateaux5;

    //affiche menu princial+choix sur modes//
    level=debut_partie_choixlevel();
    mode=debut_partie_choixmode();

    if(level=='Q'){
        printf("fin du programme\n");
        return 0;
    }


if(mode=='B'){
    visible=1;
}



    // initialise les deux grille avec des ______
    initgrille(grille, tableau);


    //affiche la grillevierge
    grilleutilisateur(tableau);
    regles();



    //genere les bateaux dans la grille
    genere_bateau(grille,&Bateaux2,&Bateaux3_1,&Bateaux3,&Bateaux4,&Bateaux5);

    //affiche grille avec bateaux
    affiche_grille(grille);



    //initialise le nb de munitions en fonction de ce qu'a choisit l'utilisateur
    NB_missile=munitions(level);

    do {

        choix_type_missile(&NB_missile, tableau, grille, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5, visible);

    } while (NB_missile.artillerie!=0 && NB_missile.bombe!=0 && NB_missile.tactique!=0 && NB_missile.simple!=0);



    return 0;
}
