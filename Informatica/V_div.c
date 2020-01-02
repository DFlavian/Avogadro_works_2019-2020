#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int V[32], n, i, c;
  do {
    printf("Inserisci un numero tra 1 e 1000 --> ");
    scanf("%d", &n);
  } while(n<0||n>1000);
  c = 0;
  V[c] = 1;
  for (i = 2; i < n/2; i++) {

    if (n%i == 0) {
      c++;
      V[c]=i;
    }
  }
  printf("I divisori sono: \n");
  for (i = 0; i < c; i++) {
    printf("%d\n", V[i]);
  }
}
