#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>

	char tab[20] = {'0','1','2','3','4','5','6','7','8','9'};
	char tabcheck[3][3];
	int empate=0;

int menu()//Menu do Jogo
{
	clrscr();
	int x=0,y=0,z=2;//x = numero aleat�rio para cor; y = recebe getch() para movimentar menu; z = contador do menu para subir ou descer;
	srand((unsigned)time(NULL));
	x = rand() % 9+1;	 
	printf("%d",x);
	textcolor(x);

	printf("\t\t����������������������������������������������������ͻ\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                    Tic Tac Toe                     �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�         �����     �����        �����               �\n");
	printf("\t\t�           �   ���   � ���  ���   � ��� ���         �\n");
	printf("\t\t�           � � �   � �  ��  �   � � � � ���         �\n");
	printf("\t\t�           � � ���   � ���� ���   � ��� ���         �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�     <Pressione qualquer tecla para continuar>      �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�         Desenvolvido por: Kewerson Hugo            �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�   Instituto Federal do Parana - Londrina - 2013    �\n");
	printf("\t\t�                                                    �\n");
	printf("\t\t�������������������������ͺ�������������������������ͼ\n");
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
			printf("\t\t����������������������������������������������������ͻ\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�         �����     �����        �����               �\n");
			printf("\t\t�           �   ���   � ���  ���   � ��� ���         �\n");
			printf("\t\t�           � � �   � �  ��  �   � � � � ���         �\n");
			printf("\t\t�           � � ���   � ���� ���   � ��� ���         �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�             ");textbackground(WHITE);cprintf(">> [Jogador vs. Jogador] <<");textbackground(BLACK);printf("            �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                  Jogador vs. CPU                   �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                    Sair do Jogo                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�         Desenvolvido por: Kewerson Hugo            �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�   Instituto Federal do Parana - Londrina - 2013    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�������������������������ͺ�������������������������ͼ\n");
		}
		else if(z==1)
		{
			clrscr();
			printf("\t\t����������������������������������������������������ͻ\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�         �����     �����        �����               �\n");
			printf("\t\t�           �   ���   � ���  ���   � ��� ���         �\n");
			printf("\t\t�           � � �   � �  ��  �   � � � � ���         �\n");
			printf("\t\t�           � � ���   � ���� ���   � ��� ���         �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                 Jogador vs. Jogador                �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�              ");textbackground(WHITE);cprintf(">> [Jogador vs. CPU] <<");textbackground(BLACK);printf("               �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                    Sair do Jogo                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�         Desenvolvido por: Kewerson Hugo            �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�   Instituto Federal do Parana - Londrina - 2013    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�������������������������ͺ�������������������������ͼ\n");
		}
		else if(z==0)
		{
			clrscr();
			printf("\t\t����������������������������������������������������ͻ\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�         �����     �����        �����               �\n");
			printf("\t\t�           �   ���   � ���  ���   � ��� ���         �\n");
			printf("\t\t�           � � �   � �  ��  �   � � � � ���         �\n");
			printf("\t\t�           � � ���   � ���� ���   � ��� ���         �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                 Jogador vs. Jogador                �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                  Jogador vs. CPU                   �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                ");textbackground(WHITE);cprintf(">> [Sair do Jogo] <<");textbackground(BLACK);printf("                �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�         Desenvolvido por: Kewerson Hugo            �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�   Instituto Federal do Parana - Londrina - 2013    �\n");
			printf("\t\t�                                                    �\n");
			printf("\t\t�������������������������ͺ�������������������������ͼ\n");
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
		printf("\t\t����������������������������������������������������ͻ\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�            ���               �                     �\n");
		printf("\t\t�              � ���  �� ��    � ��� � �             �\n");
		printf("\t\t�              � � � � �  �� ��� � � �� �            �\n");
		printf("\t\t�           ���� ���  �� ��� ��� ��� �               �\n");
		printf("\t\t�                    ���                             �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�                        ��                          �\n");
		printf("\t\t�                       ���                          �\n");
		printf("\t\t�                        ��                          �\n");
		printf("\t\t�                        ��                          �\n");
		printf("\t\t�                       ����                         �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�     ��  �� ����� ��   �� ����� ����� ��   ��       �\n");
		printf("\t\t�     ��  �� ��    ���� �� ��    ��    ��   ��       �\n");
		printf("\t\t�     ��  �� ����  ������� ��    ����  ��   ��       �\n");
		printf("\t\t�      ����  ��    ��  ��� ��    ��    ��� ���       �\n");
		printf("\t\t�       ��   ����� ��   �� ����� ����� �������       �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�������������������������ͺ�������������������������ͼ\n");
		getch();
		menu();
	}
	
	else if(jogador == 2)
	{
		printf("\t\t����������������������������������������������������ͻ\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�            ���               �                     �\n");
		printf("\t\t�              � ���  �� ��    � ��� � �             �\n");
		printf("\t\t�              � � � � �  �� ��� � � �� �            �\n");
		printf("\t\t�           ���� ���  �� ��� ��� ��� �               �\n");
		printf("\t\t�                    ���                             �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�                       �����                        �\n");
		printf("\t\t�                       �  ��                        �\n");
		printf("\t\t�                        ���                         �\n");
		printf("\t\t�                       ��  �                        �\n");
		printf("\t\t�                       �����                        �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�     ��  �� ����� ��   �� ����� ����� ��   ��       �\n");
		printf("\t\t�     ��  �� ��    ���� �� ��    ��    ��   ��       �\n");
		printf("\t\t�     ��  �� ����  ������� ��    ����  ��   ��       �\n");
		printf("\t\t�      ����  ��    ��  ��� ��    ��    ��� ���       �\n");
		printf("\t\t�       ��   ����� ��   �� ����� ����� �������       �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�                                                    �\n");
		printf("\t\t�������������������������ͺ�������������������������ͼ\n");
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

int jogada(int jogador)//Fun��o para realizar as jogadas dos jogadores
{
		
	tela();
	int y,x,w;//y= contador; x = cor; w = jogador oposto para continuar a fun��o;
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
	cprintf("Escolha a posi��o que deseja jogar\n");
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
			cprintf("O espa�o ja est� ocupado. Tente outro valor: \n");
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
			cprintf("Valor n�o permitido. Tente outro valor: \n");
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
	printf("�����������ͻ\n");
	for(x=0;x<3;x++)
	{
		printf("\t\t\t\t");
		printf("�");
		for(y=0;y<3;y++,z++)
		{
			tabcheck[x][y] = tab[z];//copia tab para tabcheck para verificar quem ganhou na fun��o check();
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
				printf("�");
			}
		}
		if(x!=2)
		{
			printf("\n\t\t\t\t");
			printf("�����������͹\n");
		}
	}
	printf("\n\t\t\t\t");
	printf("�����������ͼ\n\n\n");
}

void main()//Chama as fun��es principais
{
	menu();
	tela();
	jogada(1);
}

																																																																																																																																																																				/*
																																																																																																																																																																				�����   �����      �����  
																																																																																																																																																																				  �   ��� � ��   ��� � ��� ���
																																																																																																																																																																				  � � �   �  ��  �   � � � ���
																																																																																																																																																																				  � � ��� � ���� ��� � ��� ���
																																																																																																																																																																				  
																																																																																																																																																																				  Desenvolvido por Kewerson.
																																																																																																																																																																				 */
