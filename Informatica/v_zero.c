#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int V[50];
  int i, n, k;

  //Si prende in input la dimensione del vettore
  do {
    printf("Quanti elementi vuoi inserire? --> ");
    scanf("%d", &n);
  } while(n<1 || n>50);

  for (i = 0; i < n; i++) { //Creazione del vettore
    printf("Inserisci il %d elemento --> ", i+1);
    scanf("%d", &V[i]);
  }

  printf("Gli elementi presenti nel vettore sono: \n");
  for (i = 0; i < n; i++) { //Si stampa il vettore prima delle azzerazioni
    printf("%d: %d \n", i+1, V[i]);
  }

  do {
    printf("\nInserisci la posizione che vuoi azzerare (Compreso tra 1 ed %d) --> ", n);
    scanf("%d", &k);
  } while(k < 1 || k >= n);
  V[k-1] = 0;


  printf("Gli elementi presenti nel vettore sono: \n");
  for (i = 0; i < n; i++) { //Si stampa il vettore dopo le azzerazioni
    printf("%d: %d \n", i+1, V[i]);
  }
}
