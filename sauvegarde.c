//
// Created by simon on 29/05/2021.
//

#include <stdio.h>
#include "grille.h"
#include <stdlib.h>
#include <time.h>
#include"grille.h"
#include"fonctions_supplementaires.h"
#include "bateaux.h"
#include "inventaire.h"
#include"missile.h"

#define FILE_NAME "partie.txt"


void enregistrer(char grille[10][10], inventaire *NB_missile){
    int k,m;
    FILE *f = fopen("partie.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!,\n");
        exit(1);
    }else{
        printf("fichier bien ouvert  \n");
    }

    if (f != NULL) {
        printf("Enregistrement....");
        for ( k = 0; k < 10; k++) {
            for ( m = 0; m < 10; m++) {
                fprintf(f," %c",grille[k][m]);
            }
            fprintf(f, "\n");
        }
    }
    fprintf(f,"%d\n", NB_missile->bombe);
    fprintf(f,"%d\n", NB_missile->artillerie);
    fprintf(f,"%d\n", NB_missile->tactique);
    fclose(f);
}

void charger(char grille[10][10], inventaire *NB_missile) { //todo: pass the matrix by reference , in other words: change it from normal int[i][j] to a pointer of matrix;
    int i =0 , j=0;
    FILE *f;
    char c;
    f=fopen("partie.txt","rt");


    while((c=fgetc(f))!=EOF) {
        switch (c) {
            case ' ':
                break;
            case '\n':
                break;
            default:
                if (c == '_')
                    grille[i][j] = c;
                j++;
                if (j>9) {
                    i++;
                    j = 0;
                    if(i == 9){
                        c=fgetc(f);
                        NB_missile->bombe = (int)c;

                        c=fgetc(f);
                        NB_missile->tactique= (int)c;

                        c=fgetc(f);
                       NB_missile->simple = (int)c;
                    }
                }

                break;
        }
    }

    fclose(f);
    for (int k = 0; k < 10; ++k) {
        for (int m = 0; m < 10; ++m) {
            printf("%c ",grille[k][m]);
        }
        printf("\n");
    }


}