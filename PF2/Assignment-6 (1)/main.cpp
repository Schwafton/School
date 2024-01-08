//******************************************************************
//  Assignment 6 - Monkey Food
//  Programmer: Afton Schwendiman
//  Completed : 11/3/2020
//  Status: Complete
//
//  This program takes user input values for daily food consumption
//  by monkeys and calculates the average daily food eaten, 
//  determines the most and least amount of food eaten by any 
//  monkey, and displays a weekly report.
//*****************************************************************

// Directives
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Global constants
const int NUM_COLS = 7;   // Number of columns in array
const int NUM_ROWS = 3;   // Number of rows in array

// Function prototypes
void getFood(float [][NUM_COLS], int);              // Gets user input food values
void showTable(float const [][NUM_COLS], int);      // Displays input food values
float averageDaily(float const [][NUM_COLS], int);  // Calculates average daily food
float least(float const [][NUM_COLS], int);         // Determines least food
float most(float const [][NUM_COLS], int);          // Determines most food

int main()
{
  // Definition for array table1 that will hold daily food eaten 
  float table1[NUM_ROWS][NUM_COLS]; 

  // Calls function that asks user to input amount of food eaten
  getFood(table1, NUM_ROWS);

  // Calls function that displays the contents of table1
  showTable(table1, NUM_ROWS);

  // Calls function that calculates and returns average daily consumption
  cout << "\nThe average food eaten per day by all monkeys: " << averageDaily(table1, NUM_ROWS) << endl;

  // Calls function that determines and returns least amount eaten
  cout << "The least amount of food eaten by any monkey: " << least(table1, NUM_ROWS) << endl;

  // Calls function that determines and returns most amount eaten
  cout << "The most food eaten by any monkey: " << most(table1, NUM_ROWS) << endl;

  return 0;
}

// This function asks user to input pounds of food eaten by each monkey for each day
// and puts the values in an array
void getFood(float array[][NUM_COLS], int numRows)
{
  int monkey[3] = {1, 2, 3};
  string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

  for (int row = 0; row < NUM_ROWS; row++)
  {
    for (int col = 0; col < NUM_COLS; col++)
    { 
      do
      {
        cout << "Enter pounds of food eaten by monkey " << monkey[row] << " on " << days[col] << ": ";
        cin >> array[row][col];
      } while (array[row][col] < 0);
    }
    cout << endl;
  }
}

// This function displays the contents of an array in a table format with column headers
void showTable(float const array[][NUM_COLS], int numRows)
{
  string header[8] = {"Monkey", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  cout << "Pounds of Food Eaten by Monkey and Day of Week" << endl;
  for (int col = 0; col < 8; col++)
    cout << setw(6) << header[col];
  cout << endl;
  for (int row = 0; row < numRows; row++)
  {
    cout << setw(6) << row + 1;
    for (int col = 0; col < NUM_COLS; col++)
    {
      cout << setw(6) << setprecision(1) << fixed << array[row][col];
    }
    cout << endl;
  }
}

// This function calculates the average sum of values per column in an array
float averageDaily(float const array[][NUM_COLS], int numRows)
{
  float sum;
  float avg;
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < NUM_COLS; col++)
    {
      sum += array[row][col];
    }
  }
  avg = sum / 7;
  return avg;
}

// This function determines the smallest value in an array
float least(float const array[][NUM_COLS], int numRows)
{
  float least = array[0][0];
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < NUM_COLS; col++)
    {
      if (array[row][col] < least)
        least = array[row][col];
    }
  }
  return least;
}

// This function determines the largest value in an array
float most(float const array[][NUM_COLS], int numRows)
{
  float most = array[0][0];
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < NUM_COLS; col++)
    {
      if (array[row][col] > most)
        most = array[row][col];
    }
  }
  return most;
}
