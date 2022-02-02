#include <stdio.h>
#define max 10


void merge(int *vet, int *aux, int esq, int meio, int dir) 
{
   int l1, l2, i;

   for(l1=esq,l2=meio+1,i=esq; l1<=meio && l2<=dir; i++) 
   {
      if(vet[l1] <= vet[l2])
         aux[i] = vet[l1++];
      else
         aux[i] = vet[l2++];
   }
   while(l1 <= meio)    
      aux[i++] = vet[l1++];
   while(l2 <= dir)   
      aux[i++] = vet[l2++];
   for(i = esq; i <= dir; i++)
      vet[i] = aux[i];
}

void mergeSort(int *vet, int *aux, int esq, int dir) 
{
   int meio;
   
   if(esq < dir) 
   {
      meio = (esq + dir) / 2;
      mergeSort(vet, aux, esq, meio);
      mergeSort(vet, aux, meio+1, dir);
      merge(vet, aux, esq, meio, dir);
   }  
}

int main() 
{ 

   int vet[10] = {26,27,4,19,33,35,31,10,142,44};
   int aux[10];

   int i;

   printf("Vetor antes de ordenar\n");
   
   for(i = 0; i < max; i++)
      printf("%d ", vet[i]);

   mergeSort(vet, aux, 0, max-1);

   printf("\nVetor depois de ordenar\n");
   
   for(i = 0; i < max; i++)
      printf("%d ", vet[i]);
}

