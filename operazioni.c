/*
 * operazioni.c
 *
 *  Created on: 28 nov 2016
 *      Author: Michele97
 */

#include "lettura_scrittura.h"

void Generare_parola(codice *codice_generato)
{
  int i;
  int numero_generato;
  int doppioni = 0;
  Chiedere_ammissione_doppioni(&doppioni);
  srand(time(NULL));   //funzione della libreria time.h che permetterà in seguito di generare il codice da indovinare
  i = 0;
  printf("\ncodice generato(codice da indovinare):");
  while(i < Leggere_difficolta(codice_generato))
  {
	do {
       numero_generato = rand() % (VALMAX + VALMIN);  //tale istruzione genera un numero casuale che sia compreso tra VALMAX e VALMIN
	}while((doppioni == 0) && (Simbolo_presente(numero_generato, codice_generato, i)));
	Scrivere_elemento(numero_generato, &*codice_generato, i);

	printf(" %d ", *(codice_generato->codice_gioco + i));

    i = i + 1;
  }
  printf("\n");
  return;
}



void Valutazione_parola(codice *codice_generato, codice *codice_utente, val *valutazione)
{
  int i;
  int posizione_corretta = 0;
  int posizione_sbagliata = 0;
  i = 0;
  while(i < Leggere_difficolta(codice_generato))
  {
    if(Leggere_elemento(codice_utente, i) == Leggere_elemento(codice_generato, i))
    {
      posizione_corretta = posizione_corretta + 1;
    }
    else
    {
      if(Simbolo_presente(Leggere_elemento(codice_utente, i), codice_generato, i))
      {
    	 posizione_sbagliata = posizione_sbagliata + 1;
      }
    }
    i = i + 1;
  }
  Scrivere_valutazione(posizione_corretta, posizione_sbagliata, &*valutazione);
  return;
}

int Simbolo_presente(int valore, codice *codice_generato, int posizione_elemento)
{
  int i;
  int esito_ricerca = 0;
  i = 0;
  while(i < Leggere_difficolta(codice_generato))
  {
    if((valore == Leggere_elemento(codice_generato, i)) && (i != posizione_elemento))
    {
      esito_ricerca = 1;
    }
    i = i + 1;
  }
  return esito_ricerca;
}

int Controllo_parole_uguali(val *valutazione, int lunghezza)
{
  int esito = 0;
  if(Leggere_valutazione_corretta(valutazione) == lunghezza)
  {
    esito = 1;
  }
  return esito;
}
