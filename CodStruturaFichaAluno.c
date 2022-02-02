#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ficha_de_aluno
{
 char nome[50];
 char disciplina[30];
 float nota_prova1;
 float nota_prova2;
};
struct ficha_de_aluno aluno;

int main(void)
{
 /*Criando a struct */
 struct ficha_de_aluno
 {
 char nome[50];
 char disciplina[30];
 float nota_prova1;
 float nota_prova2;
 };

 /*Criando a variável aluno que será do
 tipo struct ficha_de_aluno */
 struct ficha_de_aluno aluno;

 printf("\n-------- Cadastro de aluno ---------\n\n\n");

 printf("Nome do aluno ......: ");
 fflush(stdin);

 /* usaremos o comando fgets() para ler strings, no caso o nome
 do aluno e a disciplina
 fgets(variavel, tamanho da string, entrada)
 como estamos lendo do teclado a entrada é stdin
 (entrada padrão), porém em outro caso, a entrada tambem
 poderia ser um arquivo
 */

 fgets(aluno.nome, 40, stdin);

 printf("Disciplina ......: ");
 fflush(stdin);
 fgets(aluno.disciplina, 40, stdin);

 printf("Informe a 1a. nota ..: ");

 scanf("%f", &aluno.nota_prova1);

 printf("Informe a 2a. nota ..: ");
 scanf("%f", &aluno.nota_prova2);

 printf("\n\n ------- Lendo os dados da struct -------\n\n");
 printf("Nome ...........: %s", aluno.nome);
 printf("Disciplina .....: %s", aluno.disciplina);
 printf("Nota da Prova 1 ...: %.2f\n" , aluno.nota_prova1);
 printf("Nota da Prova 2 ...: %.2f\n" , aluno.nota_prova2);

 return(0);
}



struct ficha_de_aluno cadastro[50];

void tiraf(char *s)
{
	s[strlen(s)-1] = '\0';
}

void leString(char *s, int tam)
{
	
	fgets(s,tam,stdin);
	tiraf(s);
}

struct ficha_de_aluno leAluno()
{
	struct ficha_de_aluno a;			// Declara uma variável a que conterá uma estrutura aluno
	char buffer[100];
	
	// Leitura dos dados da estrutura aluno
	printf("\nNome:");
	leString(a.nome,sizeof(a.nome));
	printf("\nMatricula:");
	leString(buffer,sizeof(buffer));
	
	return a;
}

int salvaCadastro(int i)
{
	FILE *arq;
	int j;
	
	arq = fopen("alunos.txt","w");
	if (arq == NULL) 
	{
		fprintf(stderr,"\nErro ao abrir arquivo alunos.txt");
		return (1);
	}
	else
	{
        for (j = 0; j < i; j ++) {
			fwrite(&cadastro[j], sizeof(struct ficha_de_aluno),1,arq);
		}
    	fclose(arq);
	}
	return (0);
}

int leCadastro()
{
	char buffer[100];
	char continua;
	int i;
	
	i = 0;
	do {
		cadastro[i] = leAluno();
		
		printf("\nJá foram lidos %d alunos. Deseja continuar (s/n):",i+1);
		leString(buffer,sizeof(buffer));
		continua = buffer[0];
		i++;
		printf("Continua = %c",continua);
	}
	while ((continua == 's') && (i<50));
	
	return i;
}

int carregaCadastro()
{
	FILE *arq;
	int j, lido;
	
	arq = fopen("alunos.txt","r");
	if (arq == NULL) 
	{
		fprintf(stderr,"\nErro ao abrir arquivo alunos.txt");
		return (-1);
	}
	else
	{
		j = 0;
        do {
			lido = fread(&cadastro[j], sizeof(struct ficha_de_aluno),1,arq);
			j++;
		} while (lido == 1);
    	fclose(arq);
	}
	return (j-1);
}

void listaCadastro(int i)
{
	int j;
	
	for (j=0 ; j<i; j++)
	{
		printf("\n%d - %s - Sexo(%c) - Nasc. %s - Fone: %s",cadastro[j]., cadastro[j].);
	}
}

int menu()
{
	int op;
	
	do {
		printf("\n1 - Carrega o Cadastro de Alunos");
		printf("\n2 - Cadastrar Alunos");
		printf("\n3 - Salva o Cadastro de Alunos");
		printf("\n4 - Listar o Cadastro de Alunos");
		printf("\n0 - Encerra");
		printf("\n\n Entre com a opção: ");
		scanf("%d",&op);
	} while ((op < 0) || (op > 4));
	return (op);
}
		

int main(void)
{
	int numAlunos, codigo, opcao;
	
	numAlunos = 0;
	do {
		opcao = menu();
		switch (opcao) {
			case 1: numAlunos = carregaCadastro();
                    printf("\nNumero de Alunos = %d",numAlunos);
			        break;
			case 2: numAlunos = leCadastro();
					break;
			case 3: codigo = salvaCadastro(numAlunos);
					if (codigo == 0) 
						printf("\nCadastro salvo com sucesso");
					break;
			case 4: listaCadastro(numAlunos);
					break;
		}
	} while (opcao != 0);
	return codigo;
}
