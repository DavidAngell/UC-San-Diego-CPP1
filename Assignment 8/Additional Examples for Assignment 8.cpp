// Concepts and examples related to "C/C++ Programming I" Assignment 8
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
//    1. Defining and using a C++ class and its members
//    2. Removing a substring from a string
//    3. Copying one file to another
//    4A. Creating a modified copy of a text file - more efficient version
//    4B. Creating a modified copy of a text file - less efficient version
//


//************  1. Defining and using a C++ class and its members  *************
// (notes 7.7, 9.13, 9.14A, 9.14B)
//
// This program illustrates some basic features of C++ classes and consists of
// the three files main.cpp, Amplifier.h, and Amplifier.cpp.  It implements a
// class named "Amplifier" that contains four private data members and nine
// public member functions that help describe a guitar amplifier.  It tests the
// class by declaring a class variable, storing some values in it, then
// displaying them.  
// 
// Runtime results:
//    Brand is "VOX"
//    Price is "1002.98"
//    Power is "ON"
//    Volume is "5"
// 
// Some important elementary C++ class concepts are:
//    1. By default, all members of a class are private.  Private members are
//       not directly accessible by code that uses the class (except for friend
//       functions, which are covered in a later course).
//    2. Any class members can explicitly be made public, protected, or private
//       by using those respective access specifiers.
//    3. Any member function can access any data or function member of the class
//       regardless of the access levels involved.
//    4. Typically, data members should be private and member functions should
//       public.  This prevents code that uses the class from directly accessing
//       the data members.
//    5. Public members are typically listed first in a class definition since
//       programmers using it cannot directly access the private members anyway.
//    6. A member function defined inside a class is implicitly inline and the
//       keyword "inline" is not needed.
//    7. A member function defined outside a class is only inline if the keyword
//       "inline" is used with the definition or the prototype.
//    8. If a class is defined in a header file, any inline member functions
//       must be also defined in that same header file, either inside or outside
//       the class definition.
//    9. Non-inline functions must not be defined in a header file.
//   10. A member function should be declared constant if it does not modify a
//       data member or call a function that does.  Declaring a function to be
//       constant is very different, both syntactically and functionally, from
//       declaring it to return a constant.
//
// What is: this->
//    The following is the definition of member function "SetPrice" from the
//    example program and its purpose is to assign the value of the function's
//    "price" parameter to the class object's "price" data member.  However,
//    because their names are the same  this->  must be used to indicate the
//    class member.  A technical explanation is provided in a later course:
//       void Amplifier::SetPrice(double price)
//       {
//          this->price = price;
//       }
//    An approach that doesn't require the use of  this->  is to use different
//    names for class members and parameters.  However, regardless of the
//    approach used you will always find programmers who will tell you that
//    another approach is better.
//

//************** Begin implementation file main.cpp
#include <iostream>
#include "Amplifier.h"
using std::cout;

int main()
{
   // Creates a type "Amplifier" variable (object).
   Amplifier myAmp;

   // Store some values in myAmp's data members:
   myAmp.SetBrand("VOX");
   myAmp.SetPrice(1002.98);
   myAmp.TurnOn();
   myAmp.SetVolume(5);
   // Do you know why accessing the members the following way won't compile?
   // myAmp.brand = "VOX";
   // myAmp.price = 1002.98;
   // myAmp.powerState = true;
   // myAmp.volume = 5;

   // Verify that the values were stored correctly:
   cout << "Brand is \"" << myAmp.GetBrand() << "\"\n";
   cout << "Price is \"" << myAmp.GetPrice() << "\"\n";
   cout << "Power is \"" << (myAmp.GetPowerState() ? "ON" : "OFF") << "\"\n";
   cout << "Volume is \"" << myAmp.GetVolume() << "\"\n";
}
//************** End implementation file main.cpp

//************** Begin header file Amplifier.h
#ifndef AMPLIFIER_H
#define AMPLIFIER_H

#include <iostream>
#include <string>

