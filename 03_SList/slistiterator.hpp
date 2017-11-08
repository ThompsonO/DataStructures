/*
  File: slistiterator.hpp
  Author: Oliver Thompson
  Makes iterators for singly linked lists
*/

template<typename generic>
SListIterator<generic>::SListIterator():m_current(NULL)
{}

template<typename generic>
SListIterator<generic>::SListIterator(SNode<generic>* s): m_current(s)
{}

template<typename generic>
generic& SListIterator<generic>::operator*()
{
  if(m_current == NULL)
  {
    throw out_of_range("The iterator is not currently on a node");
  }
  return m_current->data;
}

template<typename generic>
const generic& SListIterator<generic>::operator*() const
{
  if(m_current == NULL)
  {
    throw out_of_range("The iterator is not currently on a node");
  }
  return m_current->data;
}

template<typename generic>
SListIterator<generic> SListIterator<generic>::operator++()
{
  if(m_current != NULL)
  {
    m_current = m_current->b;
  }
  return *this;
}

template<typename generic>
SListIterator<generic> SListIterator<generic>::operator++(int x)
{
  return ++(*this);
}

template<typename generic>
bool SListIterator<generic>::operator==(const SListIterator& s) const
{
  return m_current == s.m_current;
}

template<typename generic>
bool SListIterator<generic>::operator!=(const SListIterator& s) const
{
  return m_current != s.m_current;
}

