#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio2.h>
#include<windows.h>

//--------------Variaveis globais--------------
int tam;//Variavel para checar o tamanho da matriz
char maze[1000][1000];//matriz do labirinto
int complete=0;//verifica se o desenho do labirinto est� completo
char dir;//dire��o do movimento do personagem
int speed=0;//velocidade do desenho do labirinto
int dificuldade=1;//dificuldade
int cordx=2;//cordenada do ponteiro; randomWalk;
int cordy=2;//cordenada do ponteiro; randomWalk;

//----------Prototipos--------
int randomWalk();
int walkBack();
int in_out();
void* updateScreen();
void* fastUpdate();


int main()//Tela inicial e execu��o de fun��es
{
	system("mode con: cols=550 lines=550");
	
	int x,y;

	while(1)//Menu
	{
		printf("\nDigite o tamanho do labirinto: 10 a 500: ");
		scanf("%d",&tam);//Pega o tamanho do mapa
		if(tam == 1993)
		{
			clrscr();
			printf("\n\n\tDesenvolvido por Kewerson Hugo Pereira de Melo\n\n");
			printf("\tIFPR - Campus Londrina - 2013\n\n\n");
			getch();
			return 0;
		}
		if(tam>500 || tam<10)
		{
			printf("\nDigite um numero entre 10 e 500");//Se o valor for diferente do pedido, continua no while.
		}
		else
		{
			break;
		}
	}
	printf("%d",tam);
	if(tam%2==0)//Numeros par deixam a matriz desalinhada na impress�o, por isso sempre adiciona 1.
	{
		tam++;
	}
	
	clrscr();
	
	/*while(1)//Menu
	{
		printf("\nEscolha a dificuldade.\n\n1=Facil\n\n2=Dificil\n");
		scanf("%d",&dificuldade);//Pega a dificuldade escolhida
		
		if(dificuldade!=1 && dificuldade != 2)
		{
			printf("\nValor invalido.");//Se diferente do requerido, volta ao inicio do while.
		}
		else
		{
			break;
		}
	}*/
	
	printf("\nDigite a velocidade da recursao. 1000 = 1Segundo cada ciclo: ");
	scanf("%d",&speed);//Pega a velocidade para desenhar o labirinto.
	
	clrscr();
	
	for(x=0;x<tam;x++)//For que desenha o mapa em branco.
	{
		for(y=0;y<tam;y++)
		{
			if(y==0 || y==tam-1 || x==0 || x==tam-1)//Define o limite
			{
				maze[x][y]='�';
			}
			else
			{
				maze[x][y]='�';
			}
			printf("%c",maze[x][y]);
		}
		printf("\n");
	}
	
	randomWalk();//Inicia a fun��o randomWalk();
	
	in_out();//Ap�s o t�rmino de randomWalk(), inicia a fun��o in_out()
	
	if(dificuldade==2)//Se a dificuldade escolhida for dificil, ent�o.
	{
		clrscr();//Limpa a tela
	}
	
	movPlayer();//Inicia a fun��o que movimenta o jogador at� que o jogo acabe.
}

