#include "interfaccia.h"

void Presentazione()
{
  FILE *regolamento_gioco;
  char percorso[DIM_PERCORSO];
  char *percorso_file;
  percorso_file = getcwd(percorso, DIM_PERCORSO);
  strcat(percorso_file, "\\..\\regolamento\\regolamento.txt");
  regolamento_gioco = fopen(percorso_file, "r");
  if(regolamento_gioco == NULL)
  {
    printf("Errore! Impossibile leggere il regolamento di Mastermind!\n");
  }
  else{
    FILE *puntatore_nel_file = regolamento_gioco;
    char carattere;
    while((carattere = fgetc(puntatore_nel_file)) != EOF)
    {
      putchar(carattere);
    }
  }
  fclose(regolamento_gioco);
  return;
}

//questa funzione permette di scegliere la difficoltà del gioco che consiste nell'aumentare o nel ridurre la lunghezza del codice da indovinare
void Acquisire_difficolta_scelta(codice *codice_generato, codice *codice_utente, val *valutazione, int *tentativi)
{
  int difficolta;
  int lunghezza;
  do {
    printf("\nInserire il numero corrispondente alla difficolta' desiderata: \n1.Facile \n");
    printf("2.Intermedio\n");
    printf("3.Difficile\n");
    scanf("%d", &difficolta);
    if(difficolta != 1 && difficolta != 2 && difficolta != 3)
    {
      printf("\nErrore nella digitazione!\n");
    }
  }while(difficolta != 1 && difficolta != 2 && difficolta != 3);
  if(difficolta == 1)
  {
	lunghezza = 4;
	*tentativi = 9;
    Scrivere_difficolta(lunghezza, codice_generato, codice_utente, valutazione);
  }
  else
  {
    if(difficolta == 2)
     {
       lunghezza = 6;
       *tentativi = 18;
       Scrivere_difficolta(lunghezza, codice_generato, codice_utente, valutazione);
     }
     else
     {
       lunghezza = 8;
       *tentativi = 27;
       Scrivere_difficolta(lunghezza, codice_generato, codice_utente, valutazione);
     }
  }
  return;
}

void Chiedere_ammissione_doppioni(int *doppioni)
{
  char risposta;
  do {
	printf("\nVuoi permettere anche i doppioni nel codice da indovinare? (s/n)");
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

void Acquisire_parola_utente(codice *codice_utente)
{
  int i;
  int numero;
  printf("\nInserire il codice da verificare: \n");
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

void Stampa_esito(int esito_parole_uguali, int contatore_tentativi, int tentativi)
{
  if(esito_parole_uguali)
    {
      printf("\nSEI RIUSCITO A TROVARE LA COMBINAZIONE GIUSTA IN %d TENTATIVI! COMPLIMENTI!\n", contatore_tentativi - 1);
    }
    else
    {
      if(!(contatore_tentativi < tentativi))
      {
        printf("\nNON SEI STATO FORTUNATO! NON SEI RIUSCITO A TROVARE LA COMBINAZIONE GIUSTA!\n");
      }
    }
  return;
}

void Stampa_valutazione(val *valutazione)
{
  int corretti, presenti;
  corretti = Leggere_valutazione_corrette(valutazione);
  Leggere_valutazione_presenti(valutazione, &presenti);
  printf("\n");
  printf("|  Numero di elementi in posizione corretta: %d   |\n", corretti);
  printf("|  Numero di elementi in posizione sbagliata: %d  |", presenti);
  printf("\n");
  return;
}
