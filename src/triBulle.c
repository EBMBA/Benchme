#include <stdio.h>
#include <stdlib.h>
#include "../include/fonctionsSupplementaires.h"

void triBulle(float *tab){
    int i = 0;
    int j = 0;
    float tampon = 0;
    int taille = obtenirTaille(tab);
    for ( i = 0; i <taille-1 ; i++)
        for ( j = 0; j < taille-i-2; j++)
        {
            if (tab[j]> tab[j+1])
            {
            tampon = tab[j+1];
            tab[j+1]= tab[j];
            tab[j] = tampon;
            }   
        }
}