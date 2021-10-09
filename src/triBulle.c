/**
 * @file triBulle.c
 * @author Kubilay KAPLAN et Emile METRAL (kubilay.kpl@gmail.com)
 * @brief Programme pour creer un algorithmes de tri de type "a bulle" 
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
 * @brief algorithmes de tri de type "tri a bulle"
 * 
 * @param tab tableau a trier
 */
void triBulle(float *tab){
    int i = 0;
    int j = 0;
    float tampon = 0;
    int taille = obtenirTaille(tab);
    for ( i = 0; i <taille ; i++)
        for ( j = 0; j < taille-1; j++)
        {
            if (tab[j]> tab[j+1])
            {
                tampon = tab[j+1];
                tab[j+1]= tab[j];
                tab[j] = tampon;
            }   
        }
}