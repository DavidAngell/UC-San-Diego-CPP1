// Concepts and examples related to "C/C++ Programming I" Assignment 3
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
//    1. Interpreting integer input:
//       1A - decimal
//       1B - octal
//       1C - hexadecimal
//    2. Displaying a table of integer values:
//       2A - decimal
//       2B - octal
//       2C - hexadecimal
//    3. Displaying an integer in reverse order:
//       3A - decimal
//       3B - octal
//       3C - hexadecimal
//    4. Finding an integer's most significant digit:
//       4A - decimal
//       4B - octal
//       4C - hexadecimal
//    5. Displaying integer digits in order:
//       5A - decimal
//       5B - octal
//       5C - hexadecimal
//    6. Displaying a digit as a word:
//       6A - decimal
//       6B - octal
//       6C - hexadecimal


//*****************  1A, 1B, 1C - Interpreting integer input  ******************
// (notes 1.11-1.14)
// 
// The terms decimal, octal, and hexadecimal refer only to the character
// sequences used to express numbers in human-readable format, such as the
// numbers a user might type on a keyboard or a program might display on the
// screen.  The values these sequences represent are stored inside the computer
// in formats that are unrelated to whether the human-readable number was
// expressed as decimal, octal, or hexadecimal.  For example, decimal 27, octal
// 33, and hex 1b represent exactly the same value and are stored as binary
// 11011 inside the computer.  The radix used is just a matter of convention,
// preference, or stated requirement.
//

// For each input radix indicated, this program prompts the user for an integer
// value expressed in that radix and displays its value in decimal, octal, and
// hex.  Note that the output values are the same regardless of the input radix
// specified because decimal 27, octal 33, and hex 1b represent exactly the
// same value.
// 
// Runtime results for the indicated input radices and values:
//    Enter a decimal integer value: 27
//    = 27 decimal
//    = 33 octal
//    = 1b hex
//    Enter an octal integer value: 33
//    = 27 decimal
//    = 33 octal
//    = 1b hex
//    Enter a hexadecimal integer value: 1b
//    = 27 decimal
//    = 33 octal
//    = 1b hex
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
   cin >> dec >> inVal;                      // Interpret input as decimal
   cout <<
      "= " << dec << inVal << " decimal\n" <<// Display input value as decimal
      "= " << oct << inVal << " octal\n" <<  // Display input value as octal
      "= " << hex << inVal << " hex\n";      // Display input value as hex

   cout << "Enter an octal integer value: ";
   cin >> oct >> inVal;                      // Interpret input as octal
   cout <<
      "= " << dec << inVal << " decimal\n" <<// Display input value as decimal
      "= " << oct << inVal << " octal\n" <<  // Display input value as octal
      "= " << hex << inVal << " hex\n";      // Display input value as hex

   cout << "Enter a hexadecimal integer value: ";
   cin >> hex >> inVal;                      // Interpret input as hex
   cout <<
      "= " << dec << inVal << " decimal\n" <<// Display input value as decimal
      "= " << oct << inVal << " octal\n" <<  // Display input value as octal
      "= " << hex << inVal << " hex\n";      // Display input value as hex
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
   scanf("%d", &inVal);                      // Interpret input as decimal
   printf(
      "= %d decimal\n"                       // Display input value as decimal
      "= %o octal\n"                         // Display input value as octal
      "= %x hex\n",                          // Display input value as hex
      inVal, inVal, inVal);

   printf("Enter an octal integer value: ");
   scanf("%o", &inVal);                      // Interpret input as octal
   printf(
      "= %d decimal\n"                       // Display input value as decimal
      "= %o octal\n"                         // Display input value as octal
      "= %x hex\n",                          // Display input value as hex
      inVal, inVal, inVal);

   printf("Enter a hex integer value: ");
   scanf("%x", &inVal);                      // Interpret input as hex
   printf(
      "= %d decimal\n"                       // Display input value as decimal
      "= %o octal\n"                         // Display input value as octal
      "= %x hex\n",                          // Display input value as hex
      inVal, inVal, inVal);
}


