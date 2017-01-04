#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>

	char tab[20] = {'0','1','2','3','4','5','6','7','8','9'};
	char tabcheck[3][3];
	int empate=0;

int menu()//Menu do Jogo
{
	clrscr();
	int x=0,y=0,z=2;//x = numero aleat๓rio para cor; y = recebe getch() para movimentar menu; z = contador do menu para subir ou descer;
	srand((unsigned)time(NULL));
	x = rand() % 9+1;	 
	printf("%d",x);
	textcolor(x);

	printf("\t\tษออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                    Tic Tac Toe                     บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ         ÜÜÜÜÜ     ÜÜÜÜÜ        ÜÜÜÜÜ               บ\n");
	printf("\t\tบ           Û   ÜÜÜ   Û ÜÜÜ  ÜÜÜ   Û ÜÜÜ ÜÜÜ         บ\n");
	printf("\t\tบ           Û Û Û   Ü Û  ÜÛ  Û   Ü Û Û Û ÛÜÛ         บ\n");
	printf("\t\tบ           Û Û ÛÜÜ   Û ÛÜÛÜ ÛÜÜ   Û ÛÜÛ ÛÜÜ         บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ     <Pressione qualquer tecla para continuar>      บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ         Desenvolvido por: Kewerson Hugo            บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tบ   Instituto Federal do Parana - Londrina - 2013    บ\n");
	printf("\t\tบ                                                    บ\n");
	printf("\t\tศอออออออออออออออออออออออออบออออออออออออออออออออออออออผ\n");
	getch();
		
	srand((unsigned)time(NULL));
	x = rand() % 14+1;	 
	textcolor(x);
	clrscr();
	
	while(1)
	{	


		if(z==2)
		{
			clrscr();
			printf("\t\tษออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ         ÜÜÜÜÜ     ÜÜÜÜÜ        ÜÜÜÜÜ               บ\n");
			printf("\t\tบ           Û   ÜÜÜ   Û ÜÜÜ  ÜÜÜ   Û ÜÜÜ ÜÜÜ         บ\n");
			printf("\t\tบ           Û Û Û   Ü Û  ÜÛ  Û   Ü Û Û Û ÛÜÛ         บ\n");
			printf("\t\tบ           Û Û ÛÜÜ   Û ÛÜÛÜ ÛÜÜ   Û ÛÜÛ ÛÜÜ         บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ             ");textbackground(WHITE);cprintf(">> [Jogador vs. Jogador] <<");textbackground(BLACK);printf("            บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                  Jogador vs. CPU                   บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                    Sair do Jogo                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ         Desenvolvido por: Kewerson Hugo            บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ   Instituto Federal do Parana - Londrina - 2013    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tศอออออออออออออออออออออออออบออออออออออออออออออออออออออผ\n");
		}
		else if(z==1)
		{
			clrscr();
			printf("\t\tษออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ         ÜÜÜÜÜ     ÜÜÜÜÜ        ÜÜÜÜÜ               บ\n");
			printf("\t\tบ           Û   ÜÜÜ   Û ÜÜÜ  ÜÜÜ   Û ÜÜÜ ÜÜÜ         บ\n");
			printf("\t\tบ           Û Û Û   Ü Û  ÜÛ  Û   Ü Û Û Û ÛÜÛ         บ\n");
			printf("\t\tบ           Û Û ÛÜÜ   Û ÛÜÛÜ ÛÜÜ   Û ÛÜÛ ÛÜÜ         บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                 Jogador vs. Jogador                บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ              ");textbackground(WHITE);cprintf(">> [Jogador vs. CPU] <<");textbackground(BLACK);printf("               บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                    Sair do Jogo                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ         Desenvolvido por: Kewerson Hugo            บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ   Instituto Federal do Parana - Londrina - 2013    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tศอออออออออออออออออออออออออบออออออออออออออออออออออออออผ\n");
		}
		else if(z==0)
		{
			clrscr();
			printf("\t\tษออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ         ÜÜÜÜÜ     ÜÜÜÜÜ        ÜÜÜÜÜ               บ\n");
			printf("\t\tบ           Û   ÜÜÜ   Û ÜÜÜ  ÜÜÜ   Û ÜÜÜ ÜÜÜ         บ\n");
			printf("\t\tบ           Û Û Û   Ü Û  ÜÛ  Û   Ü Û Û Û ÛÜÛ         บ\n");
			printf("\t\tบ           Û Û ÛÜÜ   Û ÛÜÛÜ ÛÜÜ   Û ÛÜÛ ÛÜÜ         บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                 Jogador vs. Jogador                บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                  Jogador vs. CPU                   บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                ");textbackground(WHITE);cprintf(">> [Sair do Jogo] <<");textbackground(BLACK);printf("                บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ         Desenvolvido por: Kewerson Hugo            บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tบ   Instituto Federal do Parana - Londrina - 2013    บ\n");
			printf("\t\tบ                                                    บ\n");
			printf("\t\tศอออออออออออออออออออออออออบออออออออออออออออออออออออออผ\n");
		}
		if(y==13)
		{
			textcolor(WHITE);
			return novo(z);
			
		}
		
		y = getche();
		clrscr();
		
		if((y-48==8 || y==72) && z<2)
		{
			z++;
		}
		else if((y-48==2 || y==80) && z>0)
		{
			z--;
		}
	}
}

