#include <iostream>
#include "murtoluku.h"

using namespace std;
using otecpp_murtoluku::Murtoluku;

int
main(int argc, char *argv[]) {
  Murtoluku mlt[6] = {Murtoluku(3, 9), Murtoluku(2, -10), Murtoluku(0, 4), Murtoluku(-2, 0), Murtoluku(), Murtoluku(5)};
  cout << "Luvut:";
  for (int i = 0; i < 6; ++i) {
    cout << " " << mlt[i];
  }
  cout << endl;
  for (int i = 1; i < 4; ++i) {
    cout << mlt[i - 1] << " + " << mlt[i] << " = " << mlt[i - 1] + mlt[i] << '\n';
    cout << mlt[i - 1] << " - " << mlt[i] << " = " << mlt[i - 1] - mlt[i] << '\n';
    cout << mlt[i - 1] << " * " << mlt[i] << " = " << mlt[i - 1]*mlt[i] << '\n';
    cout << mlt[i - 1] << " / " << mlt[i] << " = " << mlt[i - 1]/mlt[i] << '\n';
  }
  cout << mlt[0] << "++ = ";
  cout << mlt[0]++ << '\n';
  cout << mlt[0] << "-- = ";
  cout << mlt[0]-- << '\n';
  cout << "++" << mlt[0] << " = ";
  cout << ++mlt[0] << '\n';
  cout << "--" << mlt[0] << " = ";
  cout << --mlt[0] << '\n';
}