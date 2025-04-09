<?php
//Créer une classe Cercle ayant les attributs suivants : ''xCentre'', ''yCentre'', ''diametre'', ''couleur'' et ''estVisible''

/*Déclarer le constructeur par défaut de la classe qui permettra de créer un cercle avec comme origine les coordonnées (0,0), 
un diamètre de 5, de couleur rouge et visible. 

Créer une méthode qui permet de savoir si un point est dans un cercle. Pour résoudre ceci, il suffit de calculer la distance du point de coordonnées (x, y) 
au centre C du cercle. Si cette distance est supérieure au rayon, alors vous êtes dehors, sinon, vous êtes dedans.
Le calcul de la distance Euclidienne dans un plan se calcule simplement : sqrt((x-C_x)**2 + (y-C_y)**2) 
*/

class cercle{
	private $xC;
	private $yC;
	private $diametre;
	private $couleur;
	private $estVisible;
	
	function __construct(){  
	$this->xC=0;
	$this->yC=0;
	$this->diametre=5;
	$this->couleur="rouge";
	$this->estVisible="Visible";
	}
	
		function __construct($x,$y,$d,$c,$ev){  
	$this->xC=$x;
	$this->yC=$y;
	$this->diametre=$d;
	$this->couleur=$c;
	$this->estVisible=$ev;
	}
	
	//les getters pour retourner les données et les utilisers en dehors de la classe et les setters pour affecter une donnée à une propriété
	
	function get_xc(){
		return $this->xC;
	}
	
	function set_xc($x){
		$this->xC=$x;
	}
	/*Créer une méthode qui permet de savoir si un point est dans un cercle. Pour résoudre ceci, il suffit de calculer la distance du point de coordonnées (x, y) 
au centre C du cercle. Si cette distance est supérieure au rayon, alors vous êtes dehors, sinon, vous êtes dedans.
Le calcul de la distance Euclidienne dans un plan se calcule simplement : sqrt((x-C_x)**2 + (y-C_y)**2) 
*/
	Public function appartenir($xp,$yp){
		$distance=sqrt(($xp-$this->xC)**2+($yp-$this->yC)**2);
		if ($distance<($this->diametre/2)) return true;
		else return false;
	}
}

$cercle1=new Cercle();
$cercle1->set_xc(5);
$cercle1->yC=4; //Interdit : le yC est private ni protected
$verif=$cercle1->appartenit(1,3);
echo $verif;

$cercle2=new Cercle(1,3,6,"Bleu","Visible");




?>