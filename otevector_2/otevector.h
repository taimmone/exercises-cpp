#ifndef OTEVECTOR_H
#define OTEVECTOR_H

#include <iostream>
#include <stdexcept>
#include <sstream>

namespace otecpp_otevector
{
template<typename T> class OteVector {
  unsigned int koko_;
  T *taulu_;

public:
  explicit OteVector(unsigned int koko);
  ~OteVector();
  OteVector(OteVector<T> &alkuperainen);
  T &operator[](int i) throw (std::out_of_range);
  const T &operator[](int i) const throw (std::out_of_range);
  OteVector<T> &operator=(OteVector<T> const &vektori);
};

template<typename T>
OteVector<T>::OteVector(unsigned int koko)
    : koko_(koko),
      taulu_(new T[koko]) {}

template<typename T>
OteVector<T>::~OteVector<T>() {
  delete[] taulu_;
}

template<typename T>
OteVector<T>::OteVector(OteVector<T> &alkuperainen)
    : koko_(alkuperainen.koko_),
      taulu_(new T[koko_]) {
  for (unsigned i = 0; i < koko_; ++i) {
    taulu_[i] = alkuperainen[i];
  }
}

template<typename T> T &
OteVector<T>::operator[](int i) throw(std::out_of_range) {
  if (i >= koko_ || i < 0) {
    std::ostringstream oss; oss << i;
    throw std::out_of_range(oss.str());
  } else {
    return taulu_[i];
  }
}

template<typename T> T const &
OteVector<T>::operator[](int i) const throw (std::out_of_range) {
  if (i >= koko_ || i < 0) {
    std::ostringstream oss; oss << i;
    throw std::out_of_range(oss.str());
  }
  return taulu_[i];
}

template<typename T> OteVector<T> &
OteVector<T>::operator=(OteVector<T> const &vektori) {
  if (this != &vektori) {
    delete [] taulu_;
    koko_ = vektori.koko_;
    taulu_ = new T[koko_];

    for (unsigned i = 0; i < koko_; ++i) {
      taulu_[i] = vektori[i];
    }
  }
  return *this;
}
} // namespace otecpp_otevector

#endif