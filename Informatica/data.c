#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
}

void pausa() {
  printf("\n"); //Necessario per il comando successivo
  system("read continue"); //Aspetta la pressione di un tasto (al posto di getchar())
}

int main(){
  int g, m, a;//Giorni, mesi, anni
  int d = 0;  //Decine
  int r = 0;  //Resto
  int u = 0;  //Unita'
  int mi = 0; //migliaia
  int c = 0;  //Centinaia
  int scelta = 0; //Scelta dell'utente
  int stat = 0; //Flag di stato della data

  do { // ------ menu ------
    do { //Prende in input la scelta e fa il controllo formale
      //Pulisce lo schermo
      system("clear");

      //Titolo
      gotoxy(38, 1);
      printf("DATA");

      //Stampa le scelte
      gotoxy(30,3);
      printf("1) Inserisci la data");
      gotoxy(30,4);
      printf("2) Scrivi in lettere");
      gotoxy(30,5);
      printf("3) Segno zodiacale");
      gotoxy(30,6);
      printf("4) Esci");

      //Scelta
      gotoxy(35 ,8);
      printf("Scelta --> .");
      gotoxy(46, 8);
      scanf("%d", &scelta);
    } while(scelta < 1 || scelta > 4);  // Controlla se la condizione 1 < scelta < 4 e' vera
    // ------ fine menu ------

    switch (scelta) {
      case 1:{ // Inserisci la data
        do {
          system("clear");

          //Titolo
          gotoxy(36,1);
          printf("INSERISCI LA DATA");
          do {//Scelta giorno e mese
            do {//Scelta giorno
              gotoxy(40, 3);
              printf("../../....");
              gotoxy(40, 3);
              scanf("%d", &g);
            } while(g < 1 || g > 31); // 1 < g < 31

            do { // Scelta mese
              gotoxy(40, 3);
              if(g < 10) { // Nel caso in cui il giorno e' minore di 10 si stampa lo zero prima
                printf("0");
              }
              printf("%d/../....", g); //Stampa il format del mese per l'input
              gotoxy(43, 3);
              scanf("%d", &m);
            } while(m < 1 || m > 12); // 1 < m < 12
          } while((m == 2 && g > 29) || (g == 31 && (m == 3 || m == 5 || m == 9 || m == 11))); // Controlla se il mese e il giorno possono essere corretti

          //Scelta dell'anno
          do {
            gotoxy(40, 3);
            if(g < 10) { // Nel caso in cui il giorno e' minore di 10 si stampa lo zero prima
              printf("0");
            }
            printf("%d/", g);

            if(m < 10) {// Nel caso in cui il mese e' minore di 10 si stampa lo zero prima
              printf("0");
            }
            printf("%d/....", m);

            //Prende in input l'anno
            gotoxy(46, 3);
            scanf("%d", &a);
          } while((a < 1900 || a > 2100)); // 1900 < a < 2100

        } while((g == 29 && m == 2) && !(a%400 == 0 || (a%4==0 && !(a%100==0)))); // Bisestile

        stat = 1; //Aggiorna il flag dello stato della data
        break;
      }
      case 2:{ // Scrivi in lettere
        system("clear");

        //Controlla se la data e' stata inserita
        if (stat == 0) {
          printf("ATTENZIONE: Devi inserire una data prima di scegliere questa opzione.\n\n");
          printf("Premi un tasto per tornare al menu...");
          pausa();
        }
        else{
          gotoxy(37,1);
          printf("DATA IN LETTERE");

          //Intestazione
          gotoxy(0, 3);
          printf("La data " );
          if (g<10) {
            printf("0");
          }
          printf("%d/", g);
          if (m<10) {
            printf("0");
          }
          printf("%d/%d in lettere e' --> ", m, a);

          //Calcolo in lettere del giorno
          d = g%100 / 10;
          u = g%10;
          if(d != 0){
            if(d==1){  //Controllo casi speciali (10-->19)
              switch(u){
                case 0:{printf("dieci");break;}
                case 1:{printf("undici");break;}
                case 2:{printf("dodici");break;}
                case 3:{printf("tredici");break;}
                case 4:{printf("quattordici");break;}
                case 5:{printf("quindici");break;}
                case 6:{printf("sedici");break;}
                case 7:{printf("diciassette");break;}
                case 8:{printf("diciotto");break;}
                case 9:{printf("diciannove");break;}
              }
            }
            else{
              if(u == 1 || u == 8){
                if(d == 2){
                  printf("vent");
                }
                else{
                  printf("trent");
                }
              }
              else{
                if (d == 2) {
                  printf("venti");
                }
                else if(d == 3){
                  printf("trenta");
                }
              }
            }
          }
          if(d != 1){
            switch (u) {
              case 1:{printf("uno");break;}
              case 2:{printf("due");break;}
              case 3: {printf("tre");break;}
              case 4: {printf("quattro");break;}
              case 5: {printf("cinque");break;}
              case 6: {printf("sei");break;}
              case 7: {printf("sette");break;}
              case 8:{printf("otto");break;}
              case 9: {printf("nove");break;}
            }
          }

          //Stampa mese
          switch (m) {
            case 1:{printf(" gennaio");break;}
            case 2:{printf(" febbraio");break;}
            case 3:{printf(" marzo");break;}
            case 4:{printf(" aprile");break;}
            case 5:{printf(" maggio");break;}
            case 6:{printf(" giugno");break;}
            case 7:{printf(" luglio");break;}
            case 8:{printf(" agosto");break;}
            case 9:{printf(" settembre");break;}
            case 10:{printf(" ottobre");break;}
            case 11:{printf(" novembre");break;}
            case 12:{printf(" dicembre");break;
            }
          }

          //anno
          //Calcolo delle singole cifre
          mi = a / 1000;
          r = a%1000;

          c = r / 100;
          r = a%100;

          d = r / 10;
          r = a%100;

          u = a%10;

          if(mi == 1) {
            printf(" mille");
          }
          else if(mi == 2){
            printf(" duemila");
          }
          //Controllo per vedere la cifra delle centinaia e stampare il valore in lettere
              if(d == 8) {//In questa parte si controlla se la decina e' 8 (cent-ottanta, duecent-ottanta,...)
                switch(c)
                {
                  case 1: {
                    printf("cent");
                    break;
                  }
                  case 2: {
                   printf("duecent");
                   break;
                  }
                  case 3:{
                   printf("trecent");
                   break;
                  }
                  case 4:{
                   printf("quattrocent");
                   break;
                  }
                  case 5:{
                   printf("cinquecent");
                   break;
                  }
                  case 6:{
                   printf("seicent");
                   break;
                  }
                  case 7:{
                   printf("settecent");
                   break;
                  }
                  case 8:{
                   printf("ottocent");
                   break;
                  }
                  case 9:{
                   printf("novecent");
                   break;
                  }
                }
              }
              else{
                switch(c)
                {
                  case 1: {
                    printf("cento");
                    break;
                  }

                  case 2: {
                    printf("duecento");
                    break;
                  }
                  case 3:{
                    printf("trecento");
                    break;
                  }
                  case 4:{
                    printf("quattrocento");
                    break;
                  }
                  case 5:{
                    printf("cinquecento");
                    break;
                  }
                  case 6:{
                    printf("seicento");
                    break;
                  }
                  case 7:{
                    printf("settecento");
                    break;
                  }
                  case 8:{
                    printf("ottocento");
                    break;
                  }
                  case 9:{
                    printf("novecento");
                    break;
                  }
                }
              }


          //Controllo dei casi speciali delle decine (unità 1 oppure 8)
            if((u==1 || u==8) && d!=1){

                switch(d)
                 {
                   case 2: {
                    printf("vent");
                    break;
                   }
                   case 3:{
                    printf("trent");
                    break;
                   }
                   case 4:{
                    printf("quarant");
                    break;
                   }
                   case 5:{
                    printf("cinquant");
                    break;
                   }
                   case 6:{
                    printf("sessant");
                    break;
                   }
                   case 7:{
                    printf("settant");
                    break;
                   }
                   case 8:{
                    printf("ottant");
                    break;
                   }
                   case 9:{
                    printf("novant");
                    break;
                   }
                }
                  if (u==1) {//Controllo per capire se l'unità è 1 oppure 8
                    printf("uno");
                  }else{
                    printf("otto");
                  }
               }
               else if(d==1){  //Controllo casi speciali (11-->19)
                 switch(u){
                   case 0:{
                     printf("dieci");
                     break;
                   }
                   case 1:{
                     printf("undici");
                     break;
                   }
                   case 2:{
                      printf("dodici");
                     break;
                   }
                   case 3:{
                      printf("tredici");
                     break;
                   }
                   case 4:{
                      printf("quattordici");
                     break;
                   }
                   case 5:{
                      printf("quindici");
                     break;
                   }
                   case 6:{
                      printf("sedici");
                     break;
                   }
                   case 7:{
                      printf("diciassette");
                     break;
                   }
                   case 8:{
                      printf("diciotto");
                     break;
                   }
                   case 9:{
                      printf("diciannove");
                     break;
                   }
                 }


               }
               else {
                 switch(d)
                 {
                   case 2: {
                      printf("venti");
                    break;
                   }
                   case 3:{
                      printf("trenta");
                    break;
                   }
                   case 4:{
                      printf("quaranta");
                    break;
                   }
                   case 5:{
                      printf("cinquanta");
                    break;
                   }
                   case 6:{
                      printf("sessanta");
                    break;
                   }
                   case 7:{
                      printf("settanta");
                    break;
                   }
                   case 8:{
                      printf("ottanta");
                    break;
                   }
                   case 9:{
                      printf("novanta");
                    break;
                   }
                }


                  switch(u)
                  {
                     case 2: {
                      printf("due");
                      break;
                     }
                     case 3:{
                      printf("tre");
                      break;
                     }
                     case 4:{
                      printf("quattro");
                      break;
                     }
                     case 5:{
                      printf("cinque");
                      break;
                     }
                     case 6:{
                      printf("sei");
                      break;
                     }
                     case 7:{
                      printf("sette");
                      break;
                     }
                     case 9:{
                      printf("nove");
                     }
                  }

              }

          printf("\n\nPremi un tasto per continuare...");
          pausa();
        }
        break;
      }
      case 3:{ //Segno zodiacale
        system("clear");

        //Controlla se la data e' stata inserita
        if (stat == 0) {
          printf("ATTENZIONE: Devi inserire una data prima di scegliere questa opzione.\n\n");
          printf("Premi un tasto per tornare al menu...");
          pausa();
        }
        else{
          gotoxy(37,1);
          printf("SEGNO ZODIACALE");
          gotoxy(20, 3);
          printf("Il segno zodiacale della data " );
          if (g<10) {
            printf("0");
          }
          printf("%d/", g);
          if (m<10) {
            printf("0");
          }
          printf("%d/%d e' --> ", m, a);
          if ((g >= 21 && m == 3) || (g <= 20 && m == 4)) {
            printf("Ariete");
          }
          else if ((g >= 21 && m == 4) || (g <= 20 && m == 5)) {
            printf("Toro");
          }
          else if ((g >= 21 && m == 5) || (g <= 20 && m == 6)) {
            printf("Gemelli");
          }
          else if ((g >= 21 && m == 6) || (g <= 22 && m == 7)) {
            printf("Cancro");
          }
          else if ((g >= 23 && m == 7) || (g <= 23 && m == 8)) {
            printf("Leone");
          }
          else if ((g >= 24 && m == 8) || (g <= 22 && m == 9)) {
            printf("Vergine");
          }
          else if ((g >= 23 && m == 9) || (g <= 22 && m == 10)) {
            printf("bilancia");
          }
          else if ((g >= 23 && m == 10) || (g <= 22 && m == 11)) {
            printf("Scorpione");
          }
          else if ((g >= 23 && m == 11) || (g <= 21 && m == 12)) {
            printf("Saggitario");
          }
          else if ((g >= 22 && m == 12) || (g <= 20 && m == 1)) {
            printf("Capricorno");
          }
          else if ((g >= 21 && m == 1) || (g <= 19 && m == 2)) {
            printf("Acquario");
          }
          else if ((g >= 20 && m == 2) || (g <= 20 && m == 3)) {
            printf("Pesci");
          }

          printf("\n\nPremi un tasto per continuare...");
          pausa();
        }

        break;
      }
    }

  }while(scelta != 4); //condizione di uscita
  system("clear");
  return 0;
}
