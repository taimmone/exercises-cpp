#include <iostream>
#include "intlista.h"

namespace otecpp_intlista
{
// IntSolmun toteutus
IntSolmu::IntSolmu(int arvo, IntSolmu *seur)
    : arvo_(arvo),
      seur_(seur) {
  std::cout << "Luodaan Solmu(" << arvo << ')' << std::endl;
}
IntSolmu::~IntSolmu() {
  std::cout << "Tuhotaan Solmu(" << arvo_ << ')' << std::endl;
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
  for (IntSolmu *s = il.paa_; s != NULL; s = s->seur())
    lisaaTaakse(s->arvo());
}
IntLista::~IntLista() {
  while (koko_) poistaEdesta();
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
  while (s->seur()!=NULL) s = s->seur();
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
} // namespace otecpp_intlista