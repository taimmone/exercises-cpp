#ifndef VEKTORI_H
#define VEKTORI_H

#include <iostream>
#include <stdexcept>
#include <sstream>

namespace otecpp_vektori
{

template<typename T> class Vektori {
  unsigned int koko_;
  T *taulu_;

public:
  typedef T *iterator;
  typedef T *const const_iterator;
  explicit Vektori(unsigned int koko);
  ~Vektori();
  Vektori(Vektori<T> &alkuperainen);
  T &operator[](int i) throw(std::out_of_range);
  const T &operator[](int i) const throw(std::out_of_range);
  Vektori<T> &operator=(Vektori<T> const &vektori);
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
};

template<typename T>
Vektori<T>::Vektori(unsigned int koko)
    : koko_(koko),
      taulu_(new T[koko]) {}

template<typename T>
Vektori<T>::~Vektori<T>() {
  delete[] taulu_;
}

template<typename T>
Vektori<T>::Vektori(Vektori<T> &alkuperainen)
    : koko_(alkuperainen.koko_),
      taulu_(new T[koko_]) {
  for (unsigned i = 0; i < koko_; ++i) {
    taulu_[i] = alkuperainen[i];
  }
}

template<typename T> T &
Vektori<T>::operator[](int i) throw(std::out_of_range) {
  if (i >= koko_ || i < 0) {
    std::ostringstream oss;
    oss << i;
    throw std::out_of_range(oss.str());
  } else {
    return taulu_[i];
  }
}

template<typename T> T const &
Vektori<T>::operator[](int i) const throw(std::out_of_range) {
  if (i >= koko_ || i < 0) {
    std::ostringstream oss;
    oss << i;
    throw std::out_of_range(oss.str());
  }
  return taulu_[i];
}

template<typename T> Vektori<T> &
Vektori<T>::operator=(Vektori<T> const &vektori) {
  if (this!=&vektori) {
    delete[] taulu_;
    koko_ = vektori.koko_;
    taulu_ = new T[koko_];

    for (unsigned i = 0; i < koko_; ++i) {
      taulu_[i] = vektori[i];
    }
  }
  return *this;
}

template<typename T> typename Vektori<T>::iterator
Vektori<T>::begin() {
  return taulu_;
}
template<typename T> typename Vektori<T>::const_iterator
Vektori<T>::begin() const {
  return taulu_;
}
template<typename T> typename Vektori<T>::iterator
Vektori<T>::end() {
  return *taulu_[koko_];
}
template<typename T> typename Vektori<T>::const_iterator
Vektori<T>::end() const {
  return *taulu_[koko_];
}
} // namespace otecpp_vektori

#endif