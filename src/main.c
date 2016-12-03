#include "globali.h"
#include "interfaccia.h"
#include "operazioni.h"

int main()
{
  codice codice_generato;
  codice codice_utente;
  val valutazione;
  char risposta;
  char inizio;
  int tentativi;   //contatore dei tentativi
  int esito_parole_uguali = 0;
  int contatore_tentativi;
  Presentazione();
  printf(" Premere INVIO per iniziare!");
  scanf("%c",&inizio);
  system("cls");
  do {
	Acquisire_difficolta_scelta(&codice_generato, &codice_utente, &valutazione, &tentativi);
    Generare_parola(&codice_generato);
    contatore_tentativi = 1;
    do {
      printf("--------------------------------------------------------------------------");
      printf("\nTENTATIVO NUMERO: %d", contatore_tentativi);
      Acquisire_parola_utente(&codice_utente);
      Valutazione_parola(&codice_generato, &codice_utente, &valutazione); //operazioni di verifica del codice inserito da tastiera
      esito_parole_uguali = Controllo_parole_uguali(&valutazione, Leggere_difficolta(&codice_utente));  //restituisce 1 se la parola(codice) è stata indovinata
      contatore_tentativi = contatore_tentativi + 1;
      Stampa_valutazione(&valutazione);
    }while(esito_parole_uguali != 1 && (contatore_tentativi <= tentativi));
    Stampa_esito(esito_parole_uguali, contatore_tentativi, tentativi, codice_generato);
    do {
      printf("\nVuoi riprovare a giocare? (s/n)");
      fflush(stdin);
      scanf("%c", &risposta);
      if(risposta != 's' && risposta != 'n')
      {
        printf("\nErrore nella digitazione della risposta!\n");
      }
    }while(risposta != 's' && risposta != 'n');
    system("cls");
  }while(risposta == 's');
  return 0;
}
