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
  char difficolta[DIM_MAX];
  int livello_difficolta;
  int lunghezza;
  do {
	fflush(stdin);
    printf("\nInserire il numero corrispondente alla difficolta' desiderata: \n1.Facile \n");
    printf("2.Intermedio\n");
    printf("3.Difficile\n");
    scanf("%s", difficolta);
    if(strlen(difficolta) == 1)
    {
      livello_difficolta = (int)*difficolta;  //livello_difficolta assumerà il valore ASCII del carattere inserito
      if((livello_difficolta < 49) || (livello_difficolta > 51))  //49 è il codice ASCII di 1, 51 è il codice ASCII di 3
      {
        printf("\nErrore nella digitazione!\n");
      }
    }
    else
    {
      printf("\nErrore nella digitazione!\n");
    }
  }while((livello_difficolta < 49) || (livello_difficolta > 51));
  livello_difficolta = livello_difficolta - 48;  //sottraendo 48 al valore di livello_difficolta, si ricava un numero(1,2 0 3) corrispondente al livello scelto dall'utente
  if(livello_difficolta == 1)
  {
	lunghezza = 4;
	*tentativi = 9;
    Scrivere_difficolta(lunghezza, codice_generato, codice_utente, valutazione);
  }
  else
  {
    if(livello_difficolta == 2)
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
  char numero_input[DIM_MAX];
  printf("\nInserire il codice da verificare: \n");
  i = 0;
  while(i < Leggere_difficolta(codice_utente))
  {
	do {
      printf("%d. ", i + 1);
      fflush(stdin);
      scanf("%s", numero_input);
      if(strlen(numero_input) == 1)
      {
        numero = (int)*numero_input;
        if(numero < 48 || numero > 57)  //48 è il codice ASCII dello 0 mentre 57 è il codice ASCII di 9
        {
          printf("Errore! Inserire numero tra 0 e 9!\n");
        }
      }
      else
      {
        printf("Errore! Inserire numero tra 0 e 9!\n");
      }
	}while(numero < 48 || numero > 57);
    numero = numero - 48;
	Scrivere_elemento(numero, codice_utente, i);
    i = i + 1;
  }
  return;
}

void Stampa_esito(int esito_parole_uguali, int contatore_tentativi, int tentativi, codice codice_generato)
{
  int i;
  if(esito_parole_uguali)
    {
      printf("\nSEI RIUSCITO A TROVARE LA COMBINAZIONE GIUSTA IN %d TENTATIVI! COMPLIMENTI!\n", contatore_tentativi - 1);
    }
    else
    {
      if(!(contatore_tentativi < tentativi))
      {
    	printf("--------------------------------------------------------------------------");
    	printf("\nIl codice da indovinare era il seguente: \n");
    	i = 0;
    	while(i < Leggere_difficolta(&codice_generato))
    	{
    	  printf(" %d ", Leggere_elemento(&codice_generato, i));
    	  i = i + 1;
    	}
        printf("\n\nNON SEI STATO FORTUNATO! NON SEI RIUSCITO A TROVARE LA COMBINAZIONE GIUSTA!\n");
      }
    }
  return;
}

void Stampa_valutazione(val *valutazione)
{
  int corretti, presenti;
  char corretto = 'c';
  char presente = 'p';
  corretti = Leggere_valutazioni(valutazione, corretto);
  presenti = Leggere_valutazioni(valutazione, presente);
  printf("\n");
  printf("|  Numero di elementi in posizione corretta: %d   |\n", corretti);
  printf("|  Numero di elementi in posizione sbagliata: %d  |", presenti);
  printf("\n");
  return;
}
