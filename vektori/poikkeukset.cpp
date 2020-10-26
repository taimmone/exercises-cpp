#include "poikkeukset.h"

namespace otecpp_poikkeukset
{
LaitonIndeksi::LaitonIndeksi(std::string const &msg)
    : viesti_("Laiton indeksi: " + msg + '\n') {}
char const *
LaitonIndeksi::what() const throw() {
  return viesti_.c_str();
}
} // namespace otecpp_poikkeukset