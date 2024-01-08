/* BST.h contains the declaration of class template BST.
   Basic operations:
     Constructor:             Constructs an empty BST
     isEmpty:                 Checks if a BST is empty
     contains:                Search a BST for an item
     add:                     Adds a value into a BST
     remove:                  Removes a value from a BST
     inorder:                 Inorder traversal of a BST -- output the item values
     graph:                   Output a grapical representation of a BST
   Private utility helper operations:
     search2:                 Used by delete
     inorderAux:              Used by inorder
     graphAux:                Used by graph
     getHeightHelper:         Used by getHeight
     getNumberOfNodesHelper:  Used by getNumberOfNodes
     getNumberOfLeavesHelper: Used by getNumberOfLeaves
   Other operations described in the exercises:
     destructor
     copy constructor
     assignment operator
     preorder, postorder, and level-by-level traversals
     level finder
   Note: Execution terminates if memory isn't available for a new BST node.
---------------------------------------------------------------------------*/



#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include "BinaryNode.h"
#include "BSTInterface.h"

template<class ItemType>
class BST : public BSTInterface<ItemType>
{
 public:
  /***** Function Members *****/
  BST();
  /*------------------------------------------------------------------------
    Construct a BST object.

    Precondition:  None.
    Postcondition: An empty BST has been constructed.
   -----------------------------------------------------------------------*/
   
   ~BST();

  bool isEmpty() const;
  /*------------------------------------------------------------------------
    Check if BST is empty.

    Precondition:  None.
    Postcondition: Returns true if BST is empty and false otherwise.
   -----------------------------------------------------------------------*/

  bool contains(const ItemType & item) const; 
  /*------------------------------------------------------------------------
    Search the BST for item.

    Precondition:  None.
    Postcondition: Returns true if item found, and false otherwise.
   -----------------------------------------------------------------------*/
   
  bool add(const ItemType & item);
  /*------------------------------------------------------------------------
    Add item into BST.

    Precondition:  None.
    Postcondition: BST has been modified with item inserted at proper 
        position to maintain BST property. 
        Returns true if item was successfull inserted.
        Returns false if item was already in the binary search tree
  ------------------------------------------------------------------------*/
  
  bool remove(const ItemType & item);
  /*------------------------------------------------------------------------
    Remove item from BST.

    Precondition:  None.
    Postcondition: BST has been modified with item removed (if present);
        BST property is maintained.
        Returns true if item was successfully removed.
        Otherwise, returns false.
    Note: remove uses auxiliary function search2() to locate the node
          containing item and its parent.
 ------------------------------------------------------------------------*/
 
  void inorder(ostream & out) const;
  /*------------------------------------------------------------------------
    Inorder traversal of BST.

    Precondition:  ostream out is open.
    Postcondition: BST has been inorder traversed and values in nodes 
        have been output to out.
    Note: inorder uses private auxiliary function inorderAux().
 ------------------------------------------------------------------------*/
 
  void graph(ostream & out) const;
  /*------------------------------------------------------------------------
    Graphic output of BST.

    Precondition:  ostream out is open.
    Postcondition: Graphical representation of BST has been output to out.
    Note: graph() uses private auxiliary function graphAux().
 ------------------------------------------------------------------------*/
 
   int getHeight() const;
  /*------------------------------------------------------------------------
    Get height of BST.

    Precondition:  None
    Postcondition: Returns height of BST.
    Note: 
 ------------------------------------------------------------------------*/

   int getNumberOfNodes() const;
  /*------------------------------------------------------------------------
    Get number of nodes in BST.

    Precondition:  None.
    Postcondition: Returns number of nodes in BST.
    Note: 
 ------------------------------------------------------------------------*/

   int getNumberOfLeaves() const;
  /*------------------------------------------------------------------------
    Get number of leaves in BST.

    Precondition:  None.
    Postcondition: Returns number of leaves in BST.
    Note: 
 ------------------------------------------------------------------------*/

 private:
  
  void destroyTree(BinaryNode<ItemType> *subTreePtr);


  bool search(const ItemType & item) const; 
  /*------------------------------------------------------------------------
    Search the BST for item.

    Precondition:  None.
    Postcondition: Returns true if item found, and false otherwise.
   -----------------------------------------------------------------------*/

  /***** Private Function Members *****/
  void search2(const ItemType & item, bool & found,
               BinaryNode<ItemType>* & locptr, BinaryNode<ItemType>* & parent) const;
 /*------------------------------------------------------------------------
   Locate a node containing item and its parent.
 
   Precondition:  None.
   Postcondition: locptr points to node containing item or is null if 
       not found, and parent points to its parent.#include <iostream>
 ------------------------------------------------------------------------*/
 
