//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/25/2022
// C1A5E2_ComputeMinimum.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// A file containing the function definition for the
// ComputeMinimum function, which returns a reference to
// the minimum value of two const double values.
//

/// @brief Compute the minimum of two const double values
/// @param value1 A const double reference
/// @param value2 A const double reference
/// @return A reference to the minimum of the two values
double &ComputeMinimum(const double &value1, const double &value2) {
    return const_cast<double &>((value1 < value2) ? value1 : value2);
}