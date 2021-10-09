/**
 * @file triInsertion.c
 * @author Kubilay KAPLAN et Emile METRAL (kubilay.kpl@gmail.com)
 * @brief Programme pour creer un algorithmes de tri de type "par insertion"
 * @version 0.1
 * @date 2021-10-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include "../include/fonctionsSupplementaires.h"

/**
 * @brief 
 * 
 * @param tableauATrier 
 */
void triInsertion(float *tableauATrier){
    int taille = obtenirTaille(tableauATrier), compteur = 0;
    float valeurActuel = 0;

    for (int i = 1; i < taille; i++) {
        valeurActuel = tableauATrier[i];
        compteur = i;
        while (compteur > 0 && tableauATrier[compteur - 1] > valeurActuel) {
            tableauATrier[compteur] = tableauATrier[compteur - 1];
            compteur--;
        }
        tableauATrier[compteur] = valeurActuel;
    }
}