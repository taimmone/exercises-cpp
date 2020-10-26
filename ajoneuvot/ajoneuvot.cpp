#include <iostream>
#include "ajoneuvot.h"

namespace otecpp_ajoneuvot
{
Ajoneuvo::Ajoneuvo(unsigned hinta, std::string const &merkki, std::string const &malli, unsigned vuosi)
    : hinta_(hinta),
      merkki_(merkki),
      malli_(malli),
      vuosi_(vuosi) {
  std::cout << "Ajoneuvo" << *this << std::endl;
}
Ajoneuvo::~Ajoneuvo() {
  std::cout << "~Ajoneuvo" << *this << std::endl;
}
void
Ajoneuvo::tulosta(std::ostream &virta) {
  virta << "Hinta: " << hinta_ << '\n';
  virta << "Merkki: " << merkki_ << '\n';
  virta << "Malli: " << malli_ << '\n';
  virta << "Vuosi: " << vuosi_ << '\n';
}

Auto::Auto(unsigned int hinta,
           std::string const &merkki,
           std::string const &malli,
           unsigned int vuosi,
           unsigned int lukema,
           std::string const &vaihteisto)
    : Ajoneuvo(hinta, merkki, malli, vuosi),
      lukema_(lukema),
      vaihteisto_(vaihteisto) {
  std::cout << "Auto" << *this << std::endl;
}
Auto::~Auto() {
  std::cout << "~Auto" << *this << std::endl;
}
void
Auto::tulosta(std::ostream &virta) {
  Ajoneuvo::tulosta(virta);
  virta << "Mittarilukema: " << lukema_ << '\n';
  virta << "Vaihteisto: " << vaihteisto_ << '\n';
}

Vene::Vene(unsigned int hinta,
           std::string const &merkki,
           std::string const &malli,
           unsigned int vuosi,
           std::string const &tyyppi,
           unsigned int tunnit)
    : Ajoneuvo(hinta, merkki, malli, vuosi),
      tyyppi_(tyyppi),
      tunnit_(tunnit) {
  std::cout << "Vene" << *this << std::endl;
}
Vene::~Vene() {
  std::cout << "~Vene" << *this << std::endl;
}
void
Vene::tulosta(std::ostream &virta) {
  Ajoneuvo::tulosta(virta);
  virta << "Tyyppi: " << tyyppi_ << '\n';
  virta << "Ajotunnit: " << tunnit_ << '\n';
}

std::ostream &
operator<<(std::ostream &os, Ajoneuvo const &ajoneuvo) {
  os << '(' << ajoneuvo.hinta_ << ", " << ajoneuvo.merkki_ << ", " << ajoneuvo.malli_ << ", " << ajoneuvo.vuosi_ << ')';
  return os;
}

std::ostream &
operator<<(std::ostream &os, Auto const &o_auto) {
  os << '(' << o_auto.lukema_ << ", " << o_auto.vaihteisto_ << ')';
  return os;
}

std::ostream &
operator<<(std::ostream &os, Vene const &vene) {
  os << '(' << vene.tyyppi_ << ", " << vene.tunnit_ << ')';
  return os;
}
} // namespace otecpp_ajoneuvot