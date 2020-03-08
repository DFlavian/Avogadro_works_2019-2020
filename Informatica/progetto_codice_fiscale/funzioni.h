//<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
//#ifndef HEADER_FILE
//#define HEADER_FILE

void gotoxy(int x,int y){ //Equivalente al gotoxy() della conio2.h
 printf("%c[%d;%df",0x1B,y,x);
}

void pausa() {
  printf("\n"); //Necessario per il comando successivo
  system("read continue"); //Aspetta la pressione di un tasto (al posto di getchar())
}

void stampa_titolo(){
  int rig = 1;
  gotoxy(33,rig);
  printf("CODICE FISCALE");
}

void stampa_menu(){
  system("cls");//serve per pulire la schermata
  int rig = 1;    //questa variabile e' utile al posizionamento delle stampe
  stampa_titolo();
  rig = rig + 2;


  gotoxy(10,rig++);//4° rigo per il nome
  printf("NOME:");
  gotoxy(10,rig++);//5° rigo per il cognome
  printf("COGNOME:");
  for(rig=3;rig<5;rig++){
      	gotoxy(45,rig);
      	printf("..............................");
  	   }

      gotoxy(10,rig++);//6° rigo per la data
      printf("DATA:");
      gotoxy(45,5);
      printf("../../....");

      gotoxy(10,rig++);//7° rigo per il genere
      printf("GENERE (M/F):");
      gotoxy(45,6);
      printf(".");

      gotoxy(10,rig++);//8° rigo per il luogof di nascita
      printf("LUOGO DI NASCITA: (codice castale)");
  	  gotoxy(45,7);
      printf("....");

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
            s[i] = s[i] -32;
        }
    }
}

int input_nome(char nome[]){
    int ascii;
    int flag;
    do{
      flag = 0;
      gotoxy(45,3);
      printf("..............................");
      gotoxy(45, 3);
      fgets(nome, 30, stdin);
      upper_string(nome);
      for (int i = 0; nome[i] != '\0'; i++){//loop fino alla fine della stringa
          ascii = nome[i];//converte il carattere in un valore numerico rapresentante il suo valore in ASCII
          while((ascii < 65 || ascii > 90) && ascii != 0){  // Controlla se il valore e' una lettera
              if(ascii != 39 && ascii != 10){
                flag = 1;
                break;
              }
              ascii = nome[i+1];
          }
      }
    }while(flag == 1);
    gotoxy(45,3);
    printf("..............................");
    gotoxy(45, 3);
    Stampa_vettore(nome);
    return 0;
}

int input_cognome(char cognome[]){
    int ascii;
    int flag;
    do{
      flag = 0;
      gotoxy(45,4);
      printf("..............................");
      gotoxy(45, 4);
      fgets(cognome, 30, stdin);
      upper_string(cognome);
      for (int i = 0; cognome[i] != '\0'; i++){//loop fino alla fine della stringa
          ascii = cognome[i];//converte il carattere in un valore numerico rapresentante il suo valore in ASCII
          while((ascii < 65 || ascii > 90) && ascii != 0){  // Controlla se il valore e' una lettera
              if(ascii != 39 && ascii != 10){
                flag = 1;
                break;
              }
              //Se non e' una lattera rimuovi il carattere e slitta tutte le lettere dopo di essa
              ascii = cognome[i+1];
          }
      }
    }while(flag == 1);
    gotoxy(45,4);
    printf("..............................");
    gotoxy(45, 4);
    Stampa_vettore(cognome);
    return 0;
}

void input_data(int &gf,int &mf,int &af){
	int giorni_mesi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i = 0;
  //input giorno
  do{
    gotoxy(10,5);
    printf("DATA:");
    gotoxy(45,5);
    printf("../../....");
    gotoxy(45, 5);
    scanf("%d", &gf);
  }while(gf < 0 || gf > 31);

  //input mese
  do{
    do{
      gotoxy(10,5);
      printf("DATA:");
      gotoxy(45,5);
      if(gf < 10){
        printf("0");
      }
      printf("%d/../....", gf);
      gotoxy(48, 5);
      scanf("%d", &mf);
    }while(mf<0 || mf > 12);
  }while((mf == 2 && gf > 29) || (gf == 31 && (mf == 3 || mf == 5 || mf == 9 || mf == 11))); //Controlla se il mese e' valido con i giorni

  //input anno
  do{
    do{
      gotoxy(10,5);
      printf("DATA:");
      gotoxy(45,5);
      if(gf < 10){
        printf("0");
      }
      printf("%d/", gf);
      if(mf < 10){
        printf("0");
      }
      printf("%d/....", mf);
      gotoxy(51, 5);
      scanf("%d", &af);
    }while(af < 1900 || af > 2100);
  }while((gf == 29 && mf == 2) && !(af%400 == 0 || (af%4==0 && !(af%100==0)))); // Bisestile

  //Stampa tutta la data
  gotoxy(10,5);//6° rigo per la data
  printf("DATA:");
  gotoxy(45,5);
  if(gf < 10){
    printf("0");
  }
  printf("%d/", gf);
  if(mf < 10){
    printf("0");
  }
  printf("%d/", mf);
  printf("%d", af);

}

void input_genere(char &generef){
  do{
    gotoxy(45,6);
    printf(".");
    gotoxy(45,6);
    scanf(" %c", &generef);
    getchar();
    generef = toupper(generef);
  }while(generef != 'M' && generef != 'F');
  gotoxy(45,6);
  printf("%c", generef);
}

//Input del luogo
void input_luogo(char luogof[]){
  int flag;
  int ascii;
  do{
    flag = 0;
    gotoxy(45,7);
    printf("....");
    gotoxy(45,7);
    fflush(stdin);
    fflush(stdout);
    fgets(luogof, 100, stdin);
    upper_string(luogof);
    ascii = luogof[0];
    if((ascii < 65 || ascii > 90) || strlen(luogof) < 4){
      flag = 1;
    }
    else{
      for(int i = 1; i < 4; i++){
        ascii = luogof[i];
        if(ascii < 48 || ascii > 57){
          flag = 1;
        }
      }
    }
  }while(flag == 1);
  gotoxy(45,7);
  Stampa_vettore(luogof);
}
/*=======
>>>>>>> 7e2e14689f61dfb70de5df12e3538ab410b9447c*/
