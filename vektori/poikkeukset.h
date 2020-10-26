#ifndef POIKKEUKSET_H
#define POIKKEUKSET_H

#include <exception>
#include <string>

namespace otecpp_poikkeukset
{
class LaitonIndeksi : public std::exception {
  std::string viesti_;
public:
  explicit LaitonIndeksi(std::string const &msg = "");
  ~LaitonIndeksi() throw() {};
  char const *what() const throw();
};
} // namespace otecpp_poikkeukset

#endif //POIKKEUKSET_H
