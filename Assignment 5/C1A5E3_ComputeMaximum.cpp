//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/25/2022
// C1A5E3_ComputeMaximum.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// A file containing the function definition for the
// ComputeMaximum function, which returns a pointer to
// the maximum value of two const double values.
//

/// @brief Compute the maximum of two const double values
/// @param value1 A const double pointer
/// @param value2 A const double pointer
/// @return A pointer to the maximum of the two values
double *ComputeMaximum(const double *value1, const double *value2) {
  return (double *)((*value1 > *value2) ? value1 : value2);
}