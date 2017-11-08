/*  
  File: bst.h
  Author: Oliver Thompson
  Creates Binary Search Trees of data

  Class: BST
  Used for creating binary search trees of data

  Function: void insert(generic x)
  Inserts data into the tree.

    Parameters:
    x - The data to be inserted.

  Function: void remove(generic x)
  Removes data from the tree.

    Parameters:
    x - The data to be removed.

  Function: PreOrder pre_search(generic x)
  Searches for data in the tree using a preorder iterator,
  returns a pointer pointing at the data.

    Parameters:
    x - The data to be searched.

  Function: InOrder in_search(generic x)
  Searches for data in the tree using an inorder iterator,
  returns a pointer pointing at the data.

    Parameters:
    x - The data to be searched.

  Function: PostOrder post_search(generic x)
  Searches for data in the tree using a postorder iterator,
  returns a pointer pointing at the data.

    Parameters:
    x - The data to be searched.
*/
#ifndef BST_H
#define BST_H

#include"bt.h"
#include"btn.h"
template<typename generic>
class BST : public BT<generic>
{
  public:
    void insert(generic);
    void remove(generic);
    typedef BTPreorderIterator<generic> PreOrder;
    typedef BTInorderIterator<generic> InOrder;
    typedef BTPostorderIterator<generic> PostOrder;
    PreOrder pre_search(generic);
    InOrder in_search(generic);
    PostOrder post_search(generic);

  private:
    using BT<generic>::m_size;
    using BT<generic>::m_root;
};

#include"bst.hpp"
#endif

