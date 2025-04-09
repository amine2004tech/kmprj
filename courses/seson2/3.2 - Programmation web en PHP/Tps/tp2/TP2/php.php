<?php
//exo1
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $nom_produit = $_POST["nomprod"];
  $prix = $_POST["prix"];
  $date = $_POST["datepre"];
  $fournisseur = $_POST["fournisseur"];
  echo "Le produit $nom_produit a été ajouté avec succès à la base de données.".'<br>';

    class Produit
    {
        protected $idProduit;
        protected $nomProduit;
        protected $prixProduit;
        protected $datePreemption;
        protected $NomFournisseur;

        public function __construct($id, $nom, $prix, $date, $NomF)
        {
            $this->idProduit = $id;
            $this->nomProduit = $nom;
            $this->prixProduit = $prix;
            $this->datePreemption = $date;
            $this->NomFournisseur = $NomF;
        }

        //Affichage
        public function AfficherProduit()
        {
            echo "Id : " . $this->idProduit . "<br>";
            echo "Produit: " . $this->nomProduit . "<br>";
            echo "Prix: " . $this->prixProduit . "<br>";
            echo "Date de préemption: " . $this->datePreemption . "<br>";
            echo "Fournisseur: " . $this->NomFournisseur . "<br>";
        }
        public function ModifierProduit($idProduit, $nomProduit, $prixProduit, $datePreemption, $nomFournisseur) {
            $this->idProduit = $idProduit;
            $this->nomProduit = $nomProduit;
            $this->prixProduit = $prixProduit;
            $this->datePreemption = $datePreemption;
            $this->NomFournisseur = $nomFournisseur;
        }
        public function toString() {
            return "Le produit " . $this->nomProduit . " coûte " . $this->prixProduit . " Dirham et est fourni par " . $this->NomFournisseur . ".";

        }

            // Getters
        public function getIdProduit()
        {
            return $this->idProduit;
        }

        public function getNomProduit()
        {
            return $this->nomProduit;
        }

        public function getPrixProduit()
        {
            return $this->prixProduit;
        }

        public function getDatePreemption()
        {
            return $this->datePreemption;
        }

        public function getNomFournisseur()
        {
            return $this->NomFournisseur;
        }

        // Setters
        public function setIdProduit($idProduit)
        {
            $this->idProduit = $idProduit;
        }

        public function setNomProduit($nomProduit)
        {
            $this->nomProduit = $nomProduit;
        }

        public function setPrixProduit($prixProduit)
        {
            $this->prixProduit = $prixProduit;
        }

        public function setDatePreemption($datePreemption)
        {
            $this->datePreemption = $datePreemption;
        }

        public function setNomFournisseur($NomFournisseur)
        {
            $this->NomFournisseur = $NomFournisseur;
        }
    }
    class ProduitSolde extends Produit {
        private $remise;

        public function __construct($idProduit, $nomProduit, $prixProduit, $datePreemption, $nomFournisseur, $remise) {
            parent::__construct($idProduit, $nomProduit, $prixProduit, $datePreemption, $nomFournisseur);
            $this->remise = $remise;
        }
        public function afficherProduit() {
            parent::afficherProduit();
            if (is_numeric($this->remise)) {
                $pourcentageRemise = $this->remise * 100;
                echo "Le pourcentage de remise du produit " . $this->nomProduit . " est de " . $pourcentageRemise . "%.";
            } else {
                echo "Le pourcentage de remise du produit " . $this->nomProduit . " n'est pas valide.";
            }
            //$pourcentageRemise = $this->remise*100;
            //echo "Le pourcentage de remise du produit " . $this->nomProduit . " est de " . $pourcentageRemise . "%.";
        }
        public function ModifierProduit1($idProduit, $nomProduit, $prixProduit, $datePreemption, $nomFournisseur,$remise) {
            parent::ModifierProduit($idProduit, $nomProduit, $prixProduit, $datePreemption, $nomFournisseur);
            $this->remise = $remise;

        }
        public function calculerRemise() {
            $prixRemise = $this->prixProduit - ($this->prixProduit * $this->remise / 100);
            echo $prixRemise;
            echo "<br>";
            echo "Le prix du produit ".$this->nomProduit." avec une remise de ".$this->remise."% est de ".$prixRemise." DH ". "Le prix ancienne est : ". $this->prixProduit;
        }
            public function getRemise() {
            return $this->remise;
        }

        public function setRemise($remise) {
            $this->remise = $remise;
        }
        public function appliquerSolde($remise) {
            $date_aujourdhui = new DateTime();
            $date_preemption = new DateTime($this->datePreemption);
            $interval = $date_aujourdhui->diff($date_preemption);
            $nb_mois = $interval->m + $interval->y * 12;
            $this->remise = $remise;
            if ($nb_mois < 6) {
                $this->remise = $remise;
                echo "Le produit " . $this->nomProduit . " a une remise de " . $this->remise . "%.";
                $this->calculerRemise();
            }
        }
    }

    $produit1 = new Produit(id:1,nom: $_POST["nomprod"],prix:$_POST["prix"],date: $_POST["datepre"],NomF:$_POST["fournisseur"]);
    $produit1->AfficherProduit();
    echo "<hr>";
    $produit1->ModifierProduit(idProduit:10,nomProduit:$_POST["nomprod"] ,prixProduit:"1000" ,datePreemption:$_POST["datepre"] ,nomFournisseur:"HP");
    $produit1->AfficherProduit();
    echo "<hr>";
    $ProduitSolde1= new ProduitSolde(idProduit:10,nomProduit:$_POST["nomprod"] ,prixProduit:$_POST["prix"] ,datePreemption:$_POST["datepre"] ,nomFournisseur:$_POST["fournisseur"],remise:0.2);
    $ProduitSolde1->afficherProduit();
    echo "<hr>";
    $ProduitSolde1->calculerRemise();
    echo "<hr>";
    $ProduitSolde1->ModifierProduit1(idProduit:20,nomProduit:$_POST["nomprod"] ,prixProduit:"2500" ,datePreemption:$_POST["datepre"] ,nomFournisseur:$_POST["fournisseur"],remise: 1.2);
    $ProduitSolde1->afficherProduit();
    echo "<hr>";
    $ProduitSolde1->appliquerSolde(remise:0.2);
    $ProduitSolde1->calculerRemise();
    echo "<hr>";

    $produitsave = new Produit(id:1,nom: $_POST["nomprod"],prix:$_POST["prix"],date: $_POST["datepre"],NomF:$_POST["fournisseur"]);
    $file = fopen("produits.txt","a");
    fwrite($file, $produitsave->toString() . "\n");
    fclose($file);

}
?>