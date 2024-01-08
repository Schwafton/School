#include <iostream>
#include <array>
#include <iomanip>
#include <algorithm>
using namespace std;

#ifndef MAXARRAY_H
#define MAXARRAY_H

/** Searches the array anArray[first] through anArray[last]
    for the maxiumum value by using a recursion similar to a binary search.
 @pre  anArray must contain elements.
 @post  anArray is unchanged and either the maximum value or -1 is returned.
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @return  Either the maximum value in anArray, or –1.*/
int maxArray(const int anArray[], int first, int last)
{
  if (first == last)
    return anArray[first];
  else if (last > first)
  {
    int mid = first + (last - first) / 2;
    return max(maxArray(anArray, first, mid),  maxArray(anArray, (mid +1), last));
  }
  else
    return -1;
}
 
#endif