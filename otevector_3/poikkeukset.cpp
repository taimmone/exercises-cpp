#include <iostream>
#include <cstdlib>
#include <sstream>
#include "poikkeukset.h"

namespace otecpp_poikkeukset
{
OdottamatonPoikkeus::OdottamatonPoikkeus(std::string const &viesti)
    : viesti_("Odottamaton poikkeus: " + viesti) {}

const char *
OdottamatonPoikkeus::what() const throw() {
  return viesti_.c_str();
}

void unexpectedKasittelija() {
  try {
    throw;
  } catch (int i) {
    std::ostringstream oss; oss << i;
    throw OdottamatonPoikkeus("int " + oss.str());
  } catch (...) {
    std::cout << "Ohjelma lopetetaan odottamattoman poikkeuksen vuoksi" << std::endl;
    std::terminate();
  }
}

void terminateKasittelija() {
  std::cout << "Kutsuttiin omaa terminate-funktiota" << std::endl;
  exit(EXIT_SUCCESS);
}

void
asetaKasittelijat() {
  std::set_unexpected(unexpectedKasittelija);
  std::set_terminate(terminateKasittelija);
}
} // namespace otecpp_poikkeukset