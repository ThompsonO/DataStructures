/*  
  File: bst.h
  Author: Oliver Thompson
  Creates Binary Search Trees of data

  Class: BST
  Used for creating binary search trees of data

  Constructor: BST()
  Initializes the size to 0 and the root to null.

  Destructor: ~BST()
  Deletes the entire contents of the tree.

  Function: void insert(generic x)
  Inserts data into the tree.

    Parameters:
    x - The data to be inserted.

  Function: void remove(generic x)
  Removes data from the tree.

    Parameters:
    x - The data to be removed.

  Function: bool search(generic x) const
  Searches for data in the tree, and returns true if it exists.

    Parameters:
    x - The data to be searched.

  Function: void clear()
  Deletes all data in the tree.

  Function: bool empty() const
  Returns if there is no data in the tree.

  Function: unsigned int size() const
  Returns the number of elements in the tree.
*/
#ifndef BST_H
#define BST_H

#include"btn.h"
template<typename generic>
class BST
{
  public:
    BST();
    ~BST();
    void insert(generic x);
    void remove(generic x);
    bool search(generic x) const;
    void clear();
    bool empty() const;
    unsigned int size () const;

  private:
    unsigned int m_size;
    BTN<generic>* m_root;
};

#include"bst.hpp"
#endif

