#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>


struct ender 
{
	char rua[50];
	int numero;
	char complemento[15];
	char bairro[30];
	char cidade[30];
	char UF[4];
	char CEP[10];
};

struct aluno
{
	char nome[50];
	int matricula;
	char nascimento[12];
	char sexo;
	char telefone[20];
	//long int telefone;
	struct ender endereco;
};

struct aluno cadastro[50];

void tiraf(char *s)
{
	s[strlen(s)-1] = '\0';
}

void leString(char *s, int tam)
{
	__fpurge(stdin);
	fgets(s,tam,stdin);
	tiraf(s);
}

struct aluno leAluno()
{
	struct aluno a;			// Declara uma variável a que conterá uma estrutura aluno
	char buffer[100];
	
	// Leitura dos dados da estrutura aluno
	printf("\nNome:");
	leString(a.nome,sizeof(a.nome));
	printf("\nMatricula:");
	leString(buffer,sizeof(buffer));
	sscanf(buffer,"%d",&a.matricula);
	printf("\nData de nascimento (DD/MM/AAAA):");
	leString(a.nascimento, sizeof(a.nascimento));
	printf("\nSexo: ");
	leString(buffer, sizeof(buffer));
	a.sexo = buffer[0];
	printf("\nTelefone:");
	leString(a.telefone,sizeof(a.telefone));
	//sscanf(buffer,"%ld",&a.telefone);
	printf("\nRua: ");
	leString(a.endereco.rua, sizeof(a.endereco.rua));
	printf("\nNúmero: ");
	leString(buffer,6);
	// Leitura dos dados da estrutura endereço
	sscanf(buffer,"%i",&a.endereco.numero);
	printf("\nComplemento: ");
	leString(a.endereco.complemento,sizeof(a.endereco.complemento));
	printf("\nBairro: ");
	leString(a.endereco.bairro,sizeof(a.endereco.bairro));
	printf("\nCidade: ");
	leString(a.endereco.cidade,sizeof(a.endereco.cidade));
	printf("\nUF: ");
	leString(a.endereco.UF,sizeof(a.endereco.UF));
	printf("\nCEP: ");
	leString(a.endereco.CEP,sizeof(a.endereco.CEP));
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
			fwrite(&cadastro[j], sizeof(struct aluno),1,arq);
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
			lido = fread(&cadastro[j], sizeof(struct aluno),1,arq);
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
		printf("\n%d - %s - Sexo(%c) - Nasc. %s - Fone: %s",cadastro[j].matricula,cadastro[j].nome, cadastro[j].sexo ,cadastro[j].nascimento, cadastro[j].telefone);
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
		

int main()
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
	

