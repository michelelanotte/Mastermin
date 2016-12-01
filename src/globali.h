#ifndef GLOBALI_H_
#define GLOBALI_H_

//-----------------------definizione delle costanti-----------------------

#include<stdio.h>
#include<stdlib.h>

#define LUNGHEZZA_MAX 8
#define VALMAX 9
#define VALMIN 1


//-----------------------definizione delle strutture-----------------------
typedef struct {
  int codice_gioco[LUNGHEZZA_MAX];
  int lunghezza_codice;
}codice;

typedef struct {
  int codice[LUNGHEZZA_MAX];
  int lunghezza_codice;
}val;
#endif /* GLOBALI_H_ */
