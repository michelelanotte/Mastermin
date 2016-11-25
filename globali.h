#include<stdio.h>
#include<stdlib.h>

//-----------------------definizione delle costanti-----------------------
#define LUNGHEZZA_MAX 8
#define MAX_TENTATIVI 9
#define VALMAX 9
#define VALMIN 1


//-----------------------definizione delle strutture-----------------------
typedef struct {
  char codice_gioco[LUNGHEZZA_MAX];
  int lunghezza_codice;
}codice;

typedef struct {
  int posizione_corretta;
  int posizione_sbagliata;
}val;
