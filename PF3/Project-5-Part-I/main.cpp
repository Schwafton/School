#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

int main()
{
  string input;

  char items[64];
  bool flag = true;
  ArrayStack<char> stack;
  int operand1, operand2, result;
  
  while(flag)
  {
    cout << "Enter postfix expression: " << endl;
    getline(cin, input);
    int index = 0;
    for (int i = 0; i < input.length(); i++)
    {
      if (!isspace(input[i]))
      {  
        items[index] = input[i];
        cout << items[index] << endl;
        index++;
      }
    }
    for (int i = 0; i < index; i++)
    {
      if (isdigit(items[i]))
      {
        cout << "Pushing item \"" << items[i] << "\"" << endl;
        stack.push(items[i]);
      }
      else
      {
        cout << "peek: " << stack.peek() << endl;
        operand2 = stack.peek() - '0';
        cout << "op2: " << operand2 << endl;
        stack.pop();
        cout << "peek: " << stack.peek() << endl;
        operand1 = stack.peek() - '0';
        cout << "op1: " << operand1 << endl;
        stack.pop();
        if (items[i] == '+')
        {
          result = operand1 + operand2;
        }
        if (items[i] == '-')
        {
          result = operand1 - operand2;
        }
        if (items[i] == '*')
        {
          result = operand1 * operand2;
        }
        if (items[i] == '/')
        {
          result = operand1 / operand2;
        }
        cout << result << endl;
        stack.push(result + '0');
        cout << "peek: " << stack.peek() << endl;
      }
    }
    while (!stack.isEmpty())
    {
      cout << "Top item is \"" << stack.peek() << "\"" << endl;
      cout << "Removing top item" <<  endl;
      stack.pop();
      cout << "Empty: " << stack.isEmpty() << endl;
    }
    cout << "More expressions (Y or N)? " << endl;
    cin >> input;
    cin.ignore();
    if (input == "N")
      flag = false;
  }

/*
    while (!stack.isEmpty())
    {
      cout << "Top item is \"" << stack.peek() << "\"" << endl;
      cout << "Removing top item" <<  endl;
      stack.pop();
    }
  }

  
string items[5] = {"one", "two", "three", "four", "five"};

  for (int i = 0; i < 5; i++)
  {
    cout<<"Pushing item \"" << items[i] << "\""<< std::endl;
    stack.push(items[i]);

  }
  cout << endl; 
  
    
  cout << stack.peek() << endl;

  while (!stack.isEmpty())
  {
    cout << "Top item is \"" << stack.peek() << "\"" << endl;
    cout << "Removing top item" <<  endl;
    stack.pop();
  }

  cout << endl;
  cout << "Empty: " << stack.isEmpty() << endl;
*/
}  // end driver