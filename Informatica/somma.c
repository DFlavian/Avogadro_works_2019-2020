#include <stdio.h>
#include <stdlib.h>

int main(){
  int a, b, s;
  printf("Inserisci il primo numero: ");
  scanf("%d", &a);
  printf("Inserisci il secondo numero: ");
  scanf("%d", &b);
  s = a+b;
  printf("La somma di %d e %d e' %d\n", a, b, s);
}
