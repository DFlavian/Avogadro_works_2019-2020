#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "funzioni.h"

#define MAX 30

int main(){

  char nome[MAX];
  char cognome[MAX];

  int g, m, a; //Giorno, mese, anno

  char genere;

  char luogo[4];

  stampa_menu();
  input_nome(nome);
  input_cognome(cognome);
  /*input_data(g, m, a);
  input_genere(genere);
  input_luogo(luogo);*/
}
