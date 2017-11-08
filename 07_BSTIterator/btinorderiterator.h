/*  
  File: btinorderiterator.h
  Author: Oliver Thompson
  Iterates through binary trees in order of value

  Class: BTInorderIterator
  Used for creating Inorder Iterators

  Constructor: BTInorderIterator()
  Initializes m_current to null.

  Copy Constructor: BTInorderIterator(BTN* x)
  Makes a new iterator starting at a specified node.

    Parameters:
    x - The node to start at.

  Function: const generic& operator*()
  Returns data of the current node.

  Function: BTInorderIterator<generic> operator++()
  Pre-increment moves m_current to the next greatest valued node.

  Function: BTInorderIterator<generic> operator++(int)
  Post-increment moves m_current to the next greatest vauled node.

    Parameters:
    int is a dummy variable to distinguish pre and post increments.

  Function: bool operator==(const BTInorderIterator& x) const
  Returns true if m_current is pointing at the same node as x

    Parameters:
    x - the pointer to be compared to

  Function: bool operator!=(const BTInorderIterator& x) const
  Returns true if m_current is not pointing at the same node as x

    Parameters:
    x - the pointer to be compared to

*/
#ifndef BTINORDERITERATOR_H
#define BTINORDERITERATOR_H

#include"btn.h"

template<typename generic>
class BTInorderIterator
{
  public:
    BTInorderIterator();
    BTInorderIterator(BTN<generic>*);
    const generic& operator*() const;
    BTInorderIterator operator++();
    BTInorderIterator operator++(int);
    bool operator==(const BTInorderIterator<generic>&) const;
    bool operator!=(const BTInorderIterator<generic>&) const;

  private:
    BTN<generic>* m_current;
};

#include"btinorderiterator.hpp"
#endif

