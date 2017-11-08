/*
  File: queue.h
  Author: Oliver Thompson
  Queue Class

  Class: Queue
  A doubly-linked list container.

  Constructor: Queue()
  Initializes the size to 0 and the front and back to null.

  Constructor: Queue(const Queue& q)
  Clears the contents of the queue and then creates a duplicate of q.

    Parameters:
    q - The queue to be copied.

  Destructor: ~Queue()
  Deletes the entire contents of the queue.

  Function: void push(generic x)
  Inserts the data item x to the back of the queue.

    Parameters:
    x - The data item to be inserted.

  Function: void pop()
  Removes a data item from the front of the queue. If there are no items to
  remove, then the function does nothing.

  Function: generic& front()
  Retreives a writeable reference to the data item at the front of the queue. If
  the queue is empty then a standard out_of_range exception is thrown.

    Returns:
    A writeable reference to the queue's front data.

  Function: const generic& front() const
  Retreives a read-only reference to the data item at the front of the queue. If
  the queue is empty then a standard out_of_range exception is thrown.

    Returns:
    A read-only reference to the queue's front data.

  Function: generic& back()
  Retreives a writeable reference to the data item at the back of the queue. If
  the queue is empty then a standard out_of_range exception is thrown.

    Returns:
    A writeable reference to the queue's back data.

  Function: const generic& back() const
  Retreives a read-only reference to the data item at the back of the queue. If
  the queue is empty then a standard out_of_range exception is thrown.

    Returns:
    A read-only reference to the queue's back data.

  Function: void clear()
  Deletes the entire contents of the queue and sets size back to 0.

  Function: unsigned int size() const
  Reports the number of data items in the queue.

    Returns:
    The number of items stored in the queue.

  Function: bool empty() const
  Reports if the queue is holding data or is not holding any data.

    Returns:
    True if the queue has no data and false if it has data.

  Operator: Queue& operator=(const Queue& q)
  Clears the contents of the queue and then creates a duplicate of q.

    Parameters:
    q - The list to be replicated.

    Returns:
    A reference to the newly cloned queue.
*/
#ifndef QUEUE_H
#define QUEUE_H

#include"list.h"

template<typename generic>
class Queue : private List<generic>
{
 public:
  Queue();
  Queue(const Queue& q);
  ~Queue();
  Queue& operator=(const Queue& q);
  bool empty() const;
  unsigned int size() const;
  generic& front();
  generic& back();
  const generic& front() const;
  const generic& back() const;
  void push(generic x);
  void pop();
  void clear();
};

#include"queue.hpp"
#endif



