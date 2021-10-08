/**
 * @file main.c
 * @author KAPLAN Kubilay & METRAL Emile 
 * @brief Programme pour tester des algorithmes de tri en fonction de la taille du tableau.
 * 
 * @version 0.1
 * @date 2021-10-08
 * Execute les algorithmes de tri suivant :
 * - Tri à bulle
 * - Tri par sélection
 * - Tri par insertion 
 * - Tri par tas 
 *  en fournissant des statistiques dans le fichier passé en parmètre.
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/fonctionsSupplementaires.h"
#include "../include/triBulle.h"
#include "../include/triInsertion.h"
#include "../include/triParTas.h"
#include "../include/triSelection.h"


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
    float *valeur = NULL, *valeurBulle = NULL, *valeurInsertion = NULL, *valeurSelection = NULL, *valeurTas = NULL;
	int tableauTaille[6] = {100, 1000, 10000, 100000, 1000000, 10000000}; 
    int choix = 0, taille = 0;
    clock_t debut = 0.0, fin = 0.0;
	float temps = 0.0;
	FILE* fichier = NULL;

    printf("Entrez la taille du tableau (0 pour utiliser les tests automatiques): " );
    scanf("%d", &taille);

	if (taille != 0)
	{
		valeur = malloc( taille * sizeof(float)); 
		valeurInsertion = malloc(taille * sizeof(float));
		valeurBulle = malloc(taille * sizeof(float));
		valeurTas = malloc(taille * sizeof(float));
		valeurSelection = malloc(taille * sizeof(float));

		if (valeur == NULL && valeurInsertion == NULL && valeurBulle == NULL && valeurTas == NULL && valeurSelection == NULL) // On vérifie si l'allocation a marché ou non
		{
			exit(0); // On arrête tout
		}
	}
	

	
    
    
    //affiche(valeur, taille);
	// plusieurs tailles avec une moyenne des temps 


	/**
	 * @brief Si l'utilisateur a rentré un argument. 
	 * 
	 */
	if (argv[1])
	{
		fichier = fopen(argv[1],"w");

		/**
		 * @brief Si utilisateur a choisi une taille. 
		 * 
		 */
		if (fichier != NULL && taille != 0)
		{
			fprintf(fichier, "NOM,TEMPS,NOMBRE DE VALEURS\n");

			remplirTab(valeur, taille);

			copierTab(valeur, valeurBulle);
			copierTab(valeur, valeurInsertion);
			copierTab(valeur, valeurSelection);
			copierTab(valeur, valeurTas);

			/**
			 * @brief On rentre les valeurs si le tableau en a moins de 10. 
			 * 
			 */
			if (taille < 10)
			{
				for (int i = 0; i < 10; i++)
				{
					fprintf(fichier, "%f ", valeur[i]);
				}
				fprintf(fichier, "\n");
			}

			printf("1. Tri a bulle\n");
				debut = clock();
				triBulle(valeurBulle);
				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri a bulle',%f,%d\n", temps, taille);
		
			printf("2. Tri par selection\n");
				debut = clock();
				triSelection(valeurSelection);
				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri par selection',%f,%d\n", temps, taille);
		
			printf("3. Tri par insertion\n");
				debut = clock();
				triInsertion(valeurInsertion);
				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri par insertion',%f,%d\n", temps, taille);

			printf("4. Tri par tas\n");
				debut = clock();
				triParTas(valeurTas,taille);
				fin =  clock();
				temps = (float)(fin-debut)/CLOCKS_PER_SEC;
				printf("temps = %f\n", temps);
				fprintf(fichier, "'Tri par tas',%f,%d\n", temps, taille);

			if (taille < 10)
			{
				for (int i = 0; i < 10; i++)
				{
					fprintf(fichier, "%f", valeur[i]);
				}
				fprintf(fichier, "\n");
			}

			fclose(fichier);
		}
		/**
		 * @brief Si utilisateur choisi les tests automatiques.
		 * 
		 */
		else if (fichier != NULL && taille == 0)
		{
			fprintf(fichier, "NOM,TEMPS,NOMBRE DE VALEURS\n");
			for (int i = 0; i < 3; i++)
			{
				taille = tableauTaille[i];
				valeur = malloc( taille * sizeof(float)); 
				valeurInsertion = malloc(taille * sizeof(float));
				valeurBulle = malloc(taille * sizeof(float));
				valeurTas = malloc(taille * sizeof(float));
				valeurSelection = malloc(taille * sizeof(float));

				if (valeur == NULL && valeurInsertion == NULL && valeurBulle == NULL && valeurTas == NULL && valeurSelection == NULL) // On vérifie si l'allocation a marché ou non
				{
					exit(0); // On arrête tout
				}

				remplirTab(valeur, taille);

				copierTab(valeur, valeurBulle);
				copierTab(valeur, valeurInsertion);
				copierTab(valeur, valeurSelection);
				copierTab(valeur, valeurTas);


				printf("1. Tri a bulle\n");
					debut = clock();
					triBulle(valeurBulle);
					fin =  clock();
					temps = (float)(fin-debut)/CLOCKS_PER_SEC;
					printf("temps = %f\n", temps);
					fprintf(fichier, "'Tri a bulle',%f,%d\n", temps, taille);
		
				printf("2. Tri par selection\n");
					debut = clock();
					triSelection(valeurSelection);
					fin =  clock();
					temps = (float)(fin-debut)/CLOCKS_PER_SEC;
					printf("temps = %f\n", temps);
					fprintf(fichier, "'Tri par selection',%f,%d\n", temps, taille);
		
				printf("3. Tri par insertion\n");
					debut = clock();
					triInsertion(valeurInsertion);
					fin =  clock();
					temps = (float)(fin-debut)/CLOCKS_PER_SEC;
					printf("temps = %f\n", temps);
					fprintf(fichier, "'Tri par insertion',%f,%d\n", temps, taille);

				printf("4. Tri par tas\n");
					debut = clock();
					triParTas(valeurTas,taille);
					fin =  clock();
					temps = (float)(fin-debut)/CLOCKS_PER_SEC;
					printf("temps = %f\n", temps);
					fprintf(fichier, "'Tri par tas',%f,%d\n", temps, taille);

			}

			fclose(fichier);
		}
		
		else
		{
			printf("Impossible d'ouvrir le fichier %s",argv[1]);
		}

	}
	/**
	 * @brief Si l'utilisateur n'a pas rentré d'argument. 
	 * 
	 */
	else{
		printf("Merci de définir le fichier où les resultats seront envoyés en argument du programme : benchme resultat.csv\n");
	}

	free(valeur);
	free(valeurTas);
	free(valeurInsertion);
	free(valeurSelection);
	free(valeurBulle);
	return (0);
}

