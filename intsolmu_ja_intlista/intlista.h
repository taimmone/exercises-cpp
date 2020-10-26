#ifndef INTLISTA_H
#define INTLISTA_H

#include <cstddef>

namespace otecpp_intlista
{
class IntSolmu {
  int arvo_;
  IntSolmu *seur_;

public:
  IntSolmu(int arvo, IntSolmu *seur);
  ~IntSolmu();

  int arvo() const;
  IntSolmu *seur() const;
  void seur(IntSolmu *seur);
};

struct IntLista {
  typedef size_t size_type;

  explicit IntLista();
  IntLista(const IntLista &il);
  ~IntLista();

  void lisaaEteen(int arvo);
  int poistaEdesta();
  void lisaaTaakse(int arvo);
  int poistaTakaa();

  IntSolmu *paa() const;
  size_type koko() const;

private:
  IntSolmu *paa_;
  size_type koko_;
};
} // namespace otecpp_intlista

#endif //INTLISTA_H