int novo(int escolha)//Novo jogo
{
	empate = 0;
	int x;
	for(x=1;x<20;x++)
	{
		tab[x] = x+48;
	}
	
	if(escolha == 0)
	{
		clrscr();
		exit(1);
	}
	else if(escolha == 1)
	{
		//cpu();
	}
	else if(escolha == 2)
	{
		
	}
}

int final(int jogador)//Tela do vencedor
{
	getch();
	clrscr();
	if(jogador == 1)
	{
		printf("\t\tษออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ            ฿฿Û               Û                     บ\n");
		printf("\t\tบ              Û ÜÜÜ  ÜÜ ÜÜ    Û ÜÜÜ Ü Ü             บ\n");
		printf("\t\tบ              Û Û Û Û Û  ÜÛ Ü฿Û Û Û Û฿ ฿            บ\n");
		printf("\t\tบ           ฿ÜÜ฿ ÛÜÛ  ฿Û ÛÜÛ ÛÜÛ ÛÜÛ Û               บ\n");
		printf("\t\tบ                    ÜÜ฿                             บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ                        ÜÛ                          บ\n");
		printf("\t\tบ                       ÛÛÛ                          บ\n");
		printf("\t\tบ                        ÛÛ                          บ\n");
		printf("\t\tบ                        ÛÛ                          บ\n");
		printf("\t\tบ                       ÛÛÛÛ                         บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ     ÛÛ  ÛÛ ÛÛÛÛÛ ÛÛ   ÛÛ ÛÛÛÛÛ ÛÛÛÛÛ ÛÛ   ÛÛ       บ\n");
		printf("\t\tบ     ÛÛ  ÛÛ ÛÛ    ÛÛÛÜ ÛÛ ÛÛ    ÛÛ    ÛÛ   ÛÛ       บ\n");
		printf("\t\tบ     ÛÛ  ÛÛ ÛÛÛÛ  ÛÛ฿ÛÛÛÛ ÛÛ    ÛÛÛÛ  ÛÛ   ÛÛ       บ\n");
		printf("\t\tบ      ÛÜÜÛ  ÛÛ    ÛÛ  ฿ÛÛ ÛÛ    ÛÛ    ÛÛÜ ÜÛÛ       บ\n");
		printf("\t\tบ       ÛÛ   ÛÛÛÛÛ ÛÛ   ÛÛ ÛÛÛÛÛ ÛÛÛÛÛ ฿ÛÛÛÛÛ฿       บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tศอออออออออออออออออออออออออบออออออออออออออออออออออออออผ\n");
		getch();
		menu();
	}
	
	else if(jogador == 2)
	{
		printf("\t\tษออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ            ฿฿Û               Û                     บ\n");
		printf("\t\tบ              Û ÜÜÜ  ÜÜ ÜÜ    Û ÜÜÜ Ü Ü             บ\n");
		printf("\t\tบ              Û Û Û Û Û  ÜÛ Ü฿Û Û Û Û฿ ฿            บ\n");
		printf("\t\tบ           ฿ÜÜ฿ ÛÜÛ  ฿Û ÛÜÛ ÛÜÛ ÛÜÛ Û               บ\n");
		printf("\t\tบ                    ÜÜ฿                             บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ                       ÛÛÛÛÛ                        บ\n");
		printf("\t\tบ                       ฿  ÛÛ                        บ\n");
		printf("\t\tบ                        ÜÛ฿                         บ\n");
		printf("\t\tบ                       ÛÛ  Ü                        บ\n");
		printf("\t\tบ                       ÛÛÛÛÛ                        บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ     ÛÛ  ÛÛ ÛÛÛÛÛ ÛÛ   ÛÛ ÛÛÛÛÛ ÛÛÛÛÛ ÛÛ   ÛÛ       บ\n");
		printf("\t\tบ     ÛÛ  ÛÛ ÛÛ    ÛÛÛÜ ÛÛ ÛÛ    ÛÛ    ÛÛ   ÛÛ       บ\n");
		printf("\t\tบ     ÛÛ  ÛÛ ÛÛÛÛ  ÛÛ฿ÛÛÛÛ ÛÛ    ÛÛÛÛ  ÛÛ   ÛÛ       บ\n");
		printf("\t\tบ      ÛÜÜÛ  ÛÛ    ÛÛ  ฿ÛÛ ÛÛ    ÛÛ    ÛÛÜ ÜÛÛ       บ\n");
		printf("\t\tบ       ÛÛ   ÛÛÛÛÛ ÛÛ   ÛÛ ÛÛÛÛÛ ÛÛÛÛÛ ฿ÛÛÛÛÛ฿       บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tบ                                                    บ\n");
		printf("\t\tศอออออออออออออออออออออออออบออออออออออออออออออออออออออผ\n");
		getch();
		menu();
	}
}

