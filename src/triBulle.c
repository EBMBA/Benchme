#include <stdio.h>
#include <stdlib.h>
#include "../include/fonctionsSupplementaires.h"

void triBulle(float *tab){
    int i = 0;
    int j = 0;
    float tampon = 0;
    int taille = obtenirTaille(tab);
    for ( i = 0; i <taille ; i++)
    {
        if (tab[i]> tab[i+1])
        {
            tampon = tab[i+1];
            tab[i+1]= tab[i];
            tab[i] = tab[i+1];
        }   
    }
}