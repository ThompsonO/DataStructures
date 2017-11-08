template <typename generic>
BTPostorderIterator<generic>::BTPostorderIterator():m_current(NULL)
{}

template <typename generic>
BTPostorderIterator<generic>::BTPostorderIterator(BTN<generic>* x):m_current(x)
{}

template <typename generic>
const generic& BTPostorderIterator<generic>::operator*() const
{
  return *(m_current->data);
}

template <typename generic>
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++()
{
  if(m_current != NULL)
  {
    if(m_current->p != NULL && m_current == m_current->p->l 
       && m_current->p->r != NULL)
    {
      m_current = m_current->p->r;

      while(m_current->l != NULL || m_current->r != NULL)
      {
        if(m_current->l != NULL)
        {
          m_current = m_current->l;
        }

        else
        {
          m_current = m_current->r;
        }
      }
    }

    else
    {
      m_current = m_current->p;
    }
  }

  return *this;
}

template <typename generic>
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++(int)
{
  return ++(*this);
}

template <typename generic>
bool BTPostorderIterator<generic>::operator==
                                   (const BTPostorderIterator<generic>& x)const
{
  return m_current == x.m_current;
}

template <typename generic>
bool BTPostorderIterator<generic>::operator!=
                                 (const BTPostorderIterator<generic>& x)const
{
  return m_current != x.m_current;
}

