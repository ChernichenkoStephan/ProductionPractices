#include <iostream>
#include <cstdlib>

#include "Equation/linear.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

using namespace std;


int main() {
  system("clear");

  double a, b, c, d, e, f;

  a = 6.66;b = 6.66;c = 6.66;d = 6.66;e = 6.66;f = 6.66;

  //cin >> a >> b >> c >> d >> e >> f;

  string res = solve_linear(a, b, c, d, e, f);

  cout << res << endl;

  return 0;
}
