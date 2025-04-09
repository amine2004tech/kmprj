#include <stdio.h>
//tous les termes de la suite de Fibonacci, inférieurs ou égaux à n.

int fibbonacci(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibbonacci(n-1) + fibbonacci(n-2));
   }
}

int main() {
   int n = 5;
   printf("Fibbonacci de %d: " , n);
   for(int i = 0;i<=n;i++) //les termes de la suite de Fibonacci <= n .
    {
      printf("%d ",fibbonacci(i));            
   }

}

