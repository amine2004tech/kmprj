arbreB viderArbreB( arbreB a )
{
    // Si l'arbre est vide, on le retourne tel quel
    if (a == NULL) {
        return a;
    }
    else {
        // On vide les sous-arbres gauche et droit
        viderArbreB(a->filsG);
        viderArbreB(a->filsD);
        // On libère la mémoire allouée pour le nœud courant
        free(a);
        // On retourne un arbre vide
        return NULL;
    }
}
