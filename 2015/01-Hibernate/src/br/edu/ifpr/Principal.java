package br.edu.ifpr;

import java.util.Calendar;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.Query;

public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		criarTabela();
		criaObjeto();
		buscaTarefaQuery();
	}
	
	public static void criarTabela(){
		EntityManagerFactory factory = 
				Persistence.createEntityManagerFactory("tarefas");
		
		factory.close();
	}
	
	public static void criaObjeto(){
		Tarefa tarefa = new Tarefa();
		tarefa.setDescricao("Estudar JPA");
		tarefa.setFinalizado(true);
		tarefa.setDataFinalizacao(Calendar.getInstance());
		
		EntityManagerFactory factory = 
				Persistence.createEntityManagerFactory("tarefas");
		
		EntityManager manager = factory.createEntityManager();
		
		manager.getTransaction().begin();
		manager.persist(tarefa);
		manager.getTransaction().commit();
		
		System.out.println("ID da tarefa: " + tarefa.getId());
		
		manager.close();
	}
	
	public static void carregaTarefa(){
		EntityManagerFactory factory = 
				Persistence.createEntityManagerFactory("tarefas");
		EntityManager manager = factory.createEntityManager();
		
		Tarefa encontrada = manager.find(Tarefa.class, 3L);
		
		System.out.println(encontrada.getDescricao());		
	}
	
	public static void removeTarefa(){
		EntityManagerFactory factory = 
				Persistence.createEntityManagerFactory("tarefas");
		EntityManager manager = factory.createEntityManager();
		
		Tarefa encontrada = manager.find(Tarefa.class, 2L);
		
		manager.getTransaction().begin();
		manager.remove(encontrada);
		manager.getTransaction().commit();
	}
	
	public static void atualizaTarefa(){
		Tarefa tarefa =  new Tarefa();
		tarefa.setId(3L); //esse id já existe no banco
		tarefa.setDescricao("Estudar JPA e Hibernate");
		tarefa.setFinalizado(false);
		tarefa.setDataFinalizacao(null);
		
		EntityManagerFactory factory = 
				Persistence.createEntityManagerFactory("tarefas");
		EntityManager manager = factory.createEntityManager();
		
		manager.getTransaction().begin();
		manager.merge(tarefa);
		manager.getTransaction().commit();
		
	}

	public static void buscaWhere(){
		EntityManagerFactory factory = 
				Persistence.createEntityManagerFactory("tarefa");
		EntityManager manager = factory.createEntityManager();
		
		List<Tarefa> lista = manager
				.createQuery("select t from Tarefa as t where t.finalizado = true")
				.getResultList();
		
		for (Tarefa tarefa : lista){
			System.out.println(tarefa.getDescricao());
		}
	}
	
	public static void buscaTarefaQuery(){
		EntityManagerFactory factory = Persistence.createEntityManagerFactory("tarefas");
		EntityManager manager = factory.createEntityManager();
		
		Query query = manager
				.createQuery("select t from Tarefa as t where t.finalizado = :paramFinalizado");
		query.setParameter("paramFinalizado", true);
		
		List<Tarefa> lista = query.getResultList();
		for(Tarefa t:lista)
			System.out.println(t.getDescricao());
	}	
	
}