class Amplifier
{
public:
   // Prototype of an inline (why?) member function that sets the brand name
   void SetBrand(std::string brand);
   // Prototype of a non-inline member function that gets the brand name
   std::string GetBrand() const;
   // Prototype of a non-inline member function that sets the price
   void SetPrice(double price);
   // Prototype of a non-inline member function that gets the price
   double GetPrice() const;
   // Definition of an inline member function that turns the power on
   void TurnOn() { powerState = true; }
   // Definition of an inline member function that turns the power off
   void TurnOff() { powerState = false; }
   // Definition of an inline member function that gets the power status
   bool GetPowerState() const { return powerState; }
   // Prototype of a non-inline member function that sets the volume
   void SetVolume(int volume);
   // Definition of an inline member function that gets the volume
   inline int GetVolume() const;
private:
   std::string brand;   // VOX, Fender, Peavey, etc.
   double price;        // cost in US dollars
   bool powerState;     // true => on, false => off
   int volume;          // 0-10
};

// An inline member function that sets the brand name.
inline void Amplifier::SetBrand(std::string brand)
{
   this->brand = brand;
}

// An inline (why?) member function that gets the volume.
int Amplifier::GetVolume() const
{
   return volume;
}

#endif
//************** End header file Amplifier.h

//************** Begin implementation file Amplifier.cpp
#include <iostream>
#include <string>
#include "Amplifier.h"

// A non-inline member function that gets the brand name.
std::string Amplifier::GetBrand() const
{
   return brand;
}

// A non-inline member function that sets the price.
void Amplifier::SetPrice(double price)
{
   this->price = price;
}

// A non-inline member function that gets the price.
double Amplifier::GetPrice() const
{
   return price;
}

// A non-inline member function that sets the volume.
void Amplifier::SetVolume(int volume)
{
   this->volume = volume;
}
//************** End implementation file Amplifier.cpp


//
//*******************  2. Removing a substring from a string *******************
// (notes 6.17, 7.2)
// 
// This program separately prompts the user to enter a sentence and a substring
// to search for in that sentence (both possibly containing one or more spaces).
// It then searches the sentence for the first instance of the substring
// and, if found, produces a new sentence with the substring removed.
// 
// The standard library "strstr" function:
//    char *strstr(const char *str, const char *substr);
// is used to find the substring.  strstr searches the string represented by its
// first argument for the first occurrence of the substring represented by its
// second argument.  It returns a pointer to its first character of the
// substring if found.  Otherwise it returns a null pointer.
// 
// Runtime results for the indicated inputs:
//
//    Enter a sentence: I can't find these fish.
//    Enter a substring to extract: d the
//    Original line: I can't find these fish.
//    Modified line: I can't finse fish.
// 
//    Enter a sentence: I can't find these fish.
//    Enter a substring to extract: the fish
//    Substring "the fish" not found.
//

// C++ Version
#include <iostream>
#include <iomanip>
#include <cstring>
using std::cout;
using std::cin;
const int BUF_LENGTH = 256;
int main()
{
   cout << "Enter a sentence: ";
   char strBuf[BUF_LENGTH];
   cin.getline(strBuf, BUF_LENGTH);
   cout << "Enter a substring to extract: ";
   char subBuf[BUF_LENGTH];
   cin.getline(subBuf, BUF_LENGTH);

   char *subStart = strstr(strBuf, subBuf);     // substring start in strBuf
   if (subStart)                                // if substring was found
   {
      char resultBuf[BUF_LENGTH];
      size_t subIndex = subStart - strBuf;      // substring index in strBuf
      memcpy(resultBuf, strBuf, subIndex);      // copy up to substring
      size_t subLength = strlen(subBuf);        // length of substring
      char *subEnd = subStart + subLength;      // substring end in strBuf
      strcpy(resultBuf + subIndex, subEnd);     // copy all after substring
      cout << "Original line: " << strBuf << "\n";
      cout << "Modified line: " << resultBuf << "\n";
   }
   else
      cout << "Substring \"" << subBuf << "\" not found.";
}

