#include <iostream>
#include <cmath>
#include <sstream>
#include "tasokuviot.h"

namespace otecpp_tasokuviot
{
Piste::Piste(double x, double y) : x_(x), y_(y) {
  std::cout << "Luodaan " << *this << std::endl;
}
Piste::~Piste() {
  std::cout << "Tuhotaan " << *this << std::endl;
}

Suorakulmio::Suorakulmio(Piste const &va, Piste const &oy) : va_(va), oy_(oy) {
  std::cout << "Luodaan " << *this << std::endl;
}
Suorakulmio::Suorakulmio(Suorakulmio const &sk) : va_(sk.va_), oy_(sk.oy_) {
  std::cout << "Luodaan kopio " << *this << std::endl;
}
Suorakulmio::~Suorakulmio() {
  std::cout << "Tuhotaan " << *this << std::endl;
}

Piste const &
Suorakulmio::vasenAlakulma() const { return va_; }
void
Suorakulmio::vasenAlakulma(Piste const &va) { this->va_ = va; }
Piste const &
Suorakulmio::oikeaYlakulma() const { return oy_; }
void
Suorakulmio::oikeaYlakulma(Piste const &oy) { this->oy_ = oy; }

double
Suorakulmio::leveys() const { return oy_.x_ - va_.x_; }
double
Suorakulmio::korkeus() const { return oy_.y_ - va_.y_; }
double
Suorakulmio::pinta_ala() const { return leveys()*korkeus(); }

Kolmio::Kolmio(Piste const &a, Piste const &b, Piste const &c)
    : a_(a),
      b_(b),
      c_(c) {
  std::cout << "Luodaan " << *this << std::endl;
}
Kolmio::Kolmio(Kolmio const &k) {
  std::cout << "Luodaan kopio " << *this << std::endl;
}
Kolmio::~Kolmio() {
  std::cout << "Tuhotaan " << *this << std::endl;
}

Piste const &
Kolmio::a() const { return a_; }
Piste const &
Kolmio::b() const { return b_; }
Piste const &
Kolmio::c() const { return c_; }

double
Kolmio::sivunPituus(Piste const &p, Piste const &q) {
  return std::sqrt(std::pow(p.x_ - q.x_, 2) + std::pow(p.y_ - q.y_, 2));
}
double
Kolmio::sivu1() const {
  return sivunPituus(a_, b_);
}
double
Kolmio::sivu2() const {
  return sivunPituus(b_, c_);
}
double
Kolmio::sivu3() const {
  return sivunPituus(a_, c_);
}
double
Kolmio::pinta_ala() const {
  return std::abs((a_.x_-c_.x_)*(b_.y_-a_.y_)-(a_.x_-b_.x_)*(c_.y_-a_.y_))/2;
}

std::ostream &
operator<<(std::ostream &tuloste, Piste const &p) {
  tuloste << '(' << p.x_ << ", " << p.y_ << ')';
  return tuloste;
}
std::ostream &
operator<<(std::ostream &tuloste, Suorakulmio const &sk) {
  tuloste << '[' << sk.vasenAlakulma() << ", " << sk.oikeaYlakulma() << ']';
  return tuloste;
}
std::ostream &
operator<<(std::ostream &tuloste, Kolmio const &k) {
  tuloste << '<' << k.a() << ", " << k.b() << ", " << k.c() << '>';
  return tuloste;
}
} // namespace otecpp_tasokuviot
