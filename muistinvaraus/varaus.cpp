#include <iostream>
#include <algorithm>
#include <cstddef>
#include "varaus.h"

namespace otecpp_varaus
{
int *
lukusarja(size_t n, int luku) {
  int *t = new int[n];
  std::fill_n(t, n, luku);
  return t;
}
int *
nollasarja(size_t n) {
  return new int[n]();
}
int *
uusiSarja(int *t, size_t vanha_koko, size_t uusi_koko, int luku) {
  int *uusi = new int[uusi_koko];
  std::copy(t, t+(vanha_koko < uusi_koko ? vanha_koko : uusi_koko), uusi);
  if (vanha_koko < uusi_koko)
    std::fill(uusi+vanha_koko, uusi+uusi_koko, luku);
  delete [] t;
  return uusi;
}
void
tulostaSarja(int *t, size_t koko) {
  for (size_t i = 0; i < koko; i++)
    std::cout << ' ' << t[i];
  std::cout << std::endl;
}
} // namespace otecpp_varaus
