/*
 * lettura_scrittura.h
 *
 *  Created on: 28 nov 2016
 *      Author: Michele97
 */

#ifndef LETTURA_SCRITTURA_H_
#define LETTURA_SCRITTURA_H_

#include "globali.h"

void Scrivere_difficolta(int lunghezza, codice *codice_generato, codice *codice_utente);
void Scrivere_valutazione(int posizione_corretta, int posizione_sbagliata, val *valutazione);
void Scrivere_elemento(int elemento, codice *codice_di_gioco, int posizione);
int Leggere_elemento(codice *codice, int posizione);
int Leggere_difficolta(codice *codice_numerico);
int Leggere_valutazione_corretta(val *valutazione);
int Leggere_valutazione_sbagliata(val *valutazione);

#endif /* LETTURA_SCRITTURA_H_ */
