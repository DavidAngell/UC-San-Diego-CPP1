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

#ifndef MAX_OF_H
#define MAX_OF_H

#define mMaxOf2(a, b) ((a) > (b) ? (a) : (b))
#define mMaxOf3(a, b, c) (mMaxOf2(a, mMaxOf2(b, c)))

inline long double fMaxOf2(long double a, long double b) {
    if (a > b)
        return a;
    else
        return b;
}

inline long double fMaxOf3(long double a, long double b, long double c) {
    return fMaxOf2(a, fMaxOf2(b, c));
}

#endif