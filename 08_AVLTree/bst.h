/*
  File: bst.h
  Author: Oliver Thompson
  Creates Binary Search Trees of data

  Class: BST
  A binary search tree container.
  
  Function: void insert(generic x)
  Inserts a node containing the data item x into the tree.  If x already exists
  within the tree, then the request is ignored.
  
    Parameters:
    x - The data item to be inserted.
    
  Function: void remove(generic x)
  Removes the node containing the data item x from the tree.  If x does not
  exist within the tree, then the request is ignored.
  
    Parameters:
    x - The data item to be removed.
  
  Function: PreOrder pre_search(generic x)
  Places a pre-order iterator at the location of the node containing x.  If x
  can not be found within the tree, an empty iterator is returned. 
  
    Parameters:
    x - The data to locate within the tree.
    
    Returns:
    A pre-order iterator at the node containing x.

  Function: InOrder in_search(generic x)
  Places an in-order iterator at the location of the node containing x.  If x
  can not be found within the tree, an empty iterator is returned. 
  
    Parameters:
    x - The data to locate within the tree.
    
    Returns:
    An in-order iterator at the node containing x.

  Function: PostOrder post_search(generic x)
  Places a post-order iterator at the location of the node containing x.  If x
  can not be found within the tree, an empty iterator is returned. 
  
    Parameters:
    x - The data to locate within the tree.
    
    Returns:
    A post-order iterator at the node containing x.
*/
#ifndef BST_H
#define BST_H

#include<iostream>
#include"bt.h"
#include"btn.h"

template<typename generic>
class BST : public BT<generic>
{
 public:
  void insert(generic x);      
  void remove(generic x);
  typedef BTPreorderIterator<generic> PreOrder;
  typedef BTInorderIterator<generic> InOrder;
  typedef BTPostorderIterator<generic> PostOrder;
  PreOrder pre_search(generic x);
  InOrder in_search(generic x);
  PostOrder post_search(generic x);

 protected:
  BTN<generic>* p_insert(generic x);// returns a pointer to the new node
  BTN<generic>* p_remove(generic x);// returns a pointer to the parent of the deleted node 
  BTN<generic>* p_search(generic x);// returns a pointer to where x is found

 private:
  BTN<generic>* kill(BTN<generic>* x);
  using BT<generic>::m_size;
  using BT<generic>::m_root;
};

#endif

