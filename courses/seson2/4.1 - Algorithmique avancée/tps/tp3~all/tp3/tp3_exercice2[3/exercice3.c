#include <stdio.h>
#include <stdlib.h>

// Définition d'une structure pour un élément de la liste triée
typedef struct element {
    int valeur;
    struct element* suivant;
} Element;

// Fonction qui insère un élément dans une liste triée
void insere_tri(Element** liste, int valeur) {
    Element* nouvel_element = malloc(sizeof(Element));
    nouvel_element->valeur = valeur;
    nouvel_element->suivant = NULL;
    
    if (*liste == NULL || (*liste)->valeur >= valeur) {
        nouvel_element->suivant = *liste;
        *liste = nouvel_element;
    } else {
        Element* courant = *liste;
        while (courant->suivant != NULL && courant->suivant->valeur < valeur) {
            courant = courant->suivant;
        }
        nouvel_element->suivant = courant->suivant;
        courant->suivant = nouvel_element;
    }
}

// Fonction qui fusionne deux listes triées
Element* fusion_tri(Element* liste1, Element* liste2) {
    Element* resultat = NULL;
    
    if (liste1 == NULL) {
        return liste2;
    }
    
    if (liste2 == NULL) {
        return liste1;
    }
    
    if (liste1->valeur <= liste2->valeur) {
        resultat = liste1;
        resultat->suivant = fusion_tri(liste1->suivant, liste2);
    } else {
        resultat = liste2;
        resultat->suivant = fusion_tri(liste1, liste2->suivant);
    }
    
    return resultat;
}

// Fonction qui affiche une liste triée
void affiche_tri(Element* liste) {
    printf("[");
    while (liste != NULL) {
        printf("%d", liste->valeur);
        if (liste->suivant != NULL) {
            printf(", ");
        }
        liste = liste->suivant;
    }
    printf("]\n");
}

int main() {
    // Exemple d'utilisation des fonctions
    Element* liste1 = NULL;
    insere_tri(&liste1, 1);
    insere_tri(&liste1, 3);
    insere_tri(&liste1, 5);
    insere_tri(&liste1, 9);
    printf("Liste 1 : ");
    affiche_tri(liste1);
    
    Element* liste2 = NULL;
    insere_tri(&liste2, 2);
    insere_tri(&liste2, 4);
    insere_tri(&liste2, 6);
    insere_tri(&liste2, 8);
    printf("Liste 2 : ");
    affiche_tri(liste2);
    
    Element* resultat = fusion_tri(liste1, liste2);
    printf("Liste fusionnée : ");
    affiche_tri(resultat);
    
    return 0;
}
