#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//-----------------------definizione delle costanti-----------------------
#define LUNGHEZZA_MAX 8
#define MAX_TENTATIVI 4
#define VALMAX 9
#define VALMIN 1


//-----------------------definizione delle strutture-----------------------
typedef struct {
  int codice_gioco[LUNGHEZZA_MAX];
  int lunghezza_codice;
}codice;

typedef struct {
  char risultato[LUNGHEZZA_MAX];
  int lunghezza_valutazione;
}val;


//-----------------------prototipi funzioni di lettura e scrittura-----------------------
void Scrivere_difficolta(int lunghezza, codice *codice_generato, codice *codice_utente);
void Scrivere_difficolta_valutazione(int lunghezza, val *valutazione);
void Scrivere_valutazione(val *valutazione, int posizione, char carattere);
int Leggere_elemento(codice *codice, int posizione);
int Leggere_difficolta(codice *codice_simboli);
int Leggere_difficolta_valutazione(val *valutazione);
char Leggere_valutazione(val *valutazione, int i);


//-----------------------prototipi funzioni di base-----------------------
void Presentazione();
void Generare_parola(codice *codice_generato);
void Acquisire_difficolta_scelta(codice *codice_generato, codice *codice_utente, val *valutazione);
void Acquisire_parola_utente(codice *codice_utente);
void Stampa_valutazione(val *valutazione);
void Stampa_esito(int esito_parole_uguali, int tentativi);


//-----------------------prototipi funzioni utili per la verifica della parola-----------------------
void Chiedere_ammissione_doppioni(int *doppioni);
void Valutazione_parola(codice *codice_generato, codice *codice_utente, val *valutazione);
int Simbolo_presente(int valore, codice *codice_generato, int posizione_elemento);
int Controllo_parole_uguali(val *valutazione);
void Stampa_valutazione(val *valutazione);


int main()
{
  codice codice_generato;
  codice codice_utente;
  val valutazione;
  char risposta;
  int tentativi;
  int esito_parole_uguali = 0;
  Presentazione();
  do {
	Acquisire_difficolta_scelta(&codice_generato, &codice_utente, &valutazione);
    Generare_parola(&codice_generato);
    tentativi = 1;
    do {
      printf("--------------------------------------------------------------------------");
      printf("\nTENTATIVO NUMERO: %d", tentativi);
      Acquisire_parola_utente(&codice_utente);
      Valutazione_parola(&codice_generato, &codice_utente, &valutazione);
      esito_parole_uguali = Controllo_parole_uguali(&valutazione);
      tentativi = tentativi + 1;
      Stampa_valutazione(&valutazione);
    }while(esito_parole_uguali != 1 && (tentativi < MAX_TENTATIVI));
    Stampa_esito(esito_parole_uguali, tentativi);
    do {
      printf("Vuoi riprovare a giocare? (s/n)");
      fflush(stdin);
      scanf("%c", &risposta);
      if(risposta != 's' && risposta != 'n')
      {
        printf("\nErrore nella digitazione della risposta!\n");
      }
    }while(risposta != 's' && risposta != 'n');
  }while(risposta == 's');
  return 0;
}


//-----------------------funzioni di lettura e scrittura-----------------------
void Scrivere_difficolta(int lunghezza, codice *codice_generato, codice *codice_utente)
{
  codice_generato->lunghezza_codice = lunghezza;
  codice_utente->lunghezza_codice = lunghezza;
  return;
}

void Scrivere_difficolta_valutazione(int lunghezza, val *valutazione)
{
  valutazione->lunghezza_valutazione = lunghezza;
  return;
}

void Scrivere_valutazione(val *valutazione, int posizione, char carattere)
{
  *(valutazione->risultato + posizione) = carattere;
  return;
}

int Leggere_elemento(codice *codice, int posizione)
{
  return *(codice->codice_gioco + posizione);
}

char Leggere_valutazione(val *valutazione, int i)
{
  return *(valutazione->risultato + i);
}

int Leggere_difficolta(codice *codice_simboli)
{
  return codice_simboli->lunghezza_codice;
}

int Leggere_difficolta_valutazione(val *valutazione)
{
  return valutazione->lunghezza_valutazione;
}


