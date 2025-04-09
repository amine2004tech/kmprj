#include <stdio.h>
#include <stdlib.h>

typedef int Element; /* les elements sont des int */
typedef struct cellule
{
Element valeur;
struct cellule* suivant;
} Cellule;
typedef Cellule* File;
// Declaration des fonctions gerant la file
File init_file ();
File enfiler ( File f, Element e );
File defiler ( File f );
Element sommet ( File f );
int est_vide ( File f );

// Initialisation de la file
File init_file () {
    return NULL;
}

// Ajout d'un element e la fin de la file
File enfiler ( File f, Element e ) {
    // Creation d'une nouvelle cellule
    Cellule* nouvelle_cellule = (Cellule*) malloc(sizeof(Cellule));
    nouvelle_cellule->valeur = e;
    nouvelle_cellule->suivant = NULL;

    if (est_vide(f)) {
        // Si la file est vide, la nouvelle cellule devient le premier et le dernier element de la file
        f = nouvelle_cellule;
    } else {
        // Sinon, on parcourt la file jusqu'au dernier �l�ment et on ajoute la nouvelle cellule a la fin
        Cellule* dernier = f;
        while (dernier->suivant != NULL) {
            dernier = dernier->suivant;
        }
        dernier->suivant = nouvelle_cellule;
    }

    return f;
}


// Retrait du premier element de la file
File defiler ( File f ) {
    if (est_vide(f)) {
        // Si la file est vide, on ne peut pas retirer d'element
        return f;
    } else {
        // Sinon, on retire le premier element et on retourne la file modifiee
        Cellule* premier = f;
        f = premier->suivant;
        free(premier);
        return f;
    }
}

// Lecture de la valeur du premier element de la file
Element sommet ( File f ) {
    if (est_vide(f)) {
        // Si la file est vide, on ne peut pas lire de valeur
        return 0;
    } else {
        // Sinon, on retourne la valeur du premier �l�ment
        return f->valeur;
    }
}

// Verification si la file est vide
int est_vide ( File f ) {
    return f == NULL;
}



int main()
{
    // Initialisation de la file
    File f = init_file();

    // Enfiler des elements
    f = enfiler(f, 10);
    f = enfiler(f, 20);
    f = enfiler(f, 30);

    // Verifier si la file est vide
    if (est_vide(f)) {
        printf("La file est vide\n");
    } else {
        printf("La file n'est pas vide\n");
    }

    // Afficher le sommet de la file
    printf("Le sommet de la file est %d\n", sommet(f));

    // Defiler des elements
    f = defiler(f);
    f = defiler(f);

    // Afficher le sommet de la file apres avoir defile
    printf("Le sommet de la file est %d\n", sommet(f));

    return 0;
}
