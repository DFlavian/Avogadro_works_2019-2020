#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

//-------------------------------------------

void Stampa_vettore(char Vf[]);
void inserisci_bit(char bitf[]);
void Calcolo_crc(char crc[], char msgf[], char gf[]); 
void xor_vet(char R[], char V1[], char V2[]);

//-------------------------------------------

int main(){
    char msg[MAX];
    char g[MAX];
    char crc[MAX];
    char R[MAX];
    inserisci_bit(msg);
    Stampa_vettore(msg);
    inserisci_bit(g);
    Stampa_vettore(g);
    Calcolo_crc(crc, msg, g);
    Stampa_vettore(msg);
    xor_vet(R, msg, g);
    Stampa_vettore(R);
    return 0;
}

//-------------------------------------------

void Stampa_vettore(char Vf[]){
    int dim = strlen(Vf);
    for(int i = 0; i < dim; i++){
        printf("%c", Vf[i]);
    }
    printf("\n");
}

void inserisci_bit(char bitf[]){
    int flag;
    do{
        flag = 0;
        fgets(bitf, 30, stdin);
        for(int i = 0; i < strlen(bitf)-1; i++){
            if(bitf[i] != '0' && bitf[i] != '1'){
                flag = 1;
                break;
            }
        }
    }while(flag == 1);

}

void Calcolo_crc(char crc[], char msgf[], char gf[]){
    int i;
    int dimg = strlen(gf);
    char div[MAX];

    //Aggiungi gli zeri alla fine
    
    int j = strlen(msgf) - 1;

    for(i = 0; i < dimg - 2; i++){
        msgf[j] = '0';
        j++;
    }
    msgf[j] = '\0';

    //Calcolo CRC
    int p = 0;
    j = 0;
    for(i = p; i < dimg; i++){
        div[j] = msgf[i];
        j++;
    }
    
    while(p < strlen(msgf)){
        
    };
}

void xor_vet(char R[], char V1[], char V2[]){
    for(int i = 0; i < strlen(V1); i++){
        if(V1[i] != V2[i]){
            R[i] = '1';
        }
        else{
            R[i] = '0';
        }
    }
}

