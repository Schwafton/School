/** Interface for the ADT BST (Binary Search Tree)
    @file BSTInterface.h */

#ifndef BST_INTERFACE
#define BST_INTERFACE

template<class ItemType>
class BSTInterface
{
public:
   /** Test if the BST is empty
    @return true if this BST is empty; otherwise return false */
  virtual bool isEmpty() const = 0;

   /** Search the BST for an item
    @rturn true if item found, and false otherwise */
  virtual bool contains(const ItemType & item) const = 0; 

   /* Add an item to the BST.
    @return true if item was successfull inserted; otherwise
        returns false (if item was already in the binary search tree) */
  virtual bool add(const ItemType & item) = 0;

   /* Remove an item from the nBST.
    @return true if item was successfully removed;
        otherwise return false. */ 
  virtual bool remove(const ItemType & item) = 0;

  /* Perform an inorder traversal of the BST, displaying each entry */ 
  virtual void inorder(ostream & out) const = 0;

  /* Display the BST in graphical format */ 
  virtual void graph(ostream & out) const = 0;

  /** Destroys object and frees memory allocated by object. */
  virtual ~BSTInterface() {  }

  /* Return height of the BST. 
    @return BST heifht. */
  virtual int getHeight() const = 0;

  /* Return number of nodes in BST.
    @return number of nodes in BST.*/
  virtual int getNumberOfNodes() const = 0;

  /* Return number of leaves in BST.
    @return number of leaves in BST.*/
  virtual int getNumberOfLeaves() const = 0;

}; // end of BSTInterface
#endif