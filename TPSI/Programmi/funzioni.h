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

void upper_string(char s[]){
    for (int i = 0; s[i]!='\0'; i++) {
        //printf("Debug: %c\n", s[i]);
        if(s[i] >= 'a' && s[i] <= 'z') {
         s[i] = s[i] -32;
        }
    }
    //printf("Debug: Fine upper_string\n");
}

void Stampa_vettore(char V[]){
    int dim = strlen(V);
    for(int i = 0; i < dim; i++){
        printf("%c", V[i]);
    }
    printf("\n");
}

void input_msg(char msgf[]){
    int ascii;
    int flag;
    //printf("Inserisci il msgf: ");
    do{
      flag = 0;
      gotoxy(20,5);
      printf("..................................................");
      gotoxy(20, 5);
      fgets(msgf, 30, stdin);
      upper_string(msgf);
      for (int i = 0; msgf[i] != '\0'; i++){//loop fino alla fine della stringa
          ascii = msgf[i];//converte il carattere in un valore numerico rapresentante il suo valore in ASCII
          while((ascii < 65 || ascii > 90)/* && (ascii != 0 && ascii !=*/ )){  // Controlla se il valore e' una lettera
              if(ascii != 39 && ascii != 10){
                flag = 1;
              }
              //Se non e' una lattera rimuovi il carattere e slitta tutte le lettere dopo di essa
              for(int j = i; msgf[j] != '\0'; j++){
                  msgf[j] = msgf[j+1];
              }
              ascii = msgf[i];
          }
      }
    }while(flag == 1);
    gotoxy(20,5);
    printf("..................................................");
    gotoxy(20, 5);
    Stampa_vettore(msgf);
}
