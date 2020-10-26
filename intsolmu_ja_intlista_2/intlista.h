#ifndef INTLISTA_H
#define INTLISTA_H

#include <cstddef>
#include <vector>

namespace otecpp_intlista
{
class IntSolmu {
  friend class IntLista;

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
  explicit IntLista(std::vector<int> const &t);
  IntLista(const IntLista &il);
  ~IntLista();
  IntLista &operator=(IntLista const &il);
  int &operator[](size_type i);
  int const &operator[](size_type i) const;
  operator std::vector<int>() const;

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

std::ostream &
operator<<(std::ostream &virta, IntSolmu const *s);
} // namespace otecpp_intlista

#endif //INTLISTA_H
