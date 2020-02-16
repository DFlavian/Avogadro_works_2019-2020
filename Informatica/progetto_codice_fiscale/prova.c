#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funzioni.h"
const int dim = 30;


int main(){
    char nome[dim];

	stampa_titolo();
    stampa_menu();
    gotoxy(50,3);
    gets(nome);
    upper_string(nome);
    gotoxy(50,3);
    Stampa_vettore(nome);
}
