


// 
// Code récupéré sur le net

#include <stdio.h>
#include <stdlib.h>
/*void ordonner(int T[],int);

int main(int argc, char *argv[])
{
int T[5]={7,4,5,3,8},i;

ordonner(T,5);
for(i=0;i<5;i++)
{
printf("T[%d]=%d\n",i,T[i]);
}
system("pause");
return 0;
}*/



void ordonner(int T[],int taille)
{
int i,j,p=0;
for(j=0;j<taille;j++)
{
for(i=0;i<taille;i++)
{
do
{
p=T[i];

T[i]=T[i+1];

T[i+1]=p;

}while(T[i]>T[i+1]);
}
}
}