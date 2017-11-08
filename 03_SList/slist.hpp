/*
  File: slist.hpp
  Author: Oliver Thompson
  Makes singly linked lists
*/
template<typename generic>
SList<generic>::SList():m_size(0), m_front(NULL)
{}

template<typename generic>
SList<generic>::SList(const SList& s):m_size(0), m_front(NULL)
{
  *this = s;
}

template<typename generic>
SList<generic>::~SList()
{
  clear();
}

template<typename generic>
void SList<generic>::push_front(generic x)
{
  SNode<generic>* temp = new SNode<generic>;
  temp->b = m_front;
  m_front = temp;
  m_front->data = x;
  m_size++;
}

template<typename generic>
void SList<generic>::pop_front()
{
  if(m_size > 0)
  {
    SNode<generic>* temp;
    temp = m_front;
    m_front = temp->b;
    delete temp;
    m_size--;
  }
}

template<typename generic>
void SList<generic>::remove(generic x)
{
  bool popFront = true;

  while(m_front != NULL && popFront == true)
  {
    popFront = false;
    if(m_front->data == x)
    {
      pop_front();
      popFront = true;
    }
  }

  if(m_front != NULL)
  {
  SNode<generic>* temp1;
  SNode<generic>* temp2;
  temp1 = m_front;
  while(temp1->b != NULL)
  {
    while(temp1->b != NULL && temp1->b->data !=x)
    {
     temp1 = temp1->b;
    }
    if(temp1->b != NULL)
    {
      temp2 = temp1->b->b;
      delete temp1->b;
      temp1->b = temp2;
      m_size--;
    }
  }
  }  
}

template<typename generic>
generic& SList<generic>::front()
{
  if(m_front == NULL)
  {
    throw out_of_range("Front does not exist");
  }
  return m_front->data;
}

template<typename generic>
const generic& SList<generic>::front() const
{
  if(m_front == NULL)
  {
    throw out_of_range("Front does not exist");
  }
  return m_front->data;
}

template<typename generic>
void SList<generic>::clear()
{
  while(m_front != NULL)
  {
    pop_front();
  }
}

template<typename generic>
unsigned int SList<generic>::size() const
{
  return m_size;
}

template<typename generic>
bool SList<generic>::empty() const
{
  bool temp = true;
  if (m_front != NULL)
  {
    temp = false;
  }
  return temp;
}

template<typename generic>
SListIterator<generic> SList<generic>::begin() const
{
  return Iterator(m_front);
}

template<typename generic>
SListIterator<generic> SList<generic>::end() const
{
  return Iterator();
}

template<typename generic>
SList<generic>& SList<generic>::operator=(const SList& s)
{
  clear();

  if(!s.empty())
  {
    m_front = new SNode<generic>;
    SNode<generic>* temp = m_front;

    for(Iterator i = s.begin(); i != s.end(); m_size++, temp = temp->b)
    {
      temp->data = *i;
      i++ != s.end() ? temp->b = new SNode<generic> :temp->b = NULL;
    }
  }
  return *this;
}

