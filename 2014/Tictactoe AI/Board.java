
public class Board {

	int[] Tabela = new int[9];
	
	public void drawTabela()
	{
		int x,y,z=0;
		
		System.out.println();
		
		for(x=0; x<3; x++)
		{
			for(y=0; y<3; y++, z++)
			{
				if(Tabela[z] == 0)
				{
					System.out.print(z+" ");
				}
				else if(Tabela[z] == 1)
				{
					System.out.print("X ");
				}
				else if(Tabela[z] == -1)
				{
					System.out.print("O ");
				}				
			}
			System.out.println();
		}
	}
	
	public void clearTabela()
	{
		int x,y,z=0;
		
		for(x=0; x<3; x++)
		{
			for(y=0; y<3; y++, z++)
			{
				Tabela[z] = 0;
			}
		}
	}
	
	public void setJogada(int jogador ,int posicao)
	{
		
		Tabela[posicao] = jogador;
	}
	
	public int checkWin()
	{
		int lin;
		int col;
		int diag;
		
		lin=0;
		lin += Tabela[0] + Tabela[1] + Tabela[2];
		
		if(lin == 3)
		{
			return 3;
		}
		else if(lin == -3)
		{
			return -3;
		}
		
		lin=0;
		lin += Tabela[3] + Tabela[4] + Tabela[5];
		
		if(lin == 3)
		{
			return 3;
		}
		else if(lin == -3)
		{
			return -3;
		}
		
		lin=0;
		lin += Tabela[6] + Tabela[7] + Tabela[8];
		
		if(lin == 3)
		{
			return 3;
		}
		else if(lin == -3)
		{
			return -3;
		}
		
		col=0;
		col += Tabela[0] + Tabela[3] + Tabela[6];
		
		if(col == 3)
		{
			return 3;
		}
		else if(col == -3)
		{
			return -3;
		}
		
		col=0;
		col += Tabela[1] + Tabela[4] + Tabela[7];
		
		if(col == 3)
		{
			return 3;
		}
		else if(col == -3)
		{
			return -3;
		}
		
		col=0;
		col += Tabela[2] + Tabela[5] + Tabela[8];
		
		if(col == 3)
		{
			return 3;
		}
		else if(col == -3)
		{
			return -3;
		}
		
		diag=0;
		diag += Tabela[0] + Tabela[4] + Tabela[8];
		
		if(diag == 3)
		{
			return 3;
		}
		else if(diag == -3)
		{
			return -3;
		}
		
		diag=0;
		diag += Tabela[2] + Tabela[4] + Tabela[6];
		
		if(diag == 3)
		{
			return 3;
		}
		else if(diag == -3)
		{
			return -3;
		}
		
		int count=0;
		for(int x=0;x<9;x++)
		{
			if(Tabela[x] != 0)
			{
				count++;
				if(count == 9)
				{
					return 1000;
				}
			}
		}
		
		return 0;
	}
}
