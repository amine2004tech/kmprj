#include <stdio.h>
//le montant de l’allocation familiale

int main(){
    int n; // n :nombre d'enfants
    printf("Donnez le nombre d'enfants de la famille: ");
    scanf("%d",&n);
    switch(n){
        case 0:
            printf("aucune allocation");
            break;
        case 1:
        case 2:
        case 3:
            printf("allocation de 150dh");
            break;
        case 4:
        case 5:
        case 6:
            printf("allocation de 250dh");
            break;
        default:
            if(n>=7) 
                printf("allocation de 350dh");
            else 
                printf("erreur");
 
    }

    return 0;
}