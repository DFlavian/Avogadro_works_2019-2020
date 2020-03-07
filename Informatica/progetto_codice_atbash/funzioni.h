#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x, int y){ //Equivalente al gotoxy() della conio2.h
 printf("%c[%d;%df",0x1B,y,x);
}

int stampa_menu(){
    int rig, sceltaf;
        do{
            system("cls");
            rig = 1;

            gotoxy(33,rig);
            printf("CODICE ATBASH");

            rig += 2;
            gotoxy(20,rig);
            printf("1. Codifica un messaggio");

            rig += 2;
            gotoxy(20,rig);
            printf("2. Decodifica un messaggio");


            rig += 2;
            gotoxy(20,rig);
            printf("3. Esci");

            rig += 2;
            gotoxy(20,rig);
            printf("Scelta --> .");
            gotoxy(31,rig);
            scanf("%d", &sceltaf);

        }while(sceltaf<=0 || sceltaf>3);
        return sceltaf;
}

int menu_codifica(){
    int rig, sceltaf;
        do{
            system("cls");
            rig = 1;

            gotoxy(31,rig);
            printf("CODIFICA MESSAGGIO");

            rig += 2;
            gotoxy(20,rig);
            printf("1. Inserire il messaggio");

            rig += 2;
            gotoxy(20,rig);
            printf("2. Inserire la chiave");

            rig += 2;
            gotoxy(20,rig);
            printf("3. Messaggio codificato");


            rig += 2;
            gotoxy(20,rig);
            printf("4. Torna indietro");

            rig += 2;
            gotoxy(20,rig);
            printf("Scelta --> .");
            gotoxy(31,rig);
            scanf("%d", &sceltaf);

        }while(sceltaf<=0 || sceltaf>4);
        return sceltaf;

}


int menu_decodifica(){
    int rig, sceltaf;
        do{
        system("cls");
        rig = 1;

        gotoxy(30,rig);
        printf("DECODIFICA MESSAGGIO");

        rig += 2;
        gotoxy(20,rig);
        printf("1. Inserire il messaggio");

        rig += 2;
        gotoxy(20,rig);
        printf("2. Inserire la chiave");

        rig += 2;
        gotoxy(20,rig);
        printf("3. Messaggio decodificato");

        rig += 2;
        gotoxy(20,rig);
        printf("4. Torna indietro");

        rig += 2;
        gotoxy(20,rig);
        printf("Scelta --> .");
        gotoxy(31,rig);
        scanf("%d", &sceltaf);

        }while(sceltaf<=0 || sceltaf>4);
        return sceltaf;
}


void Stampa_vettore(char V[]){
    int dim = strlen(V);
    for(int i = 0; i < dim; i++){
        printf("%c", V[i]);
    }
    printf("\n");
}

void upper_string(char s[]){
    for (int i = 0; s[i]!='\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
    }
}


void input_msg(char msgf[]){
    int ascii;
    int flag;
    system("cls");
    do{
      flag = 0;
      gotoxy(45,3);
      printf("..............................");
      gotoxy(45, 3);
      fgets(msgf, 80, stdin);
      upper_string(msgf);
      for (int i = 0; msgf[i] != '\0'; i++){//loop fino alla fine della stringa
          ascii = msgf[i];//converte il carattere in un valore numerico rapresentante il suo valore in ASCII
          while((ascii <= 65 || ascii >= 90) && ascii != 0){  // Controlla se il valore e' una lettera
              if((ascii >= 0 && ascii < 65) || (ascii > 90 && ascii <= 127)){
                flag = 1;
                break;
              }
              ascii = msgf[i+1];
          }
      }
    }while(flag == 1);
    gotoxy(45,3);
    printf("..............................");
    gotoxy(45, 3);
    Stampa_vettore(msgf);
}
