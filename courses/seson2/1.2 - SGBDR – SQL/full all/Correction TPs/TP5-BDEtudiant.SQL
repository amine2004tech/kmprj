--------------------------------------------------------------
-- A exécuter pour PostgreSQL --------------------------------
--------------------------------------------------------------

---table Etudiant 

create table Etudiant (Numéro int4 not null , Nom varchar(20),Prénom varchar(20),Adresse varchar(40),Ville varchar(20),Téléphone varchar(10),
constraint pk_numéro primary key (numéro)
);


-- Remplir les données 

insert into Etudiant values (1,'Azizi','Ahmed','24, rue firdaws,kamra', 'Rabat','06112233');
insert into Etudiant values (2,'Louzi','Samir','10,rue fès, narjis','Casablanca','06823340');

-- Table Commande

create table Commande (NuméroCommande int4, 
NomLivre varchar(40),
NuméroEtudiant int4 ,
Disponible varchar(3), 
Quantité int4, 
DateCommande date,
constraint pk_numéroCommande primary key (NuméroCommande),
check (Disponible in ('Oui','Non'))
);

alter table COmmande add constraint pk_NuméroEtudiant foreign key (NuméroEtudiant) references Etudiant (Numéro);

-- Remplir les données 

insert into Commande values (1,'Informatique',1,'Oui',4,date('05/02/2013'));
insert into Commande values (2,'Bureautique',2,'Oui',5,date('14/12/2015'));

-- Vérifier les données insérées

select * from etudiant;
select * from commande ;

--1. Afficher la liste des étudiants habitant « Rabat » ou « Casablanca » ?

select nom, prénom from Etudiant where ville in ('Rabat','Casablanca');

--2. Lister les commandes du mois d’octobre 2013 et 2015 ?

select NuméroCommande from COmmande where extract ( month from dateCOmmande) = 10 and extract  (year from datecommande) >=2013 and extract  (YEAR from datecommande) <=2015;


--3. Lister les commandes passées il y a trois mois ?

select NuméroCommande from Commande where datediff(current_date ,datecommande) > 3 * 30;-- datediff donne le nommbre de jours  

 --4. Lister les étudiants qui commence par S et la 3 lettre un i qui ont fait une commande ?

select Numéro , nom, prénom from etudiant,commande  where Numéro= NuméroEtudiant;

5. Donner le nom du livre qui a le plus grand nombre d’exemplaires

select NomLivre from commande order by quantité desc limit 1;  

6. Lister les étudiants qui ont commandé plus d’un livre

select numéro , nom , prénom, count (*) as NbLivres from etudiant , commande where numéro = NuméroEtudiant group by  numéro having count (*) >1

--7. Donner les noms des étudiants ayant commandes un livre le vendredi ?

select numéro,nom,prénom from etudiant , commande where numéro = NuméroEtudiant and extract ( ISODOW from datecommande) =5 -- le paramètre ISODOW retourne le numéro du jour dans la semaine 

--8. Déterminer le nombre d’étudiants habitant « Rabat » ou « Fès »
select count(*) as NbEtudiants from etudiant where upper (ville) = 'RABAT' or upper (ville) = 'FES';  

--9. Déterminer le nombre d’étudiants nommés « X » par ville

select ville , count(*) as NbEtudiants from etudiant where upper(nom) = upper(:ParamétreNom) group by ville;

--une autre manière 

 SELECT * FROM etudiant WHERE upper(nom) = upper($1);
 

--10. Lister les étudiants qui habitent une ville mais qu’on veuille entrer nous même le nom dela ville en utilisant une requête paramétrée

SELECT * FROM etudiant WHERE upper(ville) = upper(:ParamétreVille);
SELECT * FROM etudiant WHERE upper(ville) = upper($1);