//
//************  2A - Displaying a table of decimal integer values  *************
// (notes 1.11-1.14, 3.7)
//
// This program displays a three-column table of decimal integer values:
//    1. The table header contains a label for each column and a dividing line.
//    2. The first table entry is the value the user enters when prompted.
//    3. Successive entries are the previous entry multiplied by MULT.
//    4. The table has a total of ROWS rows.
//    5. The least significant digits of all entries in a column are aligned.
//  
// Runtime results for the indicated input starting value:
//    Enter a decimal integer starting value: 1
//       Value       Value*2      Value*4
//    -------------------------------------
//              1            2            4
//              8           16           32
//             64          128          256
//            512         1024         2048
//           4096         8192        16384
//          32768        65536       131072
//         262144       524288      1048576
//        2097152      4194304      8388608
//       16777216     33554432     67108864
//      134217728    268435456    536870912
//     1073741824  -2147483648            0
//              0            0            0
//

// C++ Version
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
const int ROWS = 12;       // Determines the # rows.
const int COLUMNS = 3;     // Indicates but does not determine the # of columns.
const int MULT = 2;        // Multiplier for successive table entry values.
const int FLD_WIDTH = 11;  // Width of each entry field in table.
int main()
{
   cout << "Enter a decimal integer starting value: ";
   int entry;
   cin >> entry;
   // Display table header.
   cout <<
      "   Value       Value*" << MULT << "      Value*" << MULT * MULT << "\n"
      "-------------------------------------\n";
   // Loop to calculate and display each row of entries.
   for (int row = 0; row < ROWS; ++row)
   {
      cout <<
         setw(FLD_WIDTH) << entry << "  " <<
         setw(FLD_WIDTH) << entry * MULT << "  " <<
         setw(FLD_WIDTH) << entry * MULT * MULT << "\n";
      entry *= MULT * MULT * MULT;
   }
}

// C Version
#include <stdio.h>
#define ROWS 12            // Determines the # rows.
#define COLUMNS 3          // Indicates but does not determine the # of columns.
#define MULT 2             // Multiplier for successive table entry values.
int main(void)
{
   printf("Enter a decimal integer starting value: ");
   int entry;
   scanf("%d", &entry);
   // Display table header.
   printf(
      "   Value       Value*%d      Value*%d\n"
      "-------------------------------------\n", MULT, MULT * MULT);
   // Loop to calculate and display each row of entries.
   for (int row = 0; row < ROWS; ++row)
   {
      printf("%11d  %11d  %11d\n", entry, entry * MULT, entry * MULT * MULT);
      entry *= MULT * MULT * MULT;
   }
}


//
//*************  2B - Displaying a table of octal integer values  **************
// (notes 1.11-1.14, 3.7)
//
// This program displays a three-column table of octal integer values:
//    1. The table header contains a label for each column and a dividing line.
//    2. The first table entry is the value the user enters when prompted.
//    3. Successive entries are the previous entry multiplied by MULT.
//    4. The table has a total of ROWS rows.
//    5. The least significant digits of all entries in a column are aligned.
//  
// Runtime results for the indicated input starting value:
//    Enter an octal integer starting value: 1
//       Value       Value*2      Value*4
//    -------------------------------------
//              1            2            4
//             10           20           40
//            100          200          400
//           1000         2000         4000
//          10000        20000        40000
//         100000       200000       400000
//        1000000      2000000      4000000
//       10000000     20000000     40000000
//      100000000    200000000    400000000
//     1000000000   2000000000   4000000000
//    10000000000  20000000000            0
//              0            0            0
//

