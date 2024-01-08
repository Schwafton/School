//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Header file for an array-based implementation of the ADT set.
 @file ArraySet.h */

#ifndef ARRAY_SET_
#define ARRAY_SET_

#include "SetInterface.h"

template<class ItemType>
class ArraySet : public SetInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full set
	ItemType items[DEFAULT_CAPACITY];      // Array of set items
  int itemCount;                         // Current count of set items 
  int maxItems;                          // Max capacity of the set
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	ArraySet();
  ArraySet(ItemType [], int);
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
}; // end ArraySet

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class ArraySet.
 @file ArraySet.cpp */

#include <cstddef>

/** Default Constructor */
template<class ItemType>
ArraySet<ItemType>::ArraySet(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
  ItemType items[DEFAULT_CAPACITY] = {};
}  // end default constructor

/** Constructor that uses the array elements to intitialize the set.
@param arr[]  An array of ItemType elements.
@param k  An integer number of elements in the array. 
@post Initializes instance of a set with ItemType elements from the ItemType array.
@pre Duplicate elements are prohibited from being added.*/
template<class ItemType>
ArraySet<ItemType>::ArraySet(ItemType arr[], int k)
{
  ArraySet();
  for (int i = 0; i < k; i++)
    add(arr[i]);
}   // end constructor

template<class ItemType>
int ArraySet<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArraySet<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArraySet<ItemType>::add(const ItemType& newEntry)
{
  if (!contains(newEntry))
  {
    items[itemCount] = newEntry;
    itemCount++;
    return 1;
  }
  else if (contains(newEntry))
    return 1;
  else
    return 0;
} // end add

template<class ItemType>
bool ArraySet<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArraySet<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
bool ArraySet<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArraySet<ItemType>::toVector() const
{
   std::vector<ItemType> setContents;
	for (int i = 0; i < itemCount; i++)
		setContents.push_back(items[i]);
      
   return setContents;
}  // end toVector

// private
template<class ItemType>
int ArraySet<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the set is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
#endif