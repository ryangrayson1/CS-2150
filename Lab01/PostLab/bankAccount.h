/**
 * Ryan Grayson
 * rtg5xkh
 * 02/12/2021
 * bankAccount.h
 * Lab 1 PostLab
 */

#include <iostream>
using namespace std;

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {
 public:

  bankAccount();

  bankAccount(double amount);

  ~bankAccount();

  double withdraw(double amount);

  double deposit(double amount);

  double getBalance() const;

 private:

  double balance;
  
};
  
#endif
