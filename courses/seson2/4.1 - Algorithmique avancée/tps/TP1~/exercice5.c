#include <stdio.h>
//la somme des nombres de 1 à n

int somme(int n){
    int s=0;
    for (int i=1;i<=n;i++){
        s=s+i;}
    return s;
}

int main(){
    int n=7;
    printf("la somme des nombres de 1 a %d est: %d ",n,somme(7));
}