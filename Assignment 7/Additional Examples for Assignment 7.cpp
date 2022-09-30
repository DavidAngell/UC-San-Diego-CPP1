// Concepts and examples related to "C/C++ Programming I" Assignment 7
//
// I have provided this file because past students have occasionally requested
// additional information and examples related to their assignment exercises.
// Because exercises may differ between students, some things in this file may
// not apply to yours.
//
// Each example is written in both C++ and C whenever possible and the runtime
// results will be identical unless indicated otherwise.
//
// Information provided in this file:
//    1. Concepts related to the "elapsed time" exercise
//    2. What are strings and string literals?
//    3. Allocating memory for a string
//


//
//************  1. Concepts related to the "elapsed time" exercise  ************
//
//
//*******************************  Type MyTime  ********************************
// (notes 9.2-9.11)
//  
// C++ version:
//    struct MyTime {int hours, minutes, seconds;};
// C version:
//    typedef struct MyTime MyTime;
//    struct MyTime {int hours, minutes, seconds;};
// 
// 
// Code that declares a function named "Timer1" that returns type "pointer to
// MyTime" and has one type int parameter named "t1":
//    MyTime *Timer1(int t1);
// 
// Code that defines the previous "Timer1" function.  Its code returns a
// pointer to the local type "MyTime" variable named "result":
//    MyTime *Timer1(int t1)
//    {
//       static MyTime result;
//       return &result;
//    }
//
// Code that calls the previous "Timer1" function and stores the type "pointer
// to MyTime" pointer it returns in a type "pointer to MyTime" variable named
// "timePtr":
//    MyTime *timePtr;
//    timePtr = Timer1(10);
//
// Code that declares a function named "Timer2" that returns type int and has
// one type "pointer to const MyTime" parameter named "t1":
//    int Timer2(const MyTime *t1);
// 
// Code that calls the previous "Timer2" function and passes it a pointer to a
// type "MyTime" variable named "test":
//    MyTime test;
//    Timer2(&test);
//
// 
//********************  Implementation-dependent overflow  *********************
// (notes 2.1, 2.11)
// 
// C++ version:
//       const int SECONDS_IN_MINUTE = 60;
//       const int MINUTES_IN_HOUR = 60;
//       const int HOURS_IN_DAY = 24;
// C version:
//       #define SECONDS_IN_MINUTE 60
//       #define MINUTES_IN_HOUR 60
//       #define HOURS_IN_DAY 24
// 
// Two situations in which overflow might occur on some implementations:
// (note )
// 
// Situation 1:
// Calculation of the total seconds in a day:
//    long secondsInDay = SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY;
// 
// Situation 2:
// Calculation of the total seconds in variables hours, minutes, and seconds:
//    int hours = 23;
//    int minutes = 59;
//    int seconds = 59;
//    long secondsInTime =
//       hours * MINUTES_IN_HOUR * SECONDS_IN_MINUTE +
//       minutes * SECONDS_IN_MINUTE +
//       seconds;
//


//
//*****************  2. What are strings and string literals?  *****************
// (note 7.1)
// 
// In code, a sequence of characters occupying consecutive memory addresses and
// ending with a null character is called a "string".  It is also sometimes
// called a "C-string" to differentiate it from a C++ string class object.  A
// null character is the only character whose value is 0 and it's represented
// in code by the octal escape sequence \0
//    1. Strings are stored in character arrays with their first character in
//       element 0.
//    2. String literals are character arrays in which the characters are
//       constant and cannot be changed by the program.
//    3. The compiler automatically appends a null character to the end of the
//       characters visibly present in any string literal.
//    4. Facts pertaining to the string literal "Hello":
//          a. "Hello" has 6 elements: "Hello"[0], "Hello"[1], ... "Hello"[5]
//          b. "Hello" is type "array of 6 const chars"
//          c. Like all arrays, array "Hello" decays to a pointer to its first
//             element, H, except in the four special cases listed in note 1.16.
//             The type of that pointer for any string literal is "pointer to
//             const char".
//


//********************  3. Allocating memory for a string  *********************
// (notes 8.4, 8.5, 8.6)
//
// This program first does the group of steps 1-3 the number of times indicated
// by STRINGS:
//    1. Prompts the user to enter a string and reads it into array inBuf.
//    2. Dynamically allocates exactly the amount of memory needed for a copy
//       of the string.
//    3. Copies the string into the dynamically allocated memory.
//
// ...and then does step 4:
//    4. Displays each string and frees its dynamically allocated memory.
// 
// Runtime results for the indicated input:
//
//    Enter a string: string1
//    Enter a string: string2
//    Enter a string: string3
//    The strings are:
//       string1
//       string2
//       string3
//

// C++ Version
#include <iostream>
#include <iomanip>
#include <cstring>
using std::cout;
using std::cin;
using std::setw;
const int BUF_LENGTH = 256;
const int STRINGS = 3;
int main()
{
   char *pChar[STRINGS];      // array for pointers to allocated memory

   // Loop that processes each input string.
   for (int stringNo = 0; stringNo < STRINGS; ++stringNo)
   {
      cout << "Enter a string: ";
      char inBuf[BUF_LENGTH];
      cin >> setw(BUF_LENGTH) >> inBuf;
      size_t stringLength = strlen(inBuf) + 1;        // +1 for null character
      pChar[stringNo] = new char[stringLength];       // allocate memory
      memcpy(pChar[stringNo], inBuf, stringLength);   // copy the string
   }

   cout << "The strings are:\n";
   // Loop that displays each string and frees its memory.
   for (int stringNo = 0; stringNo < STRINGS; ++stringNo)
   {
      cout << "   " << pChar[stringNo] << "\n";       // display the string
      delete[] pChar[stringNo];                       // free its memory
   }
}

// C Version
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_LENGTH 256
#define STRINGS 3
int main(void)
{
   char *pChar[STRINGS];      // array for pointers to allocated memory

   // Loop that processes each input string.
   for (int stringNo = 0; stringNo < STRINGS; ++stringNo)
   {
      printf("Enter a string: ");
      char inBuf[BUF_LENGTH];
      scanf("%255s\n", inBuf);
      size_t stringLength = strlen(inBuf) + 1;        // +1 for null character
      pChar[stringNo] = (char *)malloc(stringLength); // allocate memory
      if (pChar[stringNo] == NULL)                    // test for failure
      {
         fprintf(stderr, "Allocation failed.\n");
         exit(EXIT_FAILURE);
      }
      memcpy(pChar[stringNo], inBuf, stringLength);   // copy the string
   }

   printf("The strings are:\n");
   // Loop that displays each string and frees its memory.
   for (int stringNo = 0; stringNo < STRINGS; ++stringNo)
   {
      printf("   %s\n", pChar[stringNo]);             // display the string
      free(pChar[stringNo]);                          // free its memory
   }
}
