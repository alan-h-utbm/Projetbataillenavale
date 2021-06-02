//
// Created by simon on 19/05/2021.
//

#ifndef PROJETBATAILLENAVALE_BATEAUX_H
#define PROJETBATAILLENAVALE_BATEAUX_H
typedef struct {
    //permet de reperer un bateaux sur la grille
    int x;
    int y;
    int taille;
    char orientation;
    int vie;
}boat;

//boat genere_bateaux(boat bateau ,char grille[10][10]);
//verif_positionboat()
void genere_bateau(char grille[10][10],boat *Bateaux2,boat *Bateaux3_1,boat *Bateaux3,boat *Bateaux4,boat *Bateaux5);

//void convertit_donnee_grille_en_boat(char grille[10][10],boat *Bateaux2,boat *Bateaux3_1,boat *Bateaux3,boat *Bateaux4,boat *Bateaux5);


#endif //PROJETBATAILLENAVALE_BATEAUX_H