// C Version
#include <stdio.h>
#include <string.h>
#define BUF_LENGTH 256
int main(void)
{
   printf("Enter a sentence: ");
   char strBuf[BUF_LENGTH];
   fgets(strBuf, BUF_LENGTH, stdin);
   strBuf[strcspn(strBuf, "\n")] = '\0';        // remove newline character
   printf("Enter a substring to extract: ");
   char subBuf[BUF_LENGTH];
   fgets(subBuf, BUF_LENGTH, stdin);
   subBuf[strcspn(subBuf, "\n")] = '\0';        // remove newline character

   char *subStart = strstr(strBuf, subBuf);     // substring start in strBuf
   if (subStart)                                // if substring was found
   {
      char resultBuf[BUF_LENGTH];
      size_t subIndex = subStart - strBuf;      // substring index in strBuf
      memcpy(resultBuf, strBuf, subIndex);      // copy up to substring
      size_t subLength = strlen(subBuf);        // length of substring
      char *subEnd = subStart + subLength;      // substring end in strBuf
      strcpy(resultBuf + subIndex, subEnd);     // copy all after substring
      printf("Original line: %s\n", strBuf);
      printf("Modified line: %s\n", resultBuf);
   }
   else
      printf("Substring \"%s\" not found.", subBuf);
}


//
//**********************  3. Copying one file to another  **********************
// (notes 10.1-10.10)
// 
// This program prompts the user to enter paths to a source and a destination
// file.  If the destination file does not exist, it will be created.  If it
// does exist, all previous data it contains will be lost.  The most efficient
// technique for copying a file without interpreting its content is to use the
// the "read" and "write" member functions in C++ and the "fread" and "fwrite"
// functions in C.  It doesn't matter whether the files are opened in the text
// or the binary mode as long as it is the same for both.
// 
// If a character array can be created that is large enough to hold the entire
// contents of the source file, only one call to the reading/writing functions
// is needed.  However, a more versatile approach is to create an array of
// "reasonable" size and read/write a block of data at a time until the entire
// file has been copied.
// 
// Runtime results if a file named "a" exists and a file named "ax" doesn't:
//
//    Enter a source file path: a
//    Enter a destination file path: b
//    File copied.
// 
//    Enter a source file path: ax
//    Enter a destination file path: b
//    Open failed: ax
// 

// C++ Version
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
const int BUF_LENGTH = 256;
const int FILE_BUF_LENGTH = 8192;
int main()
{
   cout << "Enter a source file path: ";
   char inPath[BUF_LENGTH];
   cin.getline(inPath, BUF_LENGTH);
   cout << "Enter a destination file path: ";
   char outPath[BUF_LENGTH];
   cin.getline(outPath, BUF_LENGTH);

   // Open the input file.  If it fails, terminate program with a failure code.
   ifstream inFile(inPath, ios_base::binary);
   if (!inFile.is_open())
   {
      cerr << "Open failed: " << inPath << "\n";
      exit(EXIT_FAILURE);
   }

   // Open the output file.  If it fails, terminate program with a failure code.
   ofstream outFile(outPath, ios_base::binary | ios_base::trunc);
   if (!outFile.is_open())
   {
      cerr << "Open failed: " << outPath << "\n";
      exit(EXIT_FAILURE);
   }

   // Read and write a maximum of FILE_BUF_LENGTH bytes per loop iteration.
   // Stop when zero bytes are read.
   for (;;)
   {
      char fileBuf[FILE_BUF_LENGTH];
      inFile.read(fileBuf, sizeof(fileBuf));
      streamsize bytesRead = inFile.gcount();
      if (bytesRead == 0)
         break;
      outFile.write(fileBuf, bytesRead);
   }

   inFile.close();
   outFile.close();
   cout << "File copied.\n";
}

