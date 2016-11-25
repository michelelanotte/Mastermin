#include<time.h>
#include "globali.h"

void Generare_parola(codice *codice_generato);
void Valutazione_parola(codice *codice_generato, codice *codice_utente, val *valutazione);
int Simbolo_presente(int valore, codice *codice_generato, int posizione_elemento);
int Controllo_parole_uguali(val *valutazione, int lunghezza);
void Stampa_valutazione(val *valutazione);
