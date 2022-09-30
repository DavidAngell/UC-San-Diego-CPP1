// Concepts and examples related to "C/C++ Programming I" Assignment 5
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
//    1. A program that takes a survey
//    2. Passing and returning references
//    3. Passing and returning pointers
//


//
//*********************  1. A program that takes a survey  *********************
// (note 6.3)
//
// This program prompts GUESTS party guests to enter an integer number in the
// range [LOWEST, HIGHEST] and uses an array to keep count of how many of each
// have been entered.  The quantity of LOWEST entries will be kept in element
// 0, LOWEST+1 entries in element 1, LOWEST+2 entries in element 2, etc.  If a
// guest enters an out-of-range number, it is not counted and the next guest
// (if any) is prompted.  After all guests have been processed the program
// displays how many of each number were entered.
//
// Runtime results for the indicated input values:
//    At each prompt enter an integer value from -3 through 2...
//    Guest 1: -3
//    Guest 2: 0
//    Guest 3: 4
//    Guest 4: 20
//    Guest 5: -10
//    Guest 6: 2
//    Guest 7: 3
//    Guest 8: 3
//    Guest 9: 2
//    Guest 10: 0
//    Guest 11: 0
//    Choice 2: Qty 2
//    Choice 1: Qty 0
//    Choice 0: Qty 3
//    Choice -1: Qty 0
//    Choice -2: Qty 0
//    Choice -3: Qty 1
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
const int GUESTS = 11;                    // number of party guests
const int LOWEST = -3;                    // lowest number - must be <= HIGHEST
const int HIGHEST = 2;                    // highest number - must be >= LOWEST
const int CHOICES = HIGHEST - LOWEST + 1; // # of numbers to choose from
int main()
{
   cout << "At each prompt enter an integer value in the range [" << LOWEST <<
      ", " << HIGHEST << "]\n";

   int responses[CHOICES] = {0};                // holds count of each number
   // Loop to get guest responses.
   for (int guest = 1; guest <= GUESTS; ++guest)
   {
      cout << "Guest " << guest << ": ";        // prompt guest
      int response;
      cin >> response;                          // get response
      // Record the guest's choice if in range.
      if (response >= LOWEST && response <= HIGHEST)
         ++responses[response - LOWEST];        // increment response count
   }

   cout << "Survey results:\n";
   // Display the number of occurrences of each possible choice.
   for (int respIx = CHOICES - 1; respIx >= 0; --respIx)
      cout << "Choice " << respIx + LOWEST << ": " << responses[respIx]
      << "\n";
}

// C Version
#include <stdio.h>
#define GUESTS 11                         // number of party guests
#define LOWEST (-3)                       // lowest number - must be <= HIGHEST
#define HIGHEST 2                         // highest number - must be >= LOWEST
#define CHOICES (HIGHEST - LOWEST + 1)    // # of numbers to choose from
int main(void)
{
   printf(
      "At each prompt enter an integer value in the range [%d, %d]\n",
      LOWEST, HIGHEST);

   int responses[CHOICES] = {0};                // holds count of each number
   // Loop to get guest responses.
   for (int guest = 1; guest <= GUESTS; ++guest)
   {
      printf("Guest %d: ", guest);              // prompt guest
      int response;
      scanf("%d", &response);                   // get response
      // Record the guest's choice if in range.
      if (response >= LOWEST && response <= HIGHEST)
         ++responses[response - LOWEST];        // increment response count
   }

   printf("Survey results:\n");
   // Display the number of occurrences of each possible choice.
   for (int respIx = CHOICES - 1; respIx >= 0; --respIx)
      printf("Choice %d: Qty %d\n", respIx + LOWEST, responses[respIx]);
}


