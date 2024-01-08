//******************************************************************
//  Assignment 4 - Robot Speed Estimator
//  Programmer: Afton Schwendiman
//  Completed : 9/27/2020
//  Status: Complete
//
//  Given diameter (in.) of wheel mounts and speed (RPM) of gear
//  motors, program computes maximum robot speed (ft/min.).
//*****************************************************************
#include <iostream>
#include <iomanip>
using namespace std;
// Class description.
class Robot
{
  private:  // Member variables
    double speed;
    double diameter;
  public:   // Member functions and specifications.
    Robot() // RPM and diamater.
    {
      speed = 74;
      diameter = 1;
    }
// Reassigns speed with new RPM if value is either 74, 190, or 265.
    void setRPM(double newRPM)
    {
      if (newRPM == 74 || newRPM == 190 || newRPM == 265)
          speed = newRPM;
    }
    // Reassigns diameter if new value is between 1 and 6 inclusive.
    void setDiameter(double newDiameter)
    {
      if (newDiameter >= 1 && newDiameter <= 6)
        diameter = newDiameter;
    }
    double getRPM() // Returns speed value.
    {
      return speed;
    }
    double getDiameter()  // Returns diameter value.
    {
      return diameter;
    }
    double getSpeed()     // Converts RPM to ft./min.
    {
      speed = (speed * diameter * 3.14159) / 12;
      return speed;
    }
};
// Main function where the class member functions are tested.
int main()
{
  Robot obj1;   // Arbitrary Robot class object.
  double test;  // Arbitrary test variable.
  double test2; // Arbitrary test variable.
  // Displays current RPM and diameter, showing that the Robot()
  // constructor, getRPM, getDiameter, and getSpeed member functions are
  // "functioning".
  cout << "The initialized robot speed (RPM): " << obj1.getRPM() << endl;
  cout << "The initialized wheel diameter (in.): " << obj1.getDiameter() << endl;
  cout << "Initial speed (ft/min.): " << obj1.getSpeed() << endl;
  // Tests the setRPM member function by only reassigning if value input
  // is either 74, 190, or 265.
  cout << "Enter new RPM: " << endl;
  cin >> test2;
  obj1.setRPM(test2);
  cout << "Display new RPM: " << obj1.getRPM() << endl;
  // Tests the setDiameter member function by only reassigning if value
  // input is between 1 and 6 includsive.
  cout << "Enter new diameter (in.): " << endl;
  cin >> test;
  obj1.setDiameter(test);
  cout << "Display new diameter (in.): " << obj1.getDiameter() << endl;
  // Shows one final time that the getSpeed member function works -
  // recalculating the speed in ft/min. in case speed and/or diameter
  // were reassigned with valid values.
  cout << "Speed (ft/min.): " << obj1.getSpeed() << endl;
  // Final arbitrary input so that the program doesn't close immediately.
  cin >> test;
  return 0;
}