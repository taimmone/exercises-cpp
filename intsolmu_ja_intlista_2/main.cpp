#include <iomanip>     // Alla käytetään manipulaattoria setw.
#include <iostream>
#include <vector>
#include "intlista.h"

using namespace std;
using otecpp_intlista::IntLista;

int main()
{
  vector<int> t;
  for(int i = 1; i <= 5; ++i)
  { // Aluksi arvot 5, 10, 15, 20 ja 25 vector-taulukkoon t.
    t.push_back(5*i);
  }
  const IntLista a(t);  // Vakio-IntLista a vector-taulukon t arvoista.
  IntLista b = a;       // Tavallinen IntLista b vakiolistan a kopiona.

  vector<int> t2 = a;   // vector-taulukko t2 IntListan a arvoista.
  for(IntLista::size_type i = 1; i < a.koko(); ++i)
  { // Lopputulos: b[i] = a[0] + ... + a[i] eli kumulatiivinen summa.
    for(IntLista::size_type j = 0; j < i; ++j)
    {
      b[i] += a[j];  // Arvon a[j] voi vain lukea, b[i]:n päälle saa kirjoittaa.
    }
  }

  cout << "Tulostetaan a:n arvot taulukosta t2 ja kumulatiiviset summat listasta b." << std::endl;
  for(IntLista::size_type i = 0; i < a.koko(); ++i)
  {
    cout << "Arvo: " << setw(4) << t2[i] << ", " << std::flush;
    cout << "summa: " << setw(4) << b.paa() << std::endl;
    b.poistaEdesta(); // Poistetaan listan b ensimmäinen solmu
  } // Silmukan jälkeen b on tyhjä ja b.paa() palauttaa NULL-osoittimen
  cout << b.paa() << endl; // Tulostusoperaattorisi pitäisi tulostaa "NULL".
}