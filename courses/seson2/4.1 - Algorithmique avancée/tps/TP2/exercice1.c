#include <stdio.h>


// si l'entier X appartient au tableau T
int recherche_in_tableau(int T[], int taille, int X) {
    int i;
    for (i = 0; i < taille; i++) {
        if (T[i] == X) {
            return 1;
        }
    }
    return 0;
}


// le nombre d'occurrences de l'entier X
int compte_occurences(int T[], int taille, int X) {
    int i, count = 0;
    for (i = 0; i < taille; i++) {
        if (T[i] == X) {
            count++;
        }
    }
    return count;
}

// la première position de l'entier X
int premiere_position(int T[], int taille, int X) {
    int i;
    for (i = 0; i < taille; i++) {
        if (T[i] == X) {
            return i;
        }
    }
    return -1 ;// en cas X n'est pas dans la table
}

//Afficher la dernière position de l'entier X 
int dernierePosition(int T[], int taille, int X) {
    int i, pos = -1;
    for (i = 0; i < taille; i++) {
        if (T[i] == X) {
            pos = i;
        }
    }
    return pos;
}

//Afficher toutes les positions de l'entier X 
void affiche_positions(int T[], int taille, int X) {
    int i;
    for (i = 0; i < taille; i++) {
        if (T[i] == X) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    int X ;
    printf("enter un entier : ");
    scanf("%d",&X);
    int T[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int taille=sizeof(T) / sizeof(T);

    recherche_in_tableau(T,taille,X);
    compte_occurences(T,taille,X);
    premiere_position(T,taille,X);
    dernierePosition(T,taille,X);
    affiche_positions(T,taille,X);

    return 0;

}
