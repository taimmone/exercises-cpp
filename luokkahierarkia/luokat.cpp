#include <iostream>
#include "luokat.h"

namespace otecpp_luokat
{
A::A(int i)
    : i_(i) {
  std::cout << "A(" << i_ << "): " << sizeof(*this) << std::endl;
}
A::~A() {
  std::cout << "~A(" << i_ << ")" << std::endl;
}

B::B(int i)
    : i_(i),
      A(i + 1) {
  std::cout << "B(" << i_ << "): " << sizeof(*this) << std::endl;
}
B::~B() {
  std::cout << "~B(" << i_ << ")" << std::endl;
}
C::C(int i)
    : i_(i),
      A(i + 1) {
  std::cout << "C(" << i_ << "): " << sizeof(*this) << std::endl;
}
C::~C() {
  std::cout << "~C(" << i_ << ")" << std::endl;
}
D::D(int i)
    : i_(i),
      A(i + 1) {
  std::cout << "D(" << i_ << "): " << sizeof(*this) << std::endl;
}
D::~D() {
  std::cout << "~D(" << i_ << ")" << std::endl;
}

B2::B2(int i)
    : i_(i),
      A(i + 1) {
  std::cout << "B2(" << i_ << "): " << sizeof(*this) << std::endl;
}
B2::~B2() {
  std::cout << "~B2(" << i_ << ")" << std::endl;
}
C2::C2(int i)
    : i_(i),
      A(i + 1) {
  std::cout << "C2(" << i_ << "): " << sizeof(*this) << std::endl;
}
C2::~C2() {
  std::cout << "~C2(" << i_ << ")" << std::endl;
}
D2::D2(int i)
    : i_(i),
      A(i + 1) {
  std::cout << "D2(" << i_ << "): " << sizeof(*this) << std::endl;
}
D2::~D2() {
  std::cout << "~D2(" << i_ << ")" << std::endl;
}

E::E(int i)
    : i_(i),
      B(i + 1),
      C(i + 1),
      D(i + 1) {
  std::cout << "E(" << i_ << "): " << sizeof(*this) << std::endl;
}
E::~E() {
  std::cout << "~E(" << i_ << ")" << std::endl;
}

E2::E2(int i)
    : i_(i),
      A(i + 1),
      B2(i + 1),
      C2(i + 1),
      D2(i + 1) {
  std::cout << "E2(" << i_ << "): " << sizeof(*this) << std::endl;
}
E2::~E2() {
  std::cout << "~E2(" << i_ << ")" << std::endl;
}

F::F(int i)
    : i_(i),
      A(i + 1),
      E(i + 1),
      E2(i + 1) {
  std::cout << "F(" << i_ << "): " << sizeof(*this) << std::endl;
}
F::~F() {
  std::cout << "~F(" << i_ << ")" << std::endl;
}
} // namespace otecpp_luokat