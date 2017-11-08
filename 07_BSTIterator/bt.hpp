template<typename generic>
BT<generic>::BT():m_root(NULL), m_size(0)
{}

template<typename generic>
BT<generic>::BT(const BT& c):m_root(NULL), m_size(0)
{
  *this = c;
}

template<typename generic>
BT<generic>::~BT()
{
  clear();
}

template<typename generic>
BT<generic>& BT<generic>::operator=(const BT& rhs)
{
  clear();
  BTPreorderIterator<generic> copy = rhs.pre_begin();

  if(copy != NULL)
  {
    m_root = new BTN<generic>;
    m_root->data = new generic;
    m_root->p = NULL;
    m_root->l = NULL;
    m_root->r = NULL;
    m_size++;

    *(m_root->data) = *(copy);
    copy++;

    for(copy; copy != rhs.pre_end(); copy++)
    {
      BTN<generic>* temp = m_root;

      while((*(copy) > *(temp->data) && temp->r != NULL) || 
            (*(copy) < *(temp->data) && temp->l != NULL))
      {
        while(*(copy) > *(temp->data) && temp->r != NULL)
        {
          temp = temp->r;
        }

        while(*(copy) < *(temp->data) && temp->l != NULL)
        {
          temp = temp->l;
        }
      }

      if(*(copy) > *(temp->data) && temp->r == NULL)
      {
        temp->r = new BTN<generic>;
        temp->r->p = temp;
        temp->r->l = NULL;
        temp->r->r = NULL;
        temp->r->data = new generic;
        *(temp->r->data) = *(copy);
        m_size++;
      }

      if(*(copy) < *(temp->data) && temp->l == NULL)
      {
        temp->l = new BTN<generic>;
        temp->l->p = temp;
        temp->l->l = NULL;
        temp->l->r = NULL;
        temp->l->data = new generic;
        *(temp->l->data) = *(copy);
        m_size++;
      }
    }
  }
}

template<typename generic>
void BT<generic>::clear()
{
  if(m_root != NULL)
  {
    lumberjack(m_root);
    m_root = NULL;
  }
}

template<typename generic>
bool BT<generic>::empty() const
{
  if(m_root == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename generic>
unsigned int BT<generic>::size() const
{
  return m_size;
}

template<typename generic>
BTPreorderIterator<generic> BT<generic>::pre_begin() const
{
  return BTPreorderIterator<generic>(m_root);
}

template<typename generic>
BTPreorderIterator<generic> BT<generic>::pre_end() const
{
  return BTPreorderIterator<generic>();
}

template<typename generic>
BTInorderIterator<generic> BT<generic>::in_begin() const
{
  BTN<generic>* temp = m_root;

  while(temp->l != NULL)
  {
    temp = temp->l;
  }

  return BTInorderIterator<generic>(temp);
}

template<typename generic>
BTInorderIterator<generic> BT<generic>::in_end() const
{
  return BTInorderIterator<generic>();
}

template<typename generic>
BTPostorderIterator<generic> BT<generic>::post_begin() const
{
  BTN<generic>* temp = m_root;

  while(temp->l != NULL && temp->r != NULL)
  {
    if(temp->l != NULL)
    {
      temp = temp->l;
    }

    else
    {
      temp = temp->r;
    }
  }

  return BTPostorderIterator<generic>(temp);
}

template<typename generic>
BTPostorderIterator<generic> BT<generic>::post_end() const
{
  return BTPostorderIterator<generic>();
}

template<typename generic>
void BT<generic>::lumberjack(BTN<generic>* axe)
{
  if(axe->l != NULL)
  {
    lumberjack(axe->l);
  }

  if(axe->r != NULL)
  {
    lumberjack(axe->r);
  }

  delete axe->data;
  delete axe;
}