//-----------------------funzioni di base-----------------------
void Presentazione()
{
  printf("-------------------( M | A | S | T | E | R | M | I | N | D )-------------------\n");
  printf("\n ----------------------------------------------------------------------------- ");
  printf("\n|Leggenda: c: se il simbolo inserito nella posizione apposita e' corretto;    |\n");
  printf("|          p: se il simbolo inserito nella posizione apposita e' presente     |\n|             nel codice da indovinare;");
  printf("                                       |\n");
  printf("|          /: se il simbolo inserito nella posizione apposita non e' presente |\n|             nel codice da indovinare.      ");
  printf("          		              |\n");
  printf(" ----------------------------------------------------------------------------- \n");
  return;
}

void Acquisire_parola_utente(codice *codice_utente)
{
  int i;
  printf("\nInserire la parola da verificare(occorre inserire un simbolo per volta,\ndunque una volta inserito il primo simbolo,");
  printf("premere INVIO per inserire \nil simbolo successivo)\n");
  i = 0;
  while(i < Leggere_difficolta(codice_utente))
  {
    scanf("%d", &*(codice_utente->codice_gioco + i));
    i = i + 1;
  }
  return;
}

void Acquisire_difficolta_scelta(codice *codice_generato, codice *codice_utente, val *valutazione)
{
  int difficolta;
  int lunghezza;
  do {
    printf("\nSelezionare la difficolta' desiderata: \n1.Facile(4 simboli da indovinare);\n");
    printf("2.Intermedio(6 simboli da indovinare);\n");
    printf("3.Difficile(8 simboli da indovinare);\n");
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
    Scrivere_difficolta_valutazione(lunghezza, &*valutazione);
  }
  else
  {
    if(difficolta == 2)
     {
       lunghezza = 6;
       Scrivere_difficolta(lunghezza, &*codice_generato, &*codice_utente);
       Scrivere_difficolta_valutazione(lunghezza, &*valutazione);
     }
     else
     {
       lunghezza = 8;
       Scrivere_difficolta(lunghezza, &*codice_generato, &*codice_utente);
       Scrivere_difficolta_valutazione(lunghezza, &*valutazione);
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
  int i = 0;
  printf("\n");
  while(i < Leggere_difficolta_valutazione(valutazione))
  {
    printf("| %c |", Leggere_valutazione(valutazione, i));
    i = i + 1;
  }
  printf("\n");
  return;
}


//-----------------------funzioni utili per la verifica della parola-----------------------
void Generare_parola(codice *codice_generato)
{
  int i;
  int numero_generato;
  int doppioni = 0;
  Chiedere_ammissione_doppioni(&doppioni);
  srand(time(NULL));
  i = 0;
  printf("\nparola generata(parola da indovinare):");
  while(i < Leggere_difficolta(codice_generato))
  {
	do {
       numero_generato = rand() % (VALMAX + VALMIN);
	}while((doppioni == 0) && (Simbolo_presente(numero_generato, codice_generato, i)));
	*(codice_generato->codice_gioco + i) = numero_generato;

	printf(" %d ", *(codice_generato->codice_gioco + i));

    i = i + 1;
  }
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

void Valutazione_parola(codice *codice_generato, codice *codice_utente, val *valutazione)
{
  int i;
  char presente = 'p';
  char corretto = 'c';
  char non_presente = '/';
  i = 0;
  while(i < Leggere_difficolta(codice_generato))
  {
    if(Leggere_elemento(codice_utente, i) == Leggere_elemento(codice_generato, i))
    {
      Scrivere_valutazione(valutazione, i, corretto);
    }
    else
    {
      if(Simbolo_presente(Leggere_elemento(codice_utente, i), codice_generato, i))
      {
        Scrivere_valutazione(valutazione, i, presente);
      }
      else
      {
        Scrivere_valutazione(valutazione, i, non_presente);
      }
    }
    i = i + 1;
  }
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

int Controllo_parole_uguali(val *valutazione)
{
  int i;
  int conteggio = 0;
  int esito = 0;
  i = 0;
  while(i < Leggere_difficolta_valutazione(valutazione))
  {
    if(*(valutazione->risultato + i) == 'c')
    {
      conteggio = conteggio + 1;
    }
    i = i + 1;
  }
  if(conteggio == Leggere_difficolta_valutazione(valutazione))
  {
    esito = 1;
  }
  return esito;
}
