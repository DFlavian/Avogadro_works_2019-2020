#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  do {
    system("clear");
    printf("Inserisci il valore da elevare alla seconda --> ");
    scanf("%d", &n);
  } while(n<0);
  int n_dis = 1;
  int Qn = 0;
  int c = 0;
  while (c<n) {
    Qn += n_dis;
    c++;
    n_dis+=2;
  }
  printf("Il risultato di %d al quadrato e' %d\n", n, Qn);
  return 0;
}
