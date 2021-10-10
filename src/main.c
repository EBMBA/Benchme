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
#include "../include/fonctionsSupplementaires.h"
#include "../include/triBulle.h"
#include "../include/triInsertion.h"
#include "../include/triParTas.h"
#include "../include/triSelection.h"
#include "../include/tempsExecution.h"


/**
 * @brief 
 * 
 * @param argc 
 * @param argv Nom du fichier 
 * @return int 
 */
int main(int argc, char const *argv[])
{
	// Partie des declarations des variables:
    float *valeur = NULL, *valeurBulle = NULL, *valeurInsertion = NULL, *valeurSelection = NULL, *valeurTas = NULL;
	float moyenneInsertion = 0.0, moyenneBulle = 0.0, moyenneTas = 0.0, moyenneSelection = 0.0;
	float sommeInsertion = 0.0, sommeBulle = 0.0, sommeTas = 0.0, sommeSelection = 0.0;
	int tableauTaille[6] = {100, 1000, 10000, 100000, 1000000, 10000000}, indexMaxTableau = 4; 
    int choix = 0, taille = 0;
	float temps = 0.0;
	FILE* fichier = NULL;

	/**
	 * @brief Si l'utilisateur rentre 0 les tests se feront suivant les tailles suivantes 100, 1000, 10000, 100000, 1000000, 10000000
	 * 
	 */
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

	// Si l'utilisateur a rentré un argument. 
	if (argv[1])
	{
		fichier = fopen(argv[1],"w");

		
		//@brief Si utilisateur a choisi une taille. 
		 
		if (fichier != NULL && taille != 0)
		{
			fprintf(fichier, "NOM,TEMPS,NOMBRE DE VALEURS\n");
			for (size_t i = 1; i < 4; i++)
			{
					

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
					while (!(choix == 1 || choix == 2))
					{
						printf("Tapez 1 pour croissant ou 2 pour decroissant : ");
						scanf("%d",&choix);
					}
					
					
					for (int i = 0; i < taille; i++)
					{
						fprintf(fichier, "%f ", valeur[i]);
					}
					fprintf(fichier, "\n");
				}

				printf("%ld. Tri a bulle\n",i);
					temps =tempsExecutionAvecTaille(&triBulle,valeurBulle, taille);
					
					// Changement de l'ordre en fonction du choix de l'utilisateur 
					if (choix == 2)
					{
						valeurBulle = inverserTab(valeurBulle, taille);
					}

					printf("temps = %f\n", temps);
					sommeBulle += temps;
					fprintf(fichier, "'Tri a bulle',%f,%d\n", temps, taille);
					// Si le tableau a moins de 10 valeur on affiche le tableau apres l'algorithme de tri
					if (taille < 10)
					{
						for (int i = 0; i < taille; i++)
						{
							fprintf(fichier, "%f ", valeurBulle[i]);
						}
						fprintf(fichier, "\n");
					}
			
				printf("%ld. Tri par selection\n", i+1);
					temps =tempsExecutionAvecTaille(&triSelection,valeurSelection,taille);

					// Changement de l'ordre en fonction du choix de l'utilisateur 
					if (choix == 2)
					{
						valeurSelection = inverserTab(valeurSelection, taille);
					}

					printf("temps = %f\n", temps);
					sommeSelection += temps;
					fprintf(fichier, "'Tri par selection',%f,%d\n", temps, taille);
					// Si le tableau a moins de 10 valeur on affiche le tableau apres l'algorithme de tri
					if (taille < 10)
					{
						for (int i = 0; i < taille; i++)
						{
							fprintf(fichier, "%f ", valeurSelection[i]);
						}
						fprintf(fichier, "\n");
					}
			
				printf("%ld Tri par insertion\n", i+2);
					temps =tempsExecutionAvecTaille(&triInsertion,valeurInsertion,taille);

					// Changement de l'ordre en fonction du choix de l'utilisateur 
					if (choix == 2)
					{
						valeurInsertion = inverserTab(valeurInsertion, taille);
					}

					printf("temps = %f\n", temps);
					sommeInsertion += temps;
					fprintf(fichier, "'Tri par insertion',%f,%d\n", temps, taille);
					// Si le tableau a moins de 10 valeur on affiche le tableau apres l'algorithme de tri
					if (taille < 10)
					{
						for (int i = 0; i < taille; i++)
						{
							fprintf(fichier, "%f ", valeurInsertion[i]);
						}
						fprintf(fichier, "\n");
					}

				printf("%ld. Tri par tas\n", i+3);
					temps = tempsExecutionAvecTaille(&triParTas, valeurTas, taille);

					// Changement de l'ordre en fonction du choix de l'utilisateur 
					if (choix == 2)
					{
						valeurTas = inverserTab(valeurTas, taille);
					}

					printf("temps = %f\n", temps);
					sommeTas += temps;
					fprintf(fichier, "'Tri par tas',%f,%d\n", temps, taille);
					// Si le tableau a moins de 10 valeur on affiche le tableau apres l'algorithme de tri
					if (taille < 10)
					{
						for (int i = 0; i < taille; i++)
						{
							fprintf(fichier, "%f ", valeurTas[i]);
						}
						fprintf(fichier, "\n");
					}
				
				fprintf(fichier, "\n");
			}
			
			// Calcul et écriture de la moyenne 
			moyenneBulle = sommeBulle / indexMaxTableau;
			moyenneInsertion = sommeInsertion / indexMaxTableau;
			moyenneSelection= sommeSelection / indexMaxTableau;
			moyenneTas = sommeTas / indexMaxTableau;
			fprintf(fichier, "\n\n\n");
			fprintf(fichier, " ,TriBulle,TriInsertion,TriSelection,TriTas\n");
			fprintf(fichier, "%d,%f,%f,%f,%f\n",taille, moyenneBulle, moyenneInsertion, moyenneSelection, moyenneTas);

			fclose(fichier);
		}
		
		 //Si utilisateur choisi les tests automatiques.
		 
		 
		else if (fichier != NULL && taille == 0)
		{
			//fprintf(fichier, "NOM,TEMPS,NOMBRE DE VALEURS\n");
			for (int i = 0; i < indexMaxTableau; i++)
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

				for (int j = 0; j < 3; j++)
				{
					/*if (j > 0 || i > 0)
					{
						nombreDeDeplacement = positionActuelle - positionFinTab;
						fseek(fichier, nombreDeDeplacement, SEEK_CUR);
					}*/
					
					remplirTab(valeur, taille);

					copierTab(valeur, valeurBulle);
					copierTab(valeur, valeurInsertion);
					copierTab(valeur, valeurSelection);
					copierTab(valeur, valeurTas);


					printf("1. Tri a bulle\n");
						temps =tempsExecutionAvecTaille(&triBulle,valeurBulle, taille);
						sommeBulle += temps;
						printf("temps = %f\n", temps);
			
					printf("2. Tri par selection\n");
						temps =tempsExecutionAvecTaille(&triSelection,valeurSelection,taille);
						sommeSelection += temps;
						printf("temps = %f\n", temps);
			
					printf("3. Tri par insertion\n");
						temps =tempsExecutionAvecTaille(&triInsertion,valeurInsertion,taille);
						sommeInsertion += temps;
						printf("temps = %f\n", temps);

					printf("4. Tri par tas\n");
						temps = tempsExecutionAvecTaille(&triParTas, valeurTas, taille);
						sommeTas += temps;
						printf("temps = %f\n", temps);
				}
					
				// Calcul et écriture de la moyenne 
				moyenneBulle = sommeBulle / indexMaxTableau;
				moyenneInsertion = sommeInsertion / indexMaxTableau;
				moyenneSelection= sommeSelection / indexMaxTableau;
				moyenneTas = sommeTas / indexMaxTableau;

				if (i == 0)
				{
					fprintf(fichier, " ,TriBulle,TriInsertion,TriSelection,TriTas\n");
					fprintf(fichier, "%d,%f,%f,%f,%f\n",taille, moyenneBulle, moyenneInsertion, moyenneSelection, moyenneTas);

				}
				else{
					fprintf(fichier, "%d,%f,%f,%f,%f\n",taille, moyenneBulle, moyenneInsertion, moyenneSelection, moyenneTas);
				}
				
			}

			fclose(fichier);
		}
		
		else
		{
			printf("Impossible d'ouvrir le fichier %s",argv[1]);
		}

	}
	
	 
	 
	// Si l'utilisateur n'a pas rentré d'argument.
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

