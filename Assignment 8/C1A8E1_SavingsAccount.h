//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 11/15/2022
// C1A8E1_SavingsAccount.h
// Ubuntu 20.04
// GCC 6.3.0
//
// This file contains the SavingsAccount class declaration and the 
// function prototype for GetInitialValues, and the function 
// definitions for DisplayValues and CalculatePenalty.
//

#ifndef C1A8E1_SAVINGSACCOUNT_H
#define C1A8E1_SAVINGSACCOUNT_H

#include <iostream>
#include <string>
const double PERCENTAGE_MULTIPLIER = 0.01;

class SavingsAccount {
private:
  int type;
  std::string ownerName;
  long IDnbr;
  double balance, closurePenaltyPercent;

public:
  void GetInitialValues();
  inline void DisplayValues() const;
  inline double CalculatePenalty() const {
    return balance * closurePenaltyPercent * PERCENTAGE_MULTIPLIER;
  }
};

inline void SavingsAccount::DisplayValues() const {
  // Display account type
  std::cout << "Account type: " << type << "\n";

  // Display owner name
  std::cout << "Owner name: " << ownerName << "\n";

  // Display ID number
  std::cout << "ID number: " << IDnbr << "\n";

  // Display balance
  std::cout << "Account balance: " << balance << "\n";

  // Display closure penalty percent
  std::cout 
    << "Account closure penalty percent: " 
    << closurePenaltyPercent 
    << "\n";
}

#endif