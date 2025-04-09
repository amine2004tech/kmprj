#include <stdio.h>
#include <stdlib.h>

typedef int Element; /* les �l�ments sont des int */
typedef struct cellule
{
    Element valeur;
    struct cellule* suivant;
} Cellule;
typedef Cellule* Liste;

// D�claration des fonctions g�rant la liste
Liste init_liste();
Liste inserer( Liste l, Element e );
Liste supprimer( Liste l, Element e );
void afficher( Liste l );
int est_vide ( Liste l );


// Initialisation de la liste
Liste init_liste() {
    return NULL;
}

// Ins�rer un �l�ment dans la liste
Liste inserer( Liste l, Element e ) {
    // Cr�ation d'une nouvelle cellule
    Cellule* nouvelle_cellule = (Cellule*) malloc(sizeof(Cellule));
    nouvelle_cellule->valeur = e;

    if (est_vide(l)) {
        // Si la liste est vide, la nouvelle cellule devient le premier �l�ment de la liste
        nouvelle_cellule->suivant = NULL;
        return nouvelle_cellule;
    } else {
        // Sinon, on parcourt la liste jusqu'� la fin et on ajoute la nouvelle cellule
        Cellule* dernier = l;
        while (dernier->suivant != NULL) {
            dernier = dernier->suivant;
        }
        dernier->suivant = nouvelle_cellule;
        nouvelle_cellule->suivant = NULL;
        return l;
    }
}

// Supprimer un �l�ment de la liste
Liste supprimer( Liste l, Element e ) {
    if (est_vide(l)) {
        // Si la liste est vide, on ne peut pas supprimer d'�l�ment
        return l;
    } else if (l->valeur == e) {
        // Si le premier �l�ment est celui � supprimer, on le retire de la liste
        Cellule* premier = l;
        l = premier->suivant;
        free(premier);
        return l;
    } else {
        // Sinon, on parcourt la liste jusqu'� l'�l�ment pr�c�dant celui � supprimer
        Cellule* prec = l;
        Cellule* cour = l->suivant;
        while (cour != NULL && cour->valeur != e) {
            prec = cour;
            cour = cour->suivant;
        }

        if (cour != NULL) {
            // Si on a trouv� l'�l�ment � supprimer, on le retire de la liste
            prec->suivant = cour->suivant;
            free(cour);
        }
        return l;
    }
}

int est_vide ( Liste l ) {
return (l == NULL);
}

// Afficher les �l�ments de la liste
void afficher( Liste l ) {
    if (est_vide(l)) {
        // Si la liste est vide, on n'affiche rien
        printf("La liste est vide\n");
    } else {
        // Sinon, on parcourt la liste et on
        printf("Liste : ");
Cellule* cour = l;
while (cour != NULL) {
printf("%d ", cour->valeur);
cour = cour->suivant;
}
printf("\n");
}
}


int main()
{
    // Initialisation de la liste
    Liste l = init_liste();

    // Ins�rer des �l�ments dans la liste
    l = inserer(l, 10);
    l = inserer(l, 20);
    l = inserer(l, 30);

    // Afficher la liste
    afficher(l);

    // Supprimer un �l�ment de la liste
    l = supprimer(l, 20);

    // Afficher la liste apr�s avoir supprim� un �l�ment
    afficher(l);

    return 0;
}
