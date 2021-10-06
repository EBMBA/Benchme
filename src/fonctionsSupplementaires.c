#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/triBulle.h"
#include "../include/triInsertion.h"

void afficherMenu(){
    printf("Choissisez une methode de tri :\n");
    for (size_t i = 1; i < 5; i++)
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
            printf("%ld. Tri par pas\n",i );
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

void traiterChoix(int choix, float *val){
    int taille = 0, resultat = 0;
    //char *valeurHexadecimal;
    unsigned int nombreDecimal = 0;
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
            triBulle(val);
            affiche(val,taille);
            break;

        case 2:
            printf("2. Tri par selection\n");
            
            affiche(val, taille);
            break;
        
        case 3:
            printf("3. Tri par insertion\n");
            triInsertion(val);
            affiche(val, taille);
            break;
        
        case 4:
            printf("4. Tri par pas\n");
            
            break;

        default:
            break;
    }
}

int obtenirTaille(float *tab){
    int taille = 0;

    do
    {
        taille ++;
    }while (tab[taille] != '\0');
    
    return taille;
}

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

void remplirTab(float TableauARemplir[], int taille){
    srand(time(0));
    

    for (int h = 0; h < taille; h++)
    {
        
        float num = ( ((float)rand() / (float)(RAND_MAX)) * 100.0 );
        //int num = ( rand() % ( 99 - 1  + 1 ) );
        TableauARemplir[h] = num;
        
    }

}

void affiche(float *tableau, int tailleTableau)
{
    int i;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%f\n", tableau[i]);
    }
}