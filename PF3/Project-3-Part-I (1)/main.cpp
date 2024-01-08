/*
Programmer: Afton Schwendiman
Project number: 3 Part I
Project Description: Recursion and Set ADT
Course: COSC 2436 PF III Data Structures
Date: February 23, 2021
*/

#include <iostream>
#include <array>
#include <iomanip>
#include <algorithm>
using namespace std;

#include "maxArray.h"

int main()
{
  int arr[] = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0};

  cout << "Determining the maximum value in an array containing the following values using binary recursion: " << endl;

  for (int i = 0; i < 18; i++)
    cout << arr[i] << " ";
  cout << endl << "The maximum value is: " << maxArray(arr, 0, 17);
  
  return 0;
}