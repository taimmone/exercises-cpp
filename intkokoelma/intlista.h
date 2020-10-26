#ifndef INTLISTA_H
#define INTLISTA_H

#include <cstddef>
#include <vector>
#include <ostream>
#include "intkokoelma.h"

using otecpp_intkokoelma::IntPino;
using otecpp_intkokoelma::IntJono;

namespace otecpp_intlista
{
struct IntSolmu {
  IntSolmu(int arvo, IntSolmu *seur, IntSolmu *edel);
  ~IntSolmu();
  int arvo() const;
  IntSolmu *seur() const;
  IntSolmu *edel() const;
  void seur(IntSolmu *s);
  void edel(IntSolmu *s);
private:
  friend class IntLista;
  int arvo_;
  IntSolmu *seur_;
  IntSolmu *edel_;
};

struct IntLista : IntPino, IntJono {
  typedef size_t size_type;
  explicit IntLista();
  explicit IntLista(std::vector<int> const &t);
  IntLista(const IntLista &il);
  ~IntLista();
  IntLista &operator=(IntLista const &il);
  int &operator[](size_type i);
  int const &operator[](size_type i) const;
  operator std::vector<int>() const;
  void pinoon(int arvo);
  int pinosta();
  void jonoon(int arvo);
  int jonosta();
  IntSolmu *paa() const;
  IntSolmu *hanta() const;
  size_type koko() const;
  bool onTyhja() const;
private:
  IntSolmu *paa_;
  IntSolmu *hanta_;
  size_type koko_;
};

std::ostream &
operator<<(std::ostream &virta, IntSolmu const *s);
} // namespace otecpp_intlista

#endif //INTLISTA_H
