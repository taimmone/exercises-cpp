namespace otecpp_otevector
{
template<typename T> class OteVector {
  unsigned int koko_;
  T *taulu_;

public:
  explicit OteVector(unsigned int koko);
  ~OteVector();
  OteVector(OteVector<T> &alkuperainen);
  T &operator[](unsigned int i);
  const T &operator[](unsigned int i) const;
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
OteVector<T>::operator[](unsigned int i) {
  return taulu_[i];
}

template<typename T> T const &
OteVector<T>::operator[](unsigned int i) const {
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