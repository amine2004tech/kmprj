#include <stdio.h>
//affiche les entiers de 1 à N, 5 par 5, séparés par des tabulations

int main(){
    int N;
    printf("Donnez un entier N: ");
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        printf("%d",i);
        printf(" ");
        if (i%5==0)
            printf("\n");

    }

    return 0;
}