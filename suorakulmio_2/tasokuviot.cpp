#include <iostream>
#include "tasokuviot.h"

namespace otecpp_tasokuviot
{
Piste::Piste(double x, double y) : x(x), y(y) {
  std::cout << "Luodaan Piste(" << x << ", " << y << ")\n";
}
Piste::~Piste() {
  std::cout << "Tuhotaan Piste(" << x << ", " << y << ")\n";
}

Suorakulmio::Suorakulmio(Piste const &va, Piste const &oy) : va(va), oy(oy) {
  std::cout << "Luodaan Suorakulmio((" << va.x << ", " << va.y << "), (" << oy.x << ", " << oy.y << "))\n";
}
Suorakulmio::Suorakulmio(Suorakulmio const &sk) : va(sk.va), oy(sk.oy) {
  std::cout << "Luodaan kopio Suorakulmio((" << va.x << ", " << va.y << "), (" << oy.x << ", " << oy.y << "))\n";
}
Suorakulmio::~Suorakulmio() {
  std::cout << "Tuhotaan Suorakulmio((" << va.x << ", " << va.y << "), (" << oy.x << ", " << oy.y << "))\n";
}

Piste const &
Suorakulmio::vasenAlakulma() const { return va; }
void
Suorakulmio::vasenAlakulma(Piste const &va) { this->va = va; }
Piste const &
Suorakulmio::oikeaYlakulma() const { return oy; }
void
Suorakulmio::oikeaYlakulma(Piste const &oy) { this->oy = oy; }

double
Suorakulmio::leveys() const { return oy.x - va.x; }
double
Suorakulmio::korkeus() const { return oy.y - va.y; }
double
Suorakulmio::pinta_ala() const { return leveys()*korkeus(); }

} // namespace otecpp_tasokuviot