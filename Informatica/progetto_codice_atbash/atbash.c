#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funzioni.h"

void main(){
    char msg[80];
    int scelta;//variabile utile alla scelta dell'operazione da eseguire
    int flag = 0;//Flag utile per capire se si vuole tornare indietro dai menu' codifica/decodifica
    int msg_ins = 0;


    do{
        scelta = menu_codifica();

        switch(scelta){
            case 1:{
                input_msg(msg);
                msg_ins = 1;
                break;
            }

            case 2:{
                if(msg_ins == 1){
                    flag == 1;
                    codifica_decodifica(msg);
                }else{
                    system("cls");
                    printf("INSERIRE PRIMA UN MESSAGGIO DA CODIFICARE!!\n");
                    system("pause");
                }
                break;
            }
        }
    }while(flag == 0 || scelta != 3);

    flag = 0;
    msg_ins = 0;

    do{
        scelta = menu_decodifica();

        switch(scelta){
            case 1:{
                input_msg(msg);
                msg_ins = 1;
                break;
            }

            case 2:{
                if(msg_ins == 1){
                    flag == 1;
                    codifica_decodifica(msg);
                }else{
                    system("cls");
                    printf("INSERIRE PRIMA UN MESSAGGIO DA DECODIFICARE!!\n");
                    system("pause");
                }
                break;
            }
        }
    }while(flag == 0 || scelta != 3);


}
