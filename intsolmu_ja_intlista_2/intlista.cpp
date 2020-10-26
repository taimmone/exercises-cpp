#include <iostream>
#include "intlista.h"

namespace otecpp_intlista
{
// IntSolmun toteutus
IntSolmu::IntSolmu(int arvo, IntSolmu *seur)
    : arvo_(arvo),
      seur_(seur) {
}
IntSolmu::~IntSolmu() {
}
int
IntSolmu::arvo() const { return arvo_; }

IntSolmu *
IntSolmu::seur() const { return seur_; }
void
IntSolmu::seur(IntSolmu *seur) { seur_ = seur; }

// IntListan toteutus
IntLista::IntLista()
    : paa_(NULL),
      koko_(0) {}
IntLista::IntLista(const IntLista &il)
    : paa_(NULL),
      koko_(0) {
  for (IntSolmu *s = il.paa_; s!=NULL; s = s->seur()) {
    lisaaTaakse(s->arvo());
  }
}
IntLista::IntLista(std::vector<int> const &t)
    : paa_(NULL),
      koko_(0) {
  for (std::vector<int>::const_iterator i = t.begin(); i!=t.end(); ++i) {
    lisaaTaakse(*i);
  }
}
IntLista::~IntLista() {
  while (koko_) poistaEdesta();
}
IntLista &
IntLista::operator=(IntLista const &il) {
  if (this != &il) {
    while (koko_) {
      poistaEdesta();
    }
    for (IntSolmu *s = il.paa_; s != NULL; s= s->seur()) {
      lisaaTaakse(s->arvo());
    }
  }
  return *this;
}
int &
IntLista::operator[](IntLista::size_type i) {
  IntSolmu *solmu = paa_;
  for (IntLista::size_type ind = 0; ind++!=i; solmu=solmu->seur());
  return solmu->arvo_;
}
int const &
IntLista::operator[](IntLista::size_type i) const {
  IntSolmu const *solmu = paa_;
  for (IntLista::size_type ind = 0; ind++!=i; solmu=solmu->seur());
  return solmu->arvo_;
}
IntLista::operator std::vector<int>() const {
  std::vector<int> t;
  IntSolmu *s = paa_;
  while (s) {
    t.push_back(s->arvo_);
    s=s->seur();
  }
  return t;
}

void
IntLista::lisaaEteen(int arvo) {
  IntSolmu *uusi = new IntSolmu(arvo, paa_);
  paa_ = uusi;
  koko_++;
}
int
IntLista::poistaEdesta() {
  IntSolmu *poistettava = paa_;
  int poistettavan_arvo = poistettava->arvo();
  paa_ = poistettava->seur();
  delete poistettava;
  koko_--;
  return poistettavan_arvo;
}
void
IntLista::lisaaTaakse(int arvo) {
  if (!koko_) {
    lisaaEteen(arvo);
    return;
  }
  IntSolmu *uusi = new IntSolmu(arvo, NULL);
  IntSolmu *s = paa_;
  while (s->seur()) s=s->seur();
  s->seur(uusi);
  koko_++;
}
int
IntLista::poistaTakaa() {
  if (koko_==1) {
    return poistaEdesta();
  }
  IntSolmu *nykyinen = paa_;
  IntSolmu *edellinen = NULL;
  int poistettavan_arvo = nykyinen->arvo();
  while (nykyinen->seur()!=NULL) {
    edellinen = nykyinen;
    nykyinen = nykyinen->seur();
  }
  edellinen->seur(NULL);
  delete nykyinen;
  koko_--;
  return poistettavan_arvo;
}

IntSolmu *
IntLista::paa() const { return paa_; }

IntLista::size_type
IntLista::koko() const { return koko_; }

std::ostream &
operator<<(std::ostream &virta, IntSolmu const *s) {
  if (s) {
    virta << s->arvo();
  } else {
    virta << "NULL";
  }
  return virta;
}
} // namespace otecpp_intlista