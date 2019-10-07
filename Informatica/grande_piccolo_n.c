#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int max;
  int min;
  int tmp;
  int i = 1;
  do{
    //getchar();
    system("clear");
    printf("Quanti valori vuoi inserire? ");
    scanf("%d", &n);
    if (n<1) {
      printf("Il numero non puo' essere minore di 1! \n" );
      getchar();
    }
  }while(n<1);

  printf("Inserisci il %d numero --> ", i);
  scanf("%d", &tmp);
  max = tmp;
  min = tmp;
  do {
    i++;
    printf("Inserisci il %d numero --> ", i);
    scanf("%d", &tmp);
    if (tmp>max) {
      max = tmp;
    }
    else if(tmp<min){
      min = tmp;
    }
  } while(i<n);
  system("clear");
  printf("Tra i %d numeri che hai inserito, il valore massimo e' %d, invece quello minimo e' %d\n", n, max, min);
  return 0;
}
