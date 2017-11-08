#ifndef DEQUE_H
#define DEQUE_H

#include<stdexcept>
using std::out_of_range;
#include "block.h"

template<typename generic>
class Deque
{
 public:
  Deque();
  Deque(unsigned int n);
  Deque(Deque& d);
  ~Deque();
  void push_front(generic x);
  void pop_front();
  void push_back(generic x);
  void pop_back();
  void clear();
  Deque& operator=(const Deque& d);
  generic& operator[](unsigned int p);
  const generic& operator[](unsigned int p) const;
  unsigned int size() const;
  unsigned int block_size() const;
  bool empty() const;

 private:
  Block<generic>** m_data;
  unsigned int m_size;
  unsigned int m_blocks;
  unsigned int m_block_size;
};

#include"deque.hpp"
#endif

