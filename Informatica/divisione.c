#include <stdio.h>
#include <stdlib.h>

int main() {
  int A, B;
  do {
    system("clear");
    printf("Inserisci il primo numero --> ");
    scanf("%d", &A);
  } while(A<0);
  do {
    system("clear");
    printf("Inserisci il secondo numero --> ");
    scanf("%d", &B);
  } while(B<=0);
  int r = A;
  int q = 0;
  while (r>=B) {
    q++;
    r-=B;
  }
  printf("Il quoziente e il resto tra %d e %d sono rispettivamente %d e %d\n",A, B, q, r);
  return 0;
}
