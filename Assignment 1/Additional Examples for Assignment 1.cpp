// Concepts and examples related to "C/C++ Programming I" Assignment 1
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
//    1. The hexadecimal, decimal, octal, and binary number systems
//    2. Displaying integer values in different numeric bases
//    3. String literals:   
//       3A - Representing characters in string literals
//       3B - Splitting string literals onto multiple lines
//    4. String literal characters that sometimes require special syntax   
//    5. Character literal characters that require special syntax   
//    6. Displaying the most compact forms of expressions
//    7. Implementing an equation
//    8. Converting gallons to liters
//


//
//******  1. The decimal, hexadecimal, octal, and binary number systems  *******
// (note C.1)
// 
// What are "decimal", "hexadecimal", "octal", and "binary"?
// They are number systems used for expressing numeric values in human-readable
// form.  Which system a programmer uses is just a matter of convention and
// preference and does not dictate how the numeric values are represented inside
// the computer.  For this reason, stating that a variable represents a decimal,
// hexadecimal, octal, or binary value is misleading at best.
//
// Consider the following analogy:
// Household thermometers are commonly labeled in Celsius or Fahrenheit degrees.
// If placed in boiling water, the Celsius version will indicate 100 degrees
// while the Fahrenheit version will indicate 212 degrees.  This tells us that
// 100 and 212 are merely different ways of expressing exactly the same thing,
// which is the water's thermal energy.  Similarly, the "Value Equivalences"
// table below indicates that "15" decimal, "F" hexadecimal, "17" octal, and
// "1111" binary are equivalent and represent exactly the same numeric value.
//
// What are "base" and "radix"?
// Both terms mean exactly the same thing and refer to the number of unique
// digits usable for representing numbers.  In the hexadecimal system the six
// letters A-F (uppercase or lowercase) also act as digits.  Applications that
// convert between computer number systems are readily available online and
// some come pre-installed on operating systems.
//
//        System         Base/Radix       Unique Digits
//   Decimal                10             0-9
//   Hexadecimal (hex)      16             0-9  A-F/a-f
//   Octal                   8             0-7
//   Binary                  2             0-1
//
//   Value Equivalences:
//      Decimal Hexadecimal  Octal    Binary
//         0         0         0          0
//         1         1         1          1
//         2         2         2         10
//         3         3         3         11
//         4         4         4        100
//         5         5         5        101
//         6         6         6        110
//         7         7         7        111
//         8         8        10       1000
//         9         9        11       1001
//        10         A        12       1010
//        11         B        13       1011
//        12         C        14       1100
//        13         D        15       1101
//        14         E        16       1110
//        15         F        17       1111
//


//
//*********  2. Displaying integer values in different numeric bases  **********
// (notes 1.11, 1.12).
// 
// This program prompts the user to enter a decimal integer value.  It then
// reads it and displays it in hex, octal, and decimal.
//
// Runtime results for the indicated input value:
//    Enter a decimal integer value: 25
//    25 in hexadecimal is 19
//    25 in decimal is 25
//    25 in octal is 31
//
// Runtime results for the indicated input value:
//    Enter a decimal integer value: -25
//    -25 in hexadecimal is ffffffe7
//    -25 in decimal is -25
//    -25 in octal is 37777777747
//

// C++ Version
// In C++ the default input and output bases are both decimal at program startup
// and it is not necessary to specify "dec" if decimal is desired.  However, if
// a program is using multiple bases it is usually "safer" to specify the needed
// base than to try to remember if the program is currently in that base.  The
// "dec", "oct", and "hex" manipulators are "sticky", meaning that once set they
// remain in effect until explicitly changed or the program is restarted.
#include <iostream>
using namespace std;
int main()
{
   cout << "Enter a decimal integer value: ";
   int inVal;
   cin >> inVal;
   // Display the input value in multiple bases.
   cout <<
      inVal << " in hexadecimal is " << hex << inVal << "\n" <<
      dec << inVal << " in decimal is " << inVal << "\n" <<
      dec << inVal << " in octal is " << oct << inVal << "\n";
}

// C Version
// In C there are no default bases.  The expected input and output bases are
// dictated entirely by the conversion specifications used with the scanf and
// printf family of functions.
#include <stdio.h>
int main(void)
{
   printf("Enter a decimal integer value: ");
   int inVal;
   scanf("%d", &inVal);
   // Display the input value in multiple bases.
   printf(
      "%d in hexadecimal is %x\n"
      "%d in decimal is %d\n"
      "%d in octal is %o\n",
      inVal, inVal, inVal, inVal, inVal, inVal);
}


//
//*************  3A - Representing characters in string literals  **************
//************  3B - Splitting string literals onto multiple lines  ************
// (note 1.5)
// 
// The following program displays the phrase   hello, world   followed by a
// newline character using:
//    1. Literal characters and a simple escape sequence.
//    2. Only hex and octal numeric escape sequences.
//    3. Literal characters and hex and octal numeric escape sequences.
//    4. All of 1-3 again using a single cout (C++) or printf (C).
//
// Runtime results:
//    hello, world
//    hello, world
//    hello, world
//    hello, world
//    hello, world
//    hello, world

// C++ Version
#include <iostream>
using std::cout;
int main()
{
   // Display "hello, world\n" using literal characters and numeric escapes.
   cout << "hello, world\n";                                         // 1.
   cout << "\x68\145\154\154\x6f\54\x020\x77\157\x72\x6c\144\xa";    // 2.
   cout << "he\154\154\x6f,\x20worl\144\xa";                         // 3.
   cout <<                                                           // 4.
      "hello, world\n"
      "\x68\145\154\154\x6f\54\x020\x77\157\x72\x6c\144\xa"
      "he\154\154\x6f,\x20worl\144\xa";
}

