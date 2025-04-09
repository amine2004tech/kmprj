#include <stdio.h>
#include <stdlib.h>
// un tableau comportant les valeurs des carrés des n premiers nombres impairs
int main(){
    int n;
    printf("Donnez nombre des premiers impairs: ");
    scanf("%d",&n);
    int *tab =NULL ;
    tab =(int *) malloc(n*sizeof(int));
    printf("combien de valeur : %d \n ",n);
    for (int i=0;i<n;i++) {
        tab[i]=(2*i+1)*(2*i+1);
        printf("%d",2*i+1 );
        printf(" a pour carre %d \n",tab[i]);
    }
    return 0;
}