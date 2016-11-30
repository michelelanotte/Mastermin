/*
 * lettura_scrittura.h
 *
 *  Created on: 28 nov 2016
 *      Author: Michele97
 */

#ifndef LETTURA_SCRITTURA_H_
#define LETTURA_SCRITTURA_H_

#include "globali.h"

void Scrivere_difficolta(int lunghezza, codice *codice_generato, codice *codice_utente, val *valutazione);
void Scrivere_elemento(int elemento, codice *codice_di_gioco, int posizione);
void Scrivere_valutazione(char elemento, val *valutazione, int posizione);

void Inizializza_valutazione(val * valutazione);

int Leggere_elemento(codice *codice, int posizione);
int Leggere_elemento_valutazione(val *valutazione, int posizione);
int Leggere_difficolta(codice *codice_numerico);
int Leggere_difficolta_valutazione(val *valutazione);
int Leggere_valutazione_corrette(val *valutazione);
void Leggere_valutazione_presenti(val *valutazione, int *presenti);

#endif /* LETTURA_SCRITTURA_H_ */
