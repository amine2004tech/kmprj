<!DOCTYPE html>
<html>
<head>
<style>
* {
  box-sizing: border-box;
}

input[type=text], select, textarea {
  width: 100%;
  padding: 12px;
  border: 1px solid #ccc;
  border-radius: 4px;
  resize: vertical;
}

label {
  padding: 12px 12px 12px 0;
  display: inline-block;
}

input[type=submit] {
  background-color: #04AA6D;
  color: white;
  padding: 12px 20px;
  border: none;
  border-radius: 4px;
  cursor: pointer;
  float: right;
}

input[type=submit]:hover {
  background-color: #45a049;
}

.container {
  border-radius: 5px;
  background-color: #f2f2f2;
  padding: 20px;
}

.col-25 {
  float: left;
  width: 25%;
  margin-top: 6px;
}

.col-75 {
  float: left;
  width: 75%;
  margin-top: 6px;
}

/* Clear floats after the columns */
.row::after {
  content: "";
  display: table;
  clear: both;
}

/* Responsive layout - when the screen is less than 600px wide, make the two columns stack on top of each other instead of next to each other */
@media screen and (max-width: 600px) {
  .col-25, .col-75, input[type=submit] {
    width: 100%;
    margin-top: 0;
  }
}
</style>
</head>
<body>

<div class="container">
<p>Ajouter un produit à la base de données</p>
  <form method="POST" action="">
  <div class="row">
    <div>
      <input type="text" id="nom" name="nomprod" placeholder="Nom du produit">
    </div>
  </div>
    <br>
  <div class="row">
    <div>
      <input type="text" id="prix" name="prix" placeholder="Prix">
    </div>
  </div>
    <br>
				<div class="row">
					<div class="col-25">
						<label for="subject">Date de préemption</label>
					</div>
					<div class="col-75">
						<input type="date" id="datepre" name="datepre">
					</div>
				</div>
<div class="row">
    <div>
      <input type="text" name="fournisseur" placeholder="Nom du fournisseur">
    </div>
  </div>
  <br>
  <div class="row">
    <input type="submit" value="Submit">
  </div>
  </form>
</div>

<?php

if($_SERVER['REQUEST_METHOD']==='POST'){
	$nomp=$_POST['nomprod'];
	$prixp=$_POST['prix'];
	$datepre=$_POST['datepre'];
	$nomf=$_POST['fournisseur'];
	
	echo "Le produit $nomp dont le prix est $prixp Dh a été ajouté!";
	echo '<br>';
	
	//include 'produit.php';
	require 'produit.php';
	
	$p1=new Produit(1,$nomp, $prixp, $datepre, $nomf);
	$p1->AfficherProduit();

	echo '<br>';
	$p1->ModifierProduit(1, "fromage", 30, "2024-10-20","Fournisseur A");
	$p1->AfficherProduit();
	
}

?>

</body>
</html>


