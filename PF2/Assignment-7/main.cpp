//******************************************************************
//  Assignment 7 - Postal Packages
//  Programmer: Afton Schwendiman
//  Completed : 11/5/2020
//  Status: Complete
//
//  This program takes user input package weight and dimensions,
//  calculates package girth, determines cost, and accepts/rejects
//  package specifications. 
//*****************************************************************

// Directives
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Global constant used for array size
const int SIZE = 15;

// Function prototypes
int getCostIndex(int [], int); // Returns the costTable array index
int getGirth(int, int, int);  // Returns girth
string getStatus(int, int, int, int, int);  // Returns Accepted/Rejected

int main()
{
  // Variables
  int acceptedCounter = 0;  // Keeps running total of acceptions
  int rejectedCounter = 0;  // Keeps running total of rejections
  int weight, side1, side2, side3, girth;
  int transaction = 0;  // Tracks transaction number
  double cost;  // Holds cost
  string status;  // Holds accepted/rejected status

  // Array definitions for weight/cost tables
  int weightTable[SIZE] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};  // Holds weights
  double costTable[SIZE] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.20, 27.30, 31.90, 38.50, 43.50, 44.80, 47.40, 55.20};  // Holds costs

  // User input instructions
  cout << "For each transaction, enter package weight and 3 dimensions.\nEnter -1 to quit." << endl;
  
  // Transaction loop
  while (weight != -1)
  {
    cout << "\nEnter package weight and 3 dimensions: ";   // User input instruction
    cin >> weight;  // User inputs package weight
    if (weight == -1) // If weight input is -1, loop immediately exits
      break;
    cin >> side1 >> side2 >> side3; // User inputs package dimensions
    if (weight == 0 || side1 == 0 || side2 == 0 || side3 == 0)  // If any package specification is zero, displays error and reiterates loop for new inputs
    {
      cout << "Error: Package weight and dimensions must be larger than 0.\nPlease re-enter transaction.";
    }
    else  // If package specifications are valid, they are processed
    {
      girth = getGirth(side1, side2, side3);  // Calculates girth given dimensions and assigns value to girth
      status = getStatus(weight, girth, side1, side2, side3); // Determines status given weight, girth, and dimensions and assigns value to status
      cout << setw(20) << right << "Transaction: " << ++transaction << endl;  // Accumulates and displays transaction number
      cout << setw(20) << right << "Status: " << status << endl;  // Displays status
      cout << setw(20) << right << "Weight: " << weight << " LB" << endl; // Displays weight

      // Displays cost
      if (status == "Accepted") // If status is "Accepted", cost is determined and displayed
      {
        // Function getCostIndex returns index for cost - not actual cost - given weight. Returned index is put into costTable array to determine cost and value is assigned to variable cost
        cost = costTable[getCostIndex(weightTable, weight)];
        cout << setw(20) << right << "Cost: " << "$" << setprecision(2) << fixed << cost << endl; // Displays cost
        acceptedCounter++;  // Increments number of transactions with "Accepted" status
      }
      else  // If status is "Rejected", no cost is displayed.
      {
        cout << setw(20) << right << "Cost: " << "-" << endl; // No cost displayed for "Rejected" transaction
        rejectedCounter++;  // Increments number of transactions with "Rejected" status
      }
    }
  }
  // Upon  loop exit, number of "Accepted" and "Rejected" packages are displayed
  cout << "Number of accepted packages: " << acceptedCounter << endl;
  cout << "Number of rejected packages: " << rejectedCounter << endl;
}

// Function receives weight, girth, and three dimensions and determines if package will be accepted/rejected.
string getStatus(int lb, int g, int s1, int s2, int s3)
{
  string status;  // Local function variable to hold accepted/rejected status
  // If weight is greater than 50 lbs OR girth is greater than 60 in. (5 ft) OR any dimension is greater than 36 in. (3 ft), package status is "Rejected"
  if (lb > 50 || g > 60 || s1 > 36 || s2 > 36 || s3 > 36) 
    status = "Rejected";
  else  // Otherwise package status is "Accepted"
    status = "Accepted";
  return status;  // Status is returned "Accepted" or "Rejected" when function is called
}

// Function receives package dimensions and calculates and returns girth.
int getGirth(int s1, int s2, int s3)
{
  int girth;  // Local function variable to hold calculated girth
  if (s1 > s2 && s1> s3)  // Calculates girth if first dimension passed is largest
    girth = 2 * (s2 + s3);
  else if (s2 > s1 && s2 > s3)  // Calculates girth if second dimension passed is largest
    girth = 2 * (s1 + s3);
  else  // Calculates girth if third dimension passed is largest
    girth = 2 * (s1 + s2);
  return girth; // Girth is returned when function is called
}

// Sequential search function receives weightTable array address and package weight and returns index for first weight value which is equal to or greater than the passed weight parameter
int getCostIndex(int array[], int lb)
{
  int index = 0;  // Variable to hold index value is initialized
  //  Loop iterates for each index until the value held at array[index] is greater than or equal to weight
  while (index < SIZE && lb > array[index])
  {
    index++; // Increments index value
  }
  return index; // Returns value of index where cost is located in costTable array
}


