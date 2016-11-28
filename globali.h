/*
 * globali.h
 *
 *  Created on: 28 nov 2016
 *      Author: Michele97
 */

#ifndef GLOBALI_H_
#define GLOBALI_H_

//-----------------------definizione delle costanti-----------------------

#include<stdio.h>
#include<stdlib.h>

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

#endif /* GLOBALI_H_ */
