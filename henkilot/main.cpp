#include <iostream>
#include "henkilo.h"

using namespace std;
using namespace otecpp_henkilo;
int
main() {
  Henkilo * hlot[6] = {new Henkilo("Martti"), new Henkilo("Ilona"), new Henkilo("Esko")};
  for(int i = 0; i < 3; ++i)
  {
    hlot[3+i] = new Henkilo(*hlot[i]);        // hlot[3+i] luodaan olion hlot[i] kopioksi.
    hlot[3+i]->nimi(hlot[3+i]->nimi() + "2"); // Olion hlot[3+i] nimen perään numero 2.
  }
  cout << "Luotu " << Henkilo::lkm() << " Henkilo-oliota\n";
  for(int i = 0; i < 6; ++i)
  {
    cout << "Tuhotaan olio " << hlot[i]->id() << ": " << hlot[i]->nimi() << '\n';
    delete hlot[i];
    cout << "Nyt on " << Henkilo::lkm() << " Henkilo-oliota jäljellä\n";
  }
  return 0;
}
