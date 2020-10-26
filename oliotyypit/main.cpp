#include <iostream>
#include <vector>
#include "luvut.h"
#include "oliotyypit.h"

using namespace std;
using namespace otecpp_luvut;
using namespace otecpp_oliotyypit;
int
main() {
  vector<Luku *> luvut;
  luvut.push_back(new Murtoluku(43, 70));
  luvut.push_back(new Murtoluku(51, 43));
  luvut.push_back(new Kokonaisluku(78));
  luvut.push_back(new Murtoluku(38, 73));
  luvut.push_back(new Liukuluku(3.5));
  luvut.push_back(new Kokonaisluku(83));
  luvut.push_back(new Liukuluku(75.91));
  laskeLuvut(luvut);
  while(!luvut.empty())
  {
    cout << luvut.back() << '\n';
    delete luvut.back(); // Vapautetaan Luku-olio.
    luvut.pop_back();    // Poistetaan osoitin vapautettuun lukuun.
  }
  return 0;
}
