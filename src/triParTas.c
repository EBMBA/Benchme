#include <stdio.h>
#include "../include/fonctionsSupplementaires.h"

void tamiser(float tableauATamiser[], int noeud, int longueur){
    int j = 2*noeud;
    while (j <= longueur)
    {
        if ((j < longueur) && (tableauATamiser[j] < tableauATamiser[j+1]))
        {
            j++;
        }
        else if (tableauATamiser[noeud] < tableauATamiser[j])
        {
            float temp = tableauATamiser[noeud];
            tableauATamiser[noeud] = tableauATamiser[j];
            tableauATamiser[j] = temp;
            noeud = j;
            j = 2*noeud;
        }
        else {
            j = longueur+1;
        }         
    }
}

void triParTas(float tableauATrier[], int taille){
    for (int i = taille/2 - 1; i >= 0; i--)
    {
        tamiser(tableauATrier, i, taille);
    }
    for (int i = taille - 1; i >= 0 ; i--)
    {
        float temp = tableauATrier[0];
        tableauATrier[0] = tableauATrier[i];
        tableauATrier[i] = temp;
        tamiser(tableauATrier, 0, i-1);
    }
}