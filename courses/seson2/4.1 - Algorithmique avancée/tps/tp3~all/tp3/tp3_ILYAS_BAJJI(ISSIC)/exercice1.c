#include <stdio.h>
#include <stdlib.h>

typedef struct element Element;
struct element {
    int valeur;
    Element *suivant;
};

typedef struct {
    Element *premier;
    Element *dernier;
} File;

// Initialisation d'une file vide

void initialiser_file(File *file) {
    file->premier = NULL;
    file->dernier = NULL;
}

// Ajouter un élément à la fin de la file
void enfiler(File *file, int valeur) {
    Element *nouvel_element = malloc(sizeof(Element));
    nouvel_element->valeur = valeur;
    nouvel_element->suivant = NULL;

    if (file->dernier != NULL) {
        file->dernier->suivant = nouvel_element;
    } else {
        file->premier = nouvel_element;
    }
    file->dernier = nouvel_element;
}

// Calculer la taille de la file
int taille_file(File *file) {
    int taille = 0;
    Element *courant = file->premier;
    while (courant != NULL) {
        taille++;
        courant = courant->suivant;
    }
    return taille;
}


// Copier une file

File copie_file(File *file) {
    File copie;
    initialiser_file(&copie);
    Element *courant = file->premier;
    while (courant != NULL) {
        enfiler(&copie, courant->valeur);
        courant = courant->suivant;
    }
    return copie;
}

void afficher_file(File *file) {
    Element *courant = file->premier;
    while (courant != NULL) {
        printf("%d ", courant->valeur);
        courant = courant->suivant;
    }
    printf("\n");
}

int main() {
    File file;
    initialiser_file(&file);
    enfiler(&file, 64);
    enfiler(&file, 4);
    enfiler(&file, 4);
    enfiler(&file, 8);
// Afficher la taille de la file
    printf("Taille de la file : %d\n", taille_file(&file));

// Copier une file
    File copie = copie_file(&file);
    printf("Copie de la file : ");
    afficher_file(&copie);
    return 0;
}
