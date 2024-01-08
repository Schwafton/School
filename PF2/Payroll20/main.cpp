//******************************************************************
//	Assignment 9 - Payroll Version 2.0
//	Programmer: Afton Schwendiman
//	Completed : 12/08/2020
//	Status    : Complete
//
//	This program takes employee master data from a txt file and
//  uses an array of employee class objects to hold master data for
//  each employee.  An array of structures holding payroll data for
//  each employee is also populated from a second txt file.  A 
//  payroll report is printed to a third txt file.
//*****************************************************************

//  Directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

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
  int id;                         // employee ID
  string name;                    // employee name
  double hourlyPay;               // pay per hour
  int numDeps;                    // number of dependents
  int type;                       // employee type
	const int employee_number = 6;  // Number of employees
  const double TAX = 0.15;        // Income tax percentage
  const double INS = 20.00;       // Cost of insurance per dependent
  double total_gross_pay;         // Gross pay for all employees
  double total_net_pay;           // Net pay for all employees
  int processed = 0;              // successfully processed transaction counter

  // Structure containing employee pay info
	struct Paycheck
	{
		int id;                       // employee id
    float hours_worked;           // Weekly hours worked
    float gross_pay;              // gross pay
    float tax;                    // tax
    float insurance;              // insurance
    float net_pay;                // net pay
	};

  // Array of class objects for employee master data
	Employee emp[employee_number];

  // Array of structures for employee Paycheck
  Paycheck pay[employee_number];

  // Declare ifstream class object
  ifstream fin;

  // Open input file for employee master data
  fin.open("master9.txt");

  // Read from master data file
  for (int i=0; i<employee_number; i++)
  {
    fin >> id;
    getline(fin, name, ' '); // Get rid of blank space before name
    getline(fin, name, '#');
    fin >> hourlyPay;
    fin >> numDeps;
    fin >> type;
    // Assign master data to employee class attributes
    emp[i].set(id, name, hourlyPay, numDeps, type);
  }

  // close file
  fin.close();

  // open input file for transaction info
  fin.open("trans9.txt");

  // Read from transaction file
  for (int i=0; i<employee_number; i++)
  {
    fin >> pay[i].id;
    fin >> pay[i].hours_worked;
  }

  // close file
  fin.close();

  // declare ofstream class object
  ofstream fout;

  // open output file for payroll report
  fout.open("payroll.txt");

  // Print title and column headers to payroll report file
  fout << "Payroll Report\n" << endl;
  fout << setw(5) << left << "ID#" << setw(25) << "Name" << setw(10) << right << "Gross Pay" << setw(10) << "Tax" << setw(10) << "Insurance" << setw(10) << "Net Pay" << endl;

  // Payroll processing
  //If id# or hours worked are invalid, print error message and do not process transaction.
  for (int i=0; i<employee_number; i++)
  {
    if (emp[i].getID() == 0)
      cout << "Error. Invalid employee ID#: " << emp[i].getID() << "\nTransaction was not processed for that employee." << endl;
    else if (pay[i].hours_worked < 0 || pay[i].hours_worked > 168)
      cout << "Error. Invalid number of hours worked for employee ID#: " << emp[i].getID() << "\nTransaction was not processed for that employee." << endl;
    else
    {
      // process transaction
      // If hours_worked is less than or equal to 40 OR employee type is 1 (management), calculate gross pay, tax, insurance, and net pay.
      if (pay[i].hours_worked <= 40 || emp[i].getType() == 1)
      {
        pay[i].gross_pay = pay[i].hours_worked * emp[i].getHourlyPay();
        pay[i].tax = pay[i].gross_pay * TAX;
        pay[i].insurance = emp[i].getNumDeps() * INS;
        pay[i].net_pay = pay[i].gross_pay - pay[i].tax - pay[i].insurance;
        // increment processed transaction counter
        processed++;
      }
      // Calculates gross pay, tax, insurance, and net pay for 0 type (union) employees that work more than 40 hours.
      else
      {
        pay[i].gross_pay = (40 * emp[i].getHourlyPay()) + ((pay[i].hours_worked - 40) * 1.5 * emp[i].getHourlyPay());
        pay[i].tax = pay[i].gross_pay * TAX;
        pay[i].insurance = emp[i].getNumDeps() * INS;
        pay[i].net_pay = pay[i].gross_pay - pay[i].tax - pay[i].insurance;
        // increment processed transaction counter
        processed++;
      }
      // Print payroll report to file
      fout << setprecision(2) << fixed << setw(5) << left << emp[i].getID() << setw(25) << emp[i].getName() << setw(10) << right << pay[i].gross_pay << setw(10) << pay[i].tax << setw(10) << pay[i].insurance << setw(10) << pay[i].net_pay << endl;
      
      // Calculate and total gross and net pay by accumulation
      total_gross_pay += pay[i].gross_pay;
      total_net_pay += pay[i].net_pay;
    }
  }
  // Print total gross and net pay to payroll report file
  fout << "\nTotal Gross Pay: $" << total_gross_pay;
  fout << "\nTotal Net Pay: $" << total_net_pay;

  // Display number of transactions successfully processed.
  cout << "Total number of transactions processed: " << processed << endl;
  
  // Close payroll file
  fout.close();
}