#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, c;
  printf("Inserisci a: " );
  scanf("%d", &a);
  printf("Inserisci b: " );
  scanf("%d", &b);
  c = a;
  a = b;
  b = c;
  printf("a= %d\n", a);
  printf("b= %d\n", b);
}
