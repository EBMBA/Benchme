#include <stdio.h>
#include <stdlib.h>
#include "../include/fonctionsSupplementaires.h"

void triSelection(float *tab){
     
     int taille = obtenirTaille(tab);
     float tampon;
     for (int i = 0; i < taille - 1; i++)
     {
         for (int j = i + 1; j < taille-1; j++){
              if (tab[j] < tab[i]){
               tampon = tab[i];
               tab[i]= tab[j];
               tab[j] = tampon;
              }
         }
     }
}