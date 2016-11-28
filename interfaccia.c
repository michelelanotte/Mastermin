/*
 * interfaccia.c
 *
 *  Created on: 28 nov 2016
 *      Author: Michele97
 */

#include "interfaccia.h"

void Presentazione()
{
  printf("-------------------( M | A | S | T | E | R | M | I | N | D )-------------------\n");
  printf("\n ----------------------------------------------------------------------------- ");
  printf("\n|    Mastermind e' un gioco in cui l'utente non deve far altro che provare    |\n");
  printf("|        ad indovinare una codice formato da numeri che vanno da 0 a 9.       |\n");
  printf("|       Il gioco, non fara' altro che dire all'utente quanti sono i numeri    |\n");
  printf("|     del codice inserito in posizione corretta(rispetto al codice generato), |\n");
  printf("|                        e quanti in posizione errata.      	              |\n");
  printf(" ----------------------------------------------------------------------------- \n");
  return;
}

void Acquisire_parola_utente(codice *codice_utente)
{
  int i;
  int numero;
  printf("\nInserire il codice da verificare(occorre inserire un numero per volta,\ndunque una volta inserito il primo numero,");
  printf(" premere INVIO per inserire \nil secondo numero e cosi' via)\n");
  i = 0;
  while(i < Leggere_difficolta(codice_utente))
  {
	do {
      printf("%d. ", i + 1);
      scanf("%d", &numero);
      if(numero < 0 || numero > 9)
      {
        printf("Errore! Inserire numero tra 0 e 9!\n");
      }
	}while(numero < 0 || numero > 9);
	Scrivere_elemento(numero, &*codice_utente, i);
    i = i + 1;
  }
  return;
}

//questa funzione permette di scegliere la difficoltà del gioco che consiste nell'aumentare o nel ridurre la lunghezza del codice da indovinare
void Acquisire_difficolta_scelta(codice *codice_generato, codice *codice_utente)
{
  int difficolta;
  int lunghezza;
  do {
    printf("\nInserire il numero relativo alla difficolta' desiderata: \n1.Facile(4 numeri da indovinare);\n");
    printf("2.Intermedio(6 numeri da indovinare);\n");
    printf("3.Difficile(8 numeri da indovinare);\n");
    scanf("%d", &difficolta);
    if(difficolta != 1 && difficolta != 2 && difficolta != 3)
    {
      printf("\nErrore nella digitazione!\n");
    }
  }while(difficolta != 1 && difficolta != 2 && difficolta != 3);
  if(difficolta == 1)
  {
	lunghezza = 4;
    Scrivere_difficolta(lunghezza, &*codice_generato, &*codice_utente);
  }
  else
  {
    if(difficolta == 2)
     {
       lunghezza = 6;
       Scrivere_difficolta(lunghezza, &*codice_generato, &*codice_utente);
     }
     else
     {
       lunghezza = 8;
       Scrivere_difficolta(lunghezza, &*codice_generato, &*codice_utente);
     }
  }
  return;
}

void Stampa_esito(int esito_parole_uguali, int tentativi)
{
  if(esito_parole_uguali)
    {
      printf("\nSEI RIUSCITO A TROVARE LA COMBINAZIONE GIUSTA! COMPLIMENTI!\n");
    }
    else
    {
      if(!(tentativi < MAX_TENTATIVI))
      {
        printf("\nNON SEI STATO FORTUNATO! NON SEI RIUSCITO A TROVARE LA COMBINAZIONE GIUSTA!\n");
      }
    }
  return;
}

void Stampa_valutazione(val *valutazione)
{
  printf("\n");
  printf("|  Numero di elementi in posizione corretta: %d   |\n", Leggere_valutazione_corretta(valutazione));
  printf("|  Numero di elementi in posizione sbagliata: %d  |", Leggere_valutazione_sbagliata(valutazione));
  printf("\n");
  return;
}

void Chiedere_ammissione_doppioni(int *doppioni)
{
  char risposta;
  do {
	printf("\n\nVuoi permettere anche i doppioni nel codice da indovinare? (s/n)");
	fflush(stdin);
    scanf("%c", &risposta);
    if(risposta == 's')
    {
      *doppioni = 1;
    }
    else
    {
	  if(risposta == 'n')
	  {
	    *doppioni = 0;
	  }
	  else
	  {
	    printf("\nErrore nella digitazione della risposta!");
	  }
    }
  }while((risposta != 's') && (risposta != 'n'));
  return;
}
