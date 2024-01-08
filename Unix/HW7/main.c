// NAME: Afton Schwendiman CS 4350 - Unix Systems Programming
// Assignment Number: 7
// Due Date: 11 / 29 / 2021
//
// NAME: Afton Schwendiman
// CS 4350 - Unix Systems Programming
// Section: 001
// Assignment Number 7: 7
// Due Date: 11 / 29 / 2021
// Instructor's Name: Husain Gholoom
//
// Program description:  This program takes four user input integers (m, n, r, 
// and x) each between 5 and 25 inclusive, generates and sorts m random integers
// using selections sort, computes the factorial of n, determines if r is prime,
// calculates r ^ x, and computes the distinct sequence of x where the first
// number in the sequence is x, and each subsequent number in the sequence is 
// previous/2 if the previous number is even and previous*3 + 1 if the previous
// number in the sequence is odd.  The sequence continues until 1 is achieved.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

  int m = 0;  // integer variable for first user input number
  int n = 0;  // integer variable for second user input number
  int r = 0;  // integer variable for third user input number
  int x = 0;  // integer variable for fourth user input number
  int i;  // integer variable for loop iterable
  int j;  // integer variable for loop iterable

  // Program description and user input instructions
  printf("Welcome to Afton Schwendiman's Program\n\n");
  printf("This program will Accept an integer >= 5 && <= 25, creates 3 ");
  printf("processes:\n\n");
  printf("1. The first process generates and sorts m random integers using ");
  printf("the selection sort.\n\n");
  printf("2. The second procss computes the factorial of n.\n\n");
  printf("3. The third process determines whether or not r prime number.\n\n");
  printf("4. The fourth process will display the result of r ^ x.\n\n");
  printf("The parent process computes distinct sequence of x after the ");
  printf("processes are terminated.\n\n");

  // user input validation loop
  // integers must be between 5 and 25 inclusive
  // error messages displayed for any unaccepted inputs
  while (m<5 || n<5 || r<5 || x<5 || m>25 || n>25 || r>25 || x>25) {
    printf("Enter the first Number:\t\t");
    scanf("%d", &m);
    printf("Enter the second Number:\t");
    scanf("%d", &n);
    printf("Enter the third Number:\t\t");
    scanf("%d", &r);
    printf("Enter the fourth Number:\t");
    scanf("%d", &x);

    if (m < 5 || m > 25) {
      printf("\nError ******* First number must be a positive integer >- 5 ");
      printf("&& <= 25\n");
    }
    if (n < 5 || n > 25) {
      printf("\nError ******* Second number must be a positive integer >- 5 ");
      printf("&& <= 25\n");
    }
    if (r < 5 || r > 25) {
      printf("\nError ******* Third number must be a positive integer >- 5 ");
      printf("&& <= 25\n");
    }
    if (x < 5 || x > 25) {
      printf("\nError ******* Fourth number must be a positive integer >- 5 ");
      printf("&& <= 25\n");
    }
  }

  printf("\nMain Process Waits\n\n");

  int pid1= fork(); // first process fork created
  // first child process generates m random numbers and performs selection sort
  if (pid1 == 0) {
    int rand_num_arr[m];  // array of integers to hold random numbers
    printf("Selection Sort Process Started\n");
    printf("Input Number:\t%d\n", m);
    printf("%d%s", m, " Generated Random Numbers are:\t\n");
    // for loop generates m random integers between 5 and 25 inclusive
    for (i = 0; i < m; i++) {
      int random_number = (rand() % (25 - 5 + 1)) + 5;
      rand_num_arr[i] = random_number;
      printf("%d ", random_number);
    }

    // integer variable for temporary value used in selection sort swap
    int temp;
    // selection sort
    for (i = 0; i<(m-1); i++) {
      for (j = (i+1); j<m; j++) {
        if (rand_num_arr[j] < rand_num_arr[i]) {
          temp = rand_num_arr[i];
          rand_num_arr[i] = rand_num_arr[j];
          rand_num_arr[j] = temp;
        }
      }
    }
    // end of selection sort
    printf("\nSorted Sequence:\n");
    for (i = 0; i < m; i++) {
      printf("%d ", rand_num_arr[i]);
    }
    printf("\nSelection Sort Process Exits\n\n");
    exit(0);
  }
  // end of first child process


  if (pid1 > 0) {
    wait(NULL); // parent process waits for child process to terminate
    int pid2 = fork();  // second process fork created
    // second child process calculates n!
    if(pid2 == 0) {
      double factorial = n; // double variable to hold the value of n!
      printf("Factorial Process Started\n");
      printf("Input Number\t%d\n", n);
      // calculate factorial
      for (i = (n-1); i > 0; i--) {
        factorial = factorial * i;
      }
      printf("Factorial of %d%s%.0f", n, " is ", factorial);
      printf("\nFactorial Process Exits\n\n");
      exit(0);
    }
    // end of second child process

    if(pid2 > 0) {
      wait(NULL); // parent process waits for child process to terminate
      int pid3 = fork();  // third process fork created
      // third child process determines if r is prime
      if (pid3 == 0) {
        printf("Prime Process Started\n");
        printf("Input Number\t%d\n", r);
        int prime = 1;  // integer variable to be used as flag
        // determine if r is prime
        for (i = 2; i <= (r/2); ++i) {
          if (r %i == 0) {
            prime = 0;
            break;
          }
        }
        if (prime == 1) {
          printf("%d%s", r, " is prime\n");
        }
        else {
          printf("%d%s", r, " is not prime\n");
        }
        // end of prime determination
        printf("Prime Process Exits\n\n");
        exit(0);
      }
      // end of third child process

      if(pid3 > 0){
        wait(NULL); // parent process waits for child process to terminate
        int pid4 = fork();  // fourth process fork created
        // fourth child process calculates r to the power of x
        if (pid4 == 0) {
          printf("Power Process Started\n");
          double power =  r;  // double variable to hold r ^ x
          // determine r^x
          for(i = 1; i < x; i++) {
            power = power * r;
          }
          // end of r^x calculation
          printf("Input %d%s%d%s%.0f", r, " raised to power ", x, " = ", power);
          printf("\nPower Process Exits\n\n");
          exit(0);
        }
        // end of fourth child process

        if (pid4 > 0) {
          wait(NULL); // parent process waits for child process to terminate
        }
      }
    }
  }

  // Continue with parent process to determine the distinct sequence
  printf("Main Process Continue\n\n");
  printf("Distinct Sequence Started\n");
  printf("Input Number %d\n", x);
  printf("The distinct sequence for %d%s", x, " is: ");
  printf("%d", x);
  int next = x; // integer variable to hold the next number in the sequence
  // determines the distinct sequence
  while (next != 1) {
    if (next%2 == 0) {
      next = next/2;
    }
    else {
      next = 3*next + 1;
    }
    printf(", %d", next);
  }
  // end of distinct sequence determination

  printf("\nDistinct Sequence Termianted\n\n");

  printf("Main Process Exits");

  printf("\n\n\nAfton Schwendiman- Fall 2021");
  return 0;
}