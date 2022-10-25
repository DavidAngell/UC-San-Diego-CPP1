//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/25/2022
// C1A5E3_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// A program that will prompt the user for two double
// values and then display the maximum and minimum of
// the two values.
//

#include <iostream>
#include "C1A5E3_ComputeMinMax.h"

int main() {
  // Get two double inputs from the user
  double value1, value2;
  std::cout << "Enter two values separated by a space: ";
  std::cin >> value1 >> value2;

  // Display the results
  std::cout
    << "ComputeMinimum(&" << value1 << ", &" << value2 << ") returned &" 
    << *ComputeMinimum(&value1, &value2) << "\n";

  std::cout
    << "ComputeMaximum(&" << value1 << ", &" << value2 << ") returned &" 
    << *ComputeMaximum(&value1, &value2) << "\n";

  return 0;
}
