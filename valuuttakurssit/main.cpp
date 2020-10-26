#include <fstream>
#include <iostream>
#include <vector>
#include "valuutat.h"

using namespace std;
using otecpp_valuutat::Valuutta;
using otecpp_valuutat::lueKurssit;

int main(int argc, char *argv[])
{
  ifstream syote(argv[1]);  // Valuuttakurssit sisältävä tiedosto.
  vector<Valuutta> kurssit = lueKurssit(syote);  // Luetaan tiedot.
  // Lisätään valuuttatietoihin lisäksi Suomen markka.
  kurssit.push_back(Valuutta("FIM", "Finnish Markka", 0.168188));
  while(!kurssit.empty()) // Silmukka käy taulukon kurssit läpi.
  {
    const Valuutta kurssi = kurssit.back(); // Luetaan viimeinen valuutta...
    kurssit.pop_back();                     // ...ja poistetaan se taulukosta.
    cout << kurssi.lyhenne() << '\n' << kurssi.nimi() << '\n'
         << 1/kurssi.kurssi() << '\n' << kurssi.kurssi() << "\n\n";
  }
}