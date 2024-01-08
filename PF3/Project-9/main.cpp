#include <iostream>
#include <string>
#include "ArrayMaxHeap.h"
using namespace std;

int main()
{
   ArrayMaxHeap<int> *heap1Ptr = new ArrayMaxHeap<int>(); 
   heap1Ptr->add(50);
   heap1Ptr->add(10);
   heap1Ptr->add(40);
   heap1Ptr->add(30);
   heap1Ptr->add(60);
   heap1Ptr->add(20);
   
   cout << "Heap 1: " << endl;
   while (!heap1Ptr->isEmpty())
   {
      cout << "# of nodes: " << heap1Ptr->getNumberOfNodes() << endl;
      cout << "Height: "     << heap1Ptr->getHeight() << endl;
      cout << "max value: "  << heap1Ptr->peekTop() << endl;
      cout << "remove: "     << (heap1Ptr->remove()? "success": "failure\n") << endl << endl;
   }

   return 0;
}  // end main