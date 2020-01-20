#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
}

void pausa() {
  printf("Premi un tasto per continuare...");
  printf("\n"); //Necessario per il comando successivo
  system("read continue"); //Aspetta la pressione di un tasto (al posto di getchar())
}

int main() {
  const int DIM = 24;
  int T[DIM];
  int i;
  int max, min;
  int media = 0;
  int stato = 0; //Flag di stato. 0 = Temperatura non inserita
  int scelta;

  do {
    system("clear");

    //Titolo
    gotoxy(35, 1);
    printf("Temperatura");

    //menu
    gotoxy(20, 3);
    printf("1) Inserisci le temperature");
    gotoxy(20, 4);
    printf("2) Temperatura media");
    gotoxy(20, 5);
    printf("3) Temperatura massima");
    gotoxy(20, 6);
    printf("4) Temperatura minima");
    gotoxy(20, 7);
    printf("5) Grafico");
    gotoxy(20, 8);
    printf("6) Esci");

    //Scelta
    gotoxy(25, 10);
    printf("Scegli un'opzione: ");
    scanf("%d", &scelta);

    switch (scelta) {
      case 1:{ //Caricamento delle date
        for (i = 0; i < DIM; i++) {
          do {
            system("clear");
            //Titolo
            gotoxy(35, 1);
            printf("Temperatura");


            gotoxy(20, 3);
            printf("Inserisci la Temperatura delle ore ");
            if(i < 10){
              printf("0");
            }
            printf("%d:00 --> ", i);
            scanf("%d", &T[i]);
          } while(T[i] < -99 || T[i] > 57);
        }
        break;
      }
      case 2:{//Media
        system("clear");

        //Titolo
        gotoxy(35, 1);
        printf("Temperatura");

        for(i = 0; i<DIM; i++){
          media += T[i];
        }
        media = media / DIM;

        gotoxy(20, 3);
        printf("La temperatura media e' %d gradi.\n", media);
        pausa();
        break;
      }
      case 3:{//temperatura massima
        system("clear");

        //Titolo
        gotoxy(35, 1);
        printf("Temperatura");

        max = T[0];

        for (int i = 1; i < DIM; i++) {
          if(T[i] > max){
            max = T[i];
          }
        }

        gotoxy(20, 3);
        printf("La temperatura massima e' di %d gradi. \n", max);
        pausa();
        break;
      }
      case 4:{//temperatura minima
        system("clear");

        //Titolo
        gotoxy(35, 1);
        printf("Temperatura");

        min = T[0];

        for (int i = 1; i < DIM; i++) {
          if(T[i] < max){
            max = T[i];
          }
        }

        gotoxy(20, 3);
        printf("La temperatura minima e' di %d gradi. \n", min);
        pausa();
        break;
      }
      case 5:{

        break;
      }
    }
  } while(scelta != 6);
}
