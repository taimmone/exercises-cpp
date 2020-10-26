#include <iostream>
#include <cstdlib>
#include <sstream>
#include "pvm.h"

namespace otecpp_pvm
{
Pvm::Pvm(int pv, int kk, int v)
    : pv_(pv),
      kk_(kk),
      v_(v) {}

Pvm::Pvm(std::string const &pvm) {
  pv_ = atoi(pvm.substr(0, 2).c_str());
  kk_ = atoi(pvm.substr(3, 5).c_str());
  v_ = atoi(pvm.substr(6, 11).c_str());
}
int
Pvm::pv() const {
  return pv_;
}
void
Pvm::pv(int pv) {
  pv_ = pv;
}
int
Pvm::kk() const {
  return kk_;
}
void
Pvm::kk(int kk) {
  kk_ = kk;
}
int
Pvm::v() const {
  return v_;
}
void
Pvm::v(int v) {
  v_ = v;
}

bool
Pvm::operator==(Pvm const &b) const {
  return v_==b.v() && kk_==b.kk() && pv_==b.pv();
}
bool
Pvm::operator<(Pvm const &b) const {
  if (v_ < b.v() || (v_==b.v() && kk_ < b.kk())) {
    return true;
  } else {
    return kk_==b.kk() && pv_ < b.pv();
  }
}
bool
Pvm::operator>(Pvm const &b) const {
  return !(this < &b);
}
Pvm::operator std::string() const {
  std::ostringstream s;
  s << pv_ << '.' << kk_ << '.' << v_;
  return s.str();
}

std::ostream &
operator<<(std::ostream &out, Pvm const &pvm) {
  out << std::string(pvm);
  return out;
}
} // namespace otecpp_pvm
