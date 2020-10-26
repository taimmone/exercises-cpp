#include <iostream>
#include "peitto.h"

namespace otecpp_peitto
{
A::A(std::string const &nimi)
    : kuvaus_("A-olio " + nimi) {}
std::string
A::lueKuvaus() const {
  return kuvaus_;
}
void
A::kuka(A const &a) const {
  std::cout << "Olen " << kuvaus_ << " ja parametrini on " << a.kuvaus_ << " [tai " << a.lueKuvaus() << "]" << std::endl;
}
B::B(std::string const &nimi)
    : A(nimi + "(B:n osana)"),
      kuvaus_("B-olio " + nimi) {}
std::string
B::lueKuvaus() const {
  return kuvaus_;
}
void B::kuka(B const &b) const {
  std::cout << "Olen " << kuvaus_ << " ja parametrini on " << b.kuvaus_ << " [tai " << b.lueKuvaus() << "]" << std::endl;
}
} // namespace otecpp_peitto