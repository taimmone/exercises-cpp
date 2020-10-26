#include <iostream>
#include "intlista.h"

using namespace std;
using otecpp_intlista::IntSolmu;
using otecpp_intlista::IntLista;

namespace
{
void
tulostaIntLista(const IntLista &il) { // Käy listan solmut läpi alusta loppuun ja tulostaa arvot.
  cout << "Listan arvot:";
  for (const IntSolmu *s = il.paa(); s!=NULL; s = s->seur()) {
    cout << " " << s->arvo();
  }
  cout << '\n';
}
}

int
main() {
  IntLista il;
  for (int i = 1; i <= 3; ++i) {
    il.lisaaEteen(5*i);
    il.lisaaTaakse(-3*i);
    tulostaIntLista(il);
  }
  cout << "Listan koko: " << il.koko() << '\n';
  IntLista il2 = il;  // Kutsuu kopiorakenninta.
  cout << "Kopioidun listan koko: " << il2.koko() << "; "; tulostaIntLista(il2);
  for (IntLista::size_type i = il2.koko(); i > 0; --i) { // Poistaa listan solmut yksitellen.
    if (i%2) // Joka toinen poisto edestä, joka toinen takaa.
    {
      il2.poistaEdesta();
    } else {
      il2.poistaTakaa();
    }
    tulostaIntLista(il2);
  }
}