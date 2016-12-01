#include "operazioni.h"

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
       numero_generato = rand() % (VALMAX + VALMIN );  //tale istruzione genera un numero casuale che sia compreso tra VALMAX e VALMIN
	}while((doppioni == 0) && (Simbolo_presente(numero_generato, codice_generato, i)));
	Scrivere_elemento(numero_generato, codice_generato, i);

	printf(" %d ", *(codice_generato->codice_gioco + i));

    i = i + 1;
  }
  printf("\n");
  return;
}

void Valutazione_parola(codice *codice_generato, codice *codice_utente, val *valutazione)
{
  int i, j;
  char simbolo_codice_utente, simbolo_codice_generato;
  char valore_codice_utente, valore_codice_generato;
  char corretto, presente;
  codice temp_utente, temp_generato;

  Inizializza_valutazione(valutazione);

  corretto = 'c';
  presente = 'p';
  simbolo_codice_utente = -2;
  simbolo_codice_generato = -1;

  i = 0;
  while(i < Leggere_difficolta(codice_generato))  //questo ciclo permette di individuare i numeri corretti che si trovano nel codice inserito da tastiera
  {
	valore_codice_utente = Leggere_elemento(codice_utente, i);
	valore_codice_generato = Leggere_elemento(codice_generato, i);
    if(valore_codice_utente == valore_codice_generato)
    {
      Scrivere_elemento(simbolo_codice_utente, &temp_utente, i);
      Scrivere_elemento(simbolo_codice_generato, &temp_generato, i);
      Scrivere_valutazione(corretto, valutazione, i);
    }
    else
    {
      Scrivere_elemento(valore_codice_utente, &temp_utente, i);
      Scrivere_elemento(valore_codice_generato, &temp_generato, i);
    }
    i = i + 1;
  }

  //le istruzioni che seguono permettono di individuare i numeri del codice inserito da tastiera presenti nel codice generato
  i = 0;
  while(i < Leggere_difficolta(codice_utente))
  {
    j = 0;
    while(j < Leggere_difficolta(codice_generato))
    {
      if(Leggere_elemento(&temp_utente, i) == Leggere_elemento(&temp_generato, j))
      {
        Scrivere_valutazione(presente, valutazione, i);
        Scrivere_elemento(simbolo_codice_utente, &temp_utente, i);
        Scrivere_elemento(simbolo_codice_generato, &temp_generato, j);
      }
      j = j + 1;
    }
    i = i + 1;
  }
  return;
}

//questa funzione serve per controllare se il valore dato in input alla stessa è effettivamente presente nel codice generato
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

//questa funzione controlla se la parola(codice) è stata indovinata(dunque il codice della valutazione avrà tutte le posizioni riempite con il carattere 'c'
int Controllo_parole_uguali(val *valutazione, int lunghezza)
{
  int esito = 0;
  if(Leggere_valutazione_corrette(valutazione) == lunghezza)
  {
    esito = 1;
  }
  return esito;
}
