//
// Created by simon on 25/05/2021.
//

#include "missile.h"
#include <stdio.h>
#include "grille.h"
#include <stdlib.h>
#include <time.h>
#include"grille.h"
#include"fonctions_supplementaires.h"
#include "bateaux.h"
#include "inventaire.h"
#include<ctype.h>
/**
 * demande quel type de missile l'utilisateur veut tirer et met a jour l'inventaire en conséquence de plus et renvoye le type de missiles choisi
 * @param NB_missile
 * @return type missile (le choix du type de missille)
 */
char choix_type_missile(inventaire *NB_missile, char tableau[10][10], char grille[10][10], boat *Bateaux2,boat *Bateaux3_1,boat *Bateaux3,boat *Bateaux4,boat *Bateaux5, int visible) {
   // la fontion qui demande le choix du missile et appelera les differents codes de chaque missile
   // elle ne s'arretera pas tant qu'il reste des missiles

    char type_missile;
    int valide;




    int ligne, colonne;
    int nbimpact=0;

    printf("quel type de missile voulez vous choisir\nC : classique - %d exemplaires \nB: bombe - %d exemplaires \nA: artillerie - %d exemplaires \nT: tactique - %d exemplaires \n", NB_missile->simple, NB_missile->bombe, NB_missile->artillerie, NB_missile->tactique);

   // ai rajouté les fflush car chaque premier scanf du programme ramenait une valeur fausse et formait une boucle supplementaire

   //le retrait du nombre de missile marche parfaitement

    do {
        valide=0;
        fflush(stdin);
        scanf("%c", &type_missile);
        type_missile=(type_missile);

        if (type_missile == 'C' && NB_missile->simple != 0) {
            NB_missile->simple = NB_missile->simple - 1;
            verif(tableau, grille, &ligne, &colonne);
            classique(tableau, grille, ligne, colonne, &nbimpact, *Bateaux2, *Bateaux3, *Bateaux3_1, *Bateaux4, *Bateaux5, visible);

        } else if (type_missile == 'B' && NB_missile->bombe != 0) {
            NB_missile->bombe = NB_missile->bombe - 1;
            verif(tableau, grille, &ligne, &colonne);
            bombe(tableau, grille, ligne, colonne, &nbimpact, *Bateaux2, *Bateaux3, *Bateaux3_1, *Bateaux4, *Bateaux5, visible);

        } else if (type_missile == 'A' && NB_missile->artillerie != 0) {
            NB_missile->artillerie = NB_missile->artillerie - 1;
            verif(tableau, grille, &ligne, &colonne);
            artillerie(tableau, grille, ligne, colonne, &nbimpact, *Bateaux2, *Bateaux3, *Bateaux3_1, *Bateaux4, *Bateaux5, visible);



        } else if (type_missile == 'T' && NB_missile->tactique != 0) {
            NB_missile->tactique = NB_missile->tactique - 1;

            verif(tableau, grille, &ligne, &colonne);
            //à définir

        } else {
            printf("\nvous n'avez pas bien saisi le nom du missile ou bien vous avez épuisé votre stock de celui ci veuillez redonner un choix valide de missile\n  classique:C   %d exemplaires \nbombe:B  %d  exemplaires \nartillerie:A   %d  exemplaires \ntactique:T   %d   exemplaires ", NB_missile->simple, NB_missile->bombe, NB_missile->artillerie, NB_missile->tactique);
            valide=1;
        }
    } while (valide==1);

    return type_missile;

}





void verif(char tableau[10][10], char grille[10][10], int* ligne, int* colonne) {

    // Verif est la fonction qui permettera de rentrer les coordonnees du point d'impact "central" des missiles et qui s'assurera
    // que celui ci est valide

    int codeerreur=0;

    int colonne1;
    int ligne1;

    do {
        if (codeerreur == 1) {
            printf("erreur, les coordonnes rentrees ne sont pas valide\n");
        }
        codeerreur = 0;
        printf("veuillez rentrer les coordonnes souhaitees : \n");
        fflush(stdin);
        scanf("%d", &colonne1);
        scanf("%d", &ligne1);

        if (colonne1 < 0 || colonne1 > 9 || ligne1 < 0 || ligne1 > 9) {
            codeerreur = 1;
        }

    } while (codeerreur == 1);

    *ligne=ligne1;
    *colonne=colonne1;


}

