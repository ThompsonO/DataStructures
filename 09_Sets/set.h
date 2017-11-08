/*
  Programmer: Oliver Thompson
  File: set.h
  Creates sets of data

  Class: Set
  Creates sets of data that can be maniuplated as such.
  
  Function: Set()
  Creates an empty set of data

  Function: Set(const Set& x)
  Creates a new set and copies the data of x into it
  
    Parameters:
    x - The set to be copied.

  Function: Set operator=(const Set& rhs)
  Returns a copy of the set
  
    Parameters:
    rhs - The data item to be compared to.

  Function: Set operator+(const Set& rhs) const
  Returns the union of the sets, being all data items from both sets
  
    Parameters:
    rhs - The data item to be compared to.

  Function: Set operator*(const Set& rhs) const
  Returns the intersection of the sets, being only what is in both sets
  
    Parameters:
    rhs - The data item to be compared to.

  Function: Set operator-(const Set& rhs) const
  Returns the difference of the sets, being what is in the origional set and
  not the second
  
    Parameters:
    rhs - The data item to be compared to.

  Function: void insert(generic x)
  Inserts data into the set, if the data already exists the insert is ignored
  
    Parameters:
    x - The data item to be inserted.
    
  Function: void erase(generic x)
  Erases the data from the set, if the data does not exist the erase is ignored
  
    Parameters:
    x - The data item to be removed.
  
  Function: void clear()
  Deletes the entire set and leaves it empty
  
  Function: bool empty() const
  Returns true if the set is empty, otherwise returns false.

  Function: unsigned int  size() const
  Returns the number of data items in the set

  Function: Iterator find(generic x)
  Returns a data pointer to the data node if it is in the set, otherwise
  a pointer is returned where the node's parent would be.

    Parameters:
    x - The data item to be located.

  Function: Iterator begin() const
  Returns a pointer to the lowest valued data item in the set.

  Function: Iterator end() const
  Returns a pointer to the highest valued data item in the set.
*/

#ifndef SET_H
#define SET_H
#include"avl.h"
#include"btinorderiterator.h"

template<typename generic>
class Set : private AVL<generic>
{
 public:
  Set();
  Set(const Set&);
  Set& operator=(const Set&);
  Set operator+(const Set&) const;
  Set operator*(const Set&) const;
  Set operator-(const Set&) const;
  void insert(generic);
  void erase(generic);
  void clear();
  bool empty() const;
  unsigned int size() const;
  typedef BTInorderIterator<generic> Iterator;
  Iterator find(generic);
  Iterator begin() const;
  Iterator end() const;
};

#include"set.hpp"
#endif

