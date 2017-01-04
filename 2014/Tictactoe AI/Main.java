import javax.swing.JOptionPane;

import java.util.Scanner;


public class Main {

	public static void main(String[] args)
	{
		Board tabela = new Board();
		Player jogador = new Player();
		Cpu cpu = new Cpu();
		Scanner scan = new Scanner(System.in);
		
		String nome = JOptionPane.showInputDialog("Qual é o seu nome?");
		jogador.setNome(nome);
		
		int posicao;
		int rodada=1;
		
		while(tabela.checkWin() == 0)
		{
			tabela.drawTabela();
			posicao = scan.nextInt();
			tabela.setJogada(1, posicao);
			
			tabela.setJogada(-1, cpu.avaliar(tabela.Tabela, rodada));
			tabela.drawTabela();
			rodada++;
		}
		if(tabela.checkWin() == 3)
		{
			System.out.println("Jogador "+jogador.nome+" venceu!!");
		}
		else if(tabela.checkWin() == -3)
		{
			System.out.println("A CPU venceu!!");
		}
		else
		{
			System.out.println("EMPATOU!");
		}
		scan.close();
	}
}
