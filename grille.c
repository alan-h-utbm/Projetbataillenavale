//
// Created by simon on 19/05/2021.
//

#include "grille.h"
#include <stdio.h>
/**
 * affiche la grille de départ sans les indications bateaux
 * @param grille
 */
void initgrille(char grille[10][10], char tableau[10][10]) {




    int i, j;

    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            grille[i][j]='_';
            tableau[i][j]='_';
        }
    }
}

void regles(){

    printf("Le but est de coule les bateaux dissimules dans la grille\n");
    printf("Votre adversaire possede 5 bateaux:\n");
    printf(" - un de taille 5\n - un de taille 4\n - deux de taille 3\n - un de taille 2\n");

}

/**
 * affiche la grille avec les bateaux essentielement pour nous pour connaitre l'emplacement des bateaux pour faire test missile plus rapide.
 * @param grille
 */
void affiche_grille(char grille[10][10]){

    int i, j;

    printf("    0    1   2   3   4   5   6   7   8   9\n");
    for (i=0;i<10;i++){

        printf("   -----------------------------------------");
        printf("\n");
        printf("%d  ", i);
        for (j=0;j<10;j++){

            printf("| %c ", grille[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("  -----------------------------------------\n");
    printf("     0   1   2   3   4   5   6   7   8   9\n");

    printf("\n");


}

void grilleutilisateur(char grille[10][10]){


    int i, j;

    printf("utilisateur : \n");

    printf("    0    1   2   3   4   5   6   7   8   9\n");
    for (i=0;i<10;i++){

        printf("   -----------------------------------------");
        printf("\n");
        printf("%d  ", i);
        for (j=0;j<10;j++){;
            printf("| %c ", grille[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("  -----------------------------------------\n");
    printf("     0   1   2   3   4   5   6   7   8   9\n");




}