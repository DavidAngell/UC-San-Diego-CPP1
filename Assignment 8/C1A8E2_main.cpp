//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 11/15/2022
// C1A8E2_main.cpp
// Ubuntu 20.04
// GCC 6.3.0
//
// This file contains the main function for the program that takes
// <file_in> as an argument and preforms a search and replace on the file
// such that all instances of the <search> argument are replaced with 
// the <replace> argument. Then the file is output to <file_out>.
//

#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_LINE_LENGTH = 256;

// Args: <file_in> <file_out> <search> <replace>
const int NUM_ARGS = 5;
const int FILENAME_ARG = 0;
const int FILE_IN_ARG = 1;
const int FILE_OUT_ARG = 2;
const int SEARCH_ARG = 3;
const int REPLACE_ARG = 4;

// error exit codes
const int FILE_OPEN_ERROR = 1;
const int ARGUMENT_ERROR = 2;

int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != NUM_ARGS) {
    std::cerr << "Error: Incorrect number of arguments.\n";
    std::cout << "Usage: " << argv[FILENAME_ARG] << " <file_in> <file_out> <search> <replace>\n";
    return ARGUMENT_ERROR;
  }

  // Get file name, search string, and replace string from command line
  char *fileInName = argv[FILE_IN_ARG];
  char *fileOutName = argv[FILE_OUT_ARG];
  char *searchString = argv[SEARCH_ARG];
  char *replaceString = argv[REPLACE_ARG];

  size_t searchStringLength = std::strlen(searchString);
  size_t replaceStringLength = std::strlen(replaceString);

  // Open input file and check if the file was opened successfully
  std::ifstream inFile(fileInName);
  if (!inFile) {
    std::cout << "Error opening file: " << fileInName << "\n";
    return FILE_OPEN_ERROR;
  }

  // Open output file and check if the output file was opened successfully
  std::ofstream outFile(fileOutName);
  if (!outFile) {
    std::cout << "Error opening file: " << fileOutName << "\n";
    return FILE_OPEN_ERROR;
  }

  char line[MAX_LINE_LENGTH];
  // Read the file line by line
  while (inFile.getline(line, MAX_LINE_LENGTH)) {
    // Search for the search string
    for (size_t pos = 0; line[pos] != '\0'; pos++) {
      // If the search string is found
      if (std::strncmp(&line[pos], searchString, searchStringLength) == 0) {
        // Adjust the line to account for the new string
        if (replaceStringLength > searchStringLength) {
          // Shift the rest of the line to the right
          for (size_t substringPos = std::strlen(line); substringPos >= pos; substringPos--) {
            line[substringPos + replaceStringLength - searchStringLength] = line[substringPos];
          }
        } else if (replaceStringLength < searchStringLength) {
          // Shift the rest of the line to the left
          for (size_t substringPos = pos + searchStringLength; line[substringPos] != '\0'; substringPos++) {
            line[substringPos - searchStringLength + replaceStringLength] = line[substringPos];
          }
        }

        // Copy the replace string into the line
        for (size_t substringPos = 0; substringPos < replaceStringLength; substringPos++) {
          line[pos + substringPos] = replaceString[substringPos];
        }

        // Move the position to the end of the replace string
        pos += replaceStringLength - 1;
      }
    }

    // Write the line to the output file
    outFile << line << "\n";
  }

  // Close the files
  inFile.close();
  outFile.close();

  return 0;
}