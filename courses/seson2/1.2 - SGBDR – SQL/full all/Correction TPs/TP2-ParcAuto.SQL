--------------------------------------------------------------
-- A exécuter sur "Try-SQL Editor" de w3schools.com ---------
--------------------------------------------------------------
-- création table conducteur
create table Conducteur (
CIN varchar(10) ,
Nom varchar(20) NOT NUll,
Prénom varchar(20) NOT NUll,
Adresse varchar(255),
DateNaissance Date DEFAULT "2000-01-01",
CONSTRAINT PK_Conducteur PRIMARY KEY (CIN) );
-- création Table Voiture
create table Voiture (
Immatriculation varchar(20) ,
Marque varchar(20) NOT NUll,
Type varchar(20) NOT NUll,
DateMiseEnRoute Date,
Kilométrage Int,
CONSTRAINT PK_Voiture PRIMARY KEY (Immatriculation) );
--Création Table Location
create table Location (
Immatriculation varchar(20) ,
CIN varchar(10) ,
DateDebut Date NOT NUll,
DateFin Date NOT NUll,
MontantLocation Int Default 0,
CONSTRAINT PK_Location PRIMARY KEY (Immatriculation,CIN) ,
CONSTRAINT FK_Location_Conducteur FOREIGN KEY (CIN) REFERENCES Conducteur(CIN),
CONSTRAINT FK_Location_Voiture FOREIGN KEY  (Immatriculation) REFERENCES Voiture(Immatriculation));
--question 2: Insérer les Conducteurs
insert into Conducteur  values ('B152632','Samadi','Ali','Rabat',date ('1962-12-05'));
insert into Conducteur values ('BF362234','Alej','Ahmed','Salé',date('1983-11-12'));
insert into Conducteur values ('D201365','Naciri','Aziz','Casa',date('1970-04-15'));
select * from Conducteur   -- vérifier les données entrées
-- question 3:Insérer les Voitures 
insert into Voiture values ('253-451','Mercedes','Essence',date('2000-05-05'),520000);
insert into Voiture values ('125-487','Fiat','Diesel',date('2005-12-14'),210000);
insert into Voiture values  ('214-700','Toyota','Essence', date('2008-07-23'),125000);
insert into Voiture values ('326-562','Fiat','Diesel', date('2008-07-23'),126000);
select * from Voiture;  -- vérifier les données entrées
-- question 4: Ajouter les colonnes « Heure_début » et « Heure_fin» après Date_fin dans la table location
alter table location add column Heure_début date after DateFin;
alter table location add column Heure_Fin date after Heure_début;
--question 5 :Insérer les locations suivantes
insert into Location (Immatriculation, CIN, DateDebut, DateFin, Heure_début ,Heure_Fin ) values ('253-451','BF362234', date('2010-05-02'),date(2010-02-22'),time('08:00'),time('09:00'));
insert into Location (Immatriculation, CIN, DateDebut, DateFin, Heure_début ,Heure_Fin ) values('125-487','D201365',date('2011-01-02'), date('2011-01-25'), time('10:00'),time('15:00'));
insert into Location (Immatriculation, CIN, DateDebut, DateFin, Heure_début ,Heure_Fin ) values ('214-700','B152632',date('2010-08-20'),date('2010-09-05'),time('09:30'),time('17:00'));
insert into Location (Immatriculation, CIN, DateDebut, DateFin, Heure_début ,Heure_Fin ) values ('326-562','B152632',date('2013-05-23'),date('2013-06-12'),time('14:00'),time('11:00'));
select * from Location -- vérifier les données entrées
-- question :Modifier pour le conducteur « Ali » par « Ahmed »
update Conducteur set Prénom ='Ahmed' where CIN='B152632';
--question 7:Lister les noms des conducteurs du plus âgés au plus petit
select Nom, Prénom, DateNaissance from conducteur order by DateNaissance;
--question 8:Lister les noms des conducteurs habitant à Rabat ou Casa
select Nom, Prénom, Adresse from conducteur where Adresse ='Rabat' or  Adresse ='Casa';
-- question 9 :9- Lister les immatriculations des voitures de type diesel ayant un kilométrage >20000
select immatriculation, kilométrage from Voiture where type ='Diesel' and kilométrage > 20000;
--question 10: Lister le nom et le prénom du conducteur de la voiture Mercedes
select Nom,Prénom,Marque from Conducteur,Voiture,Location where Voiture.Marque ='Mercedes'
and Voiture.immatriculation = Location.immatriculation
and Conducteur.CIN =Location.CIN;
-- question 11:Lister les noms des conducteurs et le nombre de voitures qu’ils conduisent
select nom, prénom,  count (immatriculation) as NbVoitures from Conducteur,Location
where Conducteur.Cin= Location.CIN group by Location.CIN
--question 12: Lister le nombre de voiture par type
select type, count (immatriculation) as NbVoitures from Voiture group by type;