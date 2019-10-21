#include <stdio.h>
#include <stdlib.h>

int main() {
  int A, B;
  system("clear");
  printf("Inserisci il primo numero --> ");
  scanf("%d", &A);
  do {
    system("clear");
    printf("Inserisci il secondo numero --> ");
    scanf("%d", &B);
  } while(B<=0);
  int p = 0;
  int i = 0;
  do {
    i++;
    p+=A;
  } while(i<B);
  printf("Il prodotto tra %d e %d e' uguale a %d\n",A, B, p);
  return 0;
}
