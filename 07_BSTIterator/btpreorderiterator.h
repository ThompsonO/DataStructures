/*  
  File: btpreorderiterator.h
  Author: Oliver Thompson
  Iterates through binary trees in the order inserted

  Class: BTPreorderIterator
  Used for creating Preorder Iterators

  Constructor: BTPreorderIterator()
  Initializes m_current to null.

  Copy Constructor: BTPreorderIterator(BTN* x)
  Makes a new iterator starting at a specified node.

    Parameters:
    x - The node to start at.

  Function: const generic& operator*()
  Returns data of the current node.

  Function: BTPreorderIterator<generic> operator++()
  Pre-increment moves m_current to the next inserted node.

  Function: BTPreorderIterator<generic> operator++(int)
  Post-increment moves m_current to the next inserted node.

    Parameters:
    int is a dummy variable to distinguish pre and post increments.

  Function: bool operator==(const BTPreorderIterator& x) const
  Returns true if m_current is pointing at the same node as x

    Parameters:
    x - the pointer to be compared to

  Function: bool operator!=(const BTPreorderIterator& x) const
  Returns true if m_current is not pointing at the same node as x

    Parameters:
    x - the pointer to be compared to

*/
#ifndef BTPREORDERITERATOR_H
#define BTPREORDERITERATOR_H

#include"btn.h"

template<typename generic>
class BTPreorderIterator
{
  public:
    BTPreorderIterator();
    BTPreorderIterator(BTN<generic>*);
    const generic& operator*() const;
    BTPreorderIterator operator++();
    BTPreorderIterator operator++(int);
    bool operator==(const BTPreorderIterator<generic>&) const;
    bool operator!=(const BTPreorderIterator<generic>&) const;

  private:
    BTN<generic>* m_current;
};

#include"btpreorderiterator.hpp"
#endif

