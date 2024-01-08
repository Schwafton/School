/*
Programmer: Afton Schwendiman
Project number: 2
Project Description: Rectangle class with interface
Course: COSC 2436 PF III Data Structures
Date: February 10, 2021
*/

/** @file driver.cpp */

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
	Rectangle theRectangle;
  double length;
  double width;
	
	cout << "Intital state of the rectangle" << endl;
	cout << "    length  = " << theRectangle.getLength() << endl;
	cout << "    width   = " << theRectangle.getWidth() << endl;
  cout << "    area    = " << theRectangle.getArea() << endl << endl;
	
  cout << "Set new values for length and width." << endl << "New length: ";
  cin >> length;
  cout << "New width: ";
  cin >> width;

	theRectangle.set(length, width);
	cout << endl << "Current state of the rectangle" << endl;
	cout << "    length = " << theRectangle.getLength() << endl;
	cout << "    width  = " << theRectangle.getWidth() << endl;
  cout << "    area   = " << theRectangle.getArea() << endl << endl;
	
	return 0;
}