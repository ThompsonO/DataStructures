template <typename generic>
BTPreorderIterator<generic>::BTPreorderIterator():m_current(NULL)
{}

template <typename generic>
BTPreorderIterator<generic>::BTPreorderIterator(BTN<generic>* x):m_current(x)
{}

template <typename generic>
const generic& BTPreorderIterator<generic>::operator*() const
{
  return *(m_current->data);
}

template <typename generic>
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++()
{
  if(m_current != NULL)
  {
    if(m_current->l != NULL)
    {
      m_current = m_current->l;
    }

    else if (m_current->r != NULL)
    {
      m_current = m_current->r;
    }

    else
    {
      while(m_current->p != NULL && 
           (m_current->p->r == NULL || m_current->p->r == m_current))
      {
        m_current = m_current->p;
      }

      if(m_current->p != NULL)
      {
        m_current = m_current->p->r;
      }

      else
      {
        m_current = NULL;
      }
    }
  }

  return *this;
}

template <typename generic>
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++(int)
{
  return ++(*this);
}

template <typename generic>
bool BTPreorderIterator<generic>::operator==
                                  (const BTPreorderIterator<generic>& x) const
{
  return m_current == x.m_current;
}

template <typename generic>
bool BTPreorderIterator<generic>::operator!=
                                  (const BTPreorderIterator<generic>& x) const
{
  return m_current != x.m_current;
}

