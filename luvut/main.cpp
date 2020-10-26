#include <cfloat>
#include <iostream>
#include <string>
#include "luvut.h"

using namespace std;
using otecpp_luvut::Luku;
using otecpp_luvut::Kokonaisluku;
using otecpp_luvut::Liukuluku;
using otecpp_luvut::Murtoluku;

int main()
{
  Luku * luvut[4] = {new Kokonaisluku(-5), new Murtoluku(235, 15),
                     new Liukuluku(15.7), new Murtoluku(-3, 0)};
  Luku *minimi = NULL;
  Luku *maksimi = NULL;
  for(unsigned int i = 0; i < 4; ++i)
  {  // Tulostus kummallakin tulostusoperaattoriversiolla sekä...
    cout << *luvut[i] << " " << luvut[i] << " "
         << static_cast<string>(*luvut[i]) << " "    // ...string-muunnettuna
         << static_cast<double>(*luvut[i]) << endl;  // ...double-muunnettuna
    if((minimi == NULL) || (*minimi > *luvut[i]))
    {    // Ehto vertaa osoitettuja Luku-olioita keskenään. Vertailu ok, koska
      minimi = luvut[i];  // oliot muuntuvat implisiittisesti double-arvoiksi.
    }
    if((maksimi == NULL) || (*maksimi < *luvut[i]))
    {
      maksimi = luvut[i];
    }
  }
  cout << "Minimi: " << minimi << " ja maksimi: " << maksimi << endl;
  for(unsigned int i = 0; i < 4; ++i)
  {
    delete luvut[i];  // Tuhotaan dynaamisesti varattu olio
  }
}