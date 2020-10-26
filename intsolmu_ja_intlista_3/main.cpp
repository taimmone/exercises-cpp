#include <iostream>
#include <vector>
#include "intlista.h"

using namespace std;
using otecpp_intlista::IntSolmu;
using otecpp_intlista::IntLista;

int main()
{
  IntLista a;
  IntLista b;
  for(int i = 1; i <= 5; ++i)
  { // Aluksi arvot 5, 10, 15, 20 ja 25 listoihin a ja b eri järjestyksissä.
    a.lisaaTaakse(5*i);  // Lisäys a:n taakse.
    b.lisaaEteen(5*i);   // Lisäys b:n eteen.
  }
  IntSolmu *s = a.hanta();
  IntSolmu *s2 = b.paa();
  while((s != NULL) || (s2 != NULL))
  { // s askeltaa listan a lopusta alkuun ja s2 listan b alusta loppuun.
    cout << "[" << s << " ja " << s2 << "]";  // Tulostetaan s ja s2.
    s = s->edel();     // s edelliseen solmuun.
    s2 = s2->seur();   // s2 seuraavaan solmuun.
    a.poistaTakaa();   // Poistetaan a:n viimeinen solmu (vanha s).
    b.poistaEdesta();  // Poistetaan b:n ensimmäinen solmu (vanha s2).
    if((s != a.hanta()) || (s2 != b.paa()))
    { // Varmistaa, että poistot päivittivät a:n hännän ja b:n pään oikein.
      cout << "Virhe pään tai hännän päivityksessä, kun solmu poistettiin!\n";
      return 0;  // Päivitys meni pieleen. Lopetetaan ohjelma.
    }
  }
  cout << "[" << s << " ja " << s2 << "]\n";  // Tulostuu [NULL ja NULL].
}