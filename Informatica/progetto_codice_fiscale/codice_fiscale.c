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

int main(){
    char nome[30];
    int scelta; //Scelta all'interno del menu
    int stat = 0; //Flag di stato: controlla se i dati sono stati inseriti (0 = falso, 1 = vero)

    do {
      do {
        //Titolo
        system("clear");
        gotoxy(33, 1);
        printf("CODICE FISCALE\a");

        //menu
        gotoxy(20, 3);
        printf("1) Inserisci i dati");
        gotoxy(20, 4);
        printf("2) Mostra il codice fiscale");
        gotoxy(20, 5);
        printf("3) Esci");
        gotoxy(25, 7);
        printf("Scelta --> .");
        gotoxy(36, 7);
        scanf("%d", &scelta);
      } while(scelta < 0 || scelta > 3);
    } while(scelta != 3);
}
