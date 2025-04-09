#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------|
// code source donne pour créer un arbre vide, tester si un arbre est   |
// vide, ajouter des  éléments à l'arbre, et afficherl'arbre.           |
//----------------------------------------------------------------------|
typedef int Element ;
typedef struct noeud
{
    Element valeur ;
    struct noeud *filsG ;
    struct noeud *filsD ;
} noeud;

typedef noeud* arbreB ;

arbreB arbreBVide()
{
    return NULL;
}

int testerArbreBVide(arbreB a)
{
    return a==NULL;
}

arbreB creeNoeud(Element val, arbreB fg, arbreB fd)
{
    arbreB a=(arbreB)malloc (sizeof(noeud )) ;
    a->valeur=val ;
    a->filsG=fg ;
    a->filsD=fd ;
    return a ;
}

arbreB filsGauche(arbreB a)
{
    if (testerArbreBVide(a))
        return NULL;
    return a->filsG ;
}

arbreB filsDroit(arbreB a)
{
    if (testerArbreBVide(a))
        return NULL;
    return a->filsD ;
}

arbreB ajouterGElementArbreB( arbreB a, Element val )
{
    if(testerArbreBVide(a))
        a=creeNoeud(val,NULL,NULL) ;
    else if(filsGauche(a)==NULL)
        a->filsG=creeNoeud(val,NULL,NULL) ;
    else if(filsDroit(a)==NULL)
        a->filsD=creeNoeud(val,NULL,NULL) ;
    else
        a->filsG=ajouterGElementArbreB(filsGauche(a), val) ;
    return a ;
}


void AfficherArbre(arbreB root, int niveau)
{
    //Tester si l'arbre est vide
    if(root == NULL)
    {
        return;
    }
    //Afficher la valeur du noeud courant
    for(int i = 0; i <= niveau; i++)
    {
        if(niveau - i > 1)
        {
            printf("  ");
        }
        else if (niveau - i == 1)
        {
            printf("|-");
        }
        else if (niveau - i == 0)
        {
            printf("%d", root->valeur);
        }
    }
    printf("\n");

    AfficherArbre(root->filsG, niveau + 1);

    AfficherArbre(root->filsD, niveau + 1);
}

//----------------------------------------------------------------------|
//                       Parcours de l’arbre binaire                    |
//----------------------------------------------------------------------|
// Parcours de l'arbre en préfixe : racine, sous-arbre gauche, sous-arbre droit
void parcoursPrefixe(noeud* a) {
    if (a == NULL) {
        return;
    }
    printf("%d ", a->valeur); // Affiche la valeur du nœud courant
    parcoursPrefixe(a->filsG); // Parcourt le sous-arbre gauche
    parcoursPrefixe(a->filsD); // Parcourt le sous-arbre droit
}

// Parcours de l'arbre en infixe : sous-arbre gauche, racine, sous-arbre droit
void parcoursInfixe(noeud* a) {
    if (a == NULL) {
        return;
    }
    parcoursInfixe(a->filsG); // Parcourt le sous-arbre gauche
    printf("%d ", a->valeur); // Affiche la valeur du nœud courant
    parcoursInfixe(a->filsD); // Parcourt le sous-arbre droit
}

// Parcours de l'arbre en suffixe : sous-arbre gauche, sous-arbre droit, racine
void parcoursSuffixe(noeud* a) {
    if (a == NULL) {
        return;
    }
    parcoursSuffixe(a->filsG); // Parcourt le sous-arbre gauche
    parcoursSuffixe(a->filsD); // Parcourt le sous-arbre droit
    printf("%d ", a->valeur); // Affiche la valeur du nœud courant
}

//----------------------------------------------------------------------|
//                       Rechercher élément dans un Arbre Binaire       |
//----------------------------------------------------------------------|
int rechercherElement( arbreB a, Element val ) {  
    if (a == NULL)
        return 0;
    if (a->valeur == val)
        return 1;
    return (rechercherElement(filsGauche(a), val) || rechercherElement(filsDroit(a), val));
}


