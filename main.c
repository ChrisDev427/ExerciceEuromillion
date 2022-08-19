

// main2.c
// Exercice, générateur de numèro euromillion (type loto flash)

// Créer une fonction de type 'int' pour la génération aléatoire des  5 numéros. 
// Créer une fonction de type 'int' pour la génération aléatoire des  2 étoiles. 
//
// Une demande de validation de l'utilisateur pour lancer le programme. 
// Probleme : certains numéros peuvent etres identiques.
// Trouver une sulotion pour éviter les doublons. 
// 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//...
int generateurNumeros(int tab[5]);
int generateurEtoiles(int tab[2]);


int main(int argc, char *argv[])
{
    int numeros[5] = {0};
    int etoiles[2] = {0};

    printf("\n\n==== Mes numéros Euromillion ====\n\n");
    printf("Pour générer les numéros de l'euromillion appuyez sur Entrer");
    getchar();
    
    generateurNumeros(numeros);
    generateurEtoiles(etoiles);
  
    return 0;
} 

// Fonction numéros

int generateurNumeros(int tab[5])
{
    const int MAX = 50 - 2, MIN = 1;
    
     srand(time(NULL));
     topFuncNumeros: // Etiquette goto
        tab [0] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [1] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [2] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [3] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [4] = (rand() % (MAX - MIN + 1)) + MIN;
        

       
    

    if (tab[0] == tab[1] || tab[0] == tab[2] || tab[0] == tab[3] || tab[0] == tab[4] || tab[1] == tab[2] || tab[1] == tab[3] || tab[1] == tab[4] || tab[2] == tab[3] || tab[2] == tab[4] || tab[2] == tab[4] || tab[3] == tab[4]){
        //printf("\n\n=== Erreur ===\nAu moins deux chiffres identiques\n\n %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
       goto topFuncNumeros; // Si nombre en double, alors retour à l'étiquette topFunNumeros.
    }

    
    
    else {
        
        printf("\nJouez les 5 numéros suivants : %d-%d-%d-%d-%d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
    }

    return 0;  
}

// Fonction etoiles

int generateurEtoiles(int tab[2])
{
    
    srand(time(NULL));
    topFuncEtoiles: // Etiquette goto

    tab[0] = 1+ rand() % 12;
    tab[1] = 1+ rand() % 12;

    if (tab[0] == tab[1])
    {
        //printf("DOUBLE !!! %d-%d\n", tab[0], tab[1]);
        goto topFuncEtoiles;
    }

    else {
        printf("\nAvec les deux étoiles suivantes : %d-%d\n\n", tab[0], tab[1]);
    }

    return 0;

}