void impact(char tableau[10][10], char grille[10][10], int ligne, int colonne, int * nbimpact, boat *Bateaux2,boat *Bateaux3_1,boat *Bateaux3,boat *Bateaux4,boat *Bateaux5) {

// Impact est la fonction qui gere comment un missile impactera la grille et les points de vie d'un bateau



    if (grille[colonne][ligne] != '_' && tableau[colonne][ligne] != 'X' && tableau[colonne][ligne] != 'O') {
        tableau[colonne][ligne] = 'X';
        ++*nbimpact;



// j'ai essayé de faire des essais en faisant des soustractions ou avec un switch pour changer directement la valeur, apres le premier changment cela n'est plus possible
// on peut modifier chaque point de vie une fois suelement


        if (grille[colonne][ligne] == '5' ) {

            // le on rentre bien dans la boucle me permet de voir que c'est bien le changement de la valeur qui pose probleme
            // (a moins que je me goure totalement)

            printf("on rentre bien dans la boucle\n");
            switch (Bateaux5->vie) {
                case 5: Bateaux5->vie=4;
                    break;
                case 4: Bateaux5->vie=3;
                    break;
                case 3: Bateaux5->vie=2;
                    break;
                case 2: Bateaux5->vie=1;
                    break;
                case 1: Bateaux5->vie=0;
                    printf("bateau de taille 5 could");
                    break;


            }


        } else if (grille[colonne][ligne] == '4' && Bateaux4->vie != 0) {
            Bateaux4->vie--;
            if (Bateaux4->vie == 0) {
                printf("Bateau de taille 4 coulé");
            }

        } else if (grille[colonne][ligne] == '2' && Bateaux2->vie != 0) {
            Bateaux2->vie--;
            if (Bateaux2->vie == 0) {
                printf("Bateau de taille 2 coulé");
            }
        }

        // pas encore fait pour les bateaux 3

    } else if (tableau[colonne][ligne] != 'X' && tableau[colonne][ligne] != 'O') {
        tableau[colonne][ligne] = 'O';

    }

    printf("valeur bateau5.vie : %d\n" , Bateaux5->vie);
    printf("valeur Bateaux4.vie %d\n", Bateaux4->vie);
    printf("valeur Bateaux2.vie %d\n", Bateaux2->vie);


    // a mettre soit dans premier if soit dans fonction à part mais ça fait beaucoup de fonctions
    //rajouter pour les bateaux de taille 3




}


void bombe(char tableau[10][10], char grille[10][10], int ligne, int colonne, int * nbimpact, boat Bateaux2, boat Bateaux3_1, boat Bateaux3, boat Bateaux4, boat Bateaux5, int visible){

    int min1, min2;
    int max1, max2;


// Les lignes suivantes vont restreindre la zone d'action de la fonction ipmpact afin qu'elle n'essaye pas d'atteindre des cases en dehors de la grille

    if (colonne==0){
        min1 = 0;
    } else {
        min1= colonne -1;
    }

    if (ligne==0){
        min2=0;
    } else {
        min2=ligne-1;
    }

    if (colonne==9){
        max1=9;
    } else{
        max1=colonne+1;
    }

    if (ligne==9){
        max2=9;
    } else{
        max2=ligne+1;
    }


    //on applique impact à toute les cases du perimetre (toutes les cases situee a un bloc du point d'impact renseigne au debut
    for (int k = min1; k <= max1; ++k) {
        for (int l = min2; l <= max2; ++l) {

            impact(tableau, grille, l, k, nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);
        }
    }


//Permet de faire en sorte que la grille ne s'affiche plus lorsque le mode aveugle est selectionne

    if(visible==0){
        grilleutilisateur(grille);
        affiche_grille(tableau);
    }

    affichimpact(*nbimpact);


}

void classique(char tableau[10][10], char grille[10][10], int ligne, int colonne, int * nbimpact, boat Bateaux2,boat Bateaux3_1,boat Bateaux3,boat Bateaux4,boat Bateaux5, int visible){

    // on appelel impact avec l'etat de nos deux tableaux (celui avec la position des bateaux et celui avec les cases touchees
    // nbimpact permettera juste de savoir combien de fois on a touche un bateau
    // on importe les structures bateau qui contiennent les points de vie du bateau et autre

    impact(tableau, grille, ligne, colonne, nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);


    if(visible==0){
        grilleutilisateur(grille);
        affiche_grille(tableau);
    }

    affichimpact(*nbimpact);


}

void artillerie(char tableau[10][10], char grille[10][10], int ligne, int colonne, int* nbimpact, boat Bateaux2, boat Bateaux3_1, boat Bateaux3, boat Bateaux4, boat Bateaux5, int visible){

    //applique impacty sur toutes les lignes de la croix
    int nbimpf=0;

    for (int i = 0; i < 10; ++i) {
        impact(tableau, grille, i, colonne, nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);
    }

    //applique impact sur toutes les colonnes de la croix

    for (int i = 0; i < 10; ++i) {
        impact(tableau, grille, ligne, i, nbimpact, &Bateaux2, &Bateaux3_1, &Bateaux3, &Bateaux4, &Bateaux5);
    }




    if(visible==0){
        grilleutilisateur(grille);
        affiche_grille(tableau);
    }

    affichimpact(*nbimpact);

}

// inventaire indication_impact_missile(int grille[10][10],inventaire NB_missile ){

void affichimpact(int  nbimpact){

    //sert juste à aider l'utilisateur en cas de mode aveugle
    printf("vous avez touche des bateaux %d fois\n", nbimpact);



}


