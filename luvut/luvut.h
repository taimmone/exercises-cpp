#ifndef LUVUT_H
#define LUVUT_H

#include <string>

namespace otecpp_luvut
{
struct Luku {
  virtual ~Luku() {};
  virtual operator double() const = 0;
  virtual operator std::string() const = 0;
};

class Murtoluku : public Luku {
  int os_;
  int nim_;

public:
  explicit Murtoluku(int os = 0, int nim = 1);
  int os() const;
  int nim() const;
  operator double() const;
  operator std::string() const;
private:
  void sievenna();
  static unsigned laskeSuurinYhteinenTekija(unsigned const &a, unsigned const &b);
};

class Kokonaisluku : public Luku {
  int arvo;

public:
  explicit Kokonaisluku(int arvo)
      : arvo(arvo) {}
  operator double() const;
  operator std::string() const;
};

class Liukuluku : public Luku {
  double arvo;

public:
  explicit Liukuluku(double arvo)
      : arvo(arvo) {}
  operator double() const;
  operator std::string() const;
};

std::ostream &
operator<<(std::ostream &virta, Luku const &luku);
std::ostream &
operator<<(std::ostream &virta, Luku const *luku);
std::ostream &
operator<<(std::ostream &virta, const Murtoluku &ml);
} // namespace otecpp_luvut

#endif //LUVUT_H
