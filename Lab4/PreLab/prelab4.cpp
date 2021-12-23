/**
 * Ryan Grayson
 * rtg5xkh
 * 03/03/2021
 * PreLab 4
 * prelab4.cpp
 */

#include <iostream>
using namespace std;

void sizeOfTest();

void overflow();

void outputBinary(unsigned int x);

int main(){

  unsigned int x;
  cin >> x;

  sizeOfTest();

  overflow();

  outputBinary(x);
  
  return 0;
}

void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow(){
  unsigned int u = 4294967295;
  cout << u << " + 1 = " << u + 1 << endl;
}

void outputBinary(unsigned int x){

  string s = "";
  int c = 0;
  
  for (unsigned int i = 2147483648; i > 0; i /= 2){
    if (c % 4 == 0 && c != 0)
      s += " ";
    
    if (x >= i){
      s += "1";
      x -= i;
    }
    else
      s += "0";
    c++;
  }
  cout << s << endl;
}

    
      
