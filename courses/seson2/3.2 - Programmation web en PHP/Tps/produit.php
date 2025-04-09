<?php


class Produit{
	protected $idProduit;
	protected $nomProduit;
	protected $prixProduit;
	protected $datePreemption;
	protected $NomFournisseur;
	
	public function __construct($idP, $nomp, $prixp, $datepre, $nomf){
		$this->idProduit=$idP;
		$this->nomProduit=$nomp;
		$this->prixProduit=$prixp;
		$this->datePreemption=$datepre;
		$this->NomFournisseur=$nomf;
	}
	
	public function AfficherProduit(){
		echo "Le produit #".$this->idProduit." : ".$this->nomProduit;
		echo "<br>";
		echo "Son prix : ".$this->prixProduit." Dh";
		echo "<br>";
		echo "Sa date de préemption : ".$this->datePreemption;
		echo "<br>";
		echo "Son fournisseur : ".$this->NomFournisseur;
	}
	
	function ModifierProduit($idP, $nomp, $prixp, $datepre, $nomf){
		$this->idProduit=$idP;
		$this->nomProduit=$nomp;
		$this->prixProduit=$prixp;
		$this->datePreemption=$datepre;
		$this->NomFournisseur=$nomf;
	}
}





?>