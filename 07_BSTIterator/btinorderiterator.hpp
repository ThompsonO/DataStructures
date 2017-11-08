template <typename generic>
BTInorderIterator<generic>::BTInorderIterator():m_current(NULL)
{}

template <typename generic>
BTInorderIterator<generic>::BTInorderIterator(BTN<generic>* x):m_current(x)
{}

template <typename generic>
const generic& BTInorderIterator<generic>::operator*() const
{
  return *(m_current->data);
}

template <typename generic>
BTInorderIterator<generic> BTInorderIterator<generic>::operator++()
{
  if(m_current != NULL)
  {
    if(m_current->r != NULL)
    {
      m_current = m_current->r;

      while(m_current->l != NULL)
      {
        m_current = m_current->l;
      }
    }

    else
    {
      while(m_current->p != NULL && m_current == m_current->p->r)
      {
        m_current = m_current->p;
      }

      m_current = m_current->p;
    }
  }

  return *this;
}

template <typename generic>
BTInorderIterator<generic> BTInorderIterator<generic>::operator++(int)
{
  return ++(*this);
}

template <typename generic>
bool BTInorderIterator<generic>::operator==
                                  (const BTInorderIterator<generic>& x) const
{
  return m_current == x.m_current;
}

template <typename generic>
bool BTInorderIterator<generic>::operator!=
                                  (const BTInorderIterator<generic>& x) const
{
  return m_current != x.m_current;
}

