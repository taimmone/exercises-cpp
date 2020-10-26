#ifndef VARAUS_H
#define VARAUS_H

#include <cstddef>

namespace otecpp_varaus
{
int *
lukusarja(size_t n, int luku);

int *
nollasarja(size_t n);

int *
uusiSarja(int *t, size_t vanha_koko, size_t uusi_koko, int luku);

void
tulostaSarja(int *t, size_t koko);
} // namespace otecpp_varaus

#endif //VARAUS_H
