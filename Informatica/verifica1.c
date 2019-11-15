#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main() {
  int n_tmp;
  int n;
  char r;
  do {
    do {
      system("clear");
      printf("Inserire il numero di voti che si vogliono mettere: ");
      scanf("%d", &n);
    } while(n <= 0);
    int c = 0;
    int c_suf = 0;
    int c_ins = 0;
    do {
      c++;
      do {
        system("clear");
        printf("Inserisci il %d numero: ", c);
        scanf("%d", &n_tmp);
      } while(n_tmp<=0 || n_tmp > 10);
      if (n_tmp >= 10) {
        c_suf++;
      }
      else{
        c_ins++;
      }
    } while(c<n);
    printf("Tra i %d voti ci sono %d voti sufficienti e %d voti insufficienti. ", n, c_suf, c_ins);
    printf("\nVuoi uscire?");
    scanf(" %c", &r);
  } while(toupper(r) != "S");
  return 0;
}
