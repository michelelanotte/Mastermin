#include "globali.h"
#include "interfaccia.h"
#include "operazioni.h"

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
	Acquisire_difficolta_scelta(&codice_generato, &codice_utente);
    Generare_parola(&codice_generato);
    tentativi = 1;
    do {
      printf("--------------------------------------------------------------------------");
      printf("\nTENTATIVO NUMERO: %d", tentativi);
      Acquisire_parola_utente(&codice_utente);
      Valutazione_parola(&codice_generato, &codice_utente, &valutazione); //operazioni di verifica del codice inserito da tastiera
      esito_parole_uguali = Controllo_parole_uguali(&valutazione, Leggere_difficolta(&codice_utente));
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









