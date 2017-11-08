#ifndef BLOCK_H
#define BLOCK_H

#include<stdexcept>
using std::out_of_range;
using std::invalid_argument;

template<typename generic>
class Block
{
 public:
  Block();
  Block(unsigned int n);
  Block(Block& b);
  Block& operator=(const Block& b);
  ~Block();
  void push_front(generic x);
  void pop_front();
  void push_back(generic x);
  void pop_back();
  void clear();
  generic& operator[](unsigned int p);
  const generic& operator[](unsigned int p) const;
  unsigned int size() const;
  unsigned int max_size() const;
  bool ffull() const;
  bool bfull() const;
  bool empty() const;

 private:
  generic* m_data;
  unsigned int m_size;
  unsigned int m_max_size;
  unsigned int m_front;
  bool m_ffull;
  bool m_bfull;
};

#include"block.hpp"
#endif



