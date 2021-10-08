/**
 * @file fonctionsSupplementaires.c
 * @author Kubilay KAPLAN et Emile METRAL (kubilay.kpl@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/triBulle.h"
#include "../include/triInsertion.h"
#include "../include/triParTas.h"
#include "../include/triSelection.h"

/**
 * @brief 
 * 
 * @param tab 
 * @return int 
 */
int obtenirTaille(float *tab){
    int taille = 0;

    do
    {
        taille ++;
    }while (tab[taille] != '\0');
    
    return taille;
}

/**
 * @brief 
 * 
 * @param TableauAInverser 
 * @return float* 
 */
float *inverserTab(float *TableauAInverser){
    float *tableauInverser = NULL;
    unsigned int i = obtenirTaille(TableauAInverser);
    //printf("%d", i);
    tableauInverser = malloc(i * sizeof(float));

    // inversion
    i--;
    unsigned int p = i;
    for (unsigned int n = 0; n <= p; n++)
    {
        tableauInverser[n] = TableauAInverser[i];
        //printf("Resultat : %s\nInversion Resultat : %s\n",Tab, tableauInverser);
        i--; 
    }

    return tableauInverser;
}

/**
 * @brief 
 * 
 * @param TableauARemplir 
 * @param taille 
 */
void remplirTab(float TableauARemplir[], int taille){
    srand(time(0));
    

    for (int h = 0; h < taille; h++)
    {
        
        float num = ( ((float)rand() / (float)(RAND_MAX)) * 10000000000.0);
        TableauARemplir[h] = num;
        
    }

}

void copierTab(const float *tableauACopier, float *tableauCopie){
    int taille = obtenirTaille(tableauACopier);

    for (int i = 0; i < taille; i++)
    {
        tableauCopie[i] = tableauACopier[i];
    }

}

/**
 * @brief 
 * 
 * @param tableau 
 * @param tailleTableau 
 */
void affiche(float *tableau, int tailleTableau)
{
    int i;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%f\n", tableau[i]);
    }
}