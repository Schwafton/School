//  Directives
#include <iostream>
#include <iomanip>
#include <string>
#include "EncryptedString.h"
using namespace std;

// Default constructor (no arguments) to store empty string in data field.
EncryptedString::EncryptedString()
{
  EncryptedString::str = "";
}

// Constructor that takes string as parameter and stores the encrypted version in the data field (calls the set method to encrypt and store the string).
EncryptedString::EncryptedString(string str)
{
  EncryptedString::set(str);
}

// Encrypts the string parameter and stores in obj.  Discard any illegal characters within the parameter.
void EncryptedString::set(string str)
{
  char ch;
  string estr = "";
  int length = str.length();
  for (int i = 0; i < length; i++)
  {
    if(str[i] == 'a' || str[i] == 'A')
    {
        ch = str[i] +25;
        estr += ch;
    }
    else
    {
      if(isalpha(str[i]))
      {
        ch = str[i];
        --ch;
        estr += ch;
      }
      if(str[i] == ' ')
      {
        ch = str[i];
        estr += ch;
      }
    }
  }
  EncryptedString::str = estr;
}

// Returns decrypted version of the string stored in the obj.
string EncryptedString::get() const
{
  char ch;
  string estr = "";
  int length = EncryptedString::str.length();
  for (int i = 0; i < length; i++)
  {
    if(str[i] == 'z' || str[i] == 'Z')
    {
        ch = str[i] -25;
        estr += ch;
    }
    else
    {
      if(isalpha(str[i]))
      {
        ch = str[i];
        ++ch;
        estr += ch;
      }
      if(str[i] == ' ')
      {
        ch = str[i];
        estr += ch;
      }
    }
  }
  return estr;
}

// Returns the string stored in the obj. in encrypted format.
string EncryptedString::getEncrypted() const
{
  return EncryptedString::str;
}