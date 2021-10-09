/**
 * @file tempsExecution.c
 * @author KAPLAN Kubilay & METRAL Emile 
 * @brief Fonctions permettant de calculer le temps d\'execution des algorithmes de tri
 * @version 0.1
 * @date 2021-10-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * @brief Creation de deux types de fonction. 
 * 
 */
typedef void (*algotithme)(float *);
typedef void (*algotithmeAvecTaille)(float *, int);

/**
 * @brief Calcul du temps d\'execution d'un algorithme
 * 
 * @param fonctionTri Algorithme de tri que l\'on veut utiliser.
 * @param tableauATrier Tableau que l\'on veut trier.
 * @return float  qui est le temps d\'execution de l\'algorithme.
 */
float tempsExecution(algotithme fonctionTri,float * tableauATrier){
    // Declaration des variables
    clock_t debut, fin;
    float temps = 0.0;

    // Lancement de l'algorithme 
    debut = clock();
    fonctionTri(tableauATrier);
    fin = clock();

    // Calcul du temps d'execution
    temps = (float)(fin-debut)/CLOCKS_PER_SEC;

    return temps;
}


/**
 * @brief Calcul du temps d\'execution d\'un algorithme qui prend en plus la taille du tableau en parametre.
 * 
 * @param fonctionTri Algorithme de tri que l\'on veut utiliser.
 * @param tableauATrier Tableau que l\'on veut trier.
 * @param taille Taille du tableau que l\'on veut trier.
 * @return float qui est le temps d\'execution de l\'algorithme.
 */
float tempsExecutionAvecTaille(algotithmeAvecTaille fonctionTri,float * tableauATrier, int taille){
    // Declaration des variables
    clock_t debut, fin;
    float temps = 0.0;

    // Lancement de l'algorithme 
    debut = clock();
    fonctionTri(tableauATrier, taille);
    fin = clock();

    // Calcul du temps d'execution
    temps = (float)(fin-debut)/CLOCKS_PER_SEC;

    return temps;
}