  void inorderAux(ostream & out, 
                  BinaryNode<ItemType>* subtreePtr) const;
  /*------------------------------------------------------------------------
    Inorder traversal auxiliary function.

    Precondition:  ostream out is open; subtreePtr points to a subtree 
        of this BST.
    Postcondition: Subtree with root pointed to by subtreePtr has been
        output to out.
 ------------------------------------------------------------------------*/
 
  void graphAux(ostream & out, int indent,
                      BinaryNode<ItemType>* subtreeRoot) const;
  /*------------------------------------------------------------------------
    Graph auxiliary function.

    Precondition:  ostream out is open; subtreePtr points to a subtree 
        of this BST.
    Postcondition: Graphical representation of subtree with root pointed 
        to by subtreePtr has been output to out, indented indent spaces.
 ------------------------------------------------------------------------*/
 
  int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
  /*------------------------------------------------------------------------
  getHeight auxiliary function.

  Precondition:  subtreePtr points to a subtree of this BST.
  Postcondition: Height of the BST.
------------------------------------------------------------------------*/

  int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
  /*------------------------------------------------------------------------
  getNumberOfNodes auxiliary function.

  Precondition:  subtreePtr points to a subtree of this BST.
  Postcondition: Number of nodes in the BST.
------------------------------------------------------------------------*/

  int getNumberOfLeavesHelper(BinaryNode<ItemType>* subTreePtr) const;
  /*------------------------------------------------------------------------
  getNumberOfLeaves auxiliary function.

  Precondition:  subtreePtr points to a subtree of this BST.
  Postcondition: Number of leaves in the BST.
------------------------------------------------------------------------*/


 /***** Data Members *****/
  BinaryNode<ItemType>* myRoot; 

}; // end of class template declaration

//--- Definition of constructor
template <typename ItemType>
BST<ItemType>::BST()
: myRoot(nullptr)
{}

template<class ItemType>
BST<ItemType>::~BST()
{
   destroyTree(myRoot);
}  // end destructor

template<class ItemType>
void BST<ItemType>::destroyTree(BinaryNode<ItemType> *subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      delete subTreePtr;
      subTreePtr = nullptr;
   }  // end if
}  // end destroyTree

//--- Definition of empty()
template <typename ItemType>
bool BST<ItemType>::isEmpty() const
{ return myRoot == nullptr; }

//--- Definition of contains()
template <typename ItemType>
bool BST<ItemType>::contains(const ItemType & anItem) const
{
	return search(anItem);
}

//--- Definition of search()
template <typename ItemType>
bool BST<ItemType>::search(const ItemType & anItem) const
{
   BinaryNode<ItemType> *locptr = myRoot;
   bool found = false;
   while (!found && locptr != nullptr)
   {
      if (anItem < locptr->getItem())       // descend left
        locptr = locptr->getLeftChildPtr();
      else if (locptr->getItem() < anItem)  // descend right
        locptr = locptr->getRightChildPtr();
      else                           // item found
        found = true;
   }
   return found;
}

//--- Definition of add()
template <typename ItemType>
bool BST<ItemType>::add(const ItemType & anItem)
{
   BinaryNode<ItemType>* locptr = myRoot;   // search pointer
   BinaryNode<ItemType>* parent = nullptr;        // pointer to parent of current node
   bool found = false;     // indicates if anItem already in BST
   while (!found && locptr != nullptr)
   {
      parent = locptr;
      if (anItem < locptr->getItem())       // descend left
         locptr = locptr->getLeftChildPtr();
      else if (locptr->getItem() < anItem)  // descend right
         locptr = locptr->getRightChildPtr();
      else                           // anItem found
         found = true;
   }
   if (!found)
   {                                 // construct node containing anItem
      locptr = new BinaryNode<ItemType>(anItem);  
      if (parent == nullptr)               // empty tree
         myRoot = locptr;
      else if (anItem < parent->getItem() )  // insert to left of parent
         parent->setLeftChildPtr(locptr);
      else                           // insert to right of parent
         parent->setRightChildPtr(locptr);
   }
   return found;
}

