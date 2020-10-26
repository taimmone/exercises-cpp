#include <algorithm>
//#include <iostream>
#include "murtoluku.h"

namespace otecpp_murtoluku
{
Murtoluku::Murtoluku(int os, int nim)
    : os_(os),
      nim_(nim) {
//  std::cout << "Luodaan Murtoluku: " << os_ << '/' << nim_ << '\n';
//  std::cout << "Sievennetään..." << std::endl;
  sievenna();
//  std::cout << "Sievennetty Murtoluku: " << os_ << '/' << nim_ << '\n';
//  std::cout << "Lopullinen arvo: " << *this << '\n';
//  std::cout << "Valmis.\n" << std::endl;
}
void
Murtoluku::sievenna() {
  int os = os_;
  int nim = nim_;
  if ((os < 0 && nim < 0) || nim < 0) {
    os = -os;
    nim = -nim;
  }
  if (!os || !nim) {
    os_ = os;
    nim_ = nim;
    return;
  }

  unsigned syt = laskeSuurinYhteinenTekija(abs(os), abs(nim));
  os_ = os/static_cast<int>(syt);
  nim_ = nim/static_cast<int>(syt);
}
unsigned
Murtoluku::laskeSuurinYhteinenTekija(unsigned const &a, unsigned const &b) {
  unsigned iso = std::max(a, b);
  unsigned pieni = std::min(a, b);
  while (iso!=pieni) {
    iso -= pieni;
    if (iso < pieni) {
      unsigned tmp = pieni;
      pieni = iso;
      iso = tmp;
    }
  }
  return iso;
}
int
Murtoluku::os() const {
  return os_;
}
int
Murtoluku::nim() const {
  return nim_;
}

Murtoluku &
Murtoluku::operator++() {
  os_ += nim_;
  sievenna();
  return *this;
}
Murtoluku &
Murtoluku::operator--() {
  os_ -= nim_;
  sievenna();
  return *this;
}
Murtoluku
Murtoluku::operator++(int) {
  Murtoluku ml(*this);
  operator++();
  return ml;
}
Murtoluku
Murtoluku::operator--(int) {
  Murtoluku ml(*this);
  operator--();
  return ml;
}

Murtoluku
operator+(Murtoluku const &a, Murtoluku const &b) {
  return Murtoluku(a.os()*b.nim() + b.os()*a.nim(), a.nim()*b.nim());
}
Murtoluku
operator-(Murtoluku const &a, Murtoluku const &b) {
  return Murtoluku(a.os()*b.nim() - b.os()*a.nim(), a.nim()*b.nim());
}
Murtoluku
operator*(Murtoluku const &a, Murtoluku const &b) {
  return Murtoluku(a.os()*b.os(), a.nim()*b.nim());
}
Murtoluku
operator/(Murtoluku const &a, Murtoluku const &b) {
  return Murtoluku(a.os()*b.nim(), a.nim()*b.os());
}
std::ostream &
operator<<(std::ostream &virta, Murtoluku const &ml) {
  if (ml.os() && ml.nim() && ml.nim()!=1) {
    virta << ml.os() << '/' << ml.nim();
  } else if (ml.os() && ml.nim()==1) {
    virta << ml.os();
  } else if (!ml.os()) {
    virta << 0;
  } else {
    if (!ml.nim()) {
      virta << (ml.os() && ml.os() > 0 ? "inf" : "-inf");
    }
  }
  return virta;
}
} // namespace otecpp_murtoluku