// C Version
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_LENGTH 256
#define FILE_BUF_LENGTH 8192
int main(void)
{
   printf("Enter a source file path: ");
   char inPath[BUF_LENGTH];
   fgets(inPath, BUF_LENGTH, stdin);
   inPath[strcspn(inPath, "\n")] = '\0';        // remove newline character
   printf("Enter a destination file path: ");
   char outPath[BUF_LENGTH];
   fgets(outPath, BUF_LENGTH, stdin);
   outPath[strcspn(outPath, "\n")] = '\0';      // remove newline character

   // Open the input file.  If it fails, terminate program with a failure code.
   FILE *inFile = fopen(inPath, "rb");
   if (!inFile)
   {
      fprintf(stderr, "Open failed: %s\n", inPath);
      exit(EXIT_FAILURE);
   }

   // Open the output file.  If it fails, terminate program with a failure code.
   FILE *outFile = fopen(outPath, "wb");
   if (!outFile)
   {
      fprintf(stderr, "Open failed: %s\n", outPath);
      exit(EXIT_FAILURE);
   }

   // Read and write a maximum of FILE_BUF_LENGTH bytes per loop iteration.
   // Stop when zero bytes are read.
   for (;;)
   {
      char fileBuf[FILE_BUF_LENGTH];
      size_t bytesRead = fread(fileBuf, 1, sizeof(fileBuf), inFile);
      if (bytesRead == 0)
         break;
      fwrite(fileBuf, 1, bytesRead, outFile);
   }

   fclose(inFile);
   fclose(outFile);
   printf("File copied.\n");
}


//
// **  4A. Creating a modified copy of a text file - more efficient version  ***
// (notes 10.1-10.11)
// 
// NOTE:
// This version of the program (4A) writes line-at-a-time to the destination
// file whereas version 4B writes each line in pieces.  Line-at-a-time can be
// much more efficient but requires slightly more code.
//
// This program prompts the user to enter paths to a source and a destination
// file.  If the destination file does not exist, it will be created.  If it
// does exist, all previous data it contains will be lost.  The program then
// creates a new file with each string replaced by the string in NEW_STR.  For
// this example a string is defined as a sequence of one or more non-whitespace
// characters.
// 
// Runtime results if a file named "a" exists and a file named "ax" doesn't:
//
//    Enter a source file path: a
//    Enter a destination file path: b
//    Complete!
// 
//    Enter a source file path: ax
//    Enter a destination file path: b
//    Open failed: ax
// 

// C++ Version
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int PATH_BUF_LENGTH = 256;
const int LINE_BUF_LENGTH = 256;
const char * const REP = "AAA";  // replacement string
int main(void)
{
   cout << "Enter a source file path: ";
   char inPath[PATH_BUF_LENGTH];
   cin.getline(inPath, PATH_BUF_LENGTH);
   cout << "Enter a destination file path: ";
   char outPath[PATH_BUF_LENGTH];
   cin.getline(outPath, PATH_BUF_LENGTH);

   // Open the input file.  If it fails, terminate program with a failure code.
   ifstream inFile(inPath, ios_base::binary);
   if (!inFile.is_open())
   {
      cerr << "Open failed: " << inPath << "\n";
      exit(EXIT_FAILURE);
   }

   // Open the output file.  If it fails, terminate program with a failure code.
   ofstream outFile(outPath, ios_base::binary | ios_base::trunc);
   if (!outFile.is_open())
   {
      cerr << "Open failed: " << outPath << "\n";
      exit(EXIT_FAILURE);
   }

   size_t repLength = strlen(REP);              // replacement string length
   char inBuf[LINE_BUF_LENGTH], outBuf[LINE_BUF_LENGTH];
   // Read one original file line and write one modified line per iteration.
   while (inFile.getline(inBuf, LINE_BUF_LENGTH))
   {
      char *outPos = outBuf;                    // current position in outBuf
      int nonWhtspcCount = 0;                   // non-whitespace counter
      // Analyzes one character per iteration.  Whitespaces are preserved but
      // every sequence of non-whitespaces is replaced by the string in REP.
      for (char *inPos = inBuf; *inPos != '\0'; ++inPos)
      {
         if (isspace(*inPos))                   // if whitespace character
         {
            *outPos++ = *inPos;                 // copy character to outBuf
            nonWhtspcCount = 0;                 // clear non-whitespace counter
         }
         else if (nonWhtspcCount++ == 0)        // if first non-whitespace
         {
            memcpy(outPos, REP, repLength);     // copy replacement to outBuf
            outPos += repLength;                // skip replacement in outBuf
         }
      }
      *outPos++ = '\n';                         // copy character to outBuf
      outFile.write(outBuf, outPos - outBuf);   // write modified line to file
   }

   inFile.close();
   outFile.close();
   cout << "Complete!\n";
}

