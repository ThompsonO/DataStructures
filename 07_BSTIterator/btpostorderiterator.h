/*  
  File: btpostorderiterator.h
  Author: Oliver Thompson
  Iterates through binary trees, first through the lowest level children,
  then the parents.

  Class: BTPostorderIterator
  Used for creating Postorder Iterators

  Constructor: BTPostorderIterator()
  Initializes m_current to null.

  Copy Constructor: BTPostorderIterator(BTN* x)
  Makes a new iterator starting at a specified node.

    Parameters:
    x - The node to start at.

  Function: const generic& operator*()
  Returns data of the current node.

  Function: BTPostorderIterator<generic> operator++()
  Pre-increment moves m_current to the next child node,
  otherwise moves to the parent.

  Function: BTPostorderIterator<generic> operator++(int)
  Post-increment moves m_current to the next child node,
  otherwise moves to the parent.

    Parameters:
    int is a dummy variable to distinguish pre and post increments.

  Function: bool operator==(const BTPostorderIterator& x) const
  Returns true if m_current is pointing at the same node as x

    Parameters:
    x - the pointer to be compared to

  Function: bool operator!=(const BTPostorderIterator& x) const
  Returns true if m_current is not pointing at the same node as x

    Parameters:
    x - the pointer to be compared to

*/
#ifndef BTPOSTORDERITERATOR_H
#define BTPOSTORDERITERATOR_H

#include"btn.h"

template<typename generic>
class BTPostorderIterator
{
  public:
    BTPostorderIterator();
    BTPostorderIterator(BTN<generic>*);
    const generic& operator*() const;
    BTPostorderIterator operator++();
    BTPostorderIterator operator++(int);
    bool operator==(const BTPostorderIterator<generic>&) const;
    bool operator!=(const BTPostorderIterator<generic>&) const;

  private:
    BTN<generic>* m_current;
};

#include"btpostorderiterator.hpp"
#endif

