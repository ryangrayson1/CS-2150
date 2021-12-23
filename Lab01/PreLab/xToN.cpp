/**
 * Ryan Grayson
 * rtg5xkh
 * 02/12/2021
 * xToN.cpp
 */

#include <iostream>
using namespace std;

int xton(int x, int n){
  if (n == 0)
    return 1;
  return x * xton(x, n - 1);
}

int main(){
  int x; int n;
  cin >> x;
  cin >> n;
  cout << xton(x, n) << endl;
  return 0;
}
