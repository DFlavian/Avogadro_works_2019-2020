#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
 }

int main() {
  int n;
  int div = 2;
  do {
    system("clear");
    gotoxy(25,0);
    printf("TROVA I DIVISORI DI UN NUMERO\n" );
    printf("Inserisci un numero: ");
    scanf("%d", &n);
  } while(n<=0);
  int cdiv=1;
  printf("I divisori di %d sono: 1, ", n);
  while (div<=n/2) {
    if (n%div == 0) {
      cdiv++;
      printf("%d, ", div);
    }
    div++;
  }
  if (n!=1) {
    printf("%d\n", n);
    cdiv++;
  }
  printf("I divisori totali sono %d\n", cdiv);
  return 0;
}
