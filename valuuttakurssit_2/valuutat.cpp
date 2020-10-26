#include <algorithm>
#include <istream>
#include <sstream>
#include <cstdlib>
#include "valuutat.h"

namespace otecpp_valuutat
{
Valuutta::Valuutta(std::string lyhenne, std::string nimi, double kurssi)
    : lyhenne_(lyhenne),
      nimi_(nimi),
      kurssi_(kurssi) {}

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

bool
Valuutta::lyhenneVrt(Valuutta const &a, Valuutta const &b) {
  return a.lyhenne() < b.lyhenne();
}
bool
Valuutta::nimiVrt(Valuutta const &a, Valuutta const &b) {
  return a.nimi() < b.nimi();
}
bool
Valuutta::kurssiVrt(Valuutta const &a, Valuutta const &b) {
  if (a.kurssi() < b.kurssi()) {
    return true;
  } else if (a.kurssi()==b.kurssi()) {
    return lyhenneVrt(a, b);
  } else { return false; }


}
std::ostream &
operator<<(std::ostream &virta, Valuutta valuutta) {
  virta << valuutta.lyhenne() << ' ' << valuutta.nimi() << ' ' << valuutta.kurssi();
  return virta;
}
} // namespace otecpp_valuutat