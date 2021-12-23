/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 8
 * 4/9/2021
 * mathfun.cpp
 */

#include <iostream>
using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int main() {

  long a;
  long b;
  cout << "Enter integer 1: ";
  cin >> a;
  cout << "Enter integer 2: ";
  cin >> b;
  
  cout << "Product: " << product(a, b) << endl;
  cout << "Power: " << power(a, b) << endl;
  return 0;
}
