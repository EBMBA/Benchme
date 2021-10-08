/**
 * @file main.c
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

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
	// Partie des declarations des variables:
    float *valeur;
    int choix = 0, taille = 0;
    float debut = 0.0, fin = 0.0, temps = 0.0;
	FILE* fichier = NULL;
	
    // Partie du choix de l'algorithme de tri :
	/*do
	{
		choix = 0;
		while ( choix < 1 || choix > 5)
		{
			afficherMenu();
			scanf("%d", &choix);
		}
		
		// Partie du traitement du choix :
		if (choix != 5)
		{
			traiterChoix(choix, valeur);
		}
	} while (choix != 5);*/
	
	
    printf("Entrez la taille du tableau : " );
    scanf("%d", &taille);

    valeur = malloc( taille * sizeof(float));

    if (valeur == NULL) // On vérifie si l'allocation a marché ou non
    {
        exit(0); // On arrête tout
    }

    remplirTab(valeur, taille);
    
    //affiche(valeur, taille);

	if (argv[1])
	{
		FILE *fichier = fopen(argv[1],"w");

		if (fichier != NULL)
		{
			fprintf(fichier, "NOM,TEMPS,NOMBRE DE VALEURS\n");

			printf("1. Tri a bulle\n");
				debut = clock();
				triBulle(valeur);
				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri a bulle',%f,%d\n", temps, taille);
		
			printf("2. Tri par selection\n");
				debut = clock();

				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri par selection',%f,%d\n", temps, taille);
		
			printf("3. Tri par insertion\n");
				debut = clock();
				triInsertion(valeur);
				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri par insertion',%f,%d\n", temps, taille);

			printf("4. Tri par tas\n");
				debut = clock();
				triParTas(valeur,taille);
				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri par tas',%f,%d\n", temps, taille);

			fclose(fichier);
		}
		else
		{
			printf("Impossible d'ouvrir le fichier %s",argv[0]);
		}

	}
	

	printf("Thank you :D Goodbye !\n");

	return (0);
}

