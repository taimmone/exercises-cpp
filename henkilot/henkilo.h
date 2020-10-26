#ifndef HENKILO_H
#define HENKILO_H

#include <string>

namespace otecpp_henkilo
{
class Henkilo {
  static unsigned int lukumaara;
  static unsigned int seurId;

  const unsigned int id_;
  std::string nimi_;

public:
  explicit Henkilo(std::string const &nimi);
  Henkilo(const Henkilo &h);
  ~Henkilo();

  static unsigned int lkm();
  unsigned int id() const;
  std::string const &nimi() const;
  void nimi(std::string const &uusi_nimi);
};
} // namespace otecpp_henkilo

#endif //HENKILO_H
