// Concepts and examples related to "C/C++ Programming I" Assignment 6
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
//    1. Finding the number of elements between any two array elements
//    2. Finding the first occurrence of a character in a string
//    3. Comparing the characters of two strings
//    4. Determine if an index is within a string without using strlen
//


//
//*****  1. Finding the number of elements between any two array elements  *****
// (note 6.14)
//
// For any array of any type, the number of elements between the beginnings of
// two arbitrary elements is found by subtracting either the "indices of" or
// the "pointers to" those two elements.  For example, how many elements are
// between the beginning of element 3 and the beginning of element 9 in the
// following arrays?
// 
// char A[100];
// Subtracting indices:
//    9-3=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// Subtracting pointers:
//    &A[9]-&A[3]=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// Subtracting pointers:
//    char *p1 = &A[3];
//    char *p2 = &A[9];
//    p2-p1=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// 
// int A[100];
// Subtracting indices:
//    9-3=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// Subtracting pointers:
//    &A[9]-&A[3]=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// Subtracting pointers:
//    int *p1 = &A[3];
//    int *p2 = &A[9];
//    p2-p1=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// 
// double A[100];
// Subtracting indices:
//    9-3=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// Subtracting pointers:
//    &A[9]-&A[3]=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// Subtracting pointers:
//    double *p1 = &A[3];
//    double *p2 = &A[9];
//    p2-p1=6  (A[3], A[4], A[5], A[6], A[7], A[8])
// 


//
//********  2. Finding the first occurrence of a character in a string  ********
// (note 6.17, 7.2)
//
// This program prompts the user to enter a string and a character to search for
// in that string.  A pointer to the first character in the string is passed to
// function MyStrchr as its first argument and the character to find is passed
// as its second argument.  If MyStrchr finds the character, it returns a
// pointer to its first occurrence.  Otherwise, a null pointer is returned.
// Although MyStrchr can find the null character at the end of a string just as
// easily as any other character, it may not be possible to enter that character
// from the keyboard on some systems.
// 
// Runtime results for the indicated input:
//
//    Enter a string and a character to search for in it: abcd c
//    Character found at index 2
// 
//    Enter a string and a character to search for in it: abcd x
//    Character not found.
//

// C++ Version
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
const int BUF_LENGTH = 256;
char *MyStrchr(const char *str, int ch);
int main()
{
   cout << "Enter a string and a character search for in it: ";
   char inBuf[BUF_LENGTH], inChar;
   cin >> setw(BUF_LENGTH) >> inBuf >> inChar;

   // Get pointer to the character if found or a null pointer if not.
   char *where = MyStrchr(inBuf, inChar);
   if (where)
      cout << "Character found at index " << (int)(where - inBuf) << ".\n";
   else
      cout << "Character not found.\n";
}
// Function "MyStrchr" performs like the standard library "strchr" function.
// It returns a pointer to the first character in the string in its first
// parameter that matches the character in its second parameter, or returns
// a null pointer if that character is not found.
char *MyStrchr(const char *str, int ch)
{
   // Loop to look for the character.
   for (; *str != ch; ++str)
      if (*str == '\0')    // if not found by the end of the string...
         return nullptr;   // ...return null pointer
   return (char *)str;     // found it - return pointer to it
}

// C Version
#include <stdio.h>
#define BUF_LENGTH 256
char *MyStrchr(const char *str, int ch);
int main(void)
{
   printf("Enter a string and a character to find: ");
   char inBuf[BUF_LENGTH], inChar;
   scanf("%255s\n%c", inBuf, &inChar);

   // Get pointer to the character if found or a null pointer if not.
   char *where = MyStrchr(inBuf, inChar);
   if (where)
      printf("Character found at index %d.\n", (int)(where - inBuf));
   else
      printf("Character not found.\n");
}
// Function "MyStrchr" performs like the standard library "strchr" function.
// It returns a pointer to the first character in the string in its first
// parameter that matches the character in its second parameter, or returns
// a null pointer if that character is not found.
char *MyStrchr(const char *str, int ch)
{
   // Loop to look for the character.
   for (; *str != ch; ++str)
      if (*str == '\0')    // if not found by the end of the string...
         return 0;         // ...return null pointer
   return (char *)str;     // found it - return pointer to it
}