//----------------------------------------------------------------------|
//                          vider Arbre                                 |
//----------------------------------------------------------------------|
arbreB viderArbreB( arbreB a )
{
    // Si l'arbre est vide, on le retourne tel quel
    if (a == NULL) {
        return a;
    }
    else {
        // On vide les sous-arbres gauche et droit
        viderArbreB(a->filsG);
        viderArbreB(a->filsD);
        // On libère la mémoire allouée pour le nœud courant
        free(a);
        // On retourne un arbre vide
        return NULL;
    }
}


//----------------------------------------------------------------------|
//                         Supprimer un élément                         |
//----------------------------------------------------------------------|


// Supprime un noeud contenant la valeur v dans l'arbre binaire a
// Retourne l'arbre binaire modifié
arbreB supprimerNoeudQcq(int v, arbreB a)
{
    // Si l'arbre est vide, il n'y a rien à supprimer
    if (a == NULL) {
        return a;
    }
    
    // Si la valeur à supprimer est inférieure à la valeur de la racine de l'arbre,
    // on cherche le noeud à supprimer dans le sous-arbre gauche
    if (v < a->valeur) {
        a->filsG = supprimerNoeudQcq(v, a->filsG);
    }
    // Si la valeur à supprimer est supérieure à la valeur de la racine de l'arbre,
    // on cherche le noeud à supprimer dans le sous-arbre droit
    else if (v > a->valeur) {
        a->filsD = supprimerNoeudQcq(v, a->filsD);
    }
    // Si la valeur à supprimer est égale à la valeur de la racine de l'arbre,
    // on supprime la racine et on fusionne les sous-arbres gauche et droit
    else {
        // Si l'arbre n'a pas de fils gauche, on renvoie le fils droit
        if (a->filsG == NULL) {
            arbreB temp = a->filsD;
            free(a);
            return temp;
        }
        // Si l'arbre n'a pas de fils droit, on renvoie le fils gauche
        else if (a->filsD == NULL) {
            arbreB temp = a->filsG;
            free(a);
            return temp;
        }
        // Si l'arbre a deux fils, on trouve le successeur (plus petit élément dans le sous-arbre droit),
        // on copie sa valeur dans le noeud à supprimer, puis on supprime le successeur
        arbreB successeur = a->filsD;
        while (successeur->filsG != NULL) {
            successeur = successeur->filsG;
        }
        a->valeur = successeur->valeur;
        a->filsD = supprimerNoeudQcq(successeur->valeur, a->filsD);
    }
    return a;
}




int main()
{
    arbreB A = arbreBVide();

    //Arbre Binaire Gauche
    A = ajouterGElementArbreB(A, 20);
    A = ajouterGElementArbreB(A, 5);
    A = ajouterGElementArbreB(A, 12);
    A = ajouterGElementArbreB(A, 3);
    A = ajouterGElementArbreB(A, 25);
    A = ajouterGElementArbreB(A, 28);
    A = ajouterGElementArbreB(A, 21);
    A = ajouterGElementArbreB(A, 13);
    A = ajouterGElementArbreB(A, 8);
    A = ajouterGElementArbreB(A, 6);

    AfficherArbre(A, 0);

    printf("parcours prefixe: ");
    parcoursPrefixe(A);
    printf("\n");
    printf("parcours infixe: ");
    parcoursInfixe(A);
    printf("\n");
    printf("parcours suffixe: ");
    parcoursSuffixe(A);
    printf("\n");

// cherchons 20
    Element val =20;
    rechercherElement(A, val);
        if (rechercherElement(A, val)) {
        printf("%d  exist dans l'arbre.\n", val);
    } else {
        printf("%d n'existe pas  dans l'arbre.\n", val);
    }
    printf("\n");

    int v =20;
    supprimerNoeudQcq(v, A);
    printf("%d est supprime\n",v);

    viderArbreB(A);
    printf("A est vide");

    return 0;
}
