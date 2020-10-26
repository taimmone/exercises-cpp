#include <iostream>
#include <typeinfo>
#include "oliotyypit.h"

using namespace otecpp_luvut;

namespace otecpp_oliotyypit
{
void
laskeLuvut(std::vector<Luku *> const &luvut) {
  unsigned kokonaislukuja = 0;
  unsigned liukulukuja = 0;
  unsigned murtolukuja = 0;

  for (std::vector<Luku *>::const_iterator i = luvut.begin(); i!=luvut.end(); ++i) {
    if (typeid(**i) == typeid(Kokonaisluku)) {
      ++kokonaislukuja;
    } else if (typeid(**i) == typeid(Liukuluku)) {
      ++liukulukuja;
    } else if (typeid(**i) == typeid(Murtoluku)) {
      ++murtolukuja;
    }
  }

  std::cout << "Kokonaisluku: " << kokonaislukuja << " kpl\n";
  std::cout << "Liukuluku: " << liukulukuja << " kpl\n";
  std::cout << "Murtoluku: " << murtolukuja << " kpl\n";
}
} // namespace otecpp_oliotyypit