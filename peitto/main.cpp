#include "peitto.h"

using otecpp_peitto::A;
using otecpp_peitto::B;

int main()
{
  A a("a");
  B b("b");
  a.kuka(a);
  a.kuka(b);
  b.kuka(a);
  b.kuka(b);
}