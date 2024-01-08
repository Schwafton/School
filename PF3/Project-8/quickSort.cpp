//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 11-5.
#include <iostream>
#include "insertionSort.cpp"
using namespace std;

template <class ItemType>
void sortLastMiddleFirst(ItemType theArray[], int first, int mid, int last)
{
  if (theArray[first] > theArray[mid])
  {
    ItemType temp = theArray[first];
    theArray[first] = theArray[mid];
    theArray[mid] = temp;
  }
  if (theArray[mid] > theArray[last])
  {
    ItemType temp = theArray[mid];
    theArray[mid] = theArray[last];
    theArray[last] = temp;
  }
  if (theArray[first] > theArray[mid])
  {
    ItemType temp = theArray[first];
    theArray[first] = theArray[mid];
    theArray[mid] = temp;
  }
} // end sortLaStMiddleFirst

template <class ItemType>
int partition(ItemType theArray[], int first, int last)
{
  int mid = first + (last - first) / 2;
  sortLastMiddleFirst(theArray, first, mid, last);
  //interchange theArray[mid] and theArray[last - 1]
  ItemType temp = theArray[mid];
  theArray[mid] = theArray[last - 1];
  theArray[last - 1] = temp;
  int pivotIndex = last - 1;
  ItemType pivot = theArray[pivotIndex];
  //determine the regions s1 and s2 --- I think this is done by sortLastMiddleFirst function?
  int indexFromLeft = first + 1;
  int indexFromRight = last - 2;
  bool done = false;
  while (!done)
  {
    //locate first entry on left that is >/= pivot
    while (theArray[indexFromLeft] < pivot)
      indexFromLeft = indexFromLeft + 1;
    //locate first entry on right that is </= pivot
    while (theArray[indexFromRight] > pivot)
      indexFromRight = indexFromRight - 1;
    if (indexFromLeft < indexFromRight)
    {
      //interchange theArray[indexFromLeft] and theArray[indexFromRight]
      ItemType temp = theArray[indexFromLeft];
      theArray[indexFromLeft] = theArray[indexFromRight];
      theArray[indexFromRight] = temp;
      indexFromLeft = indexFromLeft + 1;
      indexFromRight = indexFromRight - 1;
    }
    else
      done = true;
  }
  //Place pivot in proper position between s1 and s2, and mark its new location.
  //interchane theArray[pivotIndex] and theArray[indexFromLeft]
  temp = theArray[pivotIndex];
  theArray[pivotIndex] = theArray[indexFromLeft];
  theArray[indexFromLeft] = temp;
  pivotIndex = indexFromLeft;
  return pivotIndex;
} // end partition

/** Sorts an array into ascending order. Uses the quick sort with
    median-of-three pivot selection for arrays of at least MIN_SIZE
    entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{
  int MIN_SIZE = 4;
  if ((last - first + 1) < MIN_SIZE)
  {
    cout << "Array size: " << (last - first + 1) << endl;
    insertionSort(theArray, first, last);
  }
  else
  {
    // Create the partition: S1 | Pivot | S2
    int pivotIndex = partition(theArray, first, last);
    
    // Sort subarrays S1 and S2
    cout << "Left side size: " << (pivotIndex - first) << "; Right side size: " << (last - pivotIndex) << endl;
    quickSort(theArray, first, pivotIndex - 1);
    quickSort(theArray, pivotIndex + 1, last);
  }  // end if
}  // end quickSort