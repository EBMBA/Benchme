/**
 * @file triSelection.c
 * @author Kubilay KAPLAN et Emile METRAL (kubilay.kpl@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/fonctionsSupplementaires.h"

/**
 * @brief algorithmes de tri de type "tri par selection"
 * 
 * @param tab tableau a trier
 */
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