// C++ Version
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
using std::oct;
const int ROWS = 12;       // Determines the # rows.
const int COLUMNS = 3;     // Indicates but does not determine the # of columns.
const int MULT = 2;        // Multiplier for successive table entry values.
const int FLD_WIDTH = 11;  // Width of each entry field in table.
int main()
{
   cout << oct << "Enter an octal integer starting value: ";
   int entry;
   cin >> oct >> entry;
   // Display table header.
   cout <<
      "   Value       Value*" << MULT << "      Value*" << MULT * MULT << "\n"
      "-------------------------------------\n";
   // Loop to calculate and display each row of entries.
   for (int row = 0; row < ROWS; ++row)
   {
      cout <<
         setw(FLD_WIDTH) << entry << "  " <<
         setw(FLD_WIDTH) << entry * MULT << "  " <<
         setw(FLD_WIDTH) << entry * MULT * MULT << "\n";
      entry *= MULT * MULT * MULT;
   }
}

// C Version
#include <stdio.h>
#define ROWS 12            // Determines the # rows.
#define COLUMNS 3          // Indicates but does not determine the # of columns.
#define MULT 2             // Multiplier for successive table entry values.
int main(void)
{
   printf("Enter an octal integer starting value: ");
   int entry;
   scanf("%o", &entry);
   // Display table header.
   printf(
      "   Value       Value*%d      Value*%d\n"
      "-------------------------------------\n", MULT, MULT * MULT);
   // Loop to calculate and display each row of entries.
   for (int row = 0; row < ROWS; ++row)
   {
      printf("%11o  %11o  %11o\n", entry, entry * MULT, entry * MULT * MULT);
      entry *= MULT * MULT * MULT;
   }
}


//
//***********  2C - Displaying a table of hexadecimal integer values  **********
// (notes 1.11-1.14, 3.7)
//
// This program displays a three-column table of hexadecimal integer values:
//    1. The table header contains a label for each column and a dividing line.
//    2. The first table entry is the value the user enters when prompted.
//    3. Successive entries are the previous entry multiplied by MULT.
//    4. The table has a total of ROWS rows.
//    5. The least significant digits of all entries in a column are aligned.
//  
// Runtime results for the indicated input starting value:
//    Enter a hexadecimal integer starting value: 1
//       Value       Value*2      Value*4
//    -------------------------------------
//              1            2            4
//              8           10           20
//             40           80          100
//            200          400          800
//           1000         2000         4000
//           8000        10000        20000
//          40000        80000       100000
//         200000       400000       800000
//        1000000      2000000      4000000
//        8000000     10000000     20000000
//       40000000     80000000            0
//              0            0            0
//

// C++ Version
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
using std::hex;
const int ROWS = 12;       // Determines the # rows.
const int COLUMNS = 3;     // Indicates but does not determine the # of columns.
const int MULT = 2;        // Multiplier for successive table entry values.
const int FLD_WIDTH = 11;  // Width of each entry field in table.
int main()
{
   cout << hex << "Enter a hexadecimal integer starting value: ";
   int entry;
   cin >> hex >> entry;
   // Display table header.
   cout <<
      "   Value       Value*" << MULT << "      Value*" << MULT * MULT << "\n"
      "-------------------------------------\n";
   // Loop to calculate and display each row of entries.
   for (int row = 0; row < ROWS; ++row)
   {
      cout <<
         setw(FLD_WIDTH) << entry << "  " <<
         setw(FLD_WIDTH) << entry * MULT << "  " <<
         setw(FLD_WIDTH) << entry * MULT * MULT << "\n";
      entry *= MULT * MULT * MULT;
   }
}

// C Version
#include <stdio.h>
#define ROWS 12            // Determines the # rows.
#define COLUMNS 3          // Indicates but does not determine the # of columns.
#define MULT 2             // Multiplier for successive table entry values.
int main(void)
{
   printf("Enter a hexadecimal integer starting value: ");
   int entry;
   scanf("%x", &entry);
   // Display table header.
   printf(
      "   Value       Value*%d      Value*%d\n"
      "-------------------------------------\n", MULT, MULT * MULT);
   // Loop to calculate and display each row of entries.
   for (int row = 0; row < ROWS; ++row)
   {
      printf("%11x  %11x  %11x\n", entry, entry * MULT, entry * MULT * MULT);
      entry *= MULT * MULT * MULT;
   }
}


