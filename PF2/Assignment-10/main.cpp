//******************************************************************
//	Assignment 10 - Payroll Version 3.0
//	Programmer: Afton Schwendiman
//	Completed : 12/09/2020
//	Status    : Complete
//
//	This program takes employee master data from a txt file and
//  uses an array of employee class objects to hold master data for
//  each employee.  An array of structures holding payroll data for
//  each employee is also populated from a second txt file.  A 
//  payroll report is printed to a third txt file.
//*****************************************************************
// https://stackoverflow.com/questions/29836751/c-strings-vs-string-class-syntax-with-class-member-functions
//  Directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// global constants
const int EMP_NUM = 100;        // Number of employees
const double TAX = 0.15;        // Income tax percentage
const double INS = 20.00;       // Cost of insurance per dependent



// Employee class header and member function definitions

class Employee 
{
  private:
    int id;             // employee ID
    string name;        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    
  public:
    Employee( int initId=0, string initName="", 
              double initHourlyPay=0.0, 
              int initNumDeps=0, int initType=0 );  // Constructor

    bool set(int newId, string newName, double newHourlyPay,
             int newNumDeps, int newType);
    
    int getID();
    string getName();
    double getHourlyPay();
    int getNumDeps();
    int getType(); 
};

Employee::Employee( int initId, string initName, 
                    double initHourlyPay,
                    int initNumDeps, int initType )
{
  bool status = set( initId, initName, initHourlyPay, 
                     initNumDeps, initType );

  if ( !status )
  {
    id = 0;
    name = "";
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;    
  }
}

bool Employee::set( int newId, string newName, double newHourlyPay,
                                 int newNumDeps, int newType )
{
  bool status = false;

  if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && 
       newType >= 0 && newType <= 1 )
  {
    status = true;
    id = newId;
    name = newName;
    hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
  return status;
}
int Employee::getID()
{
  return id;
}
string Employee::getName()
{
  return name;
}
double Employee::getHourlyPay()
{
  return hourlyPay;
}
int Employee::getNumDeps()
{
  return numDeps;
}
int Employee::getType()
{
  return type;
}
// End of employee class member function definitions

int main()
{
  //  Variables
  int index = 0;                  // index variable for search return
  int id;                         // employee ID
  char name[21];                  // employee name
  double hourlyPay;               // pay per hour
  int numDeps;                    // number of dependents
  int type;                       // employee type
 

// Array of class objects for employee master data
	Employee emp[EMP_NUM];
  cout << "create array of class objects for master data";

  // Declare ifstream class object
  ifstream fin;
  cout << "create ifstream class object";

  // Open input file for employee master data
  fin.open("master10.txt");

// UPDATE THIS TO BE AN END OF FILE LOOP
  // Read from master data file
  while (!fin.eof())
  {
    fin >> id;
    fin.get(name, 21, ' '); // Get rid of blank space before name
    fin.get(name, 21, '\n');
    fin >> hourlyPay;
    fin >> numDeps;
    fin >> type;
    // Assign master data to employee class attributes
    emp[index].set(id, name, hourlyPay, numDeps, type);
    index++;
    cout << name << endl;
  }


  // close file
  fin.close();

}
