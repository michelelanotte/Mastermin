#ifndef INTERFACCIA_H_
#define INTERFACCIA_H_

#include <unistd.h>
#include <string.h>
#include "lettura_scrittura.h"

#define DIM_PERCORSO 300
#define DIM_MAX 10

//prototipi delle funzioni che hanno a che fare con l'interfacciamento con l'utente
void Presentazione();
void Acquisire_difficolta_scelta(codice *codice_generato, codice *codice_utente, val *valutazione, int *tentativi);
void Chiedere_ammissione_doppioni(int *doppioni);
void Acquisire_parola_utente(codice *codice_utente);
void Stampa_valutazione(val *valutazione);
void Stampa_esito(int esito_parole_uguali, int contatore_tentativi, int tentativi);

#endif /* INTERFACCIA_H_ */
