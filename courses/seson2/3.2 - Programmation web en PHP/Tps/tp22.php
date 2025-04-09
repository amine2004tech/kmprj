<?php

class Produit {
    protected $idProduit;
    protected $nomProduit;
    protected $prixProduit;
    protected $datePreemption;
    protected $NomFournisseur;
    
    public function __construct($idProduit, $nomProduit, $prixProduit, $datePreemption, $NomFournisseur) {
        $this->idProduit = $idProduit;
        $this->nomProduit = $nomProduit;
        $this->prixProduit = $prixProduit;
        $this->datePreemption = $datePreemption;
        $this->NomFournisseur = $NomFournisseur;
    }
    
    public function AfficherProduit() {
        echo "ID : " . $this->idProduit . "<br>";
        echo "Nom du produit : " . $this->nomProduit . "<br>";
        echo "Prix : " . $this->prixProduit . "<br>";
        echo "Date de péremption : " . $this->datePreemption . "<br>";
        echo "Nom du fournisseur : " . $this->NomFournisseur . "<br>";
    }
    
    public function ModifierProduit($idProduit, $nomProduit, $prixProduit, $datePreemption, $NomFournisseur) {
        $this->idProduit = $idProduit;
        $this->nomProduit = $nomProduit;
        $this->prixProduit = $prixProduit;
        $this->datePreemption = $datePreemption;
        $this->NomFournisseur = $NomFournisseur;
    }
}

class ProduitSolde extends Produit {
    private $remise;
    
    public function __construct($idProduit, $nomProduit, $prixProduit, $datePreemption, $NomFournisseur, $remise) {
        parent::__construct($idProduit, $nomProduit, $prixProduit, $datePreemption, $NomFournisseur);
        $this->remise = $remise;
    }
    
    public function AfficherProduit() {
        parent::AfficherProduit();
        echo "Remise : " . $this->remise . "<br>";
    }
}

// Exemple d'utilisation
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $produit = new Produit($_POST['idProduit'], $_POST['nomProduit'], $_POST['prixProduit'], $_POST['datePreemption'], $_POST['NomFournisseur']);
    $produit->AfficherProduit();
    $produit->ModifierProduit($_POST['idProduit'], $_POST['nomProduit'], $_POST['prixProduit'], $_POST['datePreemption'], $_POST['NomFournisseur']);
}

?>






<?php

class Produit {
    protected $idProduit;
    protected $nomProduit;
    protected $prixProduit;
    protected $datePreemption;
    protected $nomFournisseur;
    
    public function __construct($id, $nom, $prix, $date, $fournisseur) {
        $this->idProduit = $id;
        $this->nomProduit = $nom;
        $this->prixProduit = $prix;
        $this->datePreemption = $date;
        $this->nomFournisseur = $fournisseur;
    }
    
    public function afficherProduit() {
        echo "Produit : ".$this->nomProduit."<br>";
        echo "Prix : ".$this->prixProduit." €<br>";
        echo "Date de préemption : ".$this->datePreemption."<br>";
        echo "Fournisseur : ".$this->nomFournisseur."<br>";
    }
    
    public function modifierProduit($id, $nom, $prix, $date, $fournisseur) {
        $this->idProduit = $id;
        $this->nomProduit = $nom;
        $this->prixProduit = $prix;
        $this->datePreemption = $date;
        $this->nomFournisseur = $fournisseur;
    }
}

class ProduitSolde extends Produit {
    private $remise;
    
    public function afficherProduit() {
        $pourcentageRemise = $this->remise * 100;
        $prixSoldé = $this->prixProduit - ($this->prixProduit * $this->remise);
        
        echo "Produit : ".$this->nomProduit."<br>";
        echo "Prix initial : ".$this->prixProduit." €<br>";
        echo "Prix soldé : ".$prixSoldé." € (remise de ".$pourcentageRemise."%)<br>";
        echo "Date de préemption : ".$this->datePreemption."<br>";
        echo "Fournisseur : ".$this->nomFournisseur."<br>";
    }
    
    public function modifierProduit($id, $nom, $prix, $date, $fournisseur, $remise) {
        $this->idProduit = $id;
        $this->nomProduit = $nom;
        $this->prixProduit = $prix;
        $this->datePreemption = $date;
        $this->nomFournisseur = $fournisseur;
        $this->remise = $remise;
    }
    
    public function calculerRemise() {
        $pourcentageRemise = $this->remise * 100;
        $prixSoldé = $this->prixProduit - ($this->prixProduit * $this->remise);
        
        echo "Le prix soldé du produit ".$this->nomProduit." est de ".$prixSoldé." € (remise de ".$pourcentageRemise."%)<br>";
    }
    
    public function appliquerSolde() {
        $datePreemptionTimestamp = strtotime($this->datePreemption);
        $sixMonthsTimestamp = strtotime("+6 months");
        $todayTimestamp = strtotime(date("Y-m-d"));
        
        if ($datePreemptionTimestamp < $sixMonthsTimestamp && $datePreemptionTimestamp > $todayTimestamp) {
            $this->remise = 0.2;
            echo "Le produit ".$this->nomProduit." a maintenant une rem"
?>




<?php
// Inclure la définition des classes Produit et ProduitSolde
require_once 'Produit.php';
require_once 'ProduitSolde.php';

// Initialisation du tableau de produits
$produits = [];

// Vérifier si le formulaire a été soumis
if ($_SERVER['REQUEST_METHOD'] === 'POST') {

  // Récupération des données du formulaire
  $idProduit = $_POST['idProduit'];
  $nomProduit = $_POST['nomProduit'];
  $prixProduit = $_POST['prixProduit'];
  $datePreemption = $_POST['datePreemption'];
  $nomFournisseur = $_POST['nomFournisseur'];

  // Création d'un objet Produit
  $produit = new Produit($idProduit, $nomProduit, $prixProduit, $datePreemption, $nomFournisseur);

  // Enregistrement du produit dans le tableau
  $produits[] = $produit;

  // Enregistrement du produit dans le fichier
  $jsonProduits = json_encode($produits);
  file_put_contents('produits.txt', $jsonProduits);
}

// Fonction pour afficher la liste des produits
function afficherProduits($file) {
  $jsonProduits = file_get_contents($file);
  $produits = json_decode($jsonProduits);

  echo '<h2>Liste des produits</h2>';
  echo '<table>';
  echo '<tr><th>ID</th><th>Nom</th><th>Prix</th><th>Date de préemption</th><th>Nom du fournisseur</th><th>Action</th></tr>';
  foreach ($produits as $produit) {
    echo '<tr>';
    echo '<td>' . $produit->getIdProduit() . '</td>';
    echo '<td>' . $produit->getNomProduit() . '</td>';
    echo '<td>' . $produit->getPrixProduit() . '</td>';
    echo '<td>' . $produit->getDatePreemption() . '</td>';
    echo '<td>' . $produit->getNomFournisseur() . '</td>';
    echo '<td><a href="modifier-produit.php?id=' . $produit->getIdProduit() . '"><img src="modifier.png" alt="Modifier"></a> <a href="supprimer-produit.php?id=' . $produit->getIdProduit() . '"><img src="supprimer.png" alt="Supprimer"></a></td>';
    echo '</tr>';
  }
  echo '</table>';
}

// Afficher la liste des produits
afficherProduits('produits.txt');
?>