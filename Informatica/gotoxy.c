#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
 }

int main() {
  system("clear");
  gotoxy(40,0);
  printf("23\n");
  return 0;
}
