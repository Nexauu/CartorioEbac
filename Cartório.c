#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocaç~es de texto por região
#include <string.h> // biblioteca resposavel por cuidar das string

int registro()
{
	//inicio criação de variaveis//string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//final da criação de variaveis//string
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	 FILE *file; // cria o arquivo
	 file = fopen(arquivo, "w"); // cria o arquivo
	 fprintf(file,cpf); // salvo o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a");//abre o arquivo
	 fprintf(file,",");// retorna a caractere no aquivo
	 fclose(file);//fecha o arquivo
	 
	 printf("Digite o nome a ser cadastrado: ");
	 scanf("%s" , nome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,nome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o sobrenome a ser cadastrado: ");
	 scanf("%s" ,sobrenome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,sobrenome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o cargo a ser cadastrado: ");
	 scanf("%s",cargo);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,cargo);
	 fclose(file);
	 
	 system("pause");
	 
	 
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n ");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    	
    }	
    
    system("pause");
}

int deletar()
{
      char cpf[40];
      
      printf("Digite o CPF do usuario a ser deletado: ");
      scanf("%s",cpf);
      
      remove(cpf);
      
      FILE *file;
      file = fopen(cpf, "r");
      
      if(file == NULL)
      {
        printf("O usuario nao se encontra no sistema!.\n");
      	system("pause");
      }	
}


int main()
{
	
	int opcao=0; // Definindo variaveis
	int x=1;
	
    for(x=1;x=1;)
 { 
	
	
	   system("cls");//responsavel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	printf("### Cartorio ###\n\n"); // inicio do menu
	printf("Escolha a opçao desejada do menu:\n\n");
	
	
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar Nomes\n");
	printf("\t4 - Sair do Sistema\n");
	printf("Opcao: "); // Fim do menu
	
    scanf ("%d", &opcao); // Armazenando a escolha do usuario
    
    system("cls");
    
    switch(opcao)//inicio da seleção do menu
   {
    	
    	case 1:
    	registro();//chama de funções
    	break;
    	
    	case 2:
    	consulta();
    	break;
    	
    	case 3:
    	deletar();
		break;

		case 4:
		printf("Obrigado por usar o sistema, até mais!");
		return 0;
		break;
		
		default:
		printf("Essa opcao nao esta disponivel\n");
		system("pause");
		break;
    
    
    }
  }
}




