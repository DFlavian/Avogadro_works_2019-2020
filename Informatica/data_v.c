#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
}

void pausa() {
  printf("\n"); //Necessario per il comando successivo
  system("read continue"); //Aspetta la pressione di un tasto (al posto di getchar())
}

int main() {
  int giorno[2], mese[2], anno[2];
  int giorni_mesi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i, j;
  int stat = 0; //0 = nessun errore, 1 = c'e' un errore
  char scelta;

  do {
    stat = 0

    do {

      //prende le date
      for (i = 0; i < 2; i++) {
        system("clear");

        //Titolo
        gotoxy(38, 1);
        printf("DATA");

        gotoxy(30, 3);
        printf("Inserisci la %d data", i+1);

        //Giorno
        gotoxy(20, 5);
        printf("Giorno: " );
        scanf("%d", &giorno[i]);

        //Mese
        gotoxy(20, 6);
        printf("Mese: " );
        scanf("%d", &mese[i]);


        //Anno
        gotoxy(20, 7);
        printf("Anno: " );
        scanf("%d", &anno[i]);

      }

      //Controlla le date
      for (i = 0; i < 2; i++) {
          //Controlla se l'anno e' bisestile
          if(mese[i] == 2 && ){
            giorni_mesi[1] = 29;
          }
      }
      printf("Giorno: %d Mese: %d Anno: %d\n", giorno[0], mese[0], anno[0]);
      printf("Giorno: %d Mese: %d Anno: %d\n", giorno[1], mese[1], anno[1]);


    } while(status != 0);
  }while(0);
}
