//*******************************************************************
//  Assignment 8 - Test Scores, Extra Credit Version                *
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
#include <string>
using namespace std;

// Define a structure to hold student name and grade
  struct student
  {
    string name;
    int score;
  };

// Function prototypes
void getScores(student [], int);
void sortAscending(student [], int);
void display(student [], int, double);
double getAverage(student *, int);

int main()
{
  // Variable used for array size
  int numStudents;

  // Define a pointer to a student struct
  struct student *scores = nullptr;

  // Ask user for number of students and assigns the value to numStudents
  cout << "Enter the number of students: ";
  cin >> numStudents;

  // Dynamic memory allocation for a student array of size numStudents
  scores = new student[numStudents];

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
void getScores(student array[], int size)
{
  int tempScore;
  cout << "Enter test scores for each student." << endl;
  for (int count = 0; count < size; count++)
  {
    cout << "Name of student " << count + 1 << ": ";
    cin.ignore();
    getline (cin, array[count].name);
    bool isValid = false;
    while (!isValid)
    {
      cout << "Test score for student " << count + 1 << ": ";
      cin >> tempScore;
      if (tempScore >= 0 && tempScore <= 105)
      {
        array[count].score = tempScore;
        isValid = true;
      }
      else
        cout << "Invalid entry.  Try again." << endl;
    }
  }
}

// Function sorts array elements in ascending order
void sortAscending(student array[], int size)
{   
  for (int maxElement = size - 1; maxElement > 0; maxElement--)
    {
      for (int index = 0; index < maxElement; index++)
        {
          if (array[index].score > array[index + 1].score)
          {
            swap(array[index].score, array[index + 1].score);
            swap(array[index].name, array[index + 1].name);
          }
        }
    }
}

// Function returns the grade average
double getAverage(student *array, int size)
{
  int sum = 0;
  double avg = 0.0;
  for (int count = 0; count < size; count++)
  {
    sum += array[count].score;
    avg = static_cast<double>(sum) / size;
  }
  return avg;
}

// Displays students' scores and the class average
void display(student array[], int size, double avg)
{
  cout << setw(25) << left << "Name" << setw(5) << right << "Grade" << endl << setw(15) << "------------------------------" << endl;
  for (int count = 0; count < size; count++)
    cout << setw(25) << left << array[count].name << setw(5) << right << array[count].score << endl;
  cout << setw(15) << "------------------------------" << endl;
  cout << setw(25) << left << "Average" << setw(5) << right << fixed << showpoint << setprecision(1) << avg << endl;
}