import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class ChatCliente {

	BufferedReader in;
	PrintWriter out;
	
	JFrame tela = new JFrame("Chat");
	JTextArea messageField = new JTextArea(8,40);
	JTextField textField = new JTextField(40);
	
	Socket socket;
	
	public ChatCliente(){
		messageField.setEditable(false);
		tela.add(new JScrollPane(messageField), "North");
		tela.add(textField, "South");
		tela.pack();
		
		class Manipulador implements ActionListener {

			public void actionPerformed(ActionEvent e){
				out.println(textField.getText());
				textField.setText(null);
			}						
		}
		
		Manipulador manipula = new Manipulador();
		textField.addActionListener(manipula);
	}
	
	private String getServerIp(){
		return JOptionPane.showInputDialog(tela,"Digite o endereço do servidor","Bem-Vindo ao Chat - ADS13",1);
	}
	
	private String getNickname(){
		return JOptionPane.showInputDialog(tela,"Escolha seu Nickname","Nickname");
	}
	
	private void run() throws IOException{
		String serverIp = getServerIp();
		socket = new Socket(serverIp, 7070);
		in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		out = new PrintWriter(socket.getOutputStream(), true);
		
		while(true){
			String texto = in.readLine();
			if(texto.startsWith("ESCOLHERNOME")){
				out.println(getNickname());
			}
			else if(texto.startsWith("APROVADO")){
				messageField.setText("Conexão estabelecida!\n");
			}
			else if(texto.startsWith("MENSAGEM")){
				messageField.append(texto.substring(8)+"\n");
			}
		}		
	}
	
	public static void main(String[] args) throws IOException{
		ChatCliente cliente = new ChatCliente();
		cliente.tela.setVisible(true);
		cliente.run();
	}
}
