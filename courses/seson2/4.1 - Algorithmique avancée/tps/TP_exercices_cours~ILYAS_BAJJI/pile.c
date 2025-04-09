
#include <stdio.h>
#include <stdlib.h>

typedef int Element; /* les elements sont des int */

//Pile Chainee
typedef struct cellule {
    Element valeur;
    struct cellule *suivant; //pointeur de type cellue
} Cellule;

typedef Cellule* Pile;
// Declaration des fonctions gerant la pile
Pile init_pile();
Pile empiler( Pile p, Element e );
Pile depiler( Pile p );
Element sommet( Pile p );
int est_vide(Pile p);
//

Pile init_pile()
{
    return NULL;
}
    int est_vide(Pile p)
{
    return (p == NULL);
}
Pile empiler(Pile p, Element e)
{
    Cellule * pc;
    pc=(Pile)malloc(sizeof(Cellule));
    pc->valeur=e;
    pc->suivant=p;
    return pc;
}

//Depiler
Pile depiler(Pile p)
{
/* pre-condition: pile non vide ! */
    Cellule * pc = p;
    if (est_vide(p)){
        printf("Erreur: pile vide !\n");
        return NULL;
    }
    p=p->suivant;
    free(pc);
    return p;
}

//affichage
void afficher (Cellule * p)
{
    printf("%p\n", p);
    while(p){
        printf("%d \t", p->valeur);
        p =p->suivant;
        printf("%p\n", p);
    }
printf("%p\n", p);
}


//le sommet
Element sommet(Pile p)
{
/* pre-condition: pile non vide ! */
if (est_vide(p))
    {
        printf("Erreur: pile vide !\n");
        return NULL;
    }
return p->valeur;
}

// main
int main()
{
    Pile p = init_pile();
    p = empiler(p,50);
    p = empiler(p,5);
    p = empiler(p,20);
    p = empiler(p,10);
    printf("%d au sommet apres empilement de 50, 5, 20 et 10\n", sommet(p));
    p = depiler(p);
    p = depiler(p);
    printf("%d au sommet apres depilement de 10 et 20\n", sommet(p));
    return 0;
}
