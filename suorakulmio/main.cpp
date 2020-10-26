#include <iostream>
#include "tasokuviot.h"

using namespace std;
using otecpp_tasokuviot::Piste;
using otecpp_tasokuviot::Suorakulmio;

int main(int argc, char *argv[])
{
  const Suorakulmio sk(Piste(), Piste(4.5, 3.5)); // Vasen alakulma: oletusarvo (0, 0).
  cout << "Leveys: " << sk.leveys() << '\n';
  cout << "Korkeus: " << sk.korkeus() << '\n';
  cout << "Pinta-ala: " << sk.pinta_ala() << '\n';
  const Suorakulmio sk2; // Kumpikin parametri antamatta (saavat oletusarvot).
  cout << "Leveys: " << sk2.leveys() << '\n';
  cout << "Korkeus: " << sk2.korkeus() << '\n';
  cout << "Pinta-ala: " << sk2.pinta_ala() << '\n';
}