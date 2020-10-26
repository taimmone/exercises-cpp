#include <iostream>
#include <fstream>
#include "ruudut.h"

using namespace otecpp_ruudut;

int main(int argc, char const *argv[]) {
  std::ifstream in("ruudut_in.txt");
  std::cout << in.good() << '\n';
  piirraRuutuja(in, std::cout);
  return 0;
}
