// Définition de la structure d'un nœud de l'arbre binaire
typedef struct noeud {
    Element valeur;
    struct noeud* filsG;
    struct noeud* filsD;
} Noeud;

// Parcours de l'arbre en préfixe : racine, sous-arbre gauche, sous-arbre droit
void parcoursPrefixe(Noeud* a) {
    if (a == NULL) {
        return;
    }
    printf("%d ", a->valeur); // Affiche la valeur du nœud courant
    parcoursPrefixe(a->filsG); // Parcourt le sous-arbre gauche
    parcoursPrefixe(a->filsD); // Parcourt le sous-arbre droit
}

// Parcours de l'arbre en infixe : sous-arbre gauche, racine, sous-arbre droit
void parcoursInfixe(Noeud* a) {
    if (a == NULL) {
        return;
    }
    parcoursInfixe(a->filsG); // Parcourt le sous-arbre gauche
    printf("%d ", a->valeur); // Affiche la valeur du nœud courant
    parcoursInfixe(a->filsD); // Parcourt le sous-arbre droit
}

// Parcours de l'arbre en suffixe : sous-arbre gauche, sous-arbre droit, racine
void parcoursSuffixe(Noeud* a) {
    if (a == NULL) {
        return;
    }
    parcoursSuffixe(a->filsG); // Parcourt le sous-arbre gauche
    parcoursSuffixe(a->filsD); // Parcourt le sous-arbre droit
    printf("%d ", a->valeur); // Affiche la valeur du nœud courant
}