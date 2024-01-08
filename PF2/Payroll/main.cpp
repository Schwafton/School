//******************************************************************
//	Assignment 5 - Payroll Version 1.0
//	Programmer: Afton Schwendiman
//	Completed : 11/02/2020
//	Status    : Complete
//
//	This program receives user input for four employees for ID,
//  name, pay rate, type (union or management), and hours worked.
//  Gross pay, tax, and net pay are calculated for each employee.
//  Total gross pay and total net pay are calculated.  A payroll
//  report is displayed.  
//*****************************************************************

//  Directives
#include <iostream>
#include <iomanip>
#include <string>    
using namespace std;

int main()
{
  //  Variables
	const int employee_number = 4;  // Number of employees
  const double TAX = 0.15;        // Income tax percentage
  double total_gross_pay;         // Gross pay for all employees
  double total_net_pay;           // Net pay for all employees
	bool is_valid;                  // Input validation flag

  // Structure containing four elements for employee master information
	struct Emp_master
	{
		int emp_id;                   // Employee ID
		string emp_name;              // Employee name
		double pay_rate;              // Employee pay rate
		int type;                     // Employee type
	};

  // Array of structures for employee information
	Emp_master info[employee_number];

  // Program description
  cout << "This program receives user input for four employees - ID, name, pay rate, type (union or management), and number of hours worked.  Gross pay, tax, and net pay are calculated for each employee.  Total gross pay and total net pay are calculated.  A payroll report is displayed." << endl;

  // This for loop gets the master information inputs for each employee and
  // performs some input validation for each element.
	for (int emp_num = 0; emp_num < employee_number; emp_num++)
	{
	  // This while loop has user input employee ID and assigns the value to
    // the appropriate array structure element.
    is_valid = 0;
		while (!is_valid)
		{
			cout << "\nEnter master information for employee " << emp_num + 1 << ".\n" << "Employee ID: ";
			cin >> info[emp_num].emp_id;
			
			if (info[emp_num].emp_id <= 0)
			{
				cout << "Invalid entry.  Employee ID must a positive number.  Try again." << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
				is_valid = 1;
		}

    // Assigns user input employee name to the appropriate array structure 
    // element.
		cout << "Employee name: ";
		cin.ignore();
		getline(cin, info[emp_num].emp_name);

    // Assigns user input pay rate to the appropriate array structure element.
		is_valid = 0;
		while (!is_valid)
		{
			cout << "Pay rate: ";
			cin >> info[emp_num].pay_rate;
			if (info[emp_num].pay_rate <= 0)
			{
				cout << "Invalid entry.  Pay rate must be a positive number.  Try again." << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
				is_valid = 1;
		}
		
    // Assigns user input employee type to the corresponding array structure
    // element.
		is_valid = 0;
		while (!is_valid)
		{
			cout << "Type: ";
			cin >> info[emp_num].type;
			if (info[emp_num].type < 0 || info[emp_num].type > 1)
			{
				cout << "\nInvalid entry.  Employee type must be 0 (for union) or 1 (for management).  Try again." << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
				is_valid = 1;
		}
	}
	
  // Additional arrays for payroll calculations
	double hours[employee_number];      // Array for hours worked by employees
  double gross_pay[employee_number];  // Array for gross_pay of employees
  double tax[employee_number];        // Array for tax for employees
  double net_pay[employee_number];    // Array for net_pay of employees

  // This for loop takes user input hours worked for each employee, performs
  // some input validation, and calculates gross pay, tax, and net pay for
  // each employee and stores the values to a corresponding array. 
  cout << "\nEnter timecard information for each employee." << endl;
	for (int emp_num = 0; emp_num < employee_number; emp_num++)
	{
    // User input hours worked for each employee is put into the hours array
		is_valid = 0;
		while (!is_valid)
		{
			cout << "Hours worked for " << info[emp_num].emp_name << ": ";
			cin >> hours[emp_num];
			if (hours[emp_num] < 0 || hours[emp_num] > 168)
			{
				cout << "Invalid entry.  Hours worked must be a number between 0 and 168 inclusive.  Try again.";
				cin.clear();
				cin.ignore(100, '\n');
			}
				else
					is_valid = 1;
		}
    // If hours is less than or equal to 40 hours OR the employee type is 1
    // (management), calculates gross pay, tax, and net pay.
    if (hours[emp_num] <= 40 || info[emp_num].type == 1)
		{
      gross_pay[emp_num] = hours[emp_num] * info[emp_num].pay_rate;
      tax[emp_num] = gross_pay[emp_num] * TAX;
      net_pay[emp_num] = gross_pay[emp_num] - tax[emp_num];
    }
    // Calculates gross pay, tax, and net pay for 0 type (union) employees
    // that work more than 40 hours.
    else
    {
      gross_pay[emp_num] = (40 * info[emp_num].pay_rate) + ((hours[emp_num] - 40) * 1.5 * info[emp_num].pay_rate);
      tax[emp_num] = gross_pay[emp_num] * TAX;
      net_pay[emp_num] = gross_pay[emp_num] - tax[emp_num];
    }
    // Calculates total gross pay and total net pay by accumulation
    total_gross_pay += gross_pay[emp_num];
    total_net_pay += net_pay[emp_num];
	}

  // Displays payroll report which includes ID, name, gross pay, tax, and net // pay for each employee and total gross pay and total net pay for all 
  // employees.
  cout << "\nPayroll Report" << endl;
  // Column titles formatted 
  cout << setw(5) << left << "ID" << setw(40) << "Name" << setw(10) << right << "Gross Pay" << setw(10) << "Tax" << setw(10) << "Net Pay" << endl;
  // Displays information for each employee
  for (int emp_num = 0; emp_num < employee_number; emp_num++)
  {
    cout << setprecision(2) << fixed << setw(5) << left << info[emp_num].emp_id << setw(40) << info[emp_num].emp_name << setw(10)<< right << gross_pay[emp_num] << setw(10) << tax[emp_num] << setw(10) << net_pay[emp_num] << endl;
  }
  // Displays total gross and net pay for all employees for the week
  cout << "\nTotal Gross Pay: $" << total_gross_pay;
  cout << "\nTotal Net Pay: $" << total_net_pay;
}