int check(char simbolo, int jogador)//Checa quem venceu
{

	if(tab[1] == simbolo && tab[5] == simbolo && tab[9] == simbolo)//diagonal um
	{
		final(jogador);		
	}
	else if(tab[3] == simbolo && tab[5] == simbolo && tab[7] == simbolo)//diagonal dois
	{
		final(jogador);
	}
	else if(tab[1] == simbolo && tab[2] == simbolo && tab[3] == simbolo)//primeira linha
	{
		final(jogador);
	}
	else if(tab[4] == simbolo && tab[5] == simbolo && tab[6] == simbolo)//segunda linha
	{
		final(jogador);
	}
	else if(tab[7] == simbolo && tab[8] == simbolo && tab[9] == simbolo)//terceira linha
	{
		final(jogador);
	}
	else if(tab[1] == simbolo && tab[4] == simbolo && tab[7] == simbolo)//primeira coluna
	{
		final(jogador);
	}
	else if(tab[2] == simbolo && tab[5] == simbolo && tab[8] == simbolo)//segunda coluna
	{
		final(jogador);
	}
	else if(tab[3] == simbolo && tab[6] == simbolo && tab[9] == simbolo)//terceira coluna
	{
		final(jogador);
	}
	else if(empate==9)
	{
		printf("EMPATE!");
		getch();
		menu();
	}

}

