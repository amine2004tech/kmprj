#include <stdio.h>
#include <stdlib.h>

//Fonction affiche :
typedef struct Node {
    int val;
    struct Node* next;
} Node;

void affiche(Node* L) {
    while (L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
    printf("\n");
}



//Fonction copie :
Node* copie(Node* L) {
    if (L == NULL) {
        return NULL;
    }
    else {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->val = L->val;
        new_node->next = copie(L->next);
        return new_node;
    }
}



//Fonction concat :
Node* concat(Node* L1, Node* L2) {
    if (L1 == NULL) {
        return copie(L2);
    }
    else {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->val = L1->val;
        new_node->next = concat(L1->next, L2);
        return new_node;
    }
}


//Fonction supprime_occur :
Node* supprime_occur(Node* L, int val) {
    Node* current = L;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->val == val) {
            if (previous == NULL) {
                L = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            current = (previous == NULL) ? L : previous->next;
        }
        else {
            previous = current;
            current = current->next;
        }
    }

    return L;
}


//Fonction récursive compte_occur :
int compte_occur(Node* L, int e) {
    if (L == NULL) {
        return 0;
    }
    else if (L->val == e) {
        return 1 + compte_occur(L->next, e);
    }
    else {
        return compte_occur(L->next, e);
    }
}

int main() {
    Node* L1 = (Node*) malloc(sizeof(Node));
    L1->val = 1;
    L1->next = (Node*) malloc(sizeof(Node));
    L1->next->val = 2;
    L1->next->next = (Node*) malloc(sizeof(Node));
    L1->next->next->val = 3;
    L1->next->next->next = NULL;

    printf("Liste L1 : ");
    affiche(L1);

    Node* L2 = copie(L1);
    L2->val = 4;
    L2->next->val = 5;

    printf("Liste L1 après copie et modification de L2 : ");
    affiche(L1);
    printf("Liste L2 : ");
    affiche(L2);

    Node* L3 = concat(L1, L2);

    printf("Liste L3 après concaténation de L1 et L2 : ");
    affiche(L3);

    L3 = supprime_occur(L3, 2);

    printf("Liste L3 après suppression des occurrences de 2 : ");
    affiche(L3);

    int nb_occurrences = compte_occur(L3, 1);

    printf("Nombre d'occurrences de 1 dans la liste L3 : %d\n", nb_occurrences);

    return 0;
}
