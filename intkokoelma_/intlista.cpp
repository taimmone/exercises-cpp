#include "intlista.h"

namespace otecpp_intlista
{
// IntSolmun toteutus
IntSolmu::IntSolmu(int arvo, IntSolmu *seur, IntSolmu *edel)
    : arvo_(arvo),
      seur_(seur),
      edel_(edel) {
}
IntSolmu::~IntSolmu() {
}
int
IntSolmu::arvo() const { return arvo_; }

IntSolmu *
IntSolmu::seur() const { return seur_; }
IntSolmu *
IntSolmu::edel() const { return edel_; }
void
IntSolmu::seur(IntSolmu *s) { seur_ = s; }
void
IntSolmu::edel(IntSolmu *s) { edel_ = s; }

// IntListan toteutus
IntLista::IntLista()
    : paa_(NULL),
      hanta_(NULL),
      koko_(0) {}
IntLista::IntLista(const IntLista &il)
    : paa_(NULL),
      hanta_(NULL),
      koko_(0) {
  for (IntSolmu *s = il.paa_; s!=NULL; s = s->seur()) {
    lisaaTaakse(s->arvo());
  }
}
IntLista::IntLista(std::vector<int> const &t)
    : paa_(NULL),
      hanta_(NULL),
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
  if (this!=&il) {
    while (koko_) {
      poistaEdesta();
    }
    for (IntSolmu *s = il.paa_; s!=NULL; s = s->seur()) {
      lisaaTaakse(s->arvo());
    }
  }
  return *this;
}
int &
IntLista::operator[](IntLista::size_type i) {
  IntSolmu *solmu = paa_;
  for (IntLista::size_type ind = 0; ind++!=i; solmu = solmu->seur());
  return solmu->arvo_;
}
int const &
IntLista::operator[](IntLista::size_type i) const {
  IntSolmu const *solmu = paa_;
  for (IntLista::size_type ind = 0; ind++!=i; solmu = solmu->seur());
  return solmu->arvo_;
}
IntLista::operator std::vector<int>() const {
  std::vector<int> t;
  IntSolmu *s = paa_;
  while (s) {
    t.push_back(s->arvo_);
    s = s->seur();
  }
  return t;
}

void
IntLista::lisaaEteen(int arvo) {
  IntSolmu *uusi = new IntSolmu(arvo, paa_, NULL);
  if (koko_) {
    paa_->edel_ = uusi;
  } else {
    hanta_ = uusi;
  }
  paa_ = uusi;
  koko_++;
}
int
IntLista::poistaEdesta() {
    IntSolmu *poistettava = paa_;
    int poistettavan_arvo = poistettava->arvo_;
    if (--koko_) {
      paa_ = poistettava->seur_;
    } else {
      paa_ = NULL;
    }
    delete poistettava;
    return poistettavan_arvo;
}
void
IntLista::lisaaTaakse(int arvo) {
  IntSolmu *uusi = new IntSolmu(arvo, NULL, hanta_);
  if (koko_) {
    hanta_->seur_ = uusi;
  } else {
    paa_ = uusi;
  }
  hanta_ = uusi;
  koko_++;
}
int
IntLista::poistaTakaa() {
  IntSolmu *poistettava = hanta_;
  int poistettavan_arvo = poistettava->arvo_;
  if (--koko_) {
    hanta_ = poistettava->edel_;
  } else {
    hanta_ = NULL;
  }
  delete poistettava;
  return poistettavan_arvo;
}

IntSolmu *
IntLista::paa() const { return paa_; }
IntSolmu *
IntLista::hanta() const { return hanta_; }

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