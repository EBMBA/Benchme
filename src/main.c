#include <stdlib.h>
#include <stdio.h>
#include "../include/fonctionsSupplementaires.h"

int main()
{
	// Partie des declarations des variables:
    float *valeur;
    int resultat = 0, choix = 0;
    // Partie du choix de la conversion :
	do
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
	} while (choix != 5);
	
	printf("Thank you :D Goodbye !\n");

	return (0);
}