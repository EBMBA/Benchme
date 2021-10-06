#include <stdlib.h>
#include <stdio.h>

void afficheMenu(){
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
    switch (choix)
        {
        case 1:
            printf("1. Tri a bulle\n");
            
            break;

        case 2:
            printf("2. Tri par selection\n");
            
            break;
        
        case 3:
            printf("3. Tri par insertion\n");
            
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

char *inverserTab(float *Tab){
    float *tableauInverser = NULL;
    unsigned int i = obtenirTaille(Tab);
    //printf("%d", i);
    tableauInverser = malloc(i * sizeof(float));

    // inversion
    i--;
    unsigned int p = i;
    for (unsigned int n = 0; n <= p; n++)
    {
        tableauInverser[n] = Tab[i];
        //printf("Resultat : %s\nInversion Resultat : %s\n",Tab, tableauInverser);
        i--; 
    }

    return tableauInverser;
}