//
//****************  3. Comparing the characters of two strings  ****************
// (notes 6.17, 7.2)
//
// This program prompts the user to enter two strings and passes pointers to
// the first character of each to function CompareChars.  That function then
// steps through both strings simultaneously, comparing the corresponding
// characters of each.  That is, it compares the values of the first character
// in each string, then the values of the second character in each, etc.
// Comparison stops when either the two characters being compared are not the
// same or when both are the null character.  In either case, the index of
// those two characters is returned.
// 
// Runtime results for the indicated input strings:
//
//    Enter two strings: abcd ab3d
//    Last try was at index 2.
//
//    Enter a string and a character to find: abcd abcd
//    Last try was at index 4.
//

// C++ Version
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
const int BUF_LENGTH = 256;
int CompareChars(const char *str1, const char *str2);
int main()
{
   cout << "Enter two strings: ";
   char inBuf1[BUF_LENGTH], inBuf2[BUF_LENGTH];
   cin >> setw(BUF_LENGTH) >> inBuf1 >> setw(BUF_LENGTH) >> inBuf2;

   // Get the index of the last characters compared.
   int index = CompareChars(inBuf1, inBuf2);
   cout << "Last try was at index " << index << ".\n";
}
// Function "CompareChars" compares corresponding characters in the strings in
// its two parameters until either the characters don't match or both are null
// characters.  In either case, the index of those characters is returned.
int CompareChars(const char *str1, const char *str2)
{
   char const * const START = str1;
   for (; *str1 == *str2 && *str1; ++str1, ++str2)
      ;
   return (int)(str1 - START);
}

// C Version
#include <stdio.h>
#define BUF_LENGTH 256
int CompareChars(const char *str1, const char *str2);
int main(void)
{
   printf("Enter a string and a character to find: ");
   char inBuf1[BUF_LENGTH], inBuf2[BUF_LENGTH];
   scanf("%255s %255s", inBuf1, inBuf2);

   // Get the index of the last characters compared.
   int index = CompareChars(inBuf1, inBuf2);
   printf("Last try was at index %d.\n", index);
}
// Function "CompareChars" compares corresponding characters in the strings in
// its two parameters until either the characters don't match or both are null
// characters.  In either case, the index of those characters is returned.
int CompareChars(const char *str1, const char *str2)
{
   char const * const START = str1;
   for (; *str1 == *str2 && *str1; ++str1, ++str2)
      ;
   return (int)(str1 - START);
}


//
//*****  4. Determine if an index is within a string without using strlen  *****
// (note 6.17, 7.2)
//
// This program prompts the user to enter a string and any non-negative index.
// It then determines if the index represents the position of a character inside
// the string.  For example, for the string "test" the index of the letter 's'
// is 2, that of the terminating null character is 4, and any index greater than
// 4 (or less than 0) is outside the string.
// 
// Runtime results for the indicated input values:
//
//    Enter a string and a non-negative index: abc 0
//    The index is inside the string.
//
//    Enter a string and a non-negative index: abc 3
//    The index is inside the string.
//
//    Enter a string and a non-negative index: abc 4
//    The index is outside the string.
//

// C++ Version
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
const int BUF_LENGTH = 256;
int main()
{
   cout << "Enter a string and a non-negative index: ";
   char inBuf[BUF_LENGTH], index;
   cin >> setw(BUF_LENGTH) >> inBuf >> index;

   // Start with a pointer to the first character in the input string.  Before
   // each loop iteration, test if either the pointer has reached the null
   // character or the index value is 0.  If neither, increment the pointer
   // and decrement the index.  If either, stop looping and test the value of
   // the index.  If it's 0, its original value represented a position in the
   // string.  Draw a diagram if you can't visualize this.
   for (char *p = inBuf; *p && index; ++p, --index)
      ;
   if (index == 0)
      cout << "The index is inside the string.\n";
   else
      cout << "The index is outside the string.\n";
}

// C Version
#include <stdio.h>
#define BUF_LENGTH 256
int main(void)
{
   printf("Enter a string and a non-negative index: ");
   char inBuf[BUF_LENGTH], index;
   scanf("%255s %d", inBuf, &index);

   // Start with a pointer to the first character in the input string.  Before
   // each loop iteration, test if either the pointer has reached the null
   // character or the index value is 0.  If neither, increment the pointer
   // and decrement the index.  If either, stop looping and test the value of
   // the index.  If it's 0, its original value represented a position in the
   // string.  Draw a diagram if you can't visualize this.
   for (char *p = inBuf; *p && index; ++p, --index)
      ;
   if (index == 0)
      printf("The index is inside the string.\n");
   else
      printf("The index is outside the string.\n");
}
