<?php
class Produit {
  protected $idProduit;
  protected $nomProduit;
  protected $prixProduit;
  protected $datePreemption;
  protected $NomFournisseur;

  public function __construct($id, $nom, $prix, $date, $NomF) {
    $this->idProduit = $id;
    $this->nomProduit = $nom;
    $this->prixProduit = $prix;
    $this->datePreemption = $date;
    $this->NomFournisseur = $NomF;
  }
  //Affichage
  public function AfficherProduit() {
    echo "Produit: " . $this->nomProduit . "<br>";
    echo "Prix: " . $this->prixProduit . "<br>";
    echo "Date de préemption: " . $this->datePreemption . "<br>";
    echo "Fournisseur: " . $this->NomFournisseur . "<br>";
  }


  // Getters
  public function getIdProduit() {
    return $this->idProduit;
  }
  
  public function getNomProduit() {
    return $this->nomProduit;
  }
  
  public function getPrixProduit() {
    return $this->prixProduit;
  }
  
  public function getDatePreemption() {
    return $this->datePreemption;
  }
  
  public function getNomFournisseur() {
    return $this->NomFournisseur;
  }
  
  // Setters
  public function setIdProduit($idProduit) {
    $this->idProduit = $idProduit;
  }
  
  public function setNomProduit($nomProduit) {
    $this->nomProduit = $nomProduit;
  }
  
  public function setPrixProduit($prixProduit) {
    $this->prixProduit = $prixProduit;
  }
  
  public function setDatePreemption($datePreemption) {
    $this->datePreemption = $datePreemption;
  }
  
  public function setNomFournisseur($NomFournisseur) {
    $this->NomFournisseur = $NomFournisseur;
  }
}
$produit1 = new Produit(5 , "Produit 1", 10.99, "2023-05-31", "Fournisseur A");
$produit1->AfficherProduit();
?>
