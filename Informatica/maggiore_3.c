#include <stdio.h>
#include <stdlib.h>

int main(){
  int a, b, c;
  printf("Inserisci il primo numero: " );
  scanf("%d", &a);
  printf("Inserisci il secondo numero: " );
  scanf("%d", &b);
  printf("Inserisci il terzo numero: " );
  scanf("%d", &c);
  if(!(a == b && c == b && c == a)){
    if(a > b){
      if (a > c) {
        printf("Il numero maggiore e' %d\n", a);
      }
      else{
        printf("Il numero maggiore e' %d\n", c);
      }
    }
    else if(b > c){
      printf("Il numero maggiore e' %d\n", b);
    }
    else{
      printf("Il numero maggiore e' %d\n", c);
    }
  }
  else{
    printf("I numeri inseriti sono uguali\n");
  }
}
