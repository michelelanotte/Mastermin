/*
 * interfaccia.h
 *
 *  Created on: 28 nov 2016
 *      Author: Michele97
 */

#ifndef INTERFACCIA_H_
#define INTERFACCIA_H_

#include "lettura_scrittura.h"

//prototipi delle funzioni che hanno a che fare con l'interfacciamento con l'utente
void Presentazione();
void Acquisire_difficolta_scelta(codice *codice_generato, codice *codice_utente);
void Chiedere_ammissione_doppioni(int *doppioni);
void Acquisire_parola_utente(codice *codice_utente);
void Stampa_valutazione(val *valutazione);
void Stampa_esito(int esito_parole_uguali, int tentativi);

#endif /* INTERFACCIA_H_ */
