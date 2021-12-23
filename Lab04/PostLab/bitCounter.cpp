/**
 * Ryan Grayson
 * rtg5xkh
 * 03/10/2021
 * PostLab 4
 * bitCounter.cpp
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int numOnes(int n){
  if (n == 0)
    return 0;
  
  else if (n%2 == 0)
    return numOnes(n/2);
  
  else
    return numOnes(n/2) + 1;
}

string convI(int d){
  string s = "";
  char c;
  if (d < 10)
    c = d + 48;
  else
    c = d + 55;
  s.push_back(c);
  return s;
}

int convS(char d){
  int i = d;
  if (i < 65)
    return i - 48;
  
  return i - 55;
}

string convertBase(string n, int startBase, int endBase){
  
  if (startBase == endBase)
    return n;

  int tenI = 0;
  string tenS = "";

  if (startBase == 1){
    tenI = n.length();
    tenS = to_string(tenI);
  }
  else if (startBase != 10){
    for (int i = 0; i < n.length(); i++){
      tenI += convS(n.at(i)) * pow(startBase, n.length() - i - 1);
    }
    tenS = to_string(tenI);
  }
  else{
    tenI = stoi(n);
    tenS = n;  
  }
  
  if (endBase == 10)
    return tenS;

  if (endBase == 1){
    string o = "";
    for (int i = 0; i < tenI; i++){
      o += "0";
    }
    return o;
  }   

  int rI = tenI;
  string rS = "";
  int remain = 0;
  int quot = 1; 
  string temp = "";

  while (quot != 0){
    
      remain = rI % endBase;
      rI -= rI % endBase;
      quot = rI / endBase;

      temp += convI(remain);
      rI = quot;
  }
  
  for (int i = temp.length() - 1; i >= 0; i--){
    rS += temp.at(i);
  }
  return rS;
}

int main(int argc, char* argv[]){

  if (argc == 1){
    cout << "you must enter 4 integers as command line parameters" << endl;
    return 0;
  }

  int x = atoi(argv[1]);
  cout << argv[1] << " has " << numOnes(x) << " bit(s)" << endl;

  string n = argv[2];
  int s = atoi(argv[3]);
  int e = atoi(argv[4]);
  cout << n << " (base " << s << ") = " << convertBase(n, s, e) << " (base " << e << ")" << endl;
  
  return 0;
}
