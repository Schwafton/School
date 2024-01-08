// Directives
#include <iostream>
#include <iomanip>
#include <string>
#ifndef ENCRYPTEDSTRING_
#define ENCRYPTEDSTRING_
using namespace std;

// Class definition and prototypes
class EncryptedString
{
public:
  EncryptedString();
  EncryptedString(string str);
  void set(string str);
  string get() const;
  string getEncrypted() const;
private:
  string str;
};
#endif