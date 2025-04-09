#include <stdio.h>
/* choisit one main at a time (on peux commenter la fonction main non-voulu pour eviter erreur)*/


//Tri décroissant par sélection
void tri_selection_decroissant(int tab[], int n) {
    int i, j, max, temp;

    for(i = 0; i < n-1; i++) {
        max = i;
        for(j = i+1; j < n; j++) {
            if(tab[j] > tab[max]) {
                max = j;
            }
        }
        if(max != i) {
            temp = tab[i];
            tab[i] = tab[max];
            tab[max] = temp;
        }
    }
}

int main() {
    int tab[] = {3, 5, 8, 3, 2};
    int n = 5;

    tri_selection_decroissant(tab, n);

    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}


//Tri décroissant par insertion :
void tri_insertion_decroissant(int tab[], int n) {
    int i, j, cle;

    for(i = 1; i < n; i++) {
        cle = tab[i];
        j = i-1;
        while(j >= 0 && tab[j] < cle) {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = cle;
    }
}

int main() {
    int tab[] = {3, 5, 8, 3, 2};
    int n = 5;

    tri_insertion_decroissant(tab, n);

    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}
