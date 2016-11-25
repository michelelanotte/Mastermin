#include "lettura_scrittura.h"

void Scrivere_difficolta(int lunghezza, codice *codice_generato, codice *codice_utente)
{
  codice_generato->lunghezza_codice = lunghezza;
  codice_utente->lunghezza_codice = lunghezza;
  return;
}

void Scrivere_valutazione(int posizione_corretta, int posizione_sbagliata, val *valutazione)
{
  valutazione->posizione_corretta = posizione_corretta;
  valutazione->posizione_sbagliata = posizione_sbagliata;
  return;
}

void Scrivere_elemento(int elemento, codice *codice_di_gioco, int posizione)
{
  *(codice_di_gioco->codice_gioco + posizione) = (char)elemento;
  return;
}

int Leggere_elemento(codice *codice, int posizione)
{
  return *(codice->codice_gioco + posizione);
}

int Leggere_valutazione_corretta(val *valutazione)
{
  return valutazione->posizione_corretta;
}

int Leggere_valutazione_sbagliata(val *valutazione)
{
  return valutazione->posizione_sbagliata;
}

int Leggere_difficolta(codice *codice_numerico)
{
  return codice_numerico->lunghezza_codice;
}

