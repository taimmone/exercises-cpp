#include <istream>
#include <sstream>
#include <cstdlib>
#include "valuutat.h"

namespace otecpp_valuutat
{
Valuutta::Valuutta(std::string lyhenne, std::string nimi, double kurssi)
    : lyhenne_(lyhenne), nimi_(nimi), kurssi_(kurssi) {}

std::string
Valuutta::lyhenne() const {
  return lyhenne_;
}
std::string const &
Valuutta::nimi() const {
  return nimi_;
}
double
Valuutta::kurssi() const {
  return kurssi_;
}

std::vector<Valuutta>
lueKurssit(std::istream &syote) {
  std::vector<Valuutta> kurssit;
  std::string rivi;
  while (std::getline(syote, rivi)) {
    std::vector<std::string> arvot;
    std::istringstream virta(rivi);
    std::string arvo;
    while (std::getline(virta, arvo, '\t')) {
      arvot.push_back(arvo);
    }
    kurssit.push_back(Valuutta(arvot[0], arvot[1], atof(arvot[3].c_str())));
  }
  return kurssit;
}
} // namespace otecpp_valuutat