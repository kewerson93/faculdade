#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <conio2.h>



struct Lst{//Estrutura de dados.
	char nome[100];
	char telefone[100];
	char endereco[100];
	char email[100];
	char facebook[100];
	
	struct Lst *next;//Ponteiro para o outra lista.
	struct Lst *prev;
};

int inserir(struct Lst*);//Insere novo contato
int alterar(struct Lst, struct Lst*);//Altera um contato ja criado
struct Lst *pesquisa(struct Lst*, char info[100]);
int excluir(struct Lst, struct Lst*);//Exclui um contato
int imprimir(struct Lst);//Imprime a lista com nome de todos contatos
int salvar(struct Lst*);
int carregar(struct Lst *root);

int main()
{
	struct Lst root;//Declara root para ser o inicio da lista
	root.next = NULL;//O valor root.next recebe NULL para saber que a lista começa vazia
	root.prev = NULL;
	strcpy(root.nome,"@@@INICIO@@@");
	carregar(&root);
	
	while(1)//Estrutura de repetição
	{
		printf("---Menu de escolha---\n\n");
		printf("1 - Inserir contato\n");
		printf("2 - Alterar contato\n");
		printf("3 - Pesquisar contato\n");
		printf("4 - Excluir contato\n");
		printf("5 - Imprimir lista de contatos\n");
		
		int menu = getch()-48;//Declare um inteiro; menu recebe o getch()-48 para converter de char para int;
		
		clrscr();		
		
		if(menu==1)//Caso 1
		{			
			inserir(&root);//Chama a função passando o endereço de root
			salvar(&root);
		}
		else if(menu==2)//Caso 2
		{
			char info[100];
			
			printf("Digite o nome, telefone, email ou facebook do contato: \n");
			fflush(stdin);
			scanf("%[^\n]s",info);
			
			alterar(root,pesquisa(&root,info));
		}
		else if(menu==3)//Caso 3
		{
			char info[100];
			struct Lst *search = NULL;
			
			printf("Digite o nome, telefone, email ou facebook do contato: \n");
			fflush(stdin);
			scanf("%[^\n]s",info);
			
			search = pesquisa(&root,info);
			
			clrscr();
			
			if(search != NULL)
			{
				printf("Contato encontrado com sucesso.\n\n");			
				printf("------------------------------\n");
				printf("Nome: %s\n",search->nome);
				printf("Telefone: %s\n",search->telefone);
				printf("Endereço: %s\n",search->endereco);
				printf("Email: %s\n",search->email);
				printf("Facebook: %s\n",search->facebook);
				printf("------------------------------\n");
				
				printf("\n\nPressione qualquer tecla para continuar...\n\n");
				getch();
				
				clrscr();
			}
			
			else
			{
				printf("Contato não encontrado. Pressione qualquer tecla para continuar...");
				getch();				
			}
		}
		
		else if(menu==4)//Caso 4
		{
			char info[100];
			
			printf("Digite o nome, telefone, email ou facebook do contato: \n");
			fflush(stdin);
			scanf("%[^\n]s",info);
			
			excluir(root,pesquisa(&root, info));
		}
		
		else if(menu==5)
		{
			imprimir(root);
		}
		
		else
		{
			return 0;
		}
		clrscr();
	}
}

int inserir(struct Lst *root)
{
	struct Lst *check;
	
	char info[100];
	
	struct Lst *no;
	no = malloc(sizeof(struct Lst));
		
	printf("Insira as informações do contato.\n\n");

	do{
		printf("Nome: ");
		fflush(stdin);
		scanf("%[^\n]s",info);
		strcpy(no->nome,info);
	}while((check = pesquisa(root, info)) != (NULL));
	
	do{
		printf("Telefone: ");
		fflush(stdin);
		scanf("%[^\n]s",info);
		strcpy(no->telefone,info);
	}while((check = pesquisa(root, info)) != NULL);
	
	printf("Enredeço: ");
	fflush(stdin);
	scanf("%[^\n]s",info);
	strcpy(no->endereco, info);
	
	do{
		printf("Email: ");
		fflush(stdin);
		scanf("%[^\n]s",info);
		strcpy(no->email,info);
	}while((check = pesquisa(root, info)) != NULL);
	
	do{
		printf("Facebook: ");
		fflush(stdin);
		scanf("%[^\n]s",info);
		strcpy(no->facebook,info);
	}while((check = pesquisa(root, info)) != NULL);
	
	no->next = NULL;
	no->prev = NULL;
	
	if(root->next == NULL)
	{
		root->next = no;
		no->prev = root;
	}
	else
	{
		struct Lst *auxiliar;
		auxiliar = root->next;
		while(auxiliar->next != NULL)
		{
			auxiliar = auxiliar->next;
		}
		auxiliar->next = no;
		no->prev = auxiliar;
	}
}

