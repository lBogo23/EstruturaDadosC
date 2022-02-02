#include <stdio.h>
#include <string.h>

#define TAM_VETOR 10

int leInt()
{
	int ret;
	char s[10];
	
	fgets(s,10,stdin);
	s[strlen(s)-1] = '\0';
	sscanf(s,"%d",&ret);
	return ret;
}

void bubbleSort(int *vet, int n)
{
   int i, j, trocou, aux;
   j=1;
   trocou=1;
   while ((j<n) && trocou)
   {
      trocou=0;
      for(i=0; i<(n-j); i++)
      {
         if(vet[i]>vet[i+1])
         {
            aux= vet[i];
            vet[i]=vet[i+1];
            vet[i+1]=aux;
            trocou=1;
         }
      }
      j++;
   }
}


int main(void)
{
    int vetor[TAM_VETOR];
    int i;
    
    for (i=0;i<TAM_VETOR;i++)
    {
        printf("\nvetor[%d]: ",i);
        vetor[i]=leInt();
    }
    printf("\nAntes da ordenação:\n");
    for (i=0;i<TAM_VETOR;i++)
    {
        printf("%.2d[%.2d]\n",i,vetor[i]);
    }
    bubbleSort(vetor,TAM_VETOR);
    printf("\nDepois da ordenação:\n");
    for (i=0;i<TAM_VETOR;i++)
    {
        printf("%.2d[%.2d]\n",i,vetor[i]);
    }
    return 0;
}



