/*
  File: avl.h
  Author: Oliver Thompson
  Makes AVL Trees

  Class: AVL
  A self-balancing binary search tree.
  
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
  
  Function: bool unbalanced(BTN<generic>* x)
  Returns true if the depth of one child is more than 1 greater than the other
  
    Parameters:
    x - The node to check if it's balanced

  Function: int level(BTN<generic>* x)
  Returns an integer that is one greater than the level/depth of the greatest
  child node's level, leaf nodes are set to level 1.
  
    Parameters:
    x - The node whose level is to be calculated.

  Function: int balance(BTN<generic>* x)
  Returns an integer that is the difference between the node's right child's
  level and the left child's level
  
    Parameters:
    x - The node who's balance is to be calculated.

  Function: void rotate(BTN<generic>* x)
  Rotates the node passed in to balance the tree.
  
    Parameters:
    x - The node where the unbalance has occurred.

  Function: void rotate_pospos(BTN<generic>* x)
  Rotates the node passed in to balance the tree, where the imbalance is
  positive and the child has a positive balance.
  
    Parameters:
    x - The node where the unbalance has occurred.

  Function: void rotate_posneg(BTN<generic>* x)
  Rotates the node passed in to balance the tree, where the imbalance is
  positive and the child has a negative balance.
  
    Parameters:
    x - The node where the unbalance has occurred.

  Function: void rotate_negpos(BTN<generic>* x)
  Rotates the node passed in to balance the tree, where the imbalance is
  negative and the child has a positive balance.
  
    Parameters:
    x - The node where the unbalance has occurred.

  Function: void rotate_negneg(BTN<generic>* x)
  Rotates the node passed in to balance the tree, where the imbalance is
  negative and the child has a negative balance.
  
    Parameters:
    x - The node where the unbalance has occurred.
*/
#ifndef AVL_H
#define AVL_H

#include"bst.h"

template<typename generic>
class AVL : public BST<generic>
{
 public:
  void insert(generic x);
  void remove(generic x);

 private:
  bool unbalanced(BTN<generic>* temp);
  int level(BTN<generic>* lvl);
  int balance(BTN<generic>* x);
  void rotate(BTN<generic>* x);
  void rotate_pospos(BTN<generic>* x);
  void rotate_posneg(BTN<generic>* x);
  void rotate_negneg(BTN<generic>* x);
  void rotate_negpos(BTN<generic>* x);
  using BT<generic>::m_root;
};

#include"avl.hpp"
#endif

