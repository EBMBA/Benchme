#include <stdio.h>
#include "../include/fonctionsSupplementaires.h"

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