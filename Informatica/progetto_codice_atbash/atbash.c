#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funzioni.h"

void main(){
    char msg[80];
    int scelta;//variabile utile alla scelta dell'operazione da eseguire

    scelta = stampa_menu();//si stampa il menu' principale e si memorizza la scelta

    /*switch(scelta){
        case 1:{
            scelta = menu_codifica();//si stampa il menu' per la codifica e si memorizza la scelta
            break;
        }

        case 2:{
            scelta = menu_decodifica();//si stampa il menu' per la decodifica e si memorizza la scelta
            break;
        }
    }*/

    /*if(scelta == 4){
        scelta = stampa_menu;
    }*/

    input_msg(msg);

}
