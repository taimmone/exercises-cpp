#ifndef TASOKUVIOT_H
#define TASOKUVIOT_H

namespace otecpp_tasokuviot
{
struct Piste {
  double x_;
  double y_;

  explicit Piste(double x = 0, double y = 0);
  ~Piste();
};

class Suorakulmio {
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
};

class Kolmio {
  Piste a_;
  Piste b_;
  Piste c_;

  static double sivunPituus(const Piste& p, const Piste& q);

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
};

std::ostream &
operator<<(std::ostream &tuloste, const Piste &p);
std::ostream &
operator<<(std::ostream &tuloste, const Suorakulmio &sk);
std::ostream &
operator<<(std::ostream &tuloste, const Kolmio &k);
} // namespace otecpp_tasokuviot

#endif //TASOKUVIOT_H