int randomWalk()//Movimenta aleat�riamente o cursor pela matriz para desenhar o labirinto.
{
	int n=0,s=0,l=0,o=0;//Verifica a dire��o; Se todas variaveis estiverem marcando 1, uma verifica��o no final do segundo la�o de repeti��o mudar� as variaveis last_cordx e last_cordy para a coordenada atual.
	
	srand((unsigned)time(NULL));//Gera uma Seed
	
	while(1)//Primeiro la�o de repeti��o
	{			
		fastUpdate();//Atualiza a tela.	
		
		while(1)//Segundo la�o de repeti��o
		{
			dir = rand()%4;//Gera um numero aleat�rio de 0 at� 3; Cada numero representa uma dire��o.

			if(dir==0)//Se a dire��o for acessada, coloca um contador indicando
			{
				n=1;//Muda a variavel para 1 indicando que ja foi acessado
			}
			else if(dir==1)//Se a dire��o for acessada, coloca um contador indicando
			{
				s=1;//Muda a variavel para 1 indicando que ja foi acessado
			}
			else if(dir==2)//Se a dire��o for acessada, coloca um contador indicando
			{
				o=1;//Muda a variavel para 1 indicando que ja foi acessado
			}
			else if(dir==3)//Se a dire��o for acessada, coloca um contador indicando
			{
				l=1;//Muda a variavel para 1 indicando que ja foi acessado
			}
			
			if(dir==0 && maze[cordx-2][cordy]=='�')//Se dire��o norte e duas casas a frente da dire��o for igual a uma parede, ent�o
			{
				maze[cordx-2][cordy]='�';//A segunda casa recebe um caminho
				maze[cordx-1][cordy]='�';//A primeira casa recebe um caminho
				cordx-=2;//A coordenada muda para a segunda casa
				n=0;s=0;o=0;l=0;//As variaveis resetam
				break;
			}
			else if(dir==1 && maze[cordx+2][cordy]=='�')
			{
				maze[cordx+2][cordy]='�';
				maze[cordx+1][cordy]='�';
				cordx+=2;
				n=0;s=0;o=0;l=0;
				break;
			}
			else if(dir==2 && maze[cordx][cordy-2]=='�')
			{
				maze[cordx][cordy-2]='�';
				maze[cordx][cordy-1]='�';
				cordy-=2;
				n=0;s=0;o=0;l=0;
				break;
			}
			else if(dir==3 && maze[cordx][cordy+2]=='�' )
			{
				maze[cordx][cordy+2]='�';
				maze[cordx][cordy+1]='�';
				cordy+=2;
				n=0;s=0;o=0;l=0;
				break;
			}
			else if(n==1 && s==1 && o==1 && l==1)//Se uma parede sem saida for encontrada, e todas dire��es tiverem sido tentadas, ent�o...
			{
				n=0;s=0;o=0;l=0;//Zera as variaveis.
				if(walkBack())//Chama a fun��o e verifica seu retorno.
				{
					return 0;//Volta para main e continua a ordem de execu��o.
				}
				break;//Quebra o segundo la�o de repeti��o
			}
		}
	}
}

int walkBack()//Anda 2 casas para tr�s e retorna para fun��o randomWalk();
{
	int x,y;
	

	maze[cordx][cordy]=' ';//Limpa a posi��o atual.
	
	if(maze[cordx-1][cordy]=='�')//Se a casa a atras do cursor for um caminho que foi acessado
	{
		maze[cordx-1][cordy]=' ';//Limpa o casa atras do cursor...
		fastUpdate();//...Atualiza o local...
		cordx-=2;//...Volta 2 casas...
		return 0;//Retorna para fun��o randomWalk();
	}
	else if(maze[cordx+1][cordy]=='�')
	{
		maze[cordx+1][cordy]=' ';
		fastUpdate();
		cordx+=2;
		return 0;
	}
	else if(maze[cordx][cordy-1]=='�')
	{
		maze[cordx][cordy-1]=' ';
		fastUpdate();
		cordy-=2;
		return 0;
	}
	else if(maze[cordx][cordy+1]=='�')
	{
		maze[cordx][cordy+1]=' ';
		fastUpdate();
		cordy+=2;
		return 0;
	}
	else
	{
		return 1;
	}
}

