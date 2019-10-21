#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
 }

int main() {
  int n;
  int div = 2;
  int sdiv = 1;
  do {
    system("clear");
    gotoxy(17,0);
    printf("TROVA I DIVISORI DI UN NUMERO E SE E' PERFETTO\n" );
    printf("Inserisci un numero: ");
    scanf("%d", &n);
  } while(n<=0);
  int cdiv=1;
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
  return 0;
}
