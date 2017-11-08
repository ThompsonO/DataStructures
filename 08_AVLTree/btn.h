/*
  File: btn.h
  Author: Oliver Thompson
  Creates binary tree nodes

  Class: BTN
  A binary tree node.
  
  Constructor: BTN(generic pd, unsigned int* ps)
  Initializes the parent(p), left child(l), and right child(r) pointers to 
  NULL.  Directs the data pointer(d) to a new generic object and stores the
  value of pd inside of it.  Directs the tree size pointer(s) to point to ps,
  and increments the tree size by one.  Sets the number of instances(n) to 0.
  
    Parameters:
    pd - The data to be stored inside of the binary tree node.
    ps - Points to the calling tree's size counter.
    
  Constructor: BTN(BTN* pp, BTN* pl, BTN* pr, generic pdata, unsigned int* ps)
  Initializes the parent pointer(p) to pp, left child pointer(l) to pl, and the
  right child pointer(r) to pr.  Directs the data pointer(d) to a new generic
  object and stores the value of pd inside of it.  Directs the tree size
  pointer(s) to point to ps, and increments the tree size by one.  Sets the
  number of instances(n) to 0.
  
    Parameters:
    pp - Indicates where to point the parent pointer(p).
    pl - Indicates where to point the left child pointer(l).
    pr - Indicates where to point the right child pointer(r).
    pd - The data to be stored inside of the binary tree node.
    ps - Points to the calling tree's size counter.
    
  Destructor: ~BTN()
  Decrements the tree counter and releases the memory at the data pointer.
  
  Function: void set_r(BTN* pchild)
  Sets the right child pointer(r) to pchild.  Then directs pchild's parent to 
  point back to this node.
  
    Parameters:
    pchild - Indicates where to connect the right child pointer(r).
  
  Function: void set_l(BTN* pchild)
  Sets the left child pointer(l) to pchild.  Then directs pchild's parent to 
  point back to this node.
  
    Parameters:
    pchild - Indicates where to connect the left child pointer(l).
  
  Function: void swap_data(BTN* px)
  Redirects the node's data pointer(d) to point to the data in px and redirects
  px's data pointer to point to the data in this node.
  
    Parameters:
    px - Swaps data with this node.
*/
#ifndef BTN_H
#define BTN_H

template<typename generic>
class BTN
{
 public:
  BTN(generic pd, unsigned int* ps);
  BTN(BTN* pp, BTN* pl, BTN* pr, generic pd, unsigned int* ps);
  ~BTN ();
  void set_r(BTN* pchild);
  void set_l(BTN* pchild);
  void swap_data(BTN* px);
  BTN* p;
  BTN* l;
  BTN* r;
  generic* d;
  unsigned int* s;
  unsigned int depth;
};

#endif

