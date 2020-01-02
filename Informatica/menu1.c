#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Programma contenente i seguenti programmi:
1. Perfetti
2. Abbondanti
3. difettivi
*/

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
 }

int main() {
  //Variabili
  int scelta = 0;
  int n;
  int div;
  int sdiv;
  int cdiv;

  do {
    do {

      //Titolo
      system("clear");
      gotoxy(30,1);
      printf("CONTROLLO DEL NUMERO" );

      //menu
      gotoxy(15,2);
      printf("1. Perfetti");
      gotoxy(15,3);
      printf("2. Abbondanti");
      gotoxy(15,4);
      printf("3. Difettivi");
      gotoxy(15,5);
      printf("4. Esci");

      //Scelta dell'utente
      gotoxy(20,7);
      printf("Scegli un Programma da eseguire > ");
      scanf("%d", & scelta);

    } while(scelta < 1 || scelta > 4);  //Controllo formale

    switch (scelta) {

      //Numeri perfetti
      case 1: {
        n;
        div = 2;
        sdiv = 1;
        do {
          system("clear");
          gotoxy(17,0);
          printf("TROVA I DIVISORI DI UN NUMERO E SE E' PERFETTO\n" );
          printf("Inserisci un numero: ");
          scanf("%d", &n);
        } while(n<=0);
        cdiv=1;
        printf("I divisori di %d sono: 1, ", n);
        while (div<=n/2) {
          if (n%div == 0) {
            cdiv++;
            printf("%d, ", div);
            sdiv+=div;
          }
          div++;
        }
        if (n!=1) {
          printf("%d\n", n);
          cdiv++;
        }
        printf("I divisori totali sono %d\n", cdiv);
        if (sdiv == n) {
          printf("%d e' un numero perfetto!\n", n);
        }
        else{
          printf("%d non e' un numero perfetto!\n", n);
        }
        printf("\n\nPremi un tasto per continuare...");
        printf(""); //Necessario per il comando successivo
        system("read continue"); //Aspetta la pressione di un tasto
        break;
      }

      //Abbondanti
      case 2: {
        n;
        div = 2;
        sdiv = 1;
        do {
          system("clear");
          gotoxy(11,0);
          printf("TROVA I DIVISORI DI UN NUMERO E CONTROLLA SE E' ABBONDANTE\n" );
          printf("Inserisci un numero: ");
          scanf("%d", &n);
        } while(n<=0);
        cdiv=1;
        printf("I divisori di %d sono: 1, ", n);
        while (div<=n/2) {
          if (n%div == 0) {
            cdiv++;
            printf("%d, ", div);
            sdiv+=div;
          }
          div++;
        }
        if (n!=1) {
          printf("%d\n", n);
          cdiv++;

        }
        printf("I divisori totali sono %d\n", cdiv);
        if (sdiv > n) {
          printf("%d e' un numero abbondante!\n", n);
        }
        else{
          printf("%d non e' un numero abbondante!\n", n);
        }
        printf("\n\nPremi un tasto per continuare...");
        printf(""); //Necessario per il comando successivo
        system("read continue"); //Aspetta la pressione di un tasto
        break;
      }

      //Difettivi
      case 3: {
        n;
        div = 2;
        sdiv = 1;
        do {
          system("clear");
          gotoxy(24,0);
          printf("TROVA I DIVISORI DI UN NUMERO E CONTROLLA SE E' DIFETTIVO\n" );
          printf("Inserisci un numero: ");
          scanf("%d", &n);
        } while(n<=0);
        cdiv=1;
        printf("I divisori di %d sono: 1, ", n);
        while (div<=n/2) {
          if (n%div == 0) {
            cdiv++;
            printf("%d, ", div);
            sdiv+=div;
          }
          div++;
        }
        if (n!=1) {
          printf("%d\n", n);
          cdiv++;

        }
        printf("I divisori totali sono %d\n", cdiv);
        if (sdiv < n) {
          printf("%d e' un numero difettivo!\n", n);
        }
        else{
          printf("%d non e' un numero difettivo!\n", n);
        }
        printf("\n\nPremi un tasto per continuare...");
        printf(""); //Necessario per il comando successivo
        system("read continue"); //Aspetta la pressione di un tasto
        break;
      }
    }
  }while(scelta != 4);
}
