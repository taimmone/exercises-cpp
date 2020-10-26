#ifndef TASOKUVIOT_H
#define TASOKUVIOT_H

namespace otecpp_tasokuviot
{
struct Piste {
  double x;
  double y;

  explicit Piste(double x = 0, double y = 0);
  ~Piste();
};

class Suorakulmio {
  Piste va;
  Piste oy;

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
} // namespace otecpp_tasokuviot

#endif //TASOKUVIOT_H
