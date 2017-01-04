package com.mycompany.entities;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToOne;
import javax.persistence.Table;



@Entity
@Table(name = "DVD")
@NamedQueries({
	@NamedQuery(name = "DVD.findAll", query = "SELECT d FROM DVD d"),
	@NamedQuery(name = "DVD.count", query = "SELECT COUNT(d) FROM DVD d"),
	@NamedQuery(name = "DVD.findByAno", query = "SELECT d FROM DVD d WHERE d.ano = :ano")
})
public class DVD implements Serializable {

	private static final long serialVersionUID = 1L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "id")
	private Long id;

	@Column(name = "titulo", length=20, nullable = false)
	private String titulo;
	
	@Column(name = "preco", nullable = false)
	private Double preco;
	

	@Column(name = "ano", nullable = false)
	private int ano;	
	
	
	@Column(name="grupoIdade", nullable = false)
	private int grupoIdade;
	
	
	@OneToOne
	@JoinColumn(name="generoId")
	private Genero genero;


	public Long getId() {
		return id;
	}


	public void setId(Long id) {
		this.id = id;
	}


	public String getTitulo() {
		return titulo;
	}


	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}


	public Double getPreco() {
		return preco;
	}


	public void setPreco(Double preco) {
		this.preco = preco;
	}


	public int getGrupoIdade() {
		return grupoIdade;
	}


	public void setGrupoIdade(int grupoIdade) {
		this.grupoIdade = grupoIdade;
	}


	public Genero getGenero() {
		return genero;
	}


	public void setGenero(Genero genero) {
		this.genero = genero;
	}


	public int getAno() {
		return ano;
	}


	public void setAno(int ano) {
		this.ano = ano;
	}
	
	
	
}
