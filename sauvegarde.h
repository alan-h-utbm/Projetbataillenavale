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

#ifndef PROJETBATAILLENAVALE_SAUVEGARDE_H
#define PROJETBATAILLENAVALE_SAUVEGARDE_H


void enregistrer(char grille[10][10], inventaire *NB_missile);

void charger(char grille[10][10], inventaire *NB_missile);


#endif //PROJETBATAILLENAVALE_SAUVEGARDE_H