int jogada(int jogador)//Fun็ใo para realizar as jogadas dos jogadores
{
		
	tela();
	int y,x,w;//y= contador; x = cor; w = jogador oposto para continuar a fun็ใo;
	char z;
	
	if(jogador == 1)
	{
		w=2;
		x=4;
		z='X';
	}
	else if(jogador == 2)
	{
		w=1;
		x=1;
		z='O';
	}
	
	printf("\t\t\t");
	textbackground(x);
	textcolor(BLACK);
	cprintf("VEZ DO JOGADOR %d:",jogador); 
	textbackground(BLACK);
	printf("\n\n\t\t");
	textbackground(x);
	cprintf("Escolha a posi็ใo que deseja jogar\n");
	textbackground(BLACK);
	textcolor(WHITE);
	y = getch()-48;
	
	while(1)
	{
		tela();
	
		if((y>0) && (y<10) && tab[y] != 'X' && tab[y] != 'O')
		{
			tab[y] = z;			
			textbackground(BLACK);
			textcolor(WHITE);
			tela();
			check(z, jogador);
			empate++;
			return jogada(w);
		}
		else if(tab[y] == 'X' || tab[y] == 'O')
		{
			printf("\t\t\t");
			textbackground(x);
			textcolor(BLACK);
			cprintf("IMPOSSIVEL REALIZAR JOGADA.");
			textbackground(BLACK);
			printf("\n\n\t\t");
			textbackground(x);
			cprintf("O espa็o ja estแ ocupado. Tente outro valor: \n");
			textbackground(BLACK);
			textcolor(WHITE);
			y = getch()-48;
		}
		else
		{
			printf("\t\t\t");
			textbackground(x);
			textcolor(BLACK);
			cprintf("IMPOSSIVEL REALIZAR JOGADA.");
			textbackground(BLACK);
			printf("\n\n\t\t");
			textbackground(x);
			cprintf("Valor nใo permitido. Tente outro valor: \n");
			textbackground(BLACK);
			textcolor(WHITE);
			y = getch()-48;
		}
	}
	
}

int tela()//Imprime o tabuleiro
{

	clrscr();
	int x,y,z=1;
	
	printf("\n\n\n\t\t\t\t");
	printf("ษอออหอออหอออป\n");
	for(x=0;x<3;x++)
	{
		printf("\t\t\t\t");
		printf("บ");
		for(y=0;y<3;y++,z++)
		{
			tabcheck[x][y] = tab[z];//copia tab para tabcheck para verificar quem ganhou na fun็ใo check();
			if(tab[z]=='X')
			{
				textbackground(RED);
				cprintf(" %c ",tab[z]);
				textbackground(BLACK);
			}
			
			else if(tab[z]=='O')
			{
				textbackground(BLUE);
				cprintf(" %c ",tab[z]);
				textbackground(BLACK);
			}
			
			else
			{
				printf(" %c ",tab[z]);
			}
			if(y!=3)
			{
				printf("บ");
			}
		}
		if(x!=2)
		{
			printf("\n\t\t\t\t");
			printf("ฬอออฮอออฮอออน\n");
		}
	}
	printf("\n\t\t\t\t");
	printf("ศอออสอออสอออผ\n\n\n");
}

void main()//Chama as fun็๕es principais
{
	menu();
	tela();
	jogada(1);
}

																																																																																																																																																																				/*
																																																																																																																																																																				ÜÜÜÜÜ   ÜÜÜÜÜ      ÜÜÜÜÜ  
																																																																																																																																																																				  Û   ÜÜÜ Û ÜÜ   ÜÜÜ Û ÜÜÜ ÜÜÜ
																																																																																																																																																																				  Û Û Û   Û  ÜÛ  Û   Û Û Û ÛÜÛ
																																																																																																																																																																				  Û Û ÛÜÜ Û ÛÜÛÜ ÛÜÜ Û ÛÜÛ ÛÜÜ
																																																																																																																																																																				  
																																																																																																																																																																				  Desenvolvido por Kewerson.
																																																																																																																																																																				 */
