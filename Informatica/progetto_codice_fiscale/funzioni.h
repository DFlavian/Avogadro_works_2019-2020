#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void stampa_menu(){
	system("cls");//serve per pulire la schermata
    int rig = 1;    //questa variabile e' utile al posizionamento delle stampe
    gotoxy(33,rig); //1° rigo
    printf("CODICE FISCALE");
    rig = rig + 2;
    
	
	gotoxy(25,rig++);//4° rigo per il nome
    printf("NOME:");
    gotoxy(25,rig++);//5° rigo per il cognome
    printf("COGNOME:");
    for(rig=3;rig<5;rig++){
    	gotoxy(50,rig);
    	printf("..............................");
	}
    
    gotoxy(25,rig++);//6° rigo per la data
    printf("DATA:");
    gotoxy(50,5);
    printf("../../....");
    
    gotoxy(25,rig++);//7° rigo per il genere
    printf("GENERE (M/F):");
    gotoxy(50,6);
    printf(".");
    
    gotoxy(25,rig++);//8° rigo per il luogo di nascita
    printf("LUOGO DI NASCITA:");
	gotoxy(50,7);
    printf("..............................");
         
}

void stampa_titolo(){
    int rig = 1;
    gotoxy(33,rig);
    printf("CODICE FISCALE");
}


void Stampa_vettore(char V[]){
    int dim = strlen(V);
    for(int i = 0; i < dim; i++){
        printf("%c", V[i]);
    }
    
}

void upper_string(char s[]){
    for (int i = 0; s[i]!='\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] -32;
        }
    }
}


void data(int &gf,int &mf,int &af){
	int giorni_mesi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i = 0;
	
	
	//Controlla le date
      for (i = 0; i < 2; i++) {
          //Controlla se l'anno e' bisestile
          if((gf == 29 && mf == 2) && !(af%400 == 0 || (af%4==0 && !(af%100==0)))){
            giorni_mesi[1] = 29;
          }
      }
      
      
}
#endif // FUNZIONI_H_INCLUDED
