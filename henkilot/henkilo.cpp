#include "henkilo.h"

namespace otecpp_henkilo
{
unsigned Henkilo::lukumaara = 0;
unsigned Henkilo::seurId = 0;

Henkilo::Henkilo(std::string const &nimi)
    : nimi_(nimi),
      id_(++seurId) {
  lukumaara++;
}
Henkilo::Henkilo(Henkilo const &h)
    : nimi_(h.nimi()),
      id_(++seurId) {
  lukumaara++;
}
Henkilo::~Henkilo() {
  lukumaara--;
}

unsigned int
Henkilo::lkm() {
  return lukumaara;
}
unsigned int
Henkilo::id() const {
  return id_;
}
std::string const &
Henkilo::nimi() const {
  return nimi_;
}
void
Henkilo::nimi(std::string const &uusi_nimi) {
  nimi_ = uusi_nimi;
}
} // namespace otecpp_henkilo