/**
 * Ryan Grayson
 * rtg5xkh
 * 02/24/2021
 * PreLab 3
 * testPostfixCalc.cpp
 */

#include <iostream>
#include <string>
#include "postfixCalculator.h"
using namespace std;

int main() {

  string s;

  postfixCalculator pf;

  while (cin >> s){

    if (s == "+"){
      pf.plus();
    }
    else  if (s == "-"){
      pf.minus();
    }
    else{
      pf.addElement(stoi(s));
    }
  }

  pf.print();

  return 0;
}
