#ifndef MURTOLUKU_H
#define MURTOLUKU_H

#include <ostream>

namespace otecpp_murtoluku
{
class Murtoluku {
  int os_;
  int nim_;

public:
  explicit Murtoluku(int os = 0, int nim = 1);
  int os() const;
  int nim() const;
  Murtoluku &operator++();
  Murtoluku &operator--();
  Murtoluku operator++(int);
  Murtoluku operator--(int);
private:
  void sievenna();
  static unsigned laskeSuurinYhteinenTekija(unsigned const &a, unsigned const &b);
};

Murtoluku
operator+(Murtoluku const &a, Murtoluku const &b);
Murtoluku
operator-(Murtoluku const &a, Murtoluku const &b);
Murtoluku
operator*(Murtoluku const &a, Murtoluku const &b);
Murtoluku
operator/(Murtoluku const &a, Murtoluku const &b);

std::ostream &
operator<<(std::ostream &virta, const Murtoluku &ml);
} // namespace otecpp_murtoluku

#endif //MURTOLUKU_H