// C Version
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_BUF_LENGTH 256
#define LINE_BUF_LENGTH 256
#define REP "AAA"    // replacement string
int main(void)
{
   printf("Enter a source file path: ");
   char inPath[PATH_BUF_LENGTH];
   fgets(inPath, PATH_BUF_LENGTH, stdin);
   inPath[strcspn(inPath, "\n")] = '\0';        // remove newline character
   printf("Enter a destination file path: ");
   char outPath[PATH_BUF_LENGTH];
   fgets(outPath, PATH_BUF_LENGTH, stdin);
   outPath[strcspn(outPath, "\n")] = '\0';      // remove newline character

   // Open the input file.  If it fails, terminate program with a failure code.
   FILE *inFile = fopen(inPath, "r");
   if (!inFile)
   {
      fprintf(stderr, "Open failed: %s\n", inPath);
      exit(EXIT_FAILURE);
   }

   // Open the output file.  If it fails, terminate program with a failure code.
   FILE *outFile = fopen(outPath, "w");
   if (!outFile)
   {
      fprintf(stderr, "Open failed: %s\n", outPath);
      exit(EXIT_FAILURE);
   }

   size_t repLength = strlen(REP);              // replacement string length
   char inBuf[LINE_BUF_LENGTH], outBuf[LINE_BUF_LENGTH];
   // Read one original file line and write one modified line per iteration.
   while (fgets(inBuf, LINE_BUF_LENGTH, inFile))
   {
      inBuf[strcspn(inBuf, "\n")] = '\0';       // remove newline character

      char *outPos = outBuf;                    // current position in outBuf
      int nonWhtspcCount = 0;                   // non-whitespace counter
      // Analyzes one character per iteration.  Whitespaces are preserved but
      // every sequence of non-whitespaces is replaced by the string in REP.
      for (char *inPos = inBuf; *inPos != '\0'; ++inPos)
      {
         if (isspace(*inPos))                   // if whitespace character
         {
            *outPos++ = *inPos;                 // copy character to outBuf
            nonWhtspcCount = 0;                 // clear non-whitespace counter
         }
         else if (nonWhtspcCount++ == 0)        // if first non-whitespace
         {
            memcpy(outPos, REP, repLength);     // copy replacement to outBuf
            outPos += repLength;                // skip replacement in outBuf
         }
      }
      *outPos++ = '\n';                         // copy character to outBuf
      fwrite(outBuf, 1, outPos - outBuf, outFile);// write modified line to file
   }

   fclose(inFile);
   fclose(outFile);
   printf("Complete!\n");
}


//
// **  4B. Creating a modified copy of a text file - less efficient version  ***
// (notes 10.1-10.11)
// 
// NOTE:
// This version of the program (4B) writes each line to the destination file in
// pieces whereas version 4A writes them line-at-a-time.  Line-at-a-time can be
// much more efficient but requires slightly more code.
//
// This program prompts the user to enter paths to a source and a destination
// file.  If the destination file does not exist, it will be created.  If it
// does exist, all previous data it contains will be lost.  The program then
// creates a new file with each string replaced by the string in NEW_STR.  For
// this example a string is defined as a sequence of one or more non-whitespace
// characters.
// 
// Runtime results if a file named "a" exists and a file named "ax" doesn't:
//
//    Enter a source file path: a
//    Enter a destination file path: b
//    Complete!
// 
//    Enter a source file path: ax
//    Enter a destination file path: b
//    Open failed: ax
// 

