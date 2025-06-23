#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bibioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação das variaveis/string
	char arquivo[40];//número de caracteres a ser cadastrado
	char cpf[40];//número de caracteres a ser cadastrado
	char nome[40];//número de caracteres a ser cadastrado
	char sobrenome[40];//número de caracteres a ser cadastrado
	char cargo[40];//número de caracteres a ser cadastrado
	//final da criação das variaveis/string
	
	printf("Digite o CPF a ser procurado: ");//coletando informações do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,",");//o "," serve pra escrever uma vírgula no registro
	fclose(file);//fechar o arquivo
	
	printf("Digite o seu primeiro nome aqui: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,",");//o "," serve pra escrever uma vírgula no registro
	fclose(file);//fecha o arquivo
	
	printf("Digite o seu sobrenome aqui: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo e o "a" significa armazenar
	fprintf(file,",");//o "," serve pra escrever uma vírgula no registro
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
	
	char cpf[40];//número de caracteres a ser cadastrado
	char conteudo[500];//número de caracteres a ser cadastrado
	
	printf("Digite o CPF que dejesa consultar: ");
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");//abra o arquivo e "r" pra ler o arquivo
	
	if(file == NULL)//caso o usuário não seja encontrado
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 500, file) != NULL)//abra o arquivo e procura entre o valor do case colodado
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
int deletar()
{
	printf("Você escolheu deletar nomes!\n");
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
		printf("O usuário foi deletado com sucesso!.\n");
		system("pause");
	}
	
	 //para repetir blocos de código
	do {
		printf("Executando uma vez\n");
	} while (0);
	{ 
		
		setlocale(LC_ALL, "Portuguese");//definido a linguagem
		
		printf("### Cartório EBAC ###\n\n");//inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("opção: ");//final do menu
		
		//armazenamnto a escolha do usuário
		
		system("cls");//responsável por limpar a tela

		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;//pro "case" funciona como um pause
			
			case 2:
			consulta();//chamada de funções
			break;//pro "case" funciona como um pause
			
			case 3:
			deletar();//chamada de funções
			break;//pro "case" funciona como um pause
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("essa opção não está disponivel!\n");
			system("pause");
			break;
		}
}
}
