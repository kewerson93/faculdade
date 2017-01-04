import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashSet;


public class ChatServer {

	public static HashSet<String> clientes = new HashSet<String>();
	public static HashSet<PrintWriter> aprovados = new HashSet<PrintWriter>();
	
	public static class Server extends Thread{
		BufferedReader in;
		PrintWriter out;
		String nome;
		Socket socket;
		
		public Server(Socket socket){
			this.socket = socket;
		}
		
		public void run(){			
			try {
				in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				out = new PrintWriter(socket.getOutputStream(), true);
				
				while(true){
					out.println("ESCOLHERNOME");
					nome = in.readLine();
					if(nome == null){
						return;
					}
					synchronized(clientes){
						if(!clientes.contains(nome)){
							clientes.add(nome);
							break;
						}
					}
				}
				out.println("APROVADO");
				aprovados.add(out);
		
			while (true) {
				String input = in.readLine();
			    if (input == null) {
			    	return;
			    }
			    for(PrintWriter clienteAprovado : aprovados){
			    	clienteAprovado.println("MENSAGEM "+nome+": "+input);
			    }
			}
								
			} catch (IOException e) {
				System.out.println(e);
			} finally {
				if(nome != null){
					clientes.remove(nome);
				}
				if(out != null){
					aprovados.remove(out);
				}
				
				try{
					socket.close();
				}catch (IOException e){
					
				}
			}
		}
		
		public static void main(String[] args) throws IOException{
			ServerSocket serversocket = new ServerSocket(7070);
			System.out.println("Servidor Funcionando!");
			
			try{
				while(true){
					new Server(serversocket.accept()).start();
				}
			} finally{
				serversocket.close();
			}
		}
	}
}
