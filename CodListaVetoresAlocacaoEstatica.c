// Implementação de uma lista simples com alocação estática (vetores)
// As operações implementadas são:
// - Inserir um elemento na lista
// - Retirar um elemento da lista
// - Contar o número de elementos da lista
// - Imprimir os elementos da lista
// - Criar uma lista vazia

#include <stdio.h>
#include <string.h>

#define MaxItens 10     // Número máximo de itens da lista 
#define TamItem 20      // Tamanho máximo de cada item da lista

// Definição do tipo tpLista. 
// Uma matriz de caracteres onde cada linha contém um item
typedef char tpLista[MaxItens][TamItem];

// Operação para inserir o elemento "item" na lista "l"
void insereLista(tpLista l, char *item)
{
	int i;
	
    // Laço que percorre a lista até encontrar o primeiro elemento vazio
    // (com tamanho = 0), ou ultrapassar o espaço alocado para a lista
	for(i=0; i<MaxItens && strlen(l[i])>0; i++);
    
    // Testa se ainda tem espaço na lista 
	if (i<MaxItens)
	{
	   strcpy(l[i],item); // copia o item para a posição vazia da lista
	   printf("\nItem (%s) inserido com sucesso",item);
	}
	else // Não tem espaço na lista
	   printf("\nLista cheia, não pode inserir");
}



// Operação que retira o elemento "item" da lista "l"
void retiraLista(tpLista l, char *item)
{
	int i;
	
    // Procura o elemento "item" na lista. 
    // Encerra a busca se chegar ao final do espaço, ou 
    //                 se encontrar um elemento vazio, ou
    //                 se encontrar o elemento "item"
	for(i=0; i<MaxItens && strlen(l[i])>0 && (strcmp(l[i],item) != 0); i++);
	
    // Pode ter saído do laço por três razões. Descobre qual
    if (strcmp(l[i],item) == 0)   
    {  // Encontrou o elemento buscado
	   printf("\nItem (%s) encontrado, removendo",item);
	   if (i < (MaxItens-1)) 
       { // Tem outros elementos depois dele, puxa todos para cima
	       for (;i<(MaxItens-1) && strlen(l[i])>0;i++)
	           strcpy(l[i],l[i+1]);
	   }
       // Zera o último elemento do espaço da lista
       l[MaxItens-1][0] = '\0';
	}
	else // Não encontrou o elemento buscado
	   printf("\nItem (%s) não encontrado",item);
}


// Operação que retorna o comprimento da lista (número de itens contidos)
int contaLista(tpLista l)
{
	int i;
	
    // Percorre a lista, até chegar ao final do espaço
    //                   ou encontrar um elemento vazio (tamanho = 0)
	for (i = 0; i<MaxItens && strlen(l[i])>0; i++);
    
    // Retorna a posição do elemento vazio, ou MaxItens, que equivale
    //   ao número de elementos na lista.
	return(i);
}	


// Operação que imprime todos os elementos da lista
void imprimeLista(tpLista l)
{
	int i;
	
	printf("\nItens da lista\n");
	for(i=0; i<MaxItens && strlen(l[i])>0; i++)
		printf("\n%s",l[i]);
	printf("\n");
}

// Operação que inicializa a lista (todos os elementos vazios)
void criaLista(tpLista l)
{
	int i;

	for (i=0;i<MaxItens;i++)
	   l[i][0] = '\0';
}

// Função que lê um string "s", com tamanho máximo tam, retirando o "\n"
void leString(char *s, int tam)
{
	fgets(s,tam,stdin);
	s[strlen(s)-1] = '\0';
}

// Programa principal
int main()
{
	tpLista Lista;
	int op;
	int cont;
	char item[20];
	char opcao[10];
	
	criaLista(Lista);
	op = 1;
	while (op != 0) {
		printf("\nLista de strings com alocação estática");
		printf("\n\n1 - Inserir item");
		printf("\n2 - Imprimir lista");
		printf("\n3 - Retirar item");
		printf("\n4 - Tamanho da lista");
		printf("\n0 - Encerrar\n");
		printf("\nOpção: ");
		leString(opcao,8);
		sscanf(opcao,"%d",&op);
		switch(op) {
			case 1: printf("\nEntre com o item a inserir : ");
				leString(item,TamItem);
				insereLista(Lista,item);
				break;
			case 2: imprimeLista(Lista);
				break;
			case 3: printf("\nEntre com o item a retirar : ");
				leString(item,TamItem);
				retiraLista(Lista,item);
				break;
			case 4: cont = contaLista(Lista);
			        printf("\nA lista tem %d itens",cont);
				break;
			case 0: break;
			default: printf("\nOpcao invalida");
		}
	}
}

