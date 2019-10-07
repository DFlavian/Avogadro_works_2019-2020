#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, c, r;
  printf("Inserisci il primo numero: " );
  scanf("%d", &a);
  printf("Inserisci il secondo numero: " );
  scanf("%d", &b);
  printf("Inserisci il terzo numero: " );
  scanf("%d", &c);
  if (c == -2) {
    printf("Il terzo numero non puo' essere -2!\n");
  }
  else{  
    r = (a-(3*b)/(2+c));
    printf("Il risultato dell'espressione (a-(3*b)/(2+c)) e' %d\n", r);
  }
}
