#include <iostream>
#include <cstdlib>
#include "varaus.h"

using namespace std;
using namespace otecpp_varaus;

int main(int argc, char *argv[])
{
  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  int arvo1 = atoi(argv[3]);
  int arvo2 = atoi(argv[4]);
  int *taulu = lukusarja(n1, arvo1);
  tulostaSarja(taulu, n1);
  taulu = uusiSarja(taulu, n1, n2, arvo2);
  tulostaSarja(taulu, n2);
  delete [] taulu;
  taulu = nollasarja(n1+n2);
  tulostaSarja(taulu, n1 + n2);
  delete [] taulu;
}