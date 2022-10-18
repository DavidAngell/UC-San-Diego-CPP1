//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/13/2022
// C1A4E4_MaxOf.h
// Ubuntu 20.04
// GCC 6.3.0
//
// Defines a 2-parameter macro that returns the maximum of its two 
// arguments, a 3-parameter macro that returns the maximum of its 
// three arguments, a 2-parmeter inline function that returns the
// maximum of its two arguments, and a 3-parameter inline function
// that returns the maximum of its three arguments.
//

#ifndef C1A4E4_MAXOF_H
#define C1A4E4_MAXOF_H

#define mMaxOf2(a, b) ((a) > (b) ? (a) : (b))
#define mMaxOf3(a, b, c) (mMaxOf2((a), mMaxOf2((b), (c))))

/// @brief Finds the maximum of two long double values
/// @param a The first long double value
/// @param b The second long double value
/// @return The maximum of the two long double values
inline long double fMaxOf2(long double a, long double b) {
    return (a > b) ? a : b;
}

/// @brief Finds the maximum of three long double values
/// @param a The first long double value
/// @param b The second long double value
/// @param c The third long double value
/// @return The maximum of the three long double values
inline long double fMaxOf3(long double a, long double b, long double c) {
    return fMaxOf2(a, fMaxOf2(b, c));
}

#endif