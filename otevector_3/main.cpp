#include <algorithm>  // count, sort
#include <iostream>
#include <numeric>    // inner_product
#include "vektori.h"

using namespace std;
using otecpp_vektori::vektori;

int main()
{
  Vektori<int, 3> v;
  v[0] = 2; v[1] = 4; v[2] = 4;
  Vektori<int, 3> v2;
  v2[0] = 2; v2[1] = -4; v2[2] = -4;
  cout << "v.pisteTulo(v2): " << v.pisteTulo(v2) << '\n';
  const Vektori<int, 3> &cv = v;
  const Vektori<int, 3> &cv2 = v2;
  cout << "Sama <numeric>:n inner_product-funktiokaavaimella: ";
  cout << inner_product(cv.begin(), cv.end(), cv2.begin(), 0) << '\n';
  Vektori<double, 9> v3;
  for(Vektori<double, 9>::iterator i = v3.begin(); i != v3.end(); ++i)
  {
    *i = ((i - v3.begin()) % 2) + 0.5;
  }
  cout << "v3: " << v3 << '\n';
  cout << "v3:n arvojen 1.5 määrä: " << count(v3.begin(), v3.end(), 1.5) << '\n';
  sort(v3.begin(), v3.end(), greater<double>());
  cout << "v3 laskevasti lajiteltuna: " << v3 << '\n';
}