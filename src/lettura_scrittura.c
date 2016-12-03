/*
 * lettura_scrittura.c
 *
 *  Created on: 28 nov 2016
 *      Author: Michele97
 */

#include "lettura_scrittura.h"

void Scrivere_difficolta(int lunghezza, codice *codice_generato, codice *codice_utente, val *valutazione)
{
  codice_generato->lunghezza_codice = lunghezza;
  codice_utente->lunghezza_codice = lunghezza;
  valutazione->lunghezza_codice = lunghezza;
  return;
}

void Scrivere_elemento(int elemento, codice *codice_di_gioco, int posizione)
{
  *(codice_di_gioco->codice_gioco + posizione) = (char)elemento;
  return;
}

void Scrivere_valutazione(char elemento, val *valutazione, int posizione)
{
  *(valutazione->codice + posizione) = elemento;
  return;
}

void Inizializzare_valutazione(val * valutazione)
{
  int i = 0;
  while(i < Leggere_difficolta_valutazione(valutazione))
  {
    *(valutazione->codice + i) = ' ';
    i = i + 1;
  }
  return;
}

int Leggere_elemento(codice *codice, int posizione)
{
  return *(codice->codice_gioco + posizione);
}

char Leggere_elemento_valutazione(val *valutazione, int posizione)
{
  return *(valutazione->codice + posizione);
}

int Leggere_difficolta(codice *codice_numerico)
{
  return codice_numerico->lunghezza_codice;
}

int Leggere_difficolta_valutazione(val *valutazione)
{
  return valutazione->lunghezza_codice;
}

int Leggere_valutazioni(val *valutazione, char elemento)
{
  int conteggio = 0;
  int i = 0;
  while(i < Leggere_difficolta_valutazione(valutazione))
  {
    if(Leggere_elemento_valutazione(valutazione, i) == elemento)
    {
      conteggio = conteggio + 1;
    }
    i = i + 1;
  }
  return conteggio;
}
