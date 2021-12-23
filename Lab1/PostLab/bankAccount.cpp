/**
 * Ryan Grayson
 * rtg5xkh
 * 02/12/2021
 * bankAccount.cpp
 * Lab 1 PostLab
 */

#include <iostream>
#include "bankAccount.h"
using namespace std;

bankAccount::bankAccount(){
  balance = 0.0;
}

bankAccount::bankAccount(double amount){
  balance = amount;
}

bankAccount::~bankAccount() {}

double bankAccount::withdraw(double amount){
  if (amount <= balance)
    balance -= amount;
  return balance;
}

double bankAccount::deposit(double amount){
  balance += amount;
  return balance;
}

double bankAccount::getBalance() const{
  return balance;
}
