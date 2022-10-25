//
// David Angell - U09609277
// davidjangell42@gmail.com
// C/C++ Programming I : Fundamental Programming Concepts
// 167109 - Raymond L. Mitchell
// 10/25/2022
// C1A5E1_main.c
// Ubuntu 20.04
// GCC 6.3.0
//
// Creates a survey for each shopper to fill out and then prints the results.
//

#include <stdio.h>  
#include <stdbool.h>

#define SHOPPERS 0
#define BEST 5
#define WORST 1
#define CHOICES (BEST - WORST + 1)
#define MAX_ERRORS 2

int main(void) {
  int ratings[CHOICES] = {0};
  // Output a message that indicates the allowed rating range and the MAX_ERRORS value.
  printf(
    "Enter the ratings from %d to %d.\n"
    "You will be allowed %d ratings outside this range\n", 
    WORST, BEST, MAX_ERRORS
  );

  // Loop through the shoppers.
  for (int shopper = 0; shopper < SHOPPERS; ++shopper) {
    int errors = 0; // number of errors made by the current shopper

    // Prompt the user for a rating and re-prompt if the rating is out of range 
    // until MAX_ERRORS is reached or the rating is in range.
    bool inRange = false;
    do {
      int rating;
      printf("\nEnter your rating: ");
      scanf("%d", &rating);
      
      if (rating <= WORST || rating >= BEST) {
        printf("Rating must be between %d and %d.\n", WORST, BEST);
        ++errors;
      } else {
        ++ratings[rating - WORST];
      }
    } while (errors < MAX_ERRORS && !inRange);
  }

  // Output the number of ratings for each rating value.
  printf(
    "Rating    Quantity\n"
    "------    --------\n"
  );

  for (int choice = 0; choice < CHOICES; choice++) {
    printf("%6d %11d\n", choice + WORST, ratings[choice]);
  }

  return 0;
}
