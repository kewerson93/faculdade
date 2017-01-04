import java.util.*;
public class Cpu {

	int[] Diagonal = {0,2,6,8};
	int[] Cantos = {1,3,5,7};
	
	public int avaliar(int[] Tabela, int rodada)
	{
		Random gerador = new Random();
		int aleatorio;
		if(rodada == 1)
		{
			if(Tabela[4] == 0 && rodada == 1)
			{
				return 4;
			}
			else
			{
				aleatorio = gerador.nextInt(4);
				return Diagonal[aleatorio];
			}
		}

		//----------------------------ATAQUE---------------------------
		for(int x=0;x<3;x++)
		{
			if(Tabela[0] + Tabela[1] + Tabela[2] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=3;x<6;x++)
		{
			if(Tabela[3] + Tabela[4] + Tabela[5] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=6;x<9;x++)
		{
			if(Tabela[6] + Tabela[7] + Tabela[8] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=0;x<7;x+=3)
		{
			if(Tabela[0] + Tabela[3] + Tabela[6] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=1;x<8;x+=3)
		{
			if(Tabela[1] + Tabela[4] + Tabela[7] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=2;x<9;x+=3)
		{
			if(Tabela[2] + Tabela[5] + Tabela[8] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=0;x<9;x+=4)
		{
			if(Tabela[0] + Tabela[4] + Tabela[8] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=2;x<7;x+=2)
		{
			if(Tabela[2] + Tabela[4] + Tabela[6] == -2 && Tabela[x] == 0)
			{
				return x;
			}
		}

		
		//------------------------DEFESA------------------------
		for(int x=0;x<3;x++)
		{
			if(Tabela[0] + Tabela[1] + Tabela[2] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=3;x<6;x++)
		{
			if(Tabela[3] + Tabela[4] + Tabela[5] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=6;x<9;x++)
		{
			if(Tabela[6] + Tabela[7] + Tabela[8] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=0;x<7;x+=3)
		{
			if(Tabela[0] + Tabela[3] + Tabela[6] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=1;x<8;x+=3)
		{
			if(Tabela[1] + Tabela[4] + Tabela[7] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=2;x<9;x+=3)
		{
			if(Tabela[2] + Tabela[5] + Tabela[8] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=0;x<9;x+=4)
		{
			if(Tabela[0] + Tabela[4] + Tabela[8] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		for(int x=0;x<7;x+=2)
		{
			if(Tabela[2] + Tabela[4] + Tabela[6] == 2 && Tabela[x] == 0)
			{
				return x;
			}
		}
		
		
		//-----------------------ESPECIFICAS----------------------------
		if(Tabela[0] + Tabela[8] == 2 || Tabela[2] + Tabela[6] == 2)
		{
			while(Tabela[Cantos[aleatorio = gerador.nextInt(4)]] == 0)
			{
				return Cantos[aleatorio];
			}
		}
		
		if(Tabela[0] + Tabela[5] == 2 || Tabela[1] + Tabela[8] == 2)
		{
			return 2;
		}
		if(Tabela[0] + Tabela[7] == 2 || Tabela[3] + Tabela[8] == 2)
		{
			return 6;
		}
		if(Tabela[2] + Tabela[3] == 2 || Tabela[1] + Tabela[6] == 2)
		{
			return 0;
		}
		if(Tabela[2] + Tabela[7] == 2 || Tabela[6] + Tabela[5] == 2)
		{
			return 8;
		}
		
		if(Tabela[0] + Tabela[4] == 2 || Tabela[2] + Tabela[4] == 2 || Tabela[6] + Tabela[4] == 2 || Tabela[8] + Tabela[4] == 2)
		{
			while(Tabela[Diagonal[aleatorio = gerador.nextInt(4)]] == 0)
			{
				return Diagonal[aleatorio];
			}
		}
		
		//--------------------------------SEM POSSIBILIDADES---------------------
		for(int x=0;x<9;x++)
		{
			if(Tabela[x] == 0)
			{
				return x;
		}
		
		}
		
		return 5000;//Caso de erro
	}	
}
