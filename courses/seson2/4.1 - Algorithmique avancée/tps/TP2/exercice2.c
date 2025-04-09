#include <stdio.h>
/* choisit one main at a time (on peux commenter la fonction main non-voulu pour eviter erreur)*/

//Programme pour tester si un tableau de n entiers est trié ou non
int est_trie(int tab[], int n) {
    int i;
    for(i = 0; i < n-1; i++) {
        if(tab[i] > tab[i+1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5};
    int n = 5;

    if(est_trie(tab, n)) {
        printf("Le tableau est trié.\n");
    } else {
        printf("Le tableau n'est pas trié.\n");
    }

    return 0;
}

/*nombre de fois où des nombres successifs dans le tableau ne sont pas ordonnés*/

int compter_inversions(int tab[], int n) {
    int i, inversions = 0;
    for(i = 0; i < n-1; i++) {
        if(tab[i] > tab[i+1]) {
            inversions++;
        }
    }
    return inversions;
}

int main() {
    int tab[] = {3, 1, 3, 5, 4};
    int n = 5;

    int nb_inversions = compter_inversions(tab, n);

    printf("Le tableau contient %d inversions.\n", nb_inversions);

    return 0;
}

