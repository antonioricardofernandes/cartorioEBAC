#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //

int registra()
{
	//cria��o das variaveis
	char arquivo[40];
	char cpf[14];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Qual o CPF vai ser cadastrado?\n"); //coleta de informa��o
	scanf("%s", cpf); //referente a string
	
	strcpy(arquivo, cpf); //respos�vel por copiar os valores das strings
	
	FILE *arq; //cria o arquivo
	arq = fopen(arquivo, "w"); //salva o arquivo "W" grava
	fprintf (arq, cpf); //grava o arquivo
	fclose (arq); //fecha o arquivo
	
	arq = fopen(arquivo, "a");
	fprintf (arq," | ");
	fclose (arq);
	
	printf("Qual o nome a ser cadastrado?\n");
	scanf("%s", nome);
	
	arq = fopen(arquivo,"a");
	fprintf (arq, nome);
	fclose (arq);
	
	arq = fopen(arquivo, "a");
	fprintf (arq, " | ");
	fclose (arq);
	
	printf("Agora escreva o sobrenome?\n");
	scanf("%s", sobrenome);
	
	arq = fopen(arquivo,"a");
	fprintf (arq, sobrenome);
	fclose (arq);
	
	arq = fopen(arquivo, "a");
	fprintf (arq, " | ");
	fclose (arq);
	
	printf("Por favor informe o cargo?\n");
	scanf("%s", cargo);
	
	arq = fopen(arquivo,"a");
	fprintf (arq, cargo);
	fclose (arq);
	
	system("pause");
	
}

int consulta()
{
	
	setlocale(LC_ALL, "portuguese"); //localiza��o
	
	//variaveis criadas
	char cpf[14];	
	char conteudo [200];
	
	printf("Digite aqui o CPF que deseja consultar: ");
	scanf("%s",cpf);  //referencia da string
	
	FILE *arq;
	arq = fopen(cpf, "r"); //leitura do arquivo "r".
	
	if(arq == NULL)
	{
		printf("CPF n�o localizado, verifique o n�mero informado e tente novamente!\n");
	}	
	
	while(fgets(conteudo, 200, arq) != NULL)	
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deleta()
{
	char cpf[14];
	
	printf("Digite o CPF do usu�rio que desejar deletar: \n");
	scanf("%s",cpf);
			
	FILE *arq;
	arq = fopen (cpf, "r");
	fclose(arq);
	
	if(arq == NULL)
	{
		printf("O CPF digitado n�o pertence a um usu�rio cadastrado.\n\n");
	}
	else 
	{	
	remove(cpf); 	
	printf("Usu�rio deletado com sucesso! \n\n");	
	}
			
	 	system("pause");		
}


int main()
{
	
	int opcao=0;
	int laco =1;
		
	for(laco=1;laco=1;)
{
	
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "portuguese");
	
		printf(">>> Cart�rio de Alunos da EBAC <<<\n\n");
		printf(" Escolha a op��o desejada no menu abaixo: \n\n");
		printf("\t1 - Registrar alunos\n");
		printf("\t2 - Consultar alunos\n");
		printf("\t3 - Deletar alunos\n\n\n");
		printf("Op��o:");
	
	
		scanf("%d", &opcao);
	
		system("cls");
	
		switch(opcao)
	
{
	
	case 1:
		registra(); //chamada de fun��o
		
	break;
	
	case 2: 
		consulta();
	break;
	
	case 3:
		deleta();
	break;
		
	default:
		printf("Voc� escolheu uma op��o inv�lida.\n\n");
		system("pause");
	break;
}
}
}