//--- Definition of remove()
template <typename ItemType>
bool BST<ItemType>::remove(const ItemType & anItem)
{
   bool found;                      // signals if anItem is found
   BinaryNode<ItemType>* x;                            // points to node to be deleted
   BinaryNode<ItemType>* parent;                       //    "    " parent of x and xSucc
   search2(anItem, found, x, parent);

   if (!found)
   {
      return false;
   }
   //else
   if (x->getLeftChildPtr() != nullptr && x->getRightChildPtr() != nullptr)
   {                                // node has 2 children
      // Find x's inorder successor and its parent
      BinaryNode<ItemType> *xSucc = x->getRightChildPtr();
      parent = x;
      while (xSucc->getLeftChildPtr() != nullptr)       // descend left
      {
         parent = xSucc;
         xSucc = xSucc->getLeftChildPtr();
      }

     // Move contents of xSucc to x and change x 
     // to point to successor, which will be removed.
     x->setItem(xSucc->getItem());
     x = xSucc;
   } // end if node has 2 children

   // Now proceed with case where node has 0 or 2 child
   BinaryNode<ItemType>* subtree = x->getLeftChildPtr();             // pointer to a subtree of x
   if (subtree == nullptr)
      subtree = x->getRightChildPtr();
   if (parent == nullptr)                  // root being removed
      myRoot = subtree;
   else if (parent->getLeftChildPtr() == x)       // left child of parent
      parent->setLeftChildPtr(subtree); 
   else                              // right child of parent
      parent->setRightChildPtr(subtree);
   delete x;
   
   return true;
}

//--- Definition of inorder()
template <typename ItemType>
void BST<ItemType>::inorder(ostream & out) const
{ 
   inorderAux(out, myRoot); 
}

//--- Definition of graph()
template <typename ItemType>
void BST<ItemType>::graph(ostream & out) const
{ graphAux(out, 0, myRoot); }

//--- Definition of search2()
template <typename ItemType>
void BST<ItemType>::search2(const ItemType & anItem, bool & found,
                            BinaryNode<ItemType>* & locptr, 
                            BinaryNode<ItemType>* & parent) const
{
   locptr = myRoot;
   parent = nullptr;
   found = false;
   while (!found && locptr != nullptr)
   {
      if (anItem < locptr->getItem())       // descend left
      {
         parent = locptr;
         locptr = locptr->getLeftChildPtr();
      }
      else if (locptr->getItem() < anItem)  // descend right
      {
         parent = locptr;
         locptr = locptr->getRightChildPtr();
      }
      else                           // anItem found
         found = true;
   }
}

//--- Definition of inorderAux()
template <typename ItemType>
void BST<ItemType>::inorderAux(ostream & out, 
                               BinaryNode<ItemType>* subtreeRoot) const
{
   if (subtreeRoot != nullptr)
   {
      inorderAux(out, subtreeRoot->getLeftChildPtr());    // L operation
      out << subtreeRoot->getItem() << "  ";      // V operation
      inorderAux(out, subtreeRoot->getRightChildPtr());   // R operation
   }
}

//--- Definition of graphAux()
#include <iomanip>

template <typename ItemType>
void BST<ItemType>::graphAux(ostream & out, int indent, 
                             BinaryNode<ItemType>* subtreeRoot) const
{
  if (subtreeRoot != nullptr)
    {
      graphAux(out, indent + 8, subtreeRoot->getRightChildPtr());
      out << setw(indent) << " " << subtreeRoot->getItem() << endl;
      graphAux(out, indent + 8, subtreeRoot->getLeftChildPtr());
    }
}

//--- Definition of getHeightHelper()
template <typename ItemType>
int BST<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if (subTreePtr == nullptr)
    return 0;
  else
  {
    return (1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr())));
  }
}

//--- Definition of getNumberOfNodesHelper()
template <typename ItemType>
int BST<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if (subTreePtr == nullptr)
    return 0;
  else
    return (1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfLeavesHelper(subTreePtr->getRightChildPtr()));
}

//--- Definition of getNumberOfLeavesHelper()
template <typename ItemType>
int BST<ItemType>::getNumberOfLeavesHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if (subTreePtr == nullptr)
    return 0;
  else if ((subTreePtr->getLeftChildPtr() == nullptr) && (subTreePtr->getRightChildPtr() == nullptr))
    return 1;
  else
    return (getNumberOfLeavesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfLeavesHelper(subTreePtr->getRightChildPtr()));
}

//--- Definition of getHeight()
template <typename ItemType>
int BST<ItemType>::getHeight() const
{
  return getHeightHelper(myRoot);
}

//--- Definition of getNumberOfNodes()
template <typename ItemType>
int BST<ItemType>::getNumberOfNodes() const
{
  return getNumberOfNodesHelper(myRoot);
}

//--- Definition of getNumberOfLeaves
template <typename ItemType>
int BST<ItemType>::getNumberOfLeaves() const
{
  return getNumberOfLeavesHelper(myRoot);
}

#endif