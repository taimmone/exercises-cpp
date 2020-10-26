#include <string>
#include <sstream>
#include "ruudut.h"

using std::string;

static string
rakennaRuutu(unsigned x, unsigned y, unsigned char const m = '*') {
  std::ostringstream o;
  for (unsigned row = 1; row <= x; row++) {
    for (unsigned col = 1; col <= y; col++) {
      if (row==1 || row==x || col==1 || col==y)
        o << m;
      else
        o << ' ';
    }
    o << '\n';
  }
  return (o).str();
}

namespace otecpp_ruudut
{
void
piirraRuutuja(istream &syote, ostream &tuloste) {
  string rivi;
  while (std::getline(syote, rivi) && !syote.fail()) {
    std::istringstream v(rivi);
    string sana;

    v >> sana;

    if (sana=="lopeta") return;
    
    else if (sana=="ruutu") {
      int x = 0;
      int y = 0;
      unsigned char m = 0;

      v >> x >> y >> m;

      if (y > 0 && x > 0) {
        if (m)
          tuloste << rakennaRuutu((unsigned)x, (unsigned)y, m);
        else
          tuloste << rakennaRuutu((unsigned)x, (unsigned)y);
        tuloste << '\n';
        continue;
      }
    }
    tuloste << "Laiton komento!\n\n";
  }
}
} // namespace otecpp_ruudut