#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //

int novocpf;
int novaconsulta;
int novodelete;

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
	
	system("cls");
	
	printf("\nDeseja cadastrar um novo usu�rio?\n\n\n");
	
	printf(" Escolha a op��o desejada no menu abaixo: \n\n");
	printf("\t1 - Registrar novo aluno\n");
	printf("\t2 - Voltar ao Menu Principal\n");
	scanf("%d", &novocpf);
	
	switch(novocpf)
{
	case 1: 
	system("cls");
	registra();
	break;
	case 2: 
	system("cls");
	printf("Retornando ao menu principal.\n");
	system("pause");
	break;
	
	default:
		system("cls");
		printf("Op��o inv�lida.\n");
		system("pause");
	break;
}	
	

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
		printf("CPF n�o localizado, verifique o n�mero informado e tente novamente!\n\n");
	}	
	
	while(fgets(conteudo, 200, arq) != NULL)	
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	system("cls");
	
	printf("\nDeseja consultar um novo usu�rio?\n\n\n");
	
	printf(" Escolha a op��o desejada no menu abaixo: \n\n");
	printf("\t1 - Consultar novo aluno\n");
	printf("\t2 - Voltar ao Menu Principal\n");
	scanf("%d", &novaconsulta);
	
	switch(novaconsulta)
{
	case 1: 
	system("cls");
	consulta();
	break;
	
	case 2:
	system("cls");
	printf("Retornando para o menu principal.\n");
	system("pause");
	break; 
	
	default:
		system("cls");
		printf("Op��o inv�lida, retornando ao menu principal.\n");
		system("pause");	
	break;
}	
	
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
		system("cls");
	 		printf("\nDeseja deletar um novo usu�rio?\n\n\n");
	
	printf(" Escolha a op��o desejada no menu abaixo: \n\n");
	printf("\t1 - Deletar novo aluno\n");
	printf("\t2 - Voltar ao Menu Principal\n");
	scanf("%d", &novodelete);
	
	switch(novodelete)
{
	case 1: 
	system("cls");
	deleta();
	break;
	
	case 2:
	system("cls");
	printf("Retornando para o menu principal.\n");
	system("pause");
	break;
	
	default:
		system("cls");
		printf("Op��o inv�lida, retornando ao menu principal.\n");
		system("pause");	
	break;
}			
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
		printf("\t3 - Deletar alunos\n");
		printf("\t4 - Sair\n\n");
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
	
	case 4:
		printf("Obrigado, at� a pr�xima!\n");
		return 0;
	break;
		
	default:
		printf("Voc� escolheu uma op��o inv�lida.\n\n");
		system("pause");
	break;
}
}
}

