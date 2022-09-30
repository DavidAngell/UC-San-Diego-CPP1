// Concepts and examples related to "C/C++ Programming I" Assignment 2
//
// I have provided this file because past students have occasionally requested
// additional information and examples related to their assignment exercises.
// Because exercises may differ between students, some things in this file may
// not apply to yours.
//
// Each example is written in both C++ and C whenever possible and the runtime
// results will be identical unless indicated otherwise.
//
// Example programs provided in this file:
//    1. Displaying the least significant digit (LSD) of a non-negative integer
//    2. Displaying a character and its value
//    3. Converting a character to uppercase
//    4. Displaying the alphabet
//    5. Displaying a triangle of characters using loop nesting
//    6. Counting using loop nesting
//    7. Displaying unique letter combinations using loop nesting
//


//
//****  1. Displaying the least significant digit of a non-negative integer  ***
// (notes 2.8, 2.13, 2.14)
//
// This program prompts the user for a non-negative integer value then displays
// the least significant digit (LSD).
//  
// Runtime results for the indicated input values:
// 
//    Enter a non-negative integer value: 123
//    The LSD of 123 is 3
//
//    Enter a non-negative integer value: 120
//    The LSD of 120 is 0
//
//    Enter a non-negative integer value: 0
//    The LSD of 0 is 0
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
const int RADIX = 10;               // Radix of the input value
int main()
{
   cout << "Enter a non-negative integer value: ";
   int inVal;
   cin >> inVal;
   // Compute and display the LSD of the input value.
   cout << "The LSD of " << inVal << " is " << inVal % RADIX << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 10                    // Radix of the input value
int main(void)
{
   printf("Enter a non-negative integer value: ");
   int inVal;
   scanf("%d", &inVal);
   // Compute and display the LSD of the input value.
   printf("The LSD of %d is %d\n", inVal, inVal % RADIX);
}


//
//*****************  2. Displaying a character and its value  ******************
// (notes B.1, 1.15, 1.16)
// 
// This program prompts the user to enter any printable character then displays
// that character and the value used to represent it.
// 
// In the expression  cin >> x  the value of a single character will be stored
// in x if x is type char, signed char, or unsigned char.  Otherwise, some other
// value appropriate for the type of x will be stored.
// 
// In the expression  cout << x  the character represented by the value of x
// will be displayed if x is type char, signed char, or unsigned char.
// Otherwise, the value of x itself will be displayed.
// 
// In the expression  scanf("\n%c", &x)  the value of a single character will be
// stored in x.  If a conversion specification other than %c is used, some other
// value dictated by that conversion specification will be stored.  As always,
// the type of &x must be compatible with the conversion specification used.
//
// In the expression  printf("%c", x)  the character represented by the value
// of x will be displayed.  If a conversion specification other than %c is used,
// the value of x itself will be displayed.  As always, the type of x must be
// compatible with the conversion specification used.
//
// Runtime results for the indicated input characters:
//
//    Enter any printable character: z
//    Character: z  Value: 122
//
//    Enter any printable character: $
//    Character: $  Value: 36
//

// C++ Version
#include <iostream>
using namespace std;
int main()
{
   cout << "Enter any printable character: ";
   char inChar;
   cin >> inChar;
   // Display the input character and the decimal value that represents it.
   cout << "Character: " << inChar << "  Value: " << (int)inChar << "\n";
}

// C Version
#include <stdio.h>
int main(void)
{
   printf("Enter any printable character: ");
   char inChar;
   scanf("\n%c", &inChar);
   // Display the input character and the decimal value that represents it.
   printf("Character: %c  Value: %d\n", inChar, inChar);
}


//
//******************  3. Converting a character to uppercase  ******************
// (notes B.1, 1.5, 2.13, 2.14)
// 
// This program prompts the user to enter a lowercase character then converts it
// to lowercase and displays both.
// 
// The most appropriate way to convert a lowercase character to uppercase is by
// using the standard library "toupper" function.  However, for character sets
// like ASCII in which the values of the corresponding members of the lowercase
// and uppercase letters are separated by a constant value, it can be done by
// simple subtraction.  The downside of this approach is that erroneous results
// can occur if the input character is not lowercase, as shown in the second
// test below:
//
// Runtime results for the indicated input characters:
// 
//    Enter a lowercase character: z
//    Lowercase: z  Uppercase: Z
//
//    Enter a lowercase character: D
//    Lowercase: D  Uppercase: $
//

// C++ Version
#include <iostream>
using namespace std;
const int CASE_DIFF = 'a' - 'A';             // Difference between ASCII cases
int main()
{
   cout << "Enter a lowercase character: ";
   char lowerChar;
   cin >> lowerChar;
   char upperChar = lowerChar - CASE_DIFF;   // Convert input char to uppercase
   // Display the input character and its uppercase counterpart.
   cout << "Lowercase: " << lowerChar << "  Uppercase: " << upperChar << "\n";
}

// C Version
#include <stdio.h>
#define CASE_DIFF ('a' - 'A')                // Difference between ASCII cases
int main(void)
{
   printf("Enter a lowercase character: ");
   char lowerChar;
   scanf("\n%c", &lowerChar);
   char upperChar = lowerChar - CASE_DIFF;   // Convert input char to uppercase
   // Display the input character and its uppercase counterpart.
   printf("Lowercase: %c  Uppercase: %c\n", lowerChar, upperChar);
}


//
//************************  4. Displaying the alphabet  ************************
// (notes 1.11, 1.12, 3.5, 3.6)
// 
// This program displays the English alphabet in uppercase on one line.  It
// relies on the fact that the values of the successive alphabetic characters
// in the ASCII character set are sequential.
//
// Runtime results:
//    ABCDEFGHIJKLMNOPQRSTUVWXYZ
//

// C++ Version
#include <iostream>
const char FIRST_CHAR = 'A';
const char LAST_CHAR = 'Z';
int main()
{
   // Loop displaying the characters from FIRST_CHAR through LAST_CHAR.
   for (char thisChar = FIRST_CHAR; thisChar <= LAST_CHAR; ++thisChar)
      std::cout.put(thisChar);      // OR  std::cout << thisChar;
   std::cout.put('\n');             // OR  std::cout << "\n";
}

// C Version
#include <stdio.h>
#define FIRST_CHAR 'A'
#define LAST_CHAR 'Z'
int main(void)
{
   // Loop displaying the characters from FIRST_CHAR through LAST_CHAR.
   for (int thisChar = FIRST_CHAR; thisChar <= LAST_CHAR; ++thisChar)
      putchar(thisChar);            // OR  printf("%c", thisChar);
   putchar('\n');                   // OR  printf("\n");
}


//
//********  5. Displaying a triangle of characters using loop nesting  *********
// (notes B.1, 3.6, 3.7)
// 
// This program prompts the user to enter a line count and a character.  It then
// uses loop nesting to display the character once on the first line, twice on
// the second line, three times on the third line, etc. until the specified
// number of lines have been displayed.  A "nested loop" is merely a looping
// statement in another looping statement.
// 
// Runtime results for the indicated line count value and character:
//    Enter a space-separated line count and character: 5 Z
//    Z
//    ZZ
//    ZZZ
//    ZZZZ
//    ZZZZZ
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
int main()
{
   cout << "Enter a space-separated line count and character: ";
   char inChar;
   int lines;
   cin >> lines >> inChar;
   // Loops displaying a triangle of characters.
   for (int lineNo = 0; lineNo < lines; ++lineNo)           // Line counter
   {
      for (int charNo = 0; charNo < lineNo + 1; ++charNo)   // Char counter
         cout.put(inChar);    // OR  cout << inChar;
      cout.put('\n');         // OR  cout << "\n";
   }
}

// C Version
#include <stdio.h>
int main(void)
{
   printf("Enter a space-separated line count and character: ");
   char inChar;
   int lines;
   scanf("%d\n%c", &lines, &inChar);
   // Loops displaying a triangle of characters.
   for (int lineNo = 0; lineNo < lines; ++lineNo)           // Line counter
   {
      for (int charNo = 0; charNo < lineNo + 1; ++charNo)   // Char counter
         putchar(inChar);     // OR  printf("%c", inChar);
      putchar('\n');          // OR  printf("\n");
   }
}


//
//**********************  6. Counting using loop nesting  **********************
// (notes 3.5, 3.6)
// 
// A "nested loop" is merely a looping statement in another looping statement.
// This program uses loop nesting to count from 0-99.  If counting is all that
// is desired, it would be more appropriate to just do it with a single looping
// statement.  However, the nested loop technique allows the digits in each
// value to be used separately, which is necessary when indexing through a
// multi-dimensional array (note 7.8).
//
// Runtime results:
//    00
//    01
//    ...
//    98
//    99
//

// C++ Version
#include <iostream>
const int RADIX = 10;                                 // Radix of the count
int main()
{
   // Loops displaying pairs of digits counting.
   for (int index1 = 0; index1 < RADIX; ++index1)     // Leftmost digit
      for (int index0 = 0; index0 < RADIX; ++index0)  // Rightmost digit
         std::cout << index1 << index0 << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 10                                      // Radix of the count
int main(void)
{
   // Loops displaying pairs of digits counting.
   for (int index1 = 0; index1 < RADIX; ++index1)     // Leftmost digit
      for (int index0 = 0; index0 < RADIX; ++index0)  // Rightmost digit
         printf("%d%d\n", index1, index0);
}


//
//*******  7. Displaying unique letter combinations using loop nesting  ********
// (notes 3.5, 3.6)
// 
// A "nested loop" is merely a looping statement in another looping statement.
// This program uses loop nesting to determine all unique two-letter
// combinations of the letters from FIRST_CHAR through LAST_CHAR.
// 
// Runtime results for the example code:
//    aa
//    ab
//    ac
//    ba
//    bb
//    bc
//    ca
//    cb
//    cc
//

// C++ Version
#include <iostream>
const char FIRST_CHAR = 'a';
const char LAST_CHAR = 'c'; 
int main()
{
   // Loops displaying all combinations of characters FIRST_CHAR and LAST_CHAR.
   for (char ch1 = FIRST_CHAR; ch1 <= LAST_CHAR; ++ch1)     // Leftmost char
      for (char ch0 = FIRST_CHAR; ch0 <= LAST_CHAR; ++ch0)  // Rightmost char
         std::cout << ch1 << ch0 << "\n";
}

// C Version
#include <stdio.h>
#define FIRST_CHAR 'a'
#define LAST_CHAR 'c'
int main(void)
{
   // Loops displaying all combinations of characters FIRST_CHAR and LAST_CHAR.
   for (char ch1 = FIRST_CHAR; ch1 <= LAST_CHAR; ++ch1)     // Leftmost char
      for (char ch0 = FIRST_CHAR; ch0 <= LAST_CHAR; ++ch0)  // Rightmost char
         printf("%c%c\n", ch1, ch0);
}
