// Concepts and examples related to "C/C++ Programming I" Assignment 4
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
//    1. A function that returns the sum of its formal parameters
//    2. Displaying the greatest of two values
//    3. Displaying a value multiple times on multiple lines
//    4. Function overloading
//    5. Default argument functions
//    6. Macros and inline functions
//


//
//*******  1. A function that returns the sum of its formal parameters  ********
// (notes 5.1, 5.3-5.5)
//
// This program prompts the user to enter two values, where fractional values
// are allowed.  Function "main" passes those values to function "Add", which
// adds them and returns the sum.  Function "main" then displays the results.
//  
// Runtime results for the indicated input values:
//
//    Enter two floating point values: 2.4 -8e1
//    Sum(2.4, -80) returned -77.6
//
//    Enter two floating point values: 8.E-3 -16
//    Sum(0.008, -16) returned -15.992
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
float Add(float val1, float val2);
int main()
{
   cout << "Enter two floating point values: ";
   float inVal1, inVal2;
   cin >> inVal1 >> inVal2;
   // Add the input values.
   float sum = Add(inVal1, inVal2);
   // Display the input values and their sum.
   cout << "Add(" << inVal1 << ", " << inVal2 << ") returned " << sum << "\n";
}
// Function "Add" adds the values of its parameters and returns their sum.
float Add(float val1, float val2)
{
   return val1 + val2;
}

// C Version
#include <stdio.h>
float Add(float val1, float val2);
int main(void)
{
   printf("Enter two floating point values: ");
   float inVal1, inVal2;
   scanf("%g %g", &inVal1, &inVal2);
   // Add the input values.
   float sum = Add(inVal1, inVal2);
   // Display the input values and their sum.
   printf("Add(%g, %g) returned %g\n", inVal1, inVal2, sum);
}
// Function "Add" adds the values of its parameters and returns their sum.
float Add(float val1, float val2)
{
   return val1 + val2;
}


//
//*****************  2. Displaying the greatest of two values  *****************
// (note 3.16).
//
// This program prompts the user to enter two floating point values.  It then
// displays the greatest of the two, using the conditional operator to make
// that decision.
//  
// Runtime results for the indicated input values:
//
//    Enter two floating point values: 82.01 -233e-33
//    The greatest of 82.01 and -2.33e-31 is 82.01
//
//    Enter two floating point values: -99 +99
//    The greatest of -99 and 99 is 99
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
int main()
{
   cout << "Enter two floating point values: ";
   float inVal1, inVal2;
   cin >> inVal1 >> inVal2;
   // Calculate and display the greatest of two input values.
   cout << "The greatest of " << inVal1 << " and " << inVal2 << " is " <<
      (inVal1 > inVal2 ? inVal1 : inVal2) << "\n";
}

// C Version
#include <stdio.h>
int main(void)
{
   printf("Enter two floating point values: ");
   float inVal1, inVal2;
   scanf("%g %g", &inVal1, &inVal2);
   // Calculate and display the greatest of two input values.
   printf("The greatest of %g and %g is %g\n",
      inVal1, inVal2, inVal1 > inVal2 ? inVal1 : inVal2);
}


//
//**********  3. Displaying a value multiple times on multiple lines  **********
// (note 3.6).
//
// This program displays the value represented by VALUE.  It does it VALUE times
// on VALUE lines.
//  
// Runtime results:
//    333
//    333
//    333
//

// C++ Version
#include <iostream>
using std::cout;
const int VALUE = 3;
int main()
{
   // Loop to display VALUE that number of times on that number of lines.
   for (int line = 0; line < VALUE; ++line)   // line loop
   {
      for (int col = 0; col < VALUE; ++col)   // column loop
         cout << VALUE;
      cout.put('\n');
   }
}

// C Version
#include <stdio.h>
#define VALUE 3
int main(void)
{
   // Loop to display VALUE that number of times on that number of lines.
   for (int line = 0; line < VALUE; ++line)   // line loop
   {
      for (int col = 0; col < VALUE; ++col)   // column loop
         printf("%d", VALUE);
      putchar('\n');
   }
}


//
//*************************  4. Function overloading   *************************
// (note 5.8)
// 
// The "main" function in this program prompts the user to enter three integer
// values representing hours, minutes, and seconds.  There are four overloaded
// functions, each named "DisplayTimes" and each having a different number of
// parameters representing the units of time indicated in the code below.
// Which function is called depends on the number of arguments passed.  Each
// function displays the times passed to it in the format HOURS:MINUTES:SECONDS,
// with zeros in place of any arguments that are not passed.
//
// Runtime results for the indicated input times:
//
//    Enter three integers representing hours minutes seconds: 1 2 3
//    1:2:3
//    1:2:0
//    1:0:0
//    0:0:0
// 
//    Enter three integers representing hours minutes seconds: 16 43 22
//    16:43:22
//    16:43:0
//    16:0:0
//    0:0:0
//

