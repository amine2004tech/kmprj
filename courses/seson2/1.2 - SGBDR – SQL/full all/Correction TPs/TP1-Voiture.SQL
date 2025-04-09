--------------------------------------------------------------
-- A exécuter sur "Try-SQL Editor" de w3schools.com ---------
--------------------------------------------------------------
-- création table Voiture
create Table TVoiture (
	Immatriculation int , 
	Type varchar(10), 
	Couleur varchar(10), 
	Cylindre int , 
	Nom varchar(10), 
	Marque varchar(10), 
	Modèle date,
	CONSTRAINT PK_TVoiture  PRIMARY KEY (Immatriculation ));
--question 2:Remplir la table TVoiture avec les voitures suivantes
insert into TVoiture  values (123456,'Essence','Verte', 7, 'Mégane', 'Renault', date('2004-12-02'));
insert into TVoiture  values (234, 'Essence', 'Bleue', 8, 'Corrola', 'Toyota', date('1998-05-23'));
insert into TVoiture  values (365,'Diesel', 'Rouge', 6, '106', 'Peugeot', date('2001-03-02'));
select * from TVoiture;
--question 3: Ajouter la voiture R4 à la table TVoiture
insert into TVoiture  values( 15698, 'Essence', 'Noire', 7,'R4', 'Renault', date('2002-03-19'));
-- question 4.1 :Lister le nom et le modèle de toutes les voitures
select Nom, Modèle from TVoiture;
--question 4.2: Donner les caractéristiques de la voiture appelée Mégane
select * from TVoiture where Nom ='Mégane';
--question 4.3: Donner les noms des voitures de type essence
select Nom, type from TVoiture where type='Essence';
--question 4.4: Donner les noms des voitures qui ont plus de 8 ans
select Nom, Modèle from TVoiture where DateDiff (Current_Date(), Modèle) >8*365   -- 8 ans traduits en nb de jours 
--question 4.6 - Donner les matricules des voitures qui ont plus de 8 chevaux
select Immatriculation from TVoiture where Cylindre >8;
-- question: 4.7 - Donner le nom de la voiture la plus ancienne 
select Nom, Modèle from TVoiture order by Modèle limit 1;
-- question 4.8 - Donner le nom de la voiture rouge 
select Nom From TVoiture where Couleur = 'Rouge';
--question 3.9 - Donner le nom de la voiture la plus neuve 
select Nom, Modèle from TVoiture order by Modèle Desc limit 1;
-- question 4.10 - Donner le nombre de voitures du parc automobile 
select Count(*) as NbVoitures from TVoiture;