//
//*******************  2. Passing and returning references  ********************
// (notes 5.9, 6.9, 6.11, 6.13)
//
// This program prompts the user to enter three integer values and passes
// references to them to function LargestProduct.  That function determines
// which of the values referenced by its first two parameters results in the
// largest product when multiplied by the value referenced by its third
// parameter.  A reference to which of those two values results in the largest
// product is returned.  The product itself is not returned.
// 
// Note the cast of the return expression in function "LargestProduct".  It is
// necessary because the function is declared to return type "reference to int"
// but the type of what must be returned (n1 or n2) is "reference to const int".
//
// Runtime results for the indicated input values:
//
//    Enter three space-separated integer values: 2 3 4
//    3 produces the largest product.
//
//    Enter three space-separated integer values: 2 3 -4
//    2 produces the largest product.
//

// C++ Version - C does not support reference types.
#include <iostream>
using std::cout;
using std::cin;
int &LargestProduct(const int &n1, const int &n2, const int &multiplier);
int main()
{
   cout << "Enter three space-separated integer values: ";
   int in1, in2, multiplier;
   cin >> in1 >> in2 >> multiplier;

   // Determine which value produces the largest product.
   cout << LargestProduct(in1, in2, multiplier) <<
      " produces the largest product.\n";
}
// Function "LargestProduct" determines which of the values referenced by its
// first two parameters results in the largest product when multiplied by the
// value referenced by its third parameter.  A reference to which of those two
// values results in the largest product is returned.
int &LargestProduct(const int &n1, const int &n2, const int &multiplier)
{
   return (int &)(n1 * multiplier > n2 * multiplier ? n1 : n2);
}


//
//********************  3. Passing and returning pointers  *********************
// (notes 6.9, 6.10, 6.12)
//
// This program prompts the user to enter three integer values and passes
// pointers to them to function LargestProduct.  That function determines
// which of the values pointed to by its first two parameters results in the
// largest product when multiplied by the value pointed to by its third
// parameter.  A pointer to which of those two values results in the largest
// product is returned.  The product itself is not returned.
// 
// Note the cast of the return expression in function "LargestProduct".  It is
// necessary because the function is declared to return type "pointer to int"
// but the type of what must be returned (n1 or n2) is "pointer to const int".
// 
// Runtime results for the indicated input values:
//
//    Enter three space-separated integer values: 2 3 4
//    3 produces the largest product.
//
//    Enter three space-separated integer values: 2 3 -4
//    2 produces the largest product.
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
int *LargestProduct(const int *n1, const int *n2, const int *multiplier);
int main()
{
   cout << "Enter three space-separated integer values: ";
   int in1, in2, multiplier;
   cin >> in1 >> in2 >> multiplier;

   // Determine which value produces the largest product.
   cout << *LargestProduct(&in1, &in2, &multiplier) <<
      " produces the largest product.\n";
}
// Function "LargestProduct" determines which of the values pointed to by its
// first two parameters results in the largest product when multiplied by the
// value pointed to by its third parameter.  A pointer to which of those two
// values results in the largest product is returned.
int *LargestProduct(const int *n1, const int *n2, const int *multiplier)
{
   return (int *)(*n1 * *multiplier > *n2 * *multiplier ? n1 : n2);
}

// C Version
#include <stdio.h>
int *LargestProduct(const int *n1, const int *n2, const int *multiplier);
int main(void)
{
   printf("Enter three space-separated integer values: ");
   int in1, in2, multiplier;
   scanf("%d %d %d", &in1, &in2, &multiplier);

   // Determine which value produces the largest product.
   printf("%d produces the largest product.\n",
      *LargestProduct(&in1, &in2, &multiplier));
}
// Function "LargestProduct" determines which of the values pointed to by its
// first two parameters results in the largest product when multiplied by the
// value pointed to by its third parameter.  A pointer to which of those two
// values results in the largest product is returned.
int *LargestProduct(const int *n1, const int *n2, const int *multiplier)
{
   return (int *)(*n1 * *multiplier > *n2 * *multiplier ? n1 : n2);
}
