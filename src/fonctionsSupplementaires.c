/**
 * @file fonctionsSupplementaires.c
 * @author Kubilay KAPLAN et Emile METRAL (kubilay.kpl@gmail.com)
 * @brief Fonctions supplementaires
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
 */
void afficherMenu(){
    printf("Choissisez une methode de tri :\n");
    for (size_t i = 1; i < 6; i++)
    {
        switch (i)
        {
        case 1:
            printf("%ld. Tri a bulle\n",i );
            break;

        case 2:
            printf("%ld. Tri par selection\n",i );
            break;
        
        case 3:
            printf("%ld. Tri par insertion\n",i );
            break;
        
        case 4:
            printf("%ld. Tri par tas\n",i );
            break;

        case 5:
            printf("%ld. Quitter\n",i );
            break;

        default:
            break;
        }
    }
    printf(" : ");
    
}

/**
 * @brief 
 * 
 * @param choix 
 * @param val 
 */
void traiterChoix(int choix, float *val){
    int taille = 0;
    float debut = 0.0, fin = 0.0, temps = 0.0;
    printf("Entrez la taille du tableau : " );
    scanf("%d", &taille);

    val = malloc( taille * sizeof(float));

    if (val == NULL) // On vérifie si l'allocation a marché ou non
    {
        exit(0); // On arrête tout
    }

    remplirTab(val, taille);
    
    affiche(val, taille);
    
    switch (choix)
        {
        case 1:
            printf("1. Tri a bulle\n");
            debut = clock();
            triBulle(val);
            fin =  clock();
            temps = (float)(fin-debut)/CLOCKS_PER_SEC;
            affiche(val,taille);
            printf("temps = %f\n", temps);
            break;

        case 2:
            printf("2. Tri par selection\n");
            debut = clock();
            triSelection(val);
            fin =  clock();
            temps = (float)(fin-debut)/CLOCKS_PER_SEC;
            affiche(val, taille);
            printf("temps = %f\n", temps);
            break;
        
        case 3:
            printf("3. Tri par insertion\n");
            debut = clock();
            triInsertion(val);
            fin =  clock();
            temps = (float)(fin-debut)/CLOCKS_PER_SEC;
            affiche(val, taille);
            printf("temps = %f\n", temps);
            break;
        
        case 4:
            printf("4. Tri par tas\n");
            debut = clock();
            triParTas(val,taille);
            fin =  clock();
            temps = (float)(fin-debut)/CLOCKS_PER_SEC;
            affiche(val,taille);
            printf("temps = %f\n", temps);
            break;

        default:
            break;
    }
}

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