// C++ Version
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int PATH_BUF_LENGTH = 256;
const int LINE_BUF_LENGTH = 256;
const char * const REP = "AAA";  // replacement string
int main(void)
{
   cout << "Enter a source file path: ";
   char inPath[PATH_BUF_LENGTH];
   cin.getline(inPath, PATH_BUF_LENGTH);
   cout << "Enter a destination file path: ";
   char outPath[PATH_BUF_LENGTH];
   cin.getline(outPath, PATH_BUF_LENGTH);

   // Open the input file.  If it fails, terminate program with a failure code.
   ifstream inFile(inPath, ios_base::binary);
   if (!inFile.is_open())
   {
      cerr << "Open failed: " << inPath << "\n";
      exit(EXIT_FAILURE);
   }

   // Open the output file.  If it fails, terminate program with a failure code.
   ofstream outFile(outPath, ios_base::binary | ios_base::trunc);
   if (!outFile.is_open())
   {
      cerr << "Open failed: " << outPath << "\n";
      exit(EXIT_FAILURE);
   }

   size_t repLength = strlen(REP);              // replacement string length
   char inBuf[LINE_BUF_LENGTH];
   // Read one original file line and write one modified line per iteration.
   while (inFile.getline(inBuf, LINE_BUF_LENGTH))
   {
      int nonWhtspcCount = 0;                   // non-whitespace counter
      // Analyzes one character per iteration.  Whitespaces are preserved but
      // every sequence of non-whitespaces is replaced by the string in REP.
      for (char *inPos = inBuf; *inPos != '\0'; ++inPos)
      {
         if (isspace(*inPos))                   // if whitespace character
         {
            outFile.put(*inPos);                // copy character to file
            nonWhtspcCount = 0;                 // clear non-whitespace counter
         }
         else if (nonWhtspcCount++ == 0)        // if first non-whitespace
            outFile.write(REP, repLength);      // write replacement to file
      }
      outFile.put('\n');                        // write character to file
   }

   inFile.close();
   outFile.close();
   cout << "Complete!\n";
}

// C Version
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_BUF_LENGTH 256
#define LINE_BUF_LENGTH 256
#define REP "AAA"    // replacement string
int main(void)
{
   printf("Enter a source file path: ");
   char inPath[PATH_BUF_LENGTH];
   fgets(inPath, PATH_BUF_LENGTH, stdin);
   inPath[strcspn(inPath, "\n")] = '\0';        // remove newline character
   printf("Enter a destination file path: ");
   char outPath[PATH_BUF_LENGTH];
   fgets(outPath, PATH_BUF_LENGTH, stdin);
   outPath[strcspn(outPath, "\n")] = '\0';      // remove newline character

   // Open the input file.  If it fails, terminate program with a failure code.
   FILE *inFile = fopen(inPath, "r");
   if (!inFile)
   {
      fprintf(stderr, "Open failed: %s\n", inPath);
      exit(EXIT_FAILURE);
   }

   // Open the output file.  If it fails, terminate program with a failure code.
   FILE *outFile = fopen(outPath, "w");
   if (!outFile)
   {
      fprintf(stderr, "Open failed: %s\n", outPath);
      exit(EXIT_FAILURE);
   }

   size_t repLength = strlen(REP);              // replacement string length
   char inBuf[LINE_BUF_LENGTH];
   // Read one original file line and write one modified line per iteration.
   while (fgets(inBuf, LINE_BUF_LENGTH, inFile))
   {
      inBuf[strcspn(inBuf, "\n")] = '\0';       // remove newline character

      int nonWhtspcCount = 0;                   // non-whitespace counter
      // Analyzes one character per iteration.  Whitespaces are preserved but
      // every sequence of non-whitespaces is replaced by the string in REP.
      for (char *inPos = inBuf; *inPos != '\0'; ++inPos)
      {
         if (isspace(*inPos))                   // if whitespace character
         {
            fputc(*inPos, outFile);             // write character to file
            nonWhtspcCount = 0;                 // clear non-whitespace counter
         }
         else if (nonWhtspcCount++ == 0)        // if first non-whitespace
            fwrite(REP, 1, repLength, outFile); // write replacement to file
      }
      fputc('\n', outFile);                     // write character to file
   }

   fclose(inFile);
   fclose(outFile);
   printf("Complete!\n");
}
