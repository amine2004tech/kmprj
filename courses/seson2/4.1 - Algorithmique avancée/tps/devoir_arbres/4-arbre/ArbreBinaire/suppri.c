// Supprime un noeud contenant la valeur v dans l'arbre binaire a
// Retourne l'arbre binaire modifié
arbreB supprimerNoeudQcq(int v, arbreB a)
{
    // Si l'arbre est vide, il n'y a rien à supprimer
    if (a == NULL) {
        return a;
    }
    
    // Si la valeur à supprimer est inférieure à la valeur de la racine de l'arbre,
    // on cherche le noeud à supprimer dans le sous-arbre gauche
    if (v < a->valeur) {
        a->filsG = supprimerNoeudQcq(v, a->filsG);
    }
    // Si la valeur à supprimer est supérieure à la valeur de la racine de l'arbre,
    // on cherche le noeud à supprimer dans le sous-arbre droit
    else if (v > a->valeur) {
        a->filsD = supprimerNoeudQcq(v, a->filsD);
    }
    // Si la valeur à supprimer est égale à la valeur de la racine de l'arbre,
    // on supprime la racine et on fusionne les sous-arbres gauche et droit
    else {
        // Si l'arbre n'a pas de fils gauche, on renvoie le fils droit
        if (a->filsG == NULL) {
            arbreB temp = a->filsD;
            free(a);
            return temp;
        }
        // Si l'arbre n'a pas de fils droit, on renvoie le fils gauche
        else if (a->filsD == NULL) {
            arbreB temp = a->filsG;
            free(a);
            return temp;
        }
        // Si l'arbre a deux fils, on trouve le successeur (plus petit élément dans le sous-arbre droit),
        // on copie sa valeur dans le noeud à supprimer, puis on supprime le successeur
        arbreB successeur = a->filsD;
        while (successeur->filsG != NULL) {
            successeur = successeur->filsG;
        }
        a->valeur = successeur->valeur;
        a->filsD = supprimerNoeudQcq(successeur->valeur, a->filsD);
    }
    return a;
}