int alterar(struct Lst root, struct Lst *lista)
{
	char info[100];
	struct Lst *check;
	if(lista==NULL)
	{
		return 0;
	}
	printf("Escolha a informação que deseja alterar\n\n");
	
	printf("1 - Nome\n");
	printf("2 - Telefone\n");
	printf("3 - Endereço\n");
	printf("4 - Email\n");
	printf("5 - Facebook\n");
	
	while(1)
	{
		int menu = getch() - 48;
		
		if(menu==1)
		{
			do{
				printf("Pressione ENTER para cancelar");
				printf("Nome: ");
				fflush(stdin);
				scanf("%[^\n]s",info);
				
				if(info == "\n")
				{
					strcpy(info,lista->nome);
				}
				
			}while((check = pesquisa(&root, info)) != (NULL));
			
			strcpy(lista->nome,info);
			break;			
		}
		else if(menu==2)
		{
			do{
				printf("Pressione ENTER para cancelar");
				printf("Telefone: ");
				fflush(stdin);
				scanf("%[^\n]s",info);
				
				if(info == "\n")
				{
					strcpy(info,lista->telefone);
				}
				
			}while((check = pesquisa(&root, info)) != NULL);
			
			strcpy(lista->telefone,info);
			break;
		}
		else if(menu==3)
		{
			printf("Endereço: ");
			fflush(stdin);
			scanf("%[^\n]s",info);
			strcpy(lista->endereco,info);
			break;
		}
		else if(menu==4)
		{
			do{
				printf("Pressione ENTER para cancelar");
				printf("Email: ");
				fflush(stdin);
				scanf("%[^\n]s",info);
				
				if(info == "\n")
				{
					strcpy(info,lista->email);
				}
				
			}while((check = pesquisa(&root, info)) != NULL);
			
			strcpy(lista->email,info);
			break;
		}
		
		else if(menu==5)
		{
			do{
				printf("Pressione ENTER para cancelar");
				printf("Facebook: ");
				fflush(stdin);
				scanf("%[^\n]s",info);
				
				if(info == "\n")
				{
					strcpy(info,lista->facebook);
				}
				
			}while((check = pesquisa(&root, info)) != NULL);
			
			strcpy(lista->facebook,info);
			break;
		}
	}
	salvar(&root);
}
int excluir(struct Lst root, struct Lst *no)
{
	if(no == NULL)
	{
		return 0;
	}
	struct Lst *auxiliar = no;//Declara um No auxiliar que ira receber o No a ser excluido
	
	no = NULL;//Libera memória do No;
	
	if(auxiliar->next != NULL)//Se o proximo No depois do No que foi excluido não for Nulo, então...
	{
		auxiliar->next->prev = auxiliar->prev;//...Auxiliar SEGUINTE recebe o informação do No ANTERIOR ao No excluido.
	}

	if(auxiliar->next != NULL)//Se o proximo No depois do No que foi excluido não for Nulo, então...
	{
		auxiliar->prev->next = auxiliar->next;//No ANTERIOR recebe a informação do No DEPOIS do No excluido.
	}
	else
	{
		auxiliar->prev->next = NULL;//Nesse caso. O No anterior ao que for excluido será o ultimo. Por isso recebe NULL.
	}
	salvar(&root);
}

struct Lst *pesquisa(struct Lst *root, char info[100])
{
	struct Lst *auxiliar;
	
	if(root->next != NULL)
	{
		for(auxiliar = root;auxiliar != NULL;auxiliar = auxiliar->next)
		{
			if(strcmp(auxiliar->nome,info) == 0 || strcmp(auxiliar->telefone,info) == 0 || strcmp(auxiliar->email,info) == 0 || strcmp(auxiliar->facebook,info) == 0)
			{
				return auxiliar;
			}
		}
	}
	auxiliar = NULL;
	return auxiliar;
}

int imprimir(struct Lst root)
{
	struct Lst *auxiliar;
	if(root.next != NULL)
	{
		for(auxiliar = root.next;auxiliar != NULL;auxiliar = auxiliar->next)
		{
			printf("------------------------------\n");
			printf("Nome: %s\n",auxiliar->nome);
			printf("Telefone: %s\n",auxiliar->telefone);
			printf("Endereço: %s\n",auxiliar->endereco);
			printf("Email: %s\n",auxiliar->email);
			printf("Facebook: %s\n",auxiliar->facebook);	
			printf("Next: %s\nPrev:%s\n",auxiliar->next,auxiliar->prev);
		}
		printf("------------------------------\n");
	}
	else
	{
		printf("Lista vazia\n");
	}
	printf("Pressione qualquer tecla para continuar...");
	getch();
}

int salvar(struct Lst *root)
{
	FILE *arq = fopen("arquivo.txt","w");
	int sucesso = 0;
	
	if(arq == NULL)
	{
		printf("Erro ao ler o arquivo.\n");
	}
	int count=0;
	while(root->next != NULL)
	{
		root = root->next;
		sucesso = fprintf(arq, "%s-%s-%s-%s-%s-#\n", root->nome, root->telefone, root->endereco, root->email, root->facebook);
	}
		
	if(sucesso)
	{
		printf("\n\nSalvo com sucesso.\n");
	}
	else
	{
		printf("\n\nFalha ao salvar.\n");
	}
	fclose(arq);
	getch();
}

int carregar(struct Lst *root)
{
	FILE *arq = fopen("arquivo.txt","rb");

	if(arq == NULL)
	{
		printf("Falha ao carregar arquivo.\n");
		return 0;
	}
	
	fseek(arq, 0, SEEK_SET);	
	while(1)
	{	
		struct Lst *no;
		no = malloc(sizeof(struct Lst));
		
		char info[100];
		
		if(fscanf(arq, "%[A-z0-9a-z ]-%[A-z0-9a-z ]-%[A-z0-9a-z ]-%[A-z0-9a-z ]-%[A-z0-9a-z ]-#\n", no->nome, no->telefone, no->endereco, no->email, no->facebook) != EOF)
		{
			no->next = NULL;
			no->prev = NULL;
		}
		else
		{
			break;
		}
		
		if(root->next == NULL)
		{
			root->next = no;
			no->prev = root;			
		}
		else
		{
			struct Lst *auxiliar;
			auxiliar = root->next;
			while(auxiliar->next != NULL)
			{
				auxiliar = auxiliar->next;
			}
			auxiliar->next = no;
			no->prev = auxiliar;
		}
	}
	fclose(arq);
}


