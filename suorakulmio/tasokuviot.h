#ifndef TASOKUVIOT_H
#define TASOKUVIOT_H

#include <iostream>

namespace otecpp_tasokuviot
{
struct Piste {
  double x;
  double y;

  explicit Piste(double X = 0, double Y = 0) : x(X), y(Y) {
    std::cout << "Luodaan Piste(" << x << ", " << y << ")\n";
  }

  ~Piste() {
    std::cout << "Tuhotaan Piste(" << x << ", " << y << ")\n";
  }
};

class Suorakulmio {
  Piste va;
  Piste oy;

public:
  explicit Suorakulmio(Piste const &Va = Piste(), Piste const &Oy = Piste()) : va(Va), oy(Oy) {
    std::cout << "Luodaan Suorakulmio((" << va.x << ", " << va.y << "), (" << oy.x << ", " << oy.y << "))\n";
  }

  ~Suorakulmio() {
    std::cout << "Tuhotaan Suorakulmio((" << va.x << ", " << va.y << "), (" << oy.x << ", " << oy.y << "))\n";
  }

  double leveys() const { return oy.x - va.x; }
  double korkeus() const { return oy.y - va.y; }
  double pinta_ala() const { return leveys()*korkeus(); }
};
} // namespace otecpp_tasokuviot

#endif //TASOKUVIOT_H
