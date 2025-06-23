#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das variaveis/string
	char arquivo[40];//n�mero de caracteres a ser cadastrado
	char cpf[40];//n�mero de caracteres a ser cadastrado
	char nome[40];//n�mero de caracteres a ser cadastrado
	char sobrenome[40];//n�mero de caracteres a ser cadastrado
	char cargo[40];//n�mero de caracteres a ser cadastrado
	//final da cria��o das variaveis/string
	
	printf("Digite o CPF a ser procurado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,",");//o "," serve pra escrever uma v�rgula no registro
	fclose(file);//fechar o arquivo
	
	printf("Digite o seu primeiro nome aqui: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,",");//o "," serve pra escrever uma v�rgula no registro
	fclose(file);//fecha o arquivo
	
	printf("Digite o seu sobrenome aqui: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,",");//o "," serve pra escrever uma v�rgula no registro
	fclose(file);//fecha o arquivo
	
	printf("Digite o seu cargo aqui: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa armazenar
	fprintf(file, cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];//n�mero de caracteres a ser cadastrado
	char conteudo[500];//n�mero de caracteres a ser cadastrado
	
	printf("Digite o CPF que dejesa consultar: ");
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");//abra o arquivo e "r" pra ler o arquivo
	
	if(file == NULL)//caso o usu�rio n�o seja encontrado
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 500, file) != NULL)//abra o arquivo e procura entre o valor do case colodado
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	system("pause");
}

int main()
{
	char cpf[40];
	
	printf("Digitar o CPF a ser deletado");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//se for NULL, o arquivo foi deletado
	{
		printf("O usu�rio foi deletado com sucesso!.\n");
		system("pause");
	}
	
	 //para repetir blocos de c�digo
	do {
		printf("Executando uma vez\n");
	} while (0);
	{ 
		
		setlocale(LC_ALL, "Portuguese");//definido a linguagem
		
		printf("### Cart�rio EBAC ###\n\n");//inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("op��o: ");//final do menu
		
		//armazenamnto a escolha do usu�rio
		
		system("cls");//respons�vel por limpar a tela

		switch(opcao)//inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;//pro "case" funciona como um pause
			
			case 2:
			consulta();//chamada de fun��es
			break;//pro "case" funciona como um pause
			
			case 3:
			deletar();//chamada de fun��es
			break;//pro "case" funciona como um pause
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
}
}
