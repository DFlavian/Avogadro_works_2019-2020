#include <stdio.h>
#include <stdlib.h>

int main(){
  int a,b;
  printf("Inserisci il primo numero: " );
  scanf("%d", &a);
  printf("Inserisci il secondo numero: " );
  scanf("%d", &b);
  if(a==b){
    printf("I numeri sono uguali!\n" );
  }
  else{
    if (a>b) {
      printf("Il numero maggiore e' %d\n", a);
    }
    else{
      printf("Il numero maggiore e' %d\n", b);
    }
  }
}
