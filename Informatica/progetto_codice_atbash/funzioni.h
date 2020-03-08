#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x, int y){ //Equivalente al gotoxy() della conio2.h
 printf("%c[%d;%df",0x1B,y,x);
}

int stampa_menu(){//Funzione che stampa il menu' principale e che ritorna il valore della scelta
    int rig, sceltaf;
        do{
            system("cls");
            rig = 1;//Inizializzazione utile per mantenere il menu' sulle stesse righe qualora la scelta fosse errata

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

int menu_codifica(){//Funzione che stampa il menu' per la codifica e che ritorna il valore della scelta
    int rig, sceltaf;
        do{
            system("cls");
            rig = 1;//Inizializzazione utile per mantenere il menu' sulle stesse righe qualora la scelta fosse errata

            gotoxy(31,rig);
            printf("CODIFICA MESSAGGIO");

            rig += 2;
            gotoxy(20,rig);
            printf("1. Inserire il messaggio");

            rig += 2;
            gotoxy(20,rig);
            printf("2. Messaggio codificato");


            rig += 2;
            gotoxy(20,rig);
            printf("3. Torna indietro");

            rig += 2;
            gotoxy(20,rig);
            printf("Scelta --> .");
            gotoxy(31,rig);
            scanf("%d", &sceltaf);

        }while(sceltaf<=0 || sceltaf>3);
        return sceltaf;

}


int menu_decodifica(){//Funzione che stampa il menu' per la decodifica e che ritorna il valore della scelta
    int rig, sceltaf;
        do{
            system("cls");
            rig = 1;//Inizializzazione utile per mantenere il menu' sulle stesse righe qualora la scelta fosse errata

            gotoxy(30,rig);
            printf("DECODIFICA MESSAGGIO");

            rig += 2;
            gotoxy(20,rig);
            printf("1. Inserire il messaggio");

            rig += 2;
            gotoxy(20,rig);
            printf("2. Messaggio decodificato");

            rig += 2;
            gotoxy(20,rig);
            printf("3. Torna indietro");

            rig += 2;
            gotoxy(20,rig);
            printf("Scelta --> .");
            gotoxy(31,rig);
            scanf("%d", &sceltaf);

        }while(sceltaf<=0 || sceltaf>3);
        return sceltaf;
}


void Stampa_vettore(char V[]){//Procedura utile alla stampa di un vettore char
    int dim = strlen(V);
    for(int i = 0; i < dim; i++){
        printf("%c", V[i]);
    }
    printf("\n");
}

void upper_string(char s[]){//Procedura utile per l'ottenimento del messaggio SOLO IN MAIUSCOLO
    for (int i = 0; s[i]!='\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {//Controllo per capire se il carattere e' una lettera minuscola
            s[i] = s[i] - 32;
        }
    }
}


void input_msg(char msgf[]){//Procedura per ottenere il messaggio corretto da decodificare
    int ascii;
    int flag;

    do{
      system("cls");
      gotoxy(29,1);
      printf("INSERIRE UN MESSAGGIO");
      flag = 0;
      gotoxy(10,3);
      printf("NON mettere spazi o caratteri speciali");
      gotoxy(10,5);
      printf("--> ");
      gotoxy(14, 5);
      fflush(stdin);
      fflush(stdout);
      fgets(msgf, 80, stdin);
      upper_string(msgf);
      for (int i = 0; msgf[i] != '\0'; i++){//loop fino alla fine della stringa

          ascii = msgf[i];//converte il carattere in un valore numerico rapresentante il suo valore in ASCII

          while((ascii < 65 || ascii > 90) && ascii != 0){  // Controlla se il valore e' una lettera

              if(ascii != 39 && ascii != 10){
                flag = 1;
                break;
              }

              //Se non e' una lattera rimuovi il carattere e slitta tutte le lettere dopo di essa
              ascii = msgf[i+1];
          }
      }

    }while(flag == 1);

    gotoxy(10,5);
    printf("--> ");
    gotoxy(14, 5);
    Stampa_vettore(msgf);
    printf("\n");
    system("pause");
}



void codifica_decodifica(char msgf[]){//Essendo il processo ugual sia per la codifica che per la decodifica, ho deciso di creare una sola funzione per questo scopo
    int i, ascii, n_l;
    int dim = strlen(msgf);
    char cod[dim];

    for(i = 0; i < dim - 1; i++){
        ascii = msgf[i];//converte il carattere in un valore numerico rapresentante il suo valore in ASCII
        ascii = ascii - 65;//Tolgo 65 cosi' abbiamo valori da 0 a 25, rappresentanti le lettere dell'alfabeto in chiaro
        n_l = 25 - ascii;//Operazione utile a capire quale lettera del messaggio corrisponda al secondo alfabeto del codice atbash
        n_l = n_l +65;//Si porta il valore della nuova lettera di nuovo a un valore della tabella ASCII

        cod[i] = n_l;

    }

    system("cls");
    gotoxy(29,1);
    printf("MESSAGGIO TRASFORMATO");
    gotoxy(10,3);
    printf("--> ");
    gotoxy(14, 3);
    Stampa_vettore(cod);
    printf("\n");
    system("pause");
}
