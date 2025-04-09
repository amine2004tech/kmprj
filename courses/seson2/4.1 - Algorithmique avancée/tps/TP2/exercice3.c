#include <stdio.h>
/* choisit one main at a time (on peux commenter la fonction main non-voulu pour eviter erreur)*/

// Supprimer la première occurrence d'un entier 
void supprimer_premiere_occurrence(int tab[], int *k, int entier) {
    int i, j, trouve = 0;

    for(i = 0; i < *k; i++) {
        if(tab[i] == entier && !trouve) {
            trouve = 1;
        }
        if(trouve) {
            if(i < *k-1) {
                tab[i] = tab[i+1];
            }
        }
    }
    if(trouve) {
        (*k)--;
    }
}

int main() {
    int tab[] = {7, 8, 8, 2, 5};
    int k = 5;

    int entier_a_supprimer = 5;

    supprimer_premiere_occurrence(tab, &k, entier_a_supprimer);

    int i;
    for(i = 0; i < k; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}


//Supprimer toutes les occurrences d'un entier donné dans un tableau ordonné
void supprimer_occurrences(int tab[], int *k, int entier) {
    int i, j, compteur = 0;

    for(i = 0; i < *k; i++) {
        if(tab[i] != entier) {
            tab[compteur] = tab[i];
            compteur++;
        }
    }
    *k = compteur;
}

int main() {
    int tab[] = {4, 3, 6, 5, 9};
    int k = 5;

    int entier_a_supprimer = 5;

    supprimer_occurrences(tab, &k, entier_a_supprimer);

    int i;
    for(i = 0; i < k; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}
