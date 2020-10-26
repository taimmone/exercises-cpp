#ifndef INTKOKOELMA_H
#define INTKOKOELMA_H

#include <cstddef>

namespace otecpp_intkokoelma
{
struct IntKokoelma {
  typedef size_t size_type;
  virtual ~IntKokoelma() {};
  virtual size_type koko() const = 0;
  virtual bool onTyhja() const = 0;
};
struct IntPino : virtual IntKokoelma {
  virtual void pinoon(int arvo) = 0;
  virtual int pinosta() = 0;
};
struct IntJono : virtual IntKokoelma {
  virtual void jonoon(int arvo) = 0;
  virtual int jonosta() = 0;
};
} // namespace otecpp_intkokoelma

#endif //INTKOKOELMA_H
