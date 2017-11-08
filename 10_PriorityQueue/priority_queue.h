/*
  Programmer: Oliver Thompson
  File: priority_queue.h
  Creates Priority Queues

  Class: Priority_queue
  Creates priority queues of data with the largest piece of data at the root.
  
  Function: Priority_queue()
  Creates an empty priority queue of data.

  Function: Priority_queue(const Priority_queue& x)
  Creates a new priority queue and copies the data of x into it.
  
    Parameters:
    x - The priority queue to be copied.

  Function: Priority_queue operator=(const Priority_queue& rhs)
  Returns a copy of the priority queue.
  
    Parameters:
    rhs - The data item to be compared to.

  Function: void push(generic x)
  Inserts data into the priority queue, and moves it until its parent
  is greater than the data.
  
    Parameters:
    x - The data item to be inserted.
    
  Function: void pop()
  Removes the largest piece of data from the priority queue and replaces
  it with the next largest piece of data.

  Function: const generic& top() const
  Returns the largest piece of data in the priority queue.

  Function: void heapPush()
  Moves newly added data to its proper place within the priority queue.

  Function: void heapPop()
  Moves data in to replace newly removed data within the priority queue.

  Function: void locate_pointers()
  Locates where the private pointers m_push and m_pop are located after various
  function calls.

  Function: BTN<generic>* find_pointers(BTN<generic>* x, int n)
  Used within the locate_pointers function to help find the locations of m_push
  and m_pop.
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include"bt.h"
#include"btn.h"

template<typename generic>
class Priority_queue : public BT<generic>
{
 public:
  Priority_queue();
  Priority_queue(const Priority_queue &);
  Priority_queue& operator=(const Priority_queue &);
  void push(generic);      
  void pop();
  const generic& top() const;

 private:
  BTN<generic>* m_push;
  BTN<generic>* m_pop;
  using BT<generic>::m_root;
  using BT<generic>::m_size;
  void heapPush();
  void heapPop();
  void locate_pointers();
  BTN<generic>* find_pointers(BTN<generic>* x, int n);
};

#include"priority_queue.hpp"
#endif

