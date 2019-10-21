#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
 }

int main() {
  int n1, n2;
  int div = 2;
  int sdiv1 = 1;
  int sdiv2 = 1;

  do {
    system("clear");
    gotoxy(22,0);
    printf("CONTROLLA SE 2 NUMERI SONO AMICABILI\n" );
    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &n2);
  } while(n1<=0 || n2<=0);

  int cdiv1=1;
  int cdiv2=1;
  printf("I divisori di %d sono: 1, ", n1);

  while (div<=n1/2) {
    if (n1%div == 0) {
      cdiv1++;
      printf("%d, ", div);
      sdiv1 += div;
    }
    div++;
  }

  if (n1!=1) {
    printf("%d\n", n1);
    cdiv1++;
  }
  div = 2;
  printf("I divisori di %d sono: 1, ", n2);

  while (div<=n2/2) {
    if (n2%div == 0) {
      cdiv2++;
      printf("%d, ", div);
      sdiv2 += div;
    }
    div++;
  }


  if (n2!=1) {
    printf("%d\n", n2);
    cdiv2++;
  }

  printf("I divisori totali di %d sono %d\n", n1, cdiv1);
  printf("I divisori totali di %d sono %d\n", n2, cdiv2);

  if (sdiv1 == n2 && sdiv2 == n1) {
    printf("I numeri %d e %d sono amicabili!\n", n1, n2);
  }
  else{
    printf("I numeri %d e %d non sono amicabili!\n", n1, n2);
  }
  return 0;
}
