#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
}

int main(int argc, char const *argv[]) {
  int col = 37;
  int rig = 0;
  system("clear");
  gotoxy(37,0);
  printf("MATRIX\n" );
  usleep(3000000);
  col = 0;
  rig = 0;
  do {
    system("clear");
    gotoxy(col, rig);
    printf("ciao\n");
    col++;
    usleep(50000);
  } while(col<38);


  do {
    system("clear");
    gotoxy(col, rig);
    printf("c");
    gotoxy(39,0);
    printf("iao\n");
    rig++;
    usleep(50000);
  } while(rig<25);
  rig = 0;
  col++;
  do {
    system("clear");
    gotoxy(col, rig);
    printf("i");
    gotoxy(40,0);
    printf("ao\n");
    rig++;
    usleep(50000);
  } while(rig<25);
  rig = 0;
  col++;
  do {
    system("clear");
    gotoxy(col, rig);
    printf("a");
    gotoxy(41,0);
    printf("o\n");
    rig++;
    usleep(50000);
  } while(rig<25);
  rig = 0;
  col++;
  do {
    system("clear");
    gotoxy(col, rig);
    printf("o");
    gotoxy(42,0);
    printf("\n");
    rig++;
    usleep(50000);
  } while(rig<25);
  system("clear");
  return 0;
}
