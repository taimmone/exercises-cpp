#ifndef VALUUTAT_H
#define VALUUTAT_H

#include <string>
#include <vector>

namespace otecpp_valuutat
{
class Valuutta {
  std::string lyhenne_;
  std::string nimi_;
  double kurssi_;

public:
  Valuutta(std::string lyhenne, std::string nimi, double kurssi);
  std::string lyhenne() const;
  std::string const &nimi() const;
  double kurssi() const;
};

std::vector<Valuutta>
lueKurssit(std::istream &syote);
} // namespace otecpp_valuutat

#endif //VALUUTAT_H
