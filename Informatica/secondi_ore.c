#include <stdio.h>
#include <stdlib.h>

int main() {
  int sec, ore, min, r;
  printf("Inserire il tempo in secondi: ");
  scanf("%d", &sec);
  if(sec > 0){
    ore = sec/3600;
    r = sec%3600;
    min = r/60;
    r = r%60;
    printf("Il tempo in secondi %d equivale a %d:%d:%d\n", sec, ore, min, r );
  }
  else{
    printf("Il tempo non puo' essere negativo! \n");
  }
}
