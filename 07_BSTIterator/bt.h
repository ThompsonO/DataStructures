/*  
  File: bt.h
  Author: Oliver Thompson
  Creates Binary Trees of data.

  Class: BT
  Used for creating binary trees of data.

  Constructor: BST()
  Initializes the size to 0 and the root to null.

  Copy Constructor: BT(const BT& c)
  Makes a new binary tree the same as c.

    Parameters:
    c - the tree to be copied.

  Destructor: ~BST()
  Deletes the entire contents of the tree.

  Function: BT& operator=(const BT& rhs)
  Makes the tree the same as rhs.

    Parameters:
    rhs - the tree to be copied.

  Function: void clear()
  Deletes all data in the tree.

  Function: bool empty() const
  Returns true if there is no data in the tree.

  Function: unsigned int size() const
  Returns the number of elements in the tree.

  Function: PreOrder pre_begin() const
  returns a pointer where the preorder iterator should start on the tree.

  Function: PreOrder pre_end() const
  returns a pointer where the preorder iterator should end on the tree.

  Function: InOrder in_begin() const
  returns a pointer where the inorder iterator should start on the tree.

  Function: InOrder in_end() const
  returns a pointer where the inorder iterator should end on the tree.

  Function: PostOrder post_begin() const
  returns a pointer where the postorder iterator should start on the tree.

  Function: PostOrder post_end() const
  returns a pointer where the postorder iterator should end on the tree.
*/
#ifndef BT_H
#define BT_H

#include"btn.h"
#include"btpreorderiterator.h"
#include"btinorderiterator.h"
#include"btpostorderiterator.h"

template<typename generic>
class BT
{
  public:
    BT();
    BT(const BT& c);
    ~BT();
    BT& operator=(const BT& rhs);
    void clear();
    bool empty() const;
    unsigned int size() const;

    typedef BTPreorderIterator<generic> PreOrder;
    typedef BTInorderIterator<generic> InOrder;
    typedef BTPostorderIterator<generic> PostOrder;
    PreOrder pre_begin() const;
    PreOrder pre_end() const;
    InOrder in_begin() const;
    InOrder in_end() const;
    PostOrder post_begin() const;
    PostOrder post_end() const;

  protected:
    BTN<generic>* m_root;
    unsigned int m_size;

  private:
    void lumberjack(BTN<generic>* axe);
};

#include"bt.hpp"
#endif

