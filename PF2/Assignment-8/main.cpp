//*******************************************************************
//  Assignment 8 - Test Scores                                      *
//  Programmer: Afton Schwendiman                                   *
//  Completed : 11/29/2020                                          *
//  Status: Complete                                                *
//                                                                  *
//  This program asks user to input the number of students in class *
//  and a test score for each student, then displays each score and *
//  the class average.                                              *
//*******************************************************************

// Directives
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getScores(int [], int);
void sortAscending(int [], int);
void display(int [], int, double);
double getAverage(int *, int);

int main()
{
  // Variable used for array size
  int numStudents;

  // Define a pointer to an integer
  int *scores = nullptr;

  // Ask user for number of students and assigns the value to numStudents
  cout << "Enter the number of students: ";
  cin >> numStudents;

  // Dynamic memory allocation for an array of size numStudents
  scores = new int[numStudents];

  // Call function to get user input test scores for each student
  getScores(scores, numStudents);

  // Call function to sort scores in ascending order
  sortAscending(scores, numStudents);

  // Call to calculate and return the average
  double average = getAverage(scores, numStudents);

  // Call display function
  display(scores, numStudents, average);

  // Free the dynamically allocated memory 
  delete [] scores;
  scores = nullptr;
}

// Function gets and validates user input test scores for each student and stores them as array elements
void getScores(int array[], int size)
{
  int tempScore;
  cout << "Enter test scores for each student." << endl;
  for (int count = 0; count < size; count++)
  {
    bool isValid = false;
    while (!isValid)
    {
      cout << "Test score for student " << count + 1 << ": ";
      cin >> tempScore;
      if (tempScore >= 0 && tempScore <= 105)
      {
        array[count] = tempScore;
        isValid = true;
      }
      else
        cout << "Invalid entry.  Try again." << endl;
    }
  }
}

// Function sorts array elements in ascending order
void sortAscending(int array[], int size)
{   
  for (int maxElement = size - 1; maxElement > 0; maxElement--)
    {
      for (int index = 0; index < maxElement; index++)
        {
          if (array[index] > array[index + 1])
            swap(array[index], array[index + 1]);
        }
    }
}

// Function returns the grade average
double getAverage(int *array, int size)
{
  int sum = 0;
  double avg = 0.0;
  for (int count = 0; count < size; count++)
  {
    sum += *(array + count);
    avg = static_cast<double>(sum) / size;
  }
  return avg;
}

// Displays students' scores and the class average
void display(int array[], int size, double avg)
{
  cout << setw(15) << "Grade" << endl << setw(15) << "-----" << endl;
  for (int count = 0; count < size; count++)
    cout << setw(15) << array[count] << endl;
  cout << setw(15) << "-----" << endl;
  cout << setw(10) << "Average:" << setw(5) << fixed << showpoint << setprecision(1) << avg << endl;
}