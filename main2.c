

// main2.c
// Exercice, générateur de numèro euromillion (type loto flash)

// Créer une fonction de type 'void' pour la génération aléatoire des  5 numéros. 
// Créer une fonction de type 'void' pour la génération aléatoire des  2 étoiles. 
//
// Une demande de validation de l'utilisateur pour lancer le programme. ok
// Probleme : certains numéros peuvent etres identiques...
// Trouver une sulotion pour éviter les doublons. ok
// 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateurNumeros(int tab[5]);
void generateurEtoiles(int tab[2]);
void ordonner(int T[],int taille);



int main(int argc, char *argv[])

{
    int numeros[5] = {0};
    int etoiles[2] = {0};

    printf("\n\n==== Mes numéros Euromillion ====\n\n");
    printf("Pour générer les numéros de l'euromillion appuyez sur Entrer");
    getchar();

topFuncNumeros:
    generateurNumeros(numeros); 
    ordonner(numeros, 5);

    if (numeros[0] == numeros[1] || numeros[0] == numeros[2] || numeros[0] == numeros[3] || numeros[0] == numeros[4] || numeros[1] == numeros[2] || numeros[1] == numeros[3] || numeros[1] == numeros[4] || numeros[2] == numeros[3] || numeros[2] == numeros[4] || numeros[2] == numeros[4] || numeros[3] == numeros[4]){
        //printf("\n\n=== Erreur ===\nAu moins deux chiffres identiques\n\n %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
       goto topFuncNumeros; // Si nombre en double, alors retour à l'étiquette topFunctiontab
    }

    printf("\nJouez les 5 numéros suivants : %d-%d-%d-%d-%d\n", numeros[0], numeros[1], numeros[2], numeros[3], numeros[4]);


topFuncEtoiles:
    generateurEtoiles(etoiles);

    if (etoiles[0] == etoiles[1])
    {
        //printf("DOUBLE !!! %d-%d\n", tab[0], tab[1]);
        goto topFuncEtoiles;
    }

    else {
        printf("\nAvec les deux étoiles suivantes : %d-%d\n\n", etoiles[0], etoiles[1]);
    }
    

    
  

   
    return 0;
} 

//*************  Fonction numéros  *******************

void generateurNumeros(int tab[5])
{
    const int MAX = 50 - 2, MIN = 1;
    
     srand(time(NULL));
    
        tab [0] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [1] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [2] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [3] = (rand() % (MAX - MIN + 1)) + MIN;
        tab [4] = (rand() % (MAX - MIN + 1)) + MIN;
   
}

//***********  Fonction etoiles  **********************

void generateurEtoiles(int tab[2])
{
    
    srand(time(NULL));
    topFuncEtoiles: // Etiquette goto

    tab[0] = 1+ rand() % 12;
    tab[1] = 1+ rand() % 12;

}

//***********  Fonction Ordonner  **********************

void ordonner(int T[],int taille)
{
int i,j,p=0;
for(j=0;j<taille;j++)
{
for(i=0;i<taille;i++)
{
        do{
            p=T[i];

            T[i]=T[i+1];

            T[i+1]=p;

          }while(T[i]>T[i+1]);
}
}
}

