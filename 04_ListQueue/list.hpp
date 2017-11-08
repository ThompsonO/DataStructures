/*
  File: list.hpp
  Author: Oliver Thompson
  Doubly Linked List Class
*/
template<typename generic>
List<generic>::List():m_size(0), m_front(NULL), m_back(NULL)
{}

template<typename generic>
List<generic>::List(const List& l):m_size(0), m_front(NULL), m_back(NULL)
{
  *this = l;
}

template<typename generic>
List<generic>::~List()
{
  clear();
}

template<typename generic>
List<generic>& List<generic>:: operator=(const List& l)
{
  clear();

  if(!l.empty())
  {
    m_front = new Node<generic>;
    Node<generic>* temp = m_front;
    temp->f = NULL;

    for(Iterator i = l.begin(); i != l.end(); m_size++, temp = temp->b)
    {
      temp->data = *i;
      if(++i != l.end())
      {
        temp->b = new Node<generic>;
        temp->b->f = temp;
      }
      else
      {
        temp->b = NULL;
      }
    }
  }
  return *this;
}

template<typename generic>
void List<generic>::push_front(generic x)
{
  if(m_front == NULL)
  {
    m_front = new Node<generic>;
    m_front->f = NULL;
    m_front->b = NULL;
    m_front->data = x;
    m_back = m_front;
    m_size++;
  }

  else
  {
    m_front->f = new Node<generic>;
    m_front->f->b = m_front;
    m_front = m_front->f;
    m_front->f = NULL;
    m_front->data = x;
    m_size++;
  }
}

template<typename generic>
void List<generic>::pop_front()
{
  bool popped = false;
  if(m_front != NULL && m_front->b != NULL)
  {
    m_front = m_front->b;
    delete m_front->f;
    m_front->f = NULL;
    m_size--;
    popped = true;
  }
  if(m_front != NULL && m_front->b == NULL && !popped)
  {
    delete m_front;
    m_front = NULL;
    m_back = NULL;
    m_size--;
  }
}

template<typename generic>
void List<generic>::push_back (generic x)
{
  if(m_front == NULL)
  {
    m_front = new Node<generic>;
    m_front->f = NULL;
    m_front->b = NULL;
    m_front->data = x;
    m_back = m_front;
    m_size++;
  }
  else
  {
    m_back->b = new Node<generic>;
    m_back->b->f = m_back;
    m_back = m_back->b;
    m_back->data = x;
    m_back->b = NULL;
    m_size++;
  }
}

template<typename generic>
void List<generic>::pop_back()
{
  bool popped = false;
  if(m_back != NULL && m_back->f != NULL)
  {
    m_back = m_back->f;
    delete m_back->b;
    m_back->b = NULL;
    m_size--;
    popped = true;
  }
  if(m_back != NULL && m_back->f == NULL && !popped)
  {
    delete m_back;
    m_back = NULL;
    m_front = NULL;
    m_size--;
  }
}

template<typename generic>
void List<generic>::remove(generic x)
{
  bool popFront = true, popBack = true; 

  while(m_front != NULL && popFront == true)
  {
    popFront = false;
    if(m_front->data == x)
    {
      pop_front();
      popFront = true;
    }
  }

  while(m_back != NULL && popBack == true)
  {
    popBack = false;
    if(m_back->data == x)
    {
      pop_back();
      popBack = true;
    }
  }

  Node<generic>* temp = m_front;
  while(temp != NULL && temp->b != NULL)
  {
    temp = m_front;
    while(temp->data != x && temp->b != NULL)
    {
      temp = temp->b;
    }
    if(temp->b != NULL && temp->data == x)
    {
      temp->f->b = temp->b;
      temp->b->f = temp->f;
      delete temp;
      m_size--;
    }
  }
}

template<typename generic>
generic& List<generic>::front()
{
  if(m_front == NULL)
  {
    throw out_of_range("Front does not exist");
  }
  return m_front->data;
}

template<typename generic>
generic& List<generic>::back()
{
  if(m_back == NULL)
  {
    throw out_of_range("Back does not exist");
  }
  return m_back->data;

}

template<typename generic>
const generic& List<generic>::front() const
{
  if(m_front == NULL)
  {
    throw out_of_range("Front does not exist");
  }
  return m_front->data;

}

template<typename generic>
const generic& List<generic>::back() const
{
  if(m_back == NULL)
  {
    throw out_of_range("Back does not exist");
  }
  return m_back->data;

}

template<typename generic>
void List<generic>::clear()
{
  while(m_front != NULL)
  {
    pop_front();
  }
}

template<typename generic>
unsigned int List<generic>::size() const
{
  return m_size;
}

template<typename generic>
bool List<generic>::empty() const
{
  bool temp = true;
  if(m_front != NULL)
  {
    temp = false;
  }
  return temp;
}

template<typename generic>
ListIterator<generic> List<generic>::begin() const
{
  return Iterator(m_front);
}

template<typename generic>
ListIterator<generic> List<generic>::end() const
{
  return Iterator();
}

