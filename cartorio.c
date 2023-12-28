#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //

int registra()
{
	//criação das variaveis
	char arquivo[40];
	char cpf[14];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Qual o CPF vai ser cadastrado?\n"); //coleta de informação
	scanf("%s", cpf); //referente a string
	
	strcpy(arquivo, cpf); //resposável por copiar os valores das strings
	
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
	
	setlocale(LC_ALL, "portuguese"); //localização
	
	//variaveis criadas
	char cpf[14];	
	char conteudo [200];
	
	printf("Digite aqui o CPF que deseja consultar: ");
	scanf("%s",cpf);  //referencia da string
	
	FILE *arq;
	arq = fopen(cpf, "r"); //leitura do arquivo "r".
	
	if(arq == NULL)
	{
		printf("CPF não localizado, verifique o número informado e tente novamente!\n");
	}	
	
	while(fgets(conteudo, 200, arq) != NULL)	
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deleta()
{
	char cpf[14];
	
	printf("Digite o CPF do usuário que desejar deletar: \n");
	scanf("%s",cpf);
			
	FILE *arq;
	arq = fopen (cpf, "r");
	fclose(arq);
	
	if(arq == NULL)
	{
		printf("O CPF digitado não pertence a um usuário cadastrado.\n\n");
	}
	else 
	{	
	remove(cpf); 	
	printf("Usuário deletado com sucesso! \n\n");	
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
	
		printf(">>> Cartório de Alunos da EBAC <<<\n\n");
		printf(" Escolha a opção desejada no menu abaixo: \n\n");
		printf("\t1 - Registrar alunos\n");
		printf("\t2 - Consultar alunos\n");
		printf("\t3 - Deletar alunos\n");
		printf("\t4 - Sair\n\n");
		printf("Opção:");
	
	
		scanf("%d", &opcao);
	
		system("cls");
	
		switch(opcao)
	
{
	
	case 1:
		registra(); //chamada de função
		
	break;
	
	case 2: 
		consulta();
	break;
	
	case 3:
		deleta();
	break;
	
	case 4:
		printf("Obrigado, até a próxima!\n");
		return 0;
	break;
		
	default:
		printf("Você escolheu uma opção inválida.\n\n");
		system("pause");
	break;
}
}
}



