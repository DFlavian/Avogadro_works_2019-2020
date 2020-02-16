#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "base.h"


int main(){
    int min[31];
    int max[31];
    int giorni[31];
    int i;
    for(i = 0; i < 31; i++){
        giorni[i] = i+1;
    }
    Stampa_giorni(giorni);
    
    for(i = 0; i<31; i++){
        do{
            system("clear");
            printf("Inserisci la temperatura massima del %d giorno: ", i+1);
            scanf("%d", &max[i]);
        }while (max[i] > 57 || max[i] < -98);
    }

    for(i = 0; i<31; i++){
        do{
            system("clear");
            printf("Inserisci la temperatura minima del %d giorno: ", i+1);
            scanf("%d", &min[i]);
        }while (max[i] > 57 || max[i] < -98 || (min[i] > max[i]));
    }   

}

