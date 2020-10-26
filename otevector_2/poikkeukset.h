#ifndef POIKKEUKSET_H
#define POIKKEUKSET_H

#include <exception>
#include <string>

namespace otecpp_poikkeukset
{
class OdottamatonPoikkeus : public std::exception {
  std::string viesti_;
public:
  OdottamatonPoikkeus(std::string const &viesti);
  const char *what() const throw();
  ~OdottamatonPoikkeus() throw() {};
};

void
asetaKasittelijat();
} // namespace otecpp_poikkeukset

#endif //POIKKEUKSET_H
