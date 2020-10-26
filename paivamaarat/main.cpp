#include <iostream>
#include <string>
#include "pvm.h"

using namespace std;
using namespace otecpp_pvm;

int
main() {
  const Pvm p1(24, 12, 2016);
  const Pvm p2("24.12.2016");
  const Pvm p3(24, 11, 2016);
  Pvm p4("24.12.2016");
  p4.pv(1);
  p4.kk(1);
  p4.v(2017);
  cout.setf(ios_base::boolalpha);
  cout << p1 << " == " << p2 << ": " << (p1 == p2) << '\n';
  cout << p1 << " == " << p3 << ": " << (p1 == p3) << '\n';
  cout << p1 << " < " << p2 << ": " << (p1 < p2) << '\n';
  cout << p2 << " > " << p4 << ": " << (p2 > p4) << '\n';
  cout << p3 << " < " << p1 << ": " << (p3 < p1) << '\n';
  cout << p4 << " > " << p2 << ": " << (p4 > p2) << '\n';
  cout << "p1: " << p1.pv() << "." << p1.kk() << "." << p1.v() << '\n';
  string mj = "p2, p3 ja p4: " + (string) p2 + ", "
      + (string) p3 + " ja " + (string) p4;
  cout << mj << endl;
  return 0;
}
