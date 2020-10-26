#ifndef TASOKUVIOT_H
#define TASOKUVIOT_H

#include <ostream>

namespace otecpp_tasokuviot
{
struct Tasokuvio {
  virtual ~Tasokuvio() {};
  virtual double pinta_ala() const = 0;

private:
  virtual void tulosta(std::ostream &virta) const = 0;
  friend std::ostream &operator<<(std::ostream &tuloste, const Tasokuvio &tk);
};

struct Piste {
  double x_;
  double y_;

  explicit Piste(double x = 0, double y = 0);
  ~Piste();
};

class Suorakulmio : public Tasokuvio {
  Piste va_;
  Piste oy_;

public:
  explicit Suorakulmio(Piste const &va = Piste(), Piste const &oy = Piste());
  Suorakulmio(Suorakulmio const &sk);
  ~Suorakulmio();
  Piste const &vasenAlakulma() const;
  void vasenAlakulma(Piste const &va);
  Piste const &oikeaYlakulma() const;
  void oikeaYlakulma(Piste const &oy);
  double leveys() const;
  double korkeus() const;
  double pinta_ala() const;

private:
  void tulosta(std::ostream &virta) const;
};

class Kolmio : public Tasokuvio {
  Piste a_;
  Piste b_;
  Piste c_;

public:
  explicit Kolmio(Piste const &a = Piste(), Piste const &b = Piste(), Piste const &c = Piste());
  Kolmio(Kolmio const &k);
  ~Kolmio();
  Piste const &a() const;
  Piste const &b() const;
  Piste const &c() const;
  double sivu1() const;
  double sivu2() const;
  double sivu3() const;
  double pinta_ala() const;

private:
  static double laskeSivunPituus(Piste const &p, Piste const &q) ;
  void tulosta(std::ostream &virta) const;
};

std::ostream &
operator<<(std::ostream &tuloste, const Piste &p);
} // namespace otecpp_tasokuviot

#endif //TASOKUVIOT_H
