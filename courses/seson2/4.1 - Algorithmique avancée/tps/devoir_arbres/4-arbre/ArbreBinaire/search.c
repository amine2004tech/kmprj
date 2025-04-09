int rechercherElement(arbreB a, Element val)
{
    // Si l'arbre est vide, la valeur recherchée n'est pas présente
    if(testerArbreBVide(a))
    {
        return 0;
    }

    // Si la valeur recherchée est présente dans le nœud courant, retourner 1
    if(a->valeur == val)
    {
        return 1;
    }

    // Si la valeur recherchée est inférieure à la valeur du nœud courant, rechercher dans le sous-arbre gauche
    if(val < a->valeur)
    {
        return rechercherElement(filsGauche(a), val);
    }

    // Sinon, rechercher dans le sous-arbre droit
    return rechercherElement(filsDroit(a), val);
}


//or

int rechercherElement( arbreB a, Element val ) {  
    if (a == NULL)
        return 0;
    if (a->valeur == val)
        return 1;
    return (rechercherElement(filsGauche(a), val) || rechercherElement(filsDroit(a), val));
}
