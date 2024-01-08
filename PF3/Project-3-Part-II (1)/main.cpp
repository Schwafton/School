/*
Programmer: Afton Schwendiman
Project number: 3 Part II
Project Description: Recursion and Set ADT
Course: COSC 2436 PF III Data Structures
Date: February 23, 2021
*/

//  Based on code created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArraySet.h"
using namespace std;

void display(ArraySet<string>& set)
{
	cout << "The set contains " << set.getCurrentSize()
        << " items:" << endl;
   vector<string> setItems = set.toVector();
   
   int numberOfEntries = static_cast<int>(setItems.size());
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << setItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displaySet

int main()
{
	string items[] = {"one", "two", "three", "four", "one"};
  cout << "Initializing set with array items: ";
  for (int i = 0; i < 5; i++)
    cout << items[i] << " ";
  cout << endl;
  ArraySet<string> set(items, 5);
	cout << "Duplicate items will not be added." << endl;
	cout << "The initialized set is not empty." << endl;
	cout << "isEmpty: returns " << set.isEmpty() 
        << "; should be 0 (false)" << endl;
	display(set);

  cout << "isEmpty: returns " << set.isEmpty() 
      << "; should be 0 (false)" << endl;

  cout << "getCurrentSize: returns " << set.getCurrentSize() 
      << "; should be 4" << endl;    
  
  cout << "contains(\"three\"): returns " << set.contains("three")
      << "; should be 1 (true)" << endl;
  cout << "remove(\"two\"): returns " << set.remove("two")
      << "; should be 1 (true)" << endl;
  cout << "remove(\"two\"): returns " << set.remove("two")
      << "; should be 0 (false)" << endl;
  string five = "five";
  cout << "add(\"five\"): returns " << set.add(five) << "; should be 1 (true)" << endl;
  cout << endl;
  
  display(set);
  
  cout << "After clearing the set, ";
  set.clear();
  
  cout << "isEmpty: returns " << set.isEmpty()
      << "; should be 1 (true)" << endl;

  display(set);
  return 0;
}  // end main