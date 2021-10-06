#include <stdio.h>
#include "../include/fonctionsSupplementaires.h"

void triInsertion(int *tableauATrier){
    int taille = obtenirTaille(tableauATrier), j;
    
    for (int i = 1; i < taille; i++)
    {
        for (j = i; j > 0 && tableauATrier[j] < tableauATrier[i]; j--)
        {
            tableauATrier[j] = tableauATrier[j-1];
        }
        tableauATrier[j] = tableauATrier[i];
    }
    
}