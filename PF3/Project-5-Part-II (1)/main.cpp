/*
Programmer: Afton Schwendiman
Project number: 5
Project Description: Postfix Expression Calculator
Course: COSC 2436 PF III Data Structures
Date: April 05, 2021
*/

#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

int main()
{
  string input;                     //Holds user input postfix expression
  char items[64];                   //Holds postfix expression after processing
  bool flag = true;                 
  ArrayStack<int> stack;            //Array stack of integers to hold operands/resuts
  int operand1, operand2, result;   //Holds operands and result for each computation
  
  //Beginning of program loop
  while(flag)
  {
    //Asks user for input and assigns to input variable.
    cout << "Enter postfix expression: " << endl;
    getline(cin, input);
    
    /*This for loop performs input validation first.
    Character must be either a space or digit, or one of four math operators: +, -, *, /
    Error message if criteria not met.
    Following input validation, if the character is a space, it is ignored.
    All other valid characters are assigned to items array elements.*/
    int index = 0;  //variable used to increment through char array elements 
    for (int i = 0; i < input.length(); i++)
    {
      if (isspace(input[i]) || isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
      {
        if (!isspace(input[i]))
        {  
          items[index] = input[i];
          index++;
        }
      }
      else
      {
        cout << "Error: Invalid character encountered in input expression." << endl;
        flag = false;
        break;
      }
    }

    /*This loop processes the items array character elements.
    If the char is a digit, it is converted to an integer and pushed onto stack.
    If the char is an operator, the most recent two integers added to the stack are assigned to operands, popped out of stack, and the appropriate computation is performed.  The result is pushed onto stack.  When operands must pop out of stack, there is a check for malformed expression that the stack is not empty.*/
    for (int i = 0; i < index; i++)
    {
      if (!flag)
        break;
      if (isdigit(items[i]))
      {
        stack.push(items[i] - '0');
      }
      else
      {
        operand2 = stack.peek();
        if(!stack.isEmpty())
          stack.pop();
        else
        {
          cout << "Error: Malformed expression." << endl;
          flag = false;
          break;
        }
        operand1 = stack.peek();
        if(!stack.isEmpty())
          stack.pop();
        else
        {
          cout << "Error: Malformed expression." << endl;
          flag = false;
          break;
        }
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
        stack.push(result);
      }
    }

    //Displays the final result remaining on the stack after all array elements have been processed.
    cout << stack.peek() << endl;
    //Removes result from stack
    stack.pop();
    //Verifies that stack is empty (as it should be after removing final result)
    if(!stack.isEmpty())
      cout << "Error: Malformed expression." << endl;
    //Asks user to input yes or no to process an additional postfix expression
    cout << "More expressions (Y or N)? " << endl;
    cin >> input; //Y or N
    cin.ignore(); //clears input buffer
    //Exits loop if user does not wish to enter an additional porstfix expression
    if (input == "N")
      flag = false;
  } //end of while loop
}  // end driver