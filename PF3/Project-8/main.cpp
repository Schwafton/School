#include <iostream>
#include "quickSort.cpp"

using namespace std;

int main()
{
  //Testing quicksort on an array of strings.
  cout << "Testing quicksort with an array of strings." << endl << "Creating an array of 26 strings. " << endl;
  string array[] = {"Q","A","Z","W","S","X","E","D","C","R","F","V","T","G","B","Y","H","N","U","J","M","I","K","L","O","P"};
  cout << "The array contains the following elements: " << endl;
  for (int i = 0; i < 26; i++)
    cout << array[i] << " ";
  cout << endl << "Array size: " << size(array) << endl << "Using quicksort on the array." << endl;
  quickSort(array, 0, 25);
  cout << "The array contains the following elements: " << endl;
  for (int i = 0; i < 26; i++)
    cout << array[i] << " ";
  cout << endl << "Array size: " << size(array) << endl << endl;

  //Testing quicksort on an array of integers.
  cout << "Testing quicksort with an array of integers." << endl << "Creating an array of 26 integers. " << endl;
  int array2[] = {22,11,6,8,2,18,21,17,3,20,26,13,10,9,25,15,16,23,7,1,4,19,24,12,14,5};
  cout << "The array contains the following elements: " << endl;
  for (int i = 0; i < 26; i++)
    cout << array2[i] << " ";
  cout << endl << "Array size: " << size(array2) << endl << "Using quicksort on the array." << endl;
  quickSort(array2, 0, 25);
  cout << "The array contains the following elements: " << endl;
  for (int i = 0; i < 26; i++)
    cout << array2[i] << " ";
  cout << endl << "Array size: " << size(array2) << endl << endl;
}