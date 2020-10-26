#ifndef VEKTORI_H
#define VEKTORI_H

#include <cmath>
#include <cstddef>
#include <iostream>
#include <sstream>
#include "poikkeukset.h"

namespace otecpp_vektori
{
template<typename T, size_t koko> struct Vektori {
  typedef T *iterator;
  typedef T *const const_iterator;
  size_t const n;

  Vektori();
  T &operator[](size_t i) throw(otecpp_poikkeukset::LaitonIndeksi);
  T const &operator[](size_t i) const throw(otecpp_poikkeukset::LaitonIndeksi);
  template<typename U> Vektori &operator+(Vektori<U, koko> const &b) const;
  template<typename U> Vektori &operator-(Vektori<U, koko> const &b) const;
  template<typename U> double pisteTulo(const Vektori<U, koko> &b) const;
  double pituus() const;
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
private:
  T *taulu;
};

template<typename T, size_t koko>
Vektori<T, koko>::Vektori()
    : n(koko),
      taulu(new T[koko]) {}

template<typename T, size_t koko> T &
Vektori<T, koko>::operator[](size_t i) throw(otecpp_poikkeukset::LaitonIndeksi) {
  try {
    if (i >= koko || i < 0) {
      std::ostringstream oss;
      oss << i;
      throw otecpp_poikkeukset::LaitonIndeksi(oss.str());
    }
  } catch (otecpp_poikkeukset::LaitonIndeksi &e) {
    std::cout << e.what();
  }
  return taulu[i];
}
template<typename T, size_t koko> T const &
Vektori<T, koko>::operator[](size_t i) const throw(otecpp_poikkeukset::LaitonIndeksi) {
  try {
    if (i >= koko || i < 0) {
      std::ostringstream oss;
      oss << i;
      throw otecpp_poikkeukset::LaitonIndeksi(oss.str());
    }
  } catch (otecpp_poikkeukset::LaitonIndeksi &e) {
    std::cout << e.what();
  }
  return taulu[i];
}

template<typename T, size_t koko> template<typename U> Vektori<T, koko> &
Vektori<T, koko>::operator+(Vektori<U, koko> const &b) const {
  Vektori *uusi = new Vektori<T, koko>;
  for (size_t i = 0; i < koko; ++i) {
    (*uusi)[i] = taulu[i] + b[i];
  }
  return *uusi;
}
template<typename T, size_t koko> template<typename U> Vektori<T, koko> &
Vektori<T, koko>::operator-(Vektori<U, koko> const &b) const {
  Vektori *uusi = new Vektori<T, koko>;
  for (size_t i = 0; i < koko; ++i) {
    (*uusi)[i] = taulu[i] - b[i];
  }
  return *uusi;
}
template<typename T, size_t koko> template<typename U> double
Vektori<T, koko>::pisteTulo(Vektori<U, koko> const &b) const {
  double pistetulo = 0;
  for (size_t i = 0; i < koko; ++i) {
    pistetulo += taulu[i]*b[i];
  }
  return pistetulo;
}

template<typename T, size_t koko> double
Vektori<T, koko>::pituus() const {
  double summa = 0;
  for (size_t i = 0; i < koko; ++i) {
    summa += std::pow(taulu[i], 2);
  }
  return std::sqrt(summa);
}

template<typename T, size_t koko> std::ostream &
operator<<(std::ostream &out, const Vektori<T, koko> &v) {
  out << "[";
  for (size_t i = 0; i < v.n - 1; ++i) {
    out << v[i] << ", ";
  }
  out << v[v.n - 1] << ']';
  return out;
}

template<typename T, size_t koko> typename Vektori<T, koko>::iterator
Vektori<T, koko>::begin() {
  return iterator(taulu);
}
template<typename T, size_t koko> typename Vektori<T, koko>::iterator
Vektori<T, koko>::end() {
  return iterator(taulu+koko);
}
template<typename T, size_t koko> typename Vektori<T, koko>::const_iterator
Vektori<T, koko>::begin() const {
  return const_iterator(taulu);
}
template<typename T, size_t koko> typename Vektori<T, koko>::const_iterator
Vektori<T, koko>::end() const {
  return const_iterator(taulu+koko);
}
} // namespace otecpp_vektori

#endif //VEKTORI_H