//
//************  3A - Displaying a decimal integer in reverse order  ************
// (notes 1.11-1.14, 2.8, 3.5, 3.9)
//
// This program prompts the user for a non-negative decimal integer value then
// displays its significant digits in reverse order.
//  
// Runtime results for the indicated input values:
//
//    Enter a non-negative decimal integer value: 923
//    Significant digits: 923  Reversed significant digits: 329
//
//    Enter a non-negative decimal integer value: 920
//    Significant digits: 920  Reversed significant digits: 029
//
//    Enter a non-negative decimal integer value: 000945
//    Significant digits: 945  Reversed significant digits: 549
//
//    Enter a non-negative decimal integer value: 0
//    Significant digits: 0  Reversed significant digits: 0
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
const int RADIX = 10;               // radix of the input value
int main()
{
   cout << "Enter a non-negative decimal integer value: ";
   int inVal;
   cin >> inVal;
   cout << inVal << " reversed is ";

   do                               // loop to display digits in reverse
      cout << inVal % RADIX;        // display least significant digit
   while (inVal /= RADIX);          // shift inVal right by 1 digit and repeat
   cout << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 10                    // radix of the input value
int main(void)
{
   printf("Enter a non-negative decimal integer value: ");
   int inVal;
   scanf("%d", &inVal);
   printf("%d reversed is ", inVal);

   do                               // loop to display digits in reverse
      printf("%d", inVal % RADIX);  // display least significant digit
   while (inVal /= RADIX);          // shift inVal right by 1 digit and repeat
   printf("\n");
}


//
//************  3B - Displaying an octal integer in reverse order  *************
// (notes 1.11-1.14, 2.8, 3.5, 3.9)
//
// This program prompts the user for a non-negative octal integer value then
// displays its significant digits in reverse order.
//  
// Runtime results for the indicated input values:
// 
//    Enter a non-negative octal integer value: 123
//    Significant digits: 123  Reversed significant digits: 321
//
//    Enter a non-negative octal integer value: 120
//    Significant digits: 120  Reversed significant digits: 021
//
//    Enter a non-negative octal integer value: 000345
//    Significant digits: 345  Reversed significant digits: 543
//
//    Enter a non-negative octal integer value: 0
//    Significant digits: 0  Reversed significant digits: 0
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::oct;
const int RADIX = 8;                // radix of the input value
int main()
{
   cout << "Enter a non-negative octal integer value: ";
   int inVal;
   cin >> oct >> inVal;
   cout << oct << inVal << " reversed is ";

   do                               // loop to display digits in reverse
      cout << inVal % RADIX;        // display least significant digit
   while (inVal /= RADIX);          // shift inVal right by 1 digit and repeat
   cout << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 8                     // radix of the input value
int main(void)
{
   printf("Enter a non-negative octal integer value: ");
   int inVal;
   scanf("%o", &inVal);
   printf("%o reversed is ", inVal);

   do                               // loop to display digits in reverse
      printf("%o", inVal % RADIX);  // display least significant digit
   while (inVal /= RADIX);          // shift inVal right by 1 digit and repeat
   printf("\n");
}


//
//**********  3C - Displaying a hexadecimal integer in reverse order  **********
// (notes 1.11-1.14, 2.8, 3.5, 3.9)
//
// This program prompts the user for a non-negative hexadecimal integer value
// then displays its significant digits in reverse order.
//  
// Runtime results for the indicated input values:
// 
//    Enter a non-negative hexadecimal integer value: dab89
//    Significant digits: dab89  Reversed significant digits: 98bad
//
//    Enter a non-negative hexadecimal integer value: dab80
//    Significant digits: dab80  Reversed significant digits: 08bad
//
//    Enter a non-negative hexadecimal integer value: 000b45
//    Significant digits: b45  Reversed significant digits: 54b
//
//    Enter a non-negative hexadecimal integer value: 0
//    Significant digits: 0  Reversed significant digits: 0
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::hex;
const int RADIX = 16;               // radix of the input value
int main()
{
   cout << "Enter a non-negative hexadecimal integer value: ";
   int inVal;
   cin >> hex >> inVal;
   cout << hex << inVal << " reversed is ";

   do                               // loop to display digits in reverse
      cout << inVal % RADIX;        // display least significant digit
   while (inVal /= RADIX);          // shift inVal right by 1 digit and repeat
   cout << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 16                    // radix of the input value
int main(void)
{
   printf("Enter a non-negative hexadecimal integer value: ");
   int inVal;
   scanf("%x", &inVal);
   printf("%x reversed is ", inVal);

   do                               // loop to display digits in reverse
      printf("%x", inVal % RADIX);  // display least significant digit
   while (inVal /= RADIX);          // shift inVal right by 1 digit and repeat
   printf("\n");
}


//
//********  4A - Displaying a decimal integer's most significant digit  ********
// (notes 1.11-1.14)
//
// This program prompts the user for a non-negative decimal integer value then
// displays its most significant digit and the decimal divisor necessary to
// determine that digit.
//  
// Runtime results for the indicated input value:
//    Enter a non-negative decimal integer value: 94312
//    Dividing decimal 94312 by decimal 10000 produces its MSD (9)
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
const int RADIX = 10;                  // radix of the input value
int main()
{
   cout << "Enter a non-negative decimal integer value: ";
   int inVal;
   cin >> inVal;
   // Find a divisor that puts the number's MSD in the LSD.
   int divisor = 1;
   for (int dividend = inVal; dividend > RADIX - 1; dividend /= RADIX)
      divisor *= RADIX;                // increase divisor by a power of RADIX
   cout <<
      "Dividing decimal " << inVal << " by decimal " << divisor <<
      " produces its MSD (" << inVal / divisor << ")\n";
}

// C Version
#include <stdio.h>
#define RADIX 10                       // radix of the input value
int main(void)
{
   printf("Enter a non-negative integer value: ");
   int inVal;
   scanf("%d", &inVal);
   // Find a divisor that puts the number's MSD in the LSD.
   int divisor = 1;
   for (int dividend = inVal; dividend > RADIX - 1; dividend /= RADIX)
      divisor *= RADIX;                // increase divisor by a power of RADIX
   printf(
      "Dividing decimal %d by decimal %d produces its MSD (%d)\n",
      inVal, divisor, inVal / divisor);
}


//
//********  4B - Displaying an octal integer's most significant digit  *********
// (notes 1.11-1.14, 3.7)
//
// This program prompts the user for a non-negative octal integer value then
// displays its most significant digit and the octal divisor necessary to
// determine that digit.
//  
// Runtime results for the indicated input value:
//    Enter a non-negative octal integer value: 54312
//    Dividing octal 54312 by octal 10000 produces its MSD (5)
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::oct;
const int RADIX = 8;                   // radix of the input value
int main()
{
   cout << "Enter a non-negative octal integer value: ";
   int inVal;
   cin >> oct >> inVal;
   // Find a divisor that puts the number's MSD in the LSD.
   int divisor = 1;
   for (int dividend = inVal; dividend > RADIX - 1; dividend /= RADIX)
      divisor *= RADIX;                // increase divisor by a power of RADIX
   cout << oct <<
      "Dividing octal " << inVal << " by octal " << divisor <<
      " produces its MSD (" << inVal / divisor << ")\n";
}

// C Version
#include <stdio.h>
#define RADIX 8                        // radix of the input value
int main(void)
{
   printf("Enter a non-negative octal integer value: ");
   int inVal;
   scanf("%o", &inVal);
   // Find a divisor that puts the number's MSD in the LSD.
   int divisor = 1;
   for (int dividend = inVal; dividend > RADIX - 1; dividend /= RADIX)
      divisor *= RADIX;                // increase divisor by a power of RADIX
   printf(
      "Dividing octal %o by octal %o produces its MSD (%o)\n",
      inVal, divisor, inVal / divisor);
}


//
//******  4C - Displaying a hexadecimal integer's most significant digit  ******
// (notes 1.11-1.14)
//
// This program prompts the user for a non-negative hexadecimal integer value
// then displays its most significant digit and the hexadecimal divisor
// necessary to determine that digit.
//  
// Runtime results for the indicated input value:
//    Enter a non-negative hexadecimal integer value: fe312
//    Dividing hexadecimal fe312 by hexadecimal 10000 produces its MSD (f)
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::hex;
const int RADIX = 16;                  // radix of the input value
int main()
{
   cout << "Enter a non-negative hexadecimal integer value: ";
   int inVal;
   cin >> hex >> inVal;
   // Find a divisor that puts the number's MSD in the LSD.
   int divisor = 1;
   for (int dividend = inVal; dividend > RADIX - 1; dividend /= RADIX)
      divisor *= RADIX;                // increase divisor by a power of RADIX
   cout << hex <<
      "Dividing hexadecimal " << inVal << " by hexadecimal " << divisor <<
      " produces its MSD (" << inVal / divisor << ")\n";
}

// C Version
#include <stdio.h>
#define RADIX 16                       // radix of the input value
int main(void)
{
   printf("Enter a non-negative hexadecimal integer value: ");
   int inVal;
   scanf("%x", &inVal);
   // Find a divisor that puts the number's MSD in the LSD.
   int divisor = 1;
   for (int dividend = inVal; dividend > RADIX - 1; dividend /= RADIX)
      divisor *= RADIX;                // increase divisor by a power of RADIX
   printf(
      "Dividing hexadecimal %x by hexadecimal %x produces its MSD (%x)\n",
      inVal, divisor, inVal / divisor);
}


//
//*************  5A - Displaying decimal integer digits in order  **************
// (1.11-1.14)
//
// This program prompts the user for a non-negative decimal integer dividend and
// divisor.  The value of the divisor must be such that when divided into the
// dividend, the quotient will be the value of the dividend's most significant
// digit (MSD).  For example, if the dividend is 12845, the divisor will be
// 10000, or if the dividend is 9876 the divisor will be 1000.  The program
// will then display the digits of the dividend one at a time by extracting
// them from it left-to-right.
//  
// Runtime results for the indicated input values:
//    Enter a non-negative decimal integer dividend and divisor: 12845 10000
//    The result is 12845
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
const int RADIX = 10;                  // radix of the input values
int main()
{
   cout << "Enter a non-negative decimal integer dividend and divisor: ";
   int dividend, divisor;
   cin >> dividend >> divisor;
   cout << "The result is ";
   do
   {
      int msd = dividend / divisor;    // current msd
      cout << msd;                     // display the current msd
      dividend -= divisor * msd;       // delete the current msd
      divisor /= RADIX;                // reduce divisor
   } while (divisor);                  // repeat until divisor is 0
   cout << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 10                       // radix of the input values
int main(void)
{
   printf("Enter a non-negative decimal integer dividend and divisor: ");
   int dividend, divisor;
   scanf("%d %d", &dividend, &divisor);
   printf("The result is ");
   do
   {
      int msd = dividend / divisor;    // current msd
      printf("%d", msd);               // display the current msd
      dividend -= divisor * msd;       // delete the current msd
      divisor /= RADIX;                // reduce divisor
   } while (divisor);                  // repeat until divisor is 0
   printf("\n");
}


//
//**************  5B - Displaying octal integer digits in order  ***************
// (1.11-1.14)
//
// This program prompts the user for a non-negative octal integer dividend and
// divisor.  The value of the divisor must be such that when divided into the
// dividend, the quotient will be the value of the dividend's most significant
// digit (MSD).  For example, if the dividend is 12345, the divisor will be
// 10000, or if the dividend is 4076 the divisor will be 1000.  The program
// will then display the digits of the dividend one at a time by extracting
// them from it left-to-right.
//  
// Runtime results for the indicated input values:
//    Enter a non-negative octal integer dividend and divisor: 12345 10000
//    The result is 12345
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::oct;
const int RADIX = 8;                   // radix of the input values
int main()
{
   cout << oct << "Enter a non-negative octal integer dividend and divisor: ";
   int dividend, divisor;
   cin >> oct >> dividend >> divisor;
   cout << "The result is ";
   do
   {
      int msd = dividend / divisor;    // current msd
      cout << msd;                     // display the current msd
      dividend -= divisor * msd;       // delete the current msd
      divisor /= RADIX;                // reduce divisor
   } while (divisor);                  // repeat until divisor is 0
   cout << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 8                        // radix of the input values
int main(void)
{
   printf("Enter a non-negative octal integer dividend and divisor: ");
   int dividend, divisor;
   scanf("%o %o", &dividend, &divisor);
   printf("The result is ");
   do
   {
      int msd = dividend / divisor;    // current msd
      printf("%o", msd);               // display the current msd
      dividend -= divisor * msd;       // delete the current msd
      divisor /= RADIX;                // reduce divisor
   } while (divisor);                  // repeat until divisor is 0
   printf("\n");
}


//
//***********  5C - Displaying hexadecimal integer digits in order  ************
// (1.11-1.14, 3.17)
//
// This program prompts the user for a non-negative hexadecimal integer dividend
// and divisor.  The value of the divisor must be such that when divided into
// the dividend, the quotient will be the value of the dividend's most
// significant digit (MSD).  For example, if the dividend is ef345, the divisor
// will be 10000, or if the dividend is abcd the divisor will be 1000.  The
// program will then display the digits of the dividend one at a time by
// extracting them from it left-to-right.
//  
// Runtime results for the indicated input values:
//    Enter a non-negative hex integer dividend and divisor: ef345 10000
//    The result is ef345
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::hex;
const int RADIX = 16;                  // radix of the input values
int main()
{
   cout << hex << "Enter a non-negative hex integer dividend and divisor: ";
   int dividend, divisor;
   cin >> hex >> dividend >> divisor;
   cout << "The result is ";
   do
   {
      int msd = dividend / divisor;    // current msd
      cout << msd;                     // display the current msd
      dividend -= divisor * msd;       // delete the current msd
      divisor /= RADIX;                // reduce divisor
   } while (divisor);                  // repeat until divisor is 0
   cout << "\n";
}

// C Version
#include <stdio.h>
#define RADIX 16                       // radix of the input values
int main(void)
{
   printf("Enter a non-negative hex integer dividend and divisor: ");
   int dividend, divisor;
   scanf("%x %x", &dividend, &divisor);
   printf("The result is ");
   do
   {
      int msd = dividend / divisor;    // current msd
      printf("%x", msd);               // display the current msd
      dividend -= divisor * msd;       // delete the current msd
      divisor /= RADIX;                // reduce divisor
   } while (divisor);                  // repeat until divisor is 0
   printf("\n");
}


//
//****************  6A - Displaying a decimal digit as a word  *****************
// (1.11-1.14, 3.17)
//
// This program prompts the user for a decimal digit in the range FIRST-LAST
// and displays it as a word.  The case numbers are acceptable magic numbers
// in this case because they represent nothing other than the values of the
// numbers themselves.  There is a better approach but it involves pointers,
// which have not yet been covered and are not yet allowed.
//  
// Output from both versions for the indicated input value:
//    Enter a decimal digit from 7-9: 8
//    The word for 8 is eight.
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
const int FIRST = 7;
const int LAST = 9;
int main()
{
   cout << "Enter a decimal digit from " << FIRST << "-" << LAST << ": ";
   int inVal;
   cin >> inVal;
   cout << "The word for " << inVal << " is ";
   // Select and display the word corresponding to the value of the input digit.
   switch (inVal)
   {
   case 7: cout << "seven"; break;
   case 8: cout << "eight"; break;
   case 9: cout << "nine"; break;
   }
   cout << ".\n";
}

// C Version
#include <stdio.h>
#define FIRST 7
#define LAST 9
int main(void)
{
   printf("Enter a decimal digit from %d-%d: ", FIRST, LAST);
   int inVal;
   scanf("%d", &inVal);
   printf("The word for %d is ", inVal);
   // Select and display the word corresponding to the value of the input digit.
   switch (inVal)
   {
   case 7: printf("seven"); break;
   case 8: printf("eight"); break;
   case 9: printf("nine"); break;
   }
   printf(".\n");
}


//
//*****************  6B - Displaying an octal digit as a word  *****************
// (1.11-1.14, 3.17)
//
// This program prompts the user for an octal digit in the range FIRST-LAST
// and displays it as a word.  The case numbers are acceptable magic numbers
// in this case because they represent nothing other than the values of the
// numbers themselves.  There is a better approach but it involves pointers,
// which have not yet been covered and are not yet allowed.
//  
// Output from both versions for the indicated input value:
//    Enter a decimal digit from 0-2: 3
//    The word for 3 is three.
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::oct;
const int FIRST = 0;
const int LAST = 2;
int main()
{
   cout << oct << "Enter an octal digit from " << FIRST << "-" << LAST << ": ";
   int inVal;
   cin >> oct >> inVal;
   cout << "The word for " << inVal << " is ";
   // Select and display the word corresponding to the value of the input digit.
   switch (inVal)
   {
   case 0: cout << "zero"; break;
   case 1: cout << "one"; break;
   case 2: cout << "two"; break;
   }
   cout << ".\n";
}

// C Version
#include <stdio.h>
#define FIRST 0
#define LAST 2
int main(void)
{
   printf("Enter an octal digit from %o-%o: ", FIRST, LAST);
   int inVal;
   scanf("%o", &inVal);
   printf("The word for %o is ", inVal);
   // Select and display the word corresponding to the value of the input digit.
   switch (inVal)
   {
   case 0: printf("zero"); break;
   case 1: printf("one"); break;
   case 2: printf("two"); break;
   }
   printf(".\n");
}


//
//**************  6C - Displaying a hexadecimal digit as a word  ***************
// (1.11-1.14, 3.17)
//
// This program prompts the user for a hexadecimal digit in the range FIRST-LAST
// and displays it as a word.  The case numbers are acceptable magic numbers
// in this case because they represent nothing other than the values of the
// numbers themselves.  There is a better approach but it involves pointers,
// which have not yet been covered and are not yet allowed.
//  
// Output from both versions for the indicated input value:
//    Enter a hex digit from 9-b: a
//    The word for a is A.
//

// C++ Version
#include <iostream>
using std::cout;
using std::cin;
using std::hex;
const int FIRST = 9;
const int LAST = 0xb;
int main()
{
   cout << hex << "Enter a hex digit from " << FIRST << "-" << LAST << ": ";
   int inVal;
   cin >> hex >> inVal;
   cout << "The word for " << inVal << " is ";
   // Select and display the word corresponding to the value of the input digit.
   switch (inVal)
   {
   case 9: cout << "nine"; break;
   case 0xa: cout << "A"; break;
   case 0xb: cout << "B"; break;
   }
   cout << ".\n";
}

// C Version
#include <stdio.h>
#define FIRST 9
#define LAST 0xb
int main(void)
{
   printf("Enter a hex digit from %x-%x: ", FIRST, LAST);
   int inVal;
   scanf("%x", &inVal);
   printf("The word for %x is ", inVal);
   // Select and display the word corresponding to the value of the input digit.
   switch (inVal)
   {
   case 9: printf("nine"); break;
   case 0xa: printf("A"); break;
   case 0xb: printf("B"); break;
   }
   printf(".\n");
}
