#include <iostream>

#include "ajoneuvot.h"

using namespace std;
using otecpp_ajoneuvot::Ajoneuvo;
using otecpp_ajoneuvot::Auto;
using otecpp_ajoneuvot::Vene;

int
main() { // Ajoneuvo-taulukkoon dynaamisesti luotuja Auto- ja Vene-olioita.
  Ajoneuvo *at[4] = {new Vene(5800, "Fiskari", "Nenne", 1975, "puuvene", 450),
                     new Auto(600, "Mercedes-Benz", "200", 1989, 600000, "manuaali"),
                     new Vene(33900, "Buster", "Magnum", 2015, "pulpettivene", 0),
                     new Auto(3100, "Audi", "A4", 2002, 455000, "automaatti")};
  cout << '\n';
  at[1]->tulosta(cout);          // Tulostetaan olio a[1] tulostevirtaan cout.
  Ajoneuvo mersu = *at[1];       // mersu on olion at[1] kopio.
  cout << '\n';
  mersu.tulosta(cerr);           // Tulostetaan mersu tulostevirtaan cerr.
  Ajoneuvo &mersuViite = *at[1]; // mersuViite viittaa olioon at[1].
  cout << '\n';
  mersuViite.tulosta(cout);      // Tulostetaan mersuViite tulostevirtaan cout.
  cout << '\n';
  delete at[0];  // Tuhotaan dynaamisesti luodut oliot.
  delete at[1];
  delete at[2];
  delete at[3];
}