//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 11/1/2022
// C1A6E1_MyStrlen.c
// Ubuntu 20.04
// GCC 6.3.0
//
// Contains the definition of the MyStrlen function, which returns
// the length of a string.
//

#include <stddef.h>

size_t MyStrlen(const char *s1) {
    // Loop through the string until the end is reached
    const char * const START = s1;
    while (*s1 != '\0') {
        s1++;
    }

    // Return the difference between the start and end of the string
    return s1 - START;
}