void* fastUpdate()//Atualiza a tela ao redor do cursor.
{

	int x,y;
	
	Sleep(speed);//Tempo de espera para desenhar o proximo ponto.
	
	if(cordx <=1 && cordy <=1)//Caso a posi��o seja menor que 1, retorna.
	{
		return 0;
	}
	
	for(x=-1;x<2;x++)// Aqui � definido o campo de vis�o do cursor.
	{
		for(y=-1;y<2;y++)// Para aumenta-lo, reduza o numero de X e Y em 1 e aumente a condi��o de saida em 1;
		{
			gotoxy(cordy+1+y,cordx+x+1);//A fun��o gotoxy ira receber +1 em Y e X pois ele come�a do canto 1 da tela,
										//e n�o 0. cordy e cordy � a posi��o atual. o X e Y ir�o dizer onde a matriz 
										//come�a para que o cursor fique no centro.			
										
			if(maze[cordx+x][cordy+y]=='@')//Caso a posi��o dentro do labirinto tenha uma @, ent�o...
			{
				textbackground(LIGHTRED);//A posi��o ira receber o texto e...
				textcolor(LIGHTRED);//plano de fundo vermelho.
			}
			
			printf("%c",maze[cordx+x][cordy+y]);// Imprime a matriz 3x3 ao redor de @.
			
			textbackground(BLACK);//Reseta as configura��es de cor.
			textcolor(LIGHTGRAY);//Reseta as configura��es de cor.
		}
	}
	
	gotoxy(cordy+1,cordx+1);//Posiciona o cursor abaixo do @.
}

int in_out() //Gera a entrada e saida do labirinto.
{
	int x,y;
	int in_x,in_y;//Coordenadas de entrada
	int out_x,out_y;//Corrdenadas de saida
	
	while(1)//La�o de repeti��o
	{
		in_x=rand()%tam;//Coordenada de entrada recebe numero aleat�rio
		in_y=rand()%tam;//Coordenada de entrada recebe numero aleat�rio
		
		if(maze[in_x][in_y]==' ')//o valor aleat�rio for um espa�o vazio.
		{
			maze[in_x][in_y]='�';//o labirinto recebe o simbolo de entrada
			break;//Quebra o la�o de repeti��o
		}
		
	}
	while(1)//La�o de repeti��o
	{
		out_x=rand()%tam;//Coordenada de saida recebe numero aleat�rio
		out_y=rand()%tam;//Coordenada de saida recebe numero aleat�rio
		
		if(maze[out_x][out_y]==' ')//o valor aleat�rio for um espa�o vazio.
		{
			maze[out_x][out_y]='�';//o labirinto recebe o simbolo de saida
			gotoxy(out_y+1,out_x+1);//Posiciona o cursor sobre o simbolo de saida			
			textcolor(LIGHTCYAN);//Define a cor ciano
			printf("�");//Imprime o simbolo de saida
			textcolor(LIGHTGRAY);//Retorna a cor padr�o.
			break;//Quebra o la�o de repeti��o
		}
	}
	
	cordx=in_x;//Coordenadas iniciais para posicionar o cursor
	cordy=in_y;//Coordenadas iniciais para posicionar o cursor
}


int movPlayer()//Move o jogador
{
	int key;
	fastUpdate();//Chama a fun��o para atualizar a tela ao entrar
	
	while(1)//La�o de repeti��o
	{
		maze[cordx][cordy]=' ';//Ponto inicial onde est� o cursor recebe ' '.
		key=getch();//key recebe o bot�o que for pressionado.

		if(key==80 && cordx<tam && maze[cordx+1][cordy]==' ' || maze[cordx+1][cordy]=='�')
		{	
			cordx++;		
		}
		else if(key==72 && cordx>1 && maze[cordx-1][cordy]==' ' || maze[cordx-1][cordy]=='�')
		{
			cordx--;
		}
		else if(key==77 && cordy<tam && maze[cordx][cordy+1]==' ' || maze[cordx][cordy+1]=='�')
		{
			cordy++;
		}
		else if(key==75 && cordy>1 && maze[cordx][cordy-1]==' ' || maze[cordx][cordy-1]=='�')
		{
			cordy--;
		}
		
		if(maze[cordx][cordy]=='�')
		{
			clrscr();
			textbackground(YELLOW);
			textcolor(BLACK);
			printf("\n\n\nVOCE VENCEU!\n\n\n\n\n\n\n\n\n\n\n\n");
			Sleep(1000);
			getch();
			exit(1);
		}
		maze[cordx][cordy]='@';
		fastUpdate();

	}
}
