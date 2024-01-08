/*
NAME: Afton Schwendiman
Unix Systems Programming - CS4350 - 001
Assignment Number: 4
Due Date: 10/18/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// function to return a randomly generated number between 5 and 15 inclusive.
int getRandomNumber(void) {                                                     
  int MIN = 5;                              // integer value for lower
                                            // inclusive boundary.
  int MAX = 15;                             // integer value for upper 
                                            // inclusive boundary.
  int RANGE = MIN - MAX + 1;                // integer value for RANGE
                                            // of random numbers
  int randomNumber = (rand()%RANGE + MIN);  // integer value for a randomly
                                            // generated positive integer.
  return randomNumber;
}

// function takes a sum, generates random number pairs until their sum is equal
// to the sum argument, and counts the number of pairs generated.
void sumCounter(int sum) {
  int newSum = 0;                           // integer value for the sum of
                                            // two randomly generated integers.
  int counter = 0;                          // integer value for the number
                                            // of times it takes to reproduce
                                            // the initial sum.
  while (newSum != sum) {
    int numOne = getRandomNumber();         // integer value for first random
                                            // number.
    int numTwo = getRandomNumber();         // integer value for second random
                                            // number.
    newSum = numOne + numTwo;
    counter++;

    printf("Generating First Number\t\t=\t %d\n", numOne);
    printf("Generating Second Number\t=\t %d\n", numTwo);
    printf("The sum of the generated numbers is\t: %d\n\n", newSum);
  }

  printf("\nNumber of Times the Numbers were Generated");
  printf("\nBefore the Desired sum was reached\t= %d\n\n\n", counter);
}

int main(void) {
  srand(time(NULL));

  // program description
  printf("Practicing C Programming Language\n\n");
  printf("The purpose of this program is to generate 2 random numbers");
  printf("\nbetween 5 and 15 inclusive.  A sum will be calculated by adding");
  printf("\nthe generated numbers.  Then, the program will find the number of");
  printf("\ntimes it takes for the sum is be reproduced again.\n\n");

  char userOption = '1';                    // char value for the user input

  // body of program, loops until user chooses to exit the program.
  while (userOption == '1') {

    // get user input for option selection
    printf("Select One of the Following\n\n");
    printf("\t1 - Generate Numbers\n\t9 - Exit The Program\n");
    userOption = getchar();
    getchar();

    // if user input option is 1, generate initial pair of random numbers and
    // calculate their sum.  Then call sumCounter on that sum.
    if (userOption == '1') {
      int numOne = getRandomNumber();
      int numTwo = getRandomNumber();
      int sum = numOne + numTwo;
      printf("First Generated Number\t: %d\n", numOne);
      printf("Second Generated Number\t: %d\n\n", numTwo);
      printf("First Number + Second Number =\t%d\n\n", sum);
      printf("Processing . . . . . . .\n\n");
      sumCounter(sum);
    }

    // if user input option is 9, program is terminated.
    if (userOption == '9') {
      printf("Program is Termianted\n\n");
      printf("Implemented by Afton Schwendiman\n\n");
      printf("10 - 18 - 2021");
    }

    // if user input option is invalid (not 1 or 9), then display error and
    // loop back to the top to get a new user input for option selection.
    if ((userOption != '1') && (userOption != '9'))  {
      printf("**\tInvalid Selection\t**\n\n\n");
      userOption = '1';
    }
  }
  return 0;
}