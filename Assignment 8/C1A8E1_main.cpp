//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 11/15/2022
// C1A8E1_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// This file contains the main function for the program
// which creates a SavingsAccount object and calls the
// GetInitialValues, DisplayValues, and CalculatePenalty functions.
//

#include <iostream>
#include "C1A8E1_SavingsAccount.h"

int main() {
  // Create SavingsAccount object
  SavingsAccount account;

  // Call GetInitialValues and DisplayValues functions
  account.GetInitialValues();
  account.DisplayValues();

  // Call CalculatePenalty function and display result
  std::cout 
    << "Account closure penalty: " 
    << account.CalculatePenalty() 
    << "\n";

  return 0;
}