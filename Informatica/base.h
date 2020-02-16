#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void gotoxy(int x,int y){ //Equivalente al gotoxy() della conio2.h
 printf("%c[%d;%df",0x1B,y,x);
}

void pausa() {
  printf("\n"); //Necessario per il comando successivo
  system("read continue"); //Aspetta la pressione di un tasto (al posto di getchar())
}

void Stampa_giorni(int V[]){
    int dim = 31;
    for(int i = 0; i < dim; i++){
        printf("%d ", V[i]);
    }
    printf("\n");
}