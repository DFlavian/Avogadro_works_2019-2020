#include <stdio.h>
#include <stdlib.h>

int main() {
  int a;
  printf("Insrisci un numero: ");
  scanf("%d", &a);
  if ((a%2) == 0){
    printf("Il numero %d e' pari\n", a);
  }
  else {
    printf("Il numero %d e' dispari\n", a);
  }
}
