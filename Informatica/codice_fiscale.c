#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
}

void pausa() {
  printf("\n"); //Necessario per il comando successivo
  system("read continue"); //Aspetta la pressione di un tasto (al posto di getchar())
}

int main(){
    char nome[30];
    gotoxy();
    printf("CODICE FISCALE");
}
