#include <cstdlib>
#include <cfloat>
#include <sstream>
#include "luvut.h"

namespace otecpp_luvut
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

Murtoluku::operator double() const {
  if (!nim_) {
    return !os_ ? 0 : (os_ > 0 ? DBL_MAX : -DBL_MAX);
  }
  return static_cast<double>(os_)/nim_;
}
Kokonaisluku::operator double() const { return arvo; }
Liukuluku::operator double() const { return arvo; }

Murtoluku::operator std::string() const {
  std::ostringstream oss;
  oss << *this;
  return oss.str();
}

Kokonaisluku::operator std::string() const {
  std::ostringstream oss;
  oss << arvo;
  return oss.str();
}
Liukuluku::operator std::string() const {
  std::ostringstream oss;
  oss << arvo;
  return oss.str();
}

std::ostream &
operator<<(std::ostream &virta, Luku const &luku) {
  virta << static_cast<std::string>(luku);
  return virta;
}
std::ostream &
operator<<(std::ostream &virta, Luku const *luku) {
  virta << static_cast<std::string>(*luku);
  return virta;
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
} // namespace otecpp_luvut