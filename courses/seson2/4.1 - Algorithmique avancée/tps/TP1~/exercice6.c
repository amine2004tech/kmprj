#include <stdio.h>
//la somme des éléments positifs d’un tableau(recursive ).

int somme_positive(int tab[], int n, int i) {
    if (i == n) {
        return 0;
    } else {
        if (tab[i] > 0) {
            return tab[i] + somme_positive(tab, n, i+1);
        } else {
            return somme_positive(tab, n, i+1);
        }
    }
}

int main() {
    int tab[] = {7,6,-3,5,-44,9,9,3,1};
    int n = sizeof(tab) / sizeof(tab[0]);
    int i = 0;
    int somme = somme_positive(tab, n, i);
    printf("La somme des entiers positifs dans le tableau est : %d\n", somme);
    return 0;
}
