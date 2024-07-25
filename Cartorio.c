#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int Registrar() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se ao armazenamento de infomação na string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file;  //criar o arquivo
	file = fopen(arquivo, "w");  //criar o arquivo o "w" significa escrever um novo arquivo
	fprintf(file,cpf);  //salvo o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //comando responsavel por abrir o arquivo e o "a" significa adicionar algo ao arquivo
	fprintf(file,", Nome: "); //comando responsavel pelo que vai ser adicionado ao arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Sobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int Consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");
	
	if (file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, usuário não localizado!\n\n");
		system ("pause");
	}
	
	system("cls");
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("Essas são as infomações do usuário: CPF: ");
		printf("%s",conteudo);
		printf("\n\n");
		
		system("pause");
	}
	
}

int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
		
	}
	
}


int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;) //implementação do laço de repetição do menu
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definido a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção: "); //final do menu
	
        scanf("%d", &opcao); //armazenando a escolha do usuário
    
        system("cls"); //limpando o programa das opções anteriores
    
        
        switch(opcao) //inicio das variaveis das opções
        {
		
            case 1:
            Registrar();
    	    break;
    	
    	    case 2:
    	    Consultar();
		    break;
		
		    case 3:
		    Deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
		    return 0;
		    break;
		
		    default:
		    printf("Essa opção não está disponivel!\n");
		    system("pause");
		    break;
		    
        } //final das variaveis de opções
	
    }
}
