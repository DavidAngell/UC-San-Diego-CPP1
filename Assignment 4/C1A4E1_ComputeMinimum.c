//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E1_ComputeMinimum.c
// Ubuntu 20.04
// GCC 6.3.0
//
// A file containing the function definition for the
// ComputeMinimum function, which returns the minimum of
// two double values.
//

/// @brief Compute the minimum of two double values
/// @param value1 A double value
/// @param value2 A double value
/// @return The minimum of the two values
double ComputeMinimum(double value1, double value2) {
    return (value1 < value2) ? value1 : value2;
}
