//*****************************************************************
//	Programmer: Afton Schwendiman
//  Project number: 1
//	Project description: EncryptedString class
//  The EncryptedString class has one data memeber, a string. A
//  default constructor assigns an empty string to the data member
//  when an EncryptedString object is created. A constructor
//  re-assigns the data member when called.  The remaining member
//  functions "set" the data member to an encrypted string, "get"
//  the encrypted string stored in the object, and "get" and
//  decrypt the string.  The driver shows that the class is
//  functioning as intended.
//	Course: COSC 2436 PF III Data Structures
//  Date: February 2, 2021
//*****************************************************************
// Directives
#include <iostream>
#include <iomanip>
#include <string>
#include "EncryptedString.h"
using namespace std;
int main()
{
	EncryptedString stringTest; // Create an EncryptedString object.
  string str;                 // String variable to use in object.
	
  // Display the current data member stored in the stringTest object.
	cout << "Intital state of string: " << stringTest.get() << endl;

  // User inputs string.  String is encrypted and assigned to the
  // stringTest object data member.
	cout << "Enter a string to test encryption: ";
  getline(cin, str);
  stringTest.set(str);

  // Decrypts and displays the data member.
	cout << "Decrypted string: " << stringTest.get() << endl;

  // Displays the data member as it is stored (encrypted).
	cout << "String encryption: " << stringTest.getEncrypted() << endl;
	
	return 0;
}