--------------------------------------------------------------
-- A exécuter pour PostgreSQL --------------------------------
--------------------------------------------------------------


--1- Créez la table Auteur avec les champs suivants : CIN, Nom, Prénom, Spécialité, Date naissance
create table auteur (
cin varchar(10) not null ,
nom varchar(20), 
prenom varchar(20),
dateNaissance date,
constraint pk_cin primary key (cin)
);

alter table Auteur add column Specialite varchar (40);

--2-Remplir la table Auteur avec les champs suivants :
insert into auteur values ('B152632','Samadi','Ali',date('05/12/1952'),'Informatique');
insert into auteur values ('A362234','Alej','Ahmed', date ('12/11/1963'),'Gestion');
insert into auteur values ('D201365','Samiri','Aziz',date ('15/04/1970'),'Comptabilité');

select * from auteur;

--3- Créez la table Livre avec les champs suivants :
create table Livre (
ISBN varchar(10),
Titre varchar(40),
DateEdition date,
NombrePages int4,
prix float ,
Exemplaire int4,
constraint pk_ISNB primary key (ISBN)
);

--Remplir la table Livre avec les champs suivants :

insert into Livre values ('253-451','Techniques de Gestion',date ('05/05/2000'),150, 102.44,21);
insert into Livre values ('125-487', 'Comptabilité analytique',date('14/12/2005'),610,215.6,50);
insert into Livre values ('214-700','Informatique',date('23/07/2010'),256,189,33);
insert into Livre values ('326-562', 'Informatique de gestion',date('13/05/2015'),326,56,42);

select * from livre ;

--4.Créez la table AuteurLivre avec les champs suivants : ISBN, CIN
create table AuteurLivre (
ISBN varchar(40),
CIN varchar(40),
constraint pk_ISBNCIN primary key (ISBN,CIN),
foreign key (ISBN) references Livre (ISBN),
foreign key (CIN) references Auteur (CIN)
);

-- Remplir les données 
insert into AuteurLivre values ('253-451','A362234');
insert into AuteurLivre values('125-487','D201365');
insert into AuteurLivre values('214-700','B152632');
insert into AuteurLivre values('326-562','B152632');

select * from auteurlivre ;

--8.1- Lister les noms des auteurs de la bibliothèque et leurs spécialités triées selon l’ordre croissant.

select nom,prenom from Auteur order by auteur.specialite;

--8.2 Donner les titres des livres ayant le nombre de page supérieur à 250 édités entre 2008 et 2011.
select titre from Livre where nombrepages > 250 and extract ( ISOYEAR from dateedition) < 2011 and extract (ISOYEAR from dateedition)>2008 ;

--8.3- Donner les Noms des auteurs en paramètre et afficher le nombre de leurs livres.

select count (*) as NombreLivres, AuteurLivre.CIN, nom,prenom from AUteur,AuteurLivre where AuteurLivre.CIn = Auteur.cin group by  AuteurLivre.CIn, nom,prenom ;


--8.4- Lister l’auteur le plus jeune 

select nom, prenom from auteur order by datenaissance desc limit 1;

--8.5-Donner les noms et les spécialités des auteurs des livres dont le titre comporte le mot Informatique


create index idxTitre on Livre (Titre);


select Auteur.cin , nom, specialite from Auteur,livre,AuteurLivre where AuteurLivre.CIn = Auteur.cin  
and AuteurLivre.ISBN =Livre.isbn 
and  titre like 'Informatique';


-- 8.6- Donner le montant global de la somme des prix des livres de chaque auteur dans la bibliothèque

select sum (prix) from Livre, Auteur,AuteurLivre where AuteurLivre.CIn = Auteur.cin  
and AuteurLivre.ISBN =Livre.isbn 
group by (Auteur.cin );

--8.7- Donner le montant global de la somme des prix des livres de notre bibliothèque

select sum (prix) from Livre;

-- créer un index sur la colonne specialité

create index idxSpecialite on Auteur (specialite);

--Interroger le catalogue

select * from pg_catalog.pg_class;
select * from pg_catalog.pg_class where pg_catalog.pg_class.relname= 'Auteur';
select * from pg_catalog.pg_attribute ;
select * from pg_catalog.pg_attribute,pg_catalog.pg_class where pg_catalog.pg_attribute.attrelid= pg_catalog.pg_class.oid and pg_catalog.pg_class.relname ='Auteur';


select * from pg_catalog.pg_tables where schemaname='public';
select * from pg_catalog.pg_tables;
select distinct schemaname from pg_catalog.pg_tables; 










