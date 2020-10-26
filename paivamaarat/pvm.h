#ifndef PVM_H
#define PVM_H

#include <string>

namespace otecpp_pvm
{
struct Pvm {
  int pv_; int kk_; int v_;
  Pvm(int pv, int kk, int v);
  explicit Pvm(const std::string &pvm);

  int pv() const;
  void pv(int pv);
  int kk() const;
  void kk(int kk);
  int v() const;
  void v(int v);

  bool operator==(const Pvm &b) const;
  bool operator<(const Pvm &b) const;
  bool operator>(const Pvm &b) const;
  operator std::string() const;
};

std::ostream & operator<<(std::ostream &out, const Pvm &pvm);
} // namespace otecpp_pvm

#endif //PVM_H