// C++ Version  (C does not support function overloading.)
#include <iostream>
using namespace std;
void DisplayTimes(int hours, int minute, int second);
void DisplayTimes(int hours, int minute);
void DisplayTimes(int hours);
void DisplayTimes();
int main()
{
   cout << "Enter three integers representing hours minutes seconds: ";
   int hours, minutes, seconds;
   cin >> hours >> minutes >> seconds;
   // Call overloaded functions to display input or default times.
   DisplayTimes(hours, minutes, seconds);
   DisplayTimes(hours, minutes);
   DisplayTimes(hours);
   DisplayTimes();
}
// Function that displays the specified hours, minutes, and seconds.
void DisplayTimes(int hours, int minutes, int seconds)
{
   cout << hours << ":" << minutes << ":" << seconds << "\n";
}
// Function that displays the specified hours and minutes and 0 seconds.
void DisplayTimes(int hours, int minutes)
{
   cout << hours << ":" << minutes << ":0\n";
}
// Function that displays the specified hours and 0 minutes and 0 seconds.
void DisplayTimes(int hours)
{
   cout << hours << ":0:0\n";
}
// Function that displays the specified 0 hours, 0 minutes, and 0 seconds.
void DisplayTimes()
{
   cout << "0:0:0\n";
}


//
//**********************  5. Default argument functions   **********************
// (note 5.7)
// 
// The "main" function in this program prompts the user to enter three integer
// values representing hours, minutes, and seconds.  There is one other function
// and it is named "DisplayTimes".  Its three parameters represent the units of
// time indicated in the code below and it displays the times passed to it in
// the format HOURS:MINUTES:SECONDS, with zeros in place of any arguments that
// are not passed.
//
// Runtime results for the indicated input times:
//
//    Enter three integers representing hours minutes seconds: 1 2 3
//    1:2:3
//    1:2:0
//    1:0:0
//    0:0:0
// 
//    Enter three integers representing hours minutes seconds: 16 43 22
//    16:43:22
//    16:43:0
//    16:0:0
//    0:0:0
//

// C++ Version  (C does not support default argument functions.)
#include <iostream>
using namespace std;
void DisplayTimes(int hours = 0, int minute = 0, int second = 0);
int main()
{
   cout << "Enter three integers representing hours minutes seconds: ";
   int hours, minutes, seconds;
   cin >> hours >> minutes >> seconds;
   // Call a single default-argument function to display input or default times.
   DisplayTimes(hours, minutes, seconds);
   DisplayTimes(hours, minutes);
   DisplayTimes(hours);
   DisplayTimes();
}
// Function that displays the specified hours, minutes, and seconds.
void DisplayTimes(int hours, int minutes, int seconds)
{
   cout << hours << ":" << minutes << ":" << seconds << "\n";
}


//
//**********************  6. Macros and inline functions  **********************
// (notes 5.17-5.19)
// 
// Although C++ and C both support macros, they should typically only be used
// in C++ if an equivalent const variable or inline function will not suffice
// (or if listed as a requirement for a course exercise).
// In C, inline functions are not supported and const variables should not be
// used instead of macros.
// 
// To prevent unwanted and unexpected precedence problems with macros, follow
// these two guidelines:
//    1. If a macro's replacement list contains more than one token, place
//       parentheses around the entire replacement list.
//    2. If a macro has parameters, place parentheses around each instance of
//       each parameter in the macro's replacement list.
//
// This C++ program passes the values indicated by the various object-like
// macros and const variables to the mAdd3 macro and fAdd3 inline function to
// get the sums of those values and display the results.  A C program is not
// shown because inline functions are not supported in C and const variables
// should not be used instead of macros in C. 
//
// Runtime results:
//    mAdd3(12, 7, 27) returned 46
//    fAdd3(5, 15, 12) returned 32
//

// Three "object-like" macros:
#define PENNIES 5
#define NICKLES 7
#define COINS (PENNIES + NICKLES)

// const variables should typically be used instead of object-like macros in
// C++ but not in C.
const int CHEVYS = 12;
const int TOYOTAS = 15;
const int CARS = CHEVYS + TOYOTAS;

// Two function-like macros:
// Adds two values
#define mAdd2(val1, val2) ((val1) + (val2))    
// Adds three values by using the mAdd2 macro twice
#define mAdd3(val1, val2, val3) (mAdd2((val1), mAdd2((val2), (val3))))

// Two inline functions (C++ only):
// Adds two values
inline int fAdd2(int val1, int val2)
{
   return val1 + val2;
}
// Adds three values by calling the fAdd2 function twice
inline int fAdd3(int val1, int val2, int val3)
{
   return fAdd2(val1, fAdd2(val2, val3));
}

#include <iostream>
using std::cout;
int main()
{
   // Add values using function-like macros and display the results.
   cout << "mAdd3(" << CHEVYS << ", " << NICKLES << ", " << CARS <<
      ") returned " << mAdd3(CHEVYS, NICKLES, CARS) << "\n";

   // Add values using inline functions and display the results.
   cout << "fAdd3(" << PENNIES << ", " << TOYOTAS << ", " << COINS <<
      ") returned " << fAdd3(PENNIES, TOYOTAS, COINS) << "\n";
}
