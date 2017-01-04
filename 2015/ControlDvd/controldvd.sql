CREATE DATABASE controldvd;

CREATE TABLE dvd (
  id int(11) NOT NULL AUTO_INCREMENT,
  titulo varchar(45) DEFAULT NULL,
  generoId int(11) DEFAULT NULL,
  preco double NOT NULL,
  grupoIdade int(11) NOT NULL,
  ano int(11) NOT NULL,
  PRIMARY KEY (id),
  KEY FK109F2476EF2E2 (generoId),
  CONSTRAINT FK109F2476EF2E2 FOREIGN KEY (generoId) REFERENCES genero (id)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;

CREATE TABLE genero (
  id int(11) NOT NULL,
  nome varchar(255) DEFAULT NULL,
  PRIMARY KEY (id)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO genero (id,nome) VALUES (1,'Aventura');
INSERT INTO genero (id,nome) VALUES (2,'Comédia');
INSERT INTO genero (id,nome) VALUES (3,'Ficção');
INSERT INTO genero (id,nome) VALUES (4,'Terror');
INSERT INTO genero (id,nome) VALUES (5,'Infantil');
INSERT INTO genero (id,nome) VALUES (6,'Documentário');

INSERT INTO dvd (id,titulo,generoId,preco,grupoIdade,ano) VALUES (1,'Rambo I',1,10.9,10,1991);
INSERT INTO dvd (id,titulo,generoId,preco,grupoIdade,ano) VALUES (2,'Bambi II',2,13.23,10,1992);
INSERT INTO dvd (id,titulo,generoId,preco,grupoIdade,ano) VALUES (3,'TADS III: A Missão',3,15.89,10,2013);