// C Version
#include <stdio.h>
int main(void)
{
   // Display "hello, world\n" using literal characters and numeric escapes.
   printf("hello, world\n");                                         // 1.
   printf("\x68\145\154\154\x6f\54\x020\x77\157\x72\x6c\144\xa");    // 2.
   printf("he\154\154\x6f,\x20worl\144\xa");                         // 3.
   printf(                                                           // 4.
      "hello, world\n"
      "\x68\145\154\154\x6f\54\x020\x77\157\x72\x6c\144\xa"
      "he\154\154\x6f,\x20worl\144\xa");
}


//
//****  4. String literal characters that sometimes require special syntax  ****
// (note 1.5)
// 
// This program displays each of the following three space-separated punctuators
// just as shown, then each within single quotes, then each within double
// quotes:
//    "   %  \
//
// Runtime results:
//    "  %  \
//    '"'  '%'  '\'
//    """  "%"  "\"
//

// C++ Version
#include <iostream>
int main()
{
   // Display characters singly, in single quotes, and in double quotes.
   std::cout <<
      "\"  %  \\\n"
      "'\"'  '%'  '\\'\n"
      "\"\"\"  \"%\"  \"\\\"\n";
}

// C Version
#include <stdio.h>
int main(void)
{
   // Display characters singly, in single quotes, and in double quotes.
   printf(
      "\"  %  \\\n"
      "'\"'  '%%'  '\\'\n"
      "\"\"\"  \"%%\"  \"\\\"\n");
}


//
//*******  5. Character literal characters that require special syntax  ********
// (note 1.5)
// 
// This program uses a character literal representing a single quote character
// as the argument of cout.put in C++ and putchar in C.  It then does the same
// for a character literal representing a backslash character.
//
// Runtime results:
//    '\
//

// C++ Version
#include <iostream>
using std::cout;
int main()
{
   // Display a single quote and a backslash expressed as character literals.
   cout.put('\'');
   cout.put('\\');
}

// C Version
#include <stdio.h>
int main(void)
{
   // Display a single quote and a backslash expressed as character literals.
   putchar('\'');
   putchar('\\');
}


//
//***********  6. Displaying the most compact forms of expressions  ************
// (note 1.7).
// 
// This program displays the most compact forms of the two expressions:
//    a1 = a1 + 1
//    b1 = b1 % a1
// 
// Runtime results:
//    The most compact form of  a1 = a1 + 1  is  ++a1
//    The most compact form of  b1 = b1 % a1  is  b1 %= a1

// C++ Version
#include <iostream>
int main()
{
   // Display the most compact forms of two expressions.
   std::cout <<
      "The most compact form of  a1 = a1 + 1  is  ++a1\n"
      "The most compact form of  b1 = b1 % a1  is  b1 %= a1\n";
}

// C Version
#include <stdio.h>
int main(void)
{
   // Display the most compact forms of two expressions.
   printf(
      "The most compact form of  a1 = a1 + 1  is  ++a1\n"
      "The most compact form of  b1 = b1 %% a1  is  b1 %%= a1\n");
}


//
//***********************  7. Implementing an equation  ************************
// 
// This program prompts the user for two floating point values to be used in
// the equation below for variables y and z, respectively:
//    x = y^2 + z^3 + 7
// Although the ^ symbol is often used indicate exponentiation in documentation
// (y squared and z cubed in this case), C and C++ have no actual exponentiation
// operator.  Exponentiation must be done in some other way in actual code.
//
// After inputting the two user values the program then displays the equation
// with appropriate values in place of the three variables.  For example, for
// input values of 2.3 and 4 the display would be:
//    -51.71 = 2.3^2 + -4^3 + 7
//
// Runtime results for the indicated input values:
//    Enter two space-separated floating point values: 2.3 -4
//    -51.71 = 2.3^2 + -4^3 + 7
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
int main()
{
   cout << "Enter two space-separated floating point values: ";
   double y, z;
   cin >> y >> z;
   // Compute the value of the right side of an equation.
   double x = y * y + z * z * z + 7;
   // Display the equation showing all values.
   cout << x << " = " << y << "^" << 2 << " + " << z << "^" << 3 << " + 7\n";
}

// C Version
#include <stdio.h>
int main(void)
{
   printf("Enter two space-separated floating point values: ");
   double y, z;
   scanf("%lg %lg", &y, &z);
   // Compute the value of the right side of an equation.
   double x = y * y + z * z * z + 7;
   // Display the equation showing all values.
   printf("%g = %g^2 + %g^3 + 7\n", x, y, z);
}


//
//*********************  8. Converting gallons to liters  **********************
// 
// This program prompts the user for a value representing gallons, converts it
// to liters, and displays the equivalence.  A fractional input values are
// allowed.
//
// Output from both versions for the indicated input value:
//    Enter the number gallons: 2.3
//    2.3 gallons = 8.70644 liters
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
int main()
{
   cout << "Enter the number of gallons: ";
   double gallons;
   cin >> gallons;
   // Convert gallons to liters.
   double liters = 3.78541 * gallons;
   // Display the equivalence.
   cout << gallons << " gallons = " << liters << " liters\n";
}

// C Version
#include <stdio.h>
int main(void)
{
   printf("Enter the number of gallons: ");
   double gallons;
   scanf("%lg", &gallons);
   // Convert gallons to liters.
   double liters = 3.78541 * gallons;
   // Display the equivalence.
   printf("%g gallons = %g liters\n", gallons, liters);
}
