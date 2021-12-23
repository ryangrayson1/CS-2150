/**
 * Ryan Grayson
 * rtg5xkh
 * PreLab 9
 * threexinput.cpp
 * 4/14/2021
 */

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int collatz, int steps);

int main() {

  int x;
  cout << "Enter a number: ";
  cin >> x;

  int n;
  cout << "Enter iterations of subroutine: ";
  cin >> n;

  int r = threexplusone(x, 0);

  //timer t;
  //t.start();

  for(int i = 0; i < n; i++){
    threexplusone(x, 0);
  }

  cout << "Steps: " << r << endl;
  
  //t.stop();
  //double avg = t.getTime() * 1000000000;
  //avg /= n;
  //cout << "avg time taken: " << avg << " nanoseconds" << endl;
  
  return 0;
}
