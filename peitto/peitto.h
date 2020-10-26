#ifndef PEITTO_H
#define PEITTO_H

#include <string>

namespace otecpp_peitto
{
struct A {
  std::string kuvaus_;
  explicit A(std::string const &nimi);
  virtual std::string lueKuvaus() const;
  virtual void kuka(A const &a) const;
};

struct B : A {
  std::string kuvaus_;
  explicit B(std::string const & nimi);
  std::string lueKuvaus() const;
  using A::kuka;
  void kuka(B const &B) const;
};
} // namespace otecpp_peitto

#endif //PEITTO_H
