/*  
  File: bst.hpp
  Author: Oliver Thompson
  Creates Binary Search Trees of data
*/

template<typename generic>
BST<generic>::BST():m_size(0), m_root(NULL)
{}

template<typename generic>
BST<generic>::~BST()
{
  clear();
}

template<typename generic>
void BST<generic>::insert(generic x)
{
  if(m_root == NULL)
  {
    m_root = new BTN<generic>;
    m_root->r = NULL;
    m_root->l = NULL;
    m_root->p = NULL;
    m_root->data = new generic;
    *(m_root->data) = x;
    m_size++;
  }

  else
  {
    BTN<generic>* temp = m_root;

    while((x > *(temp->data) && temp->r != NULL) || 
          (x < *(temp->data) && temp->l != NULL))
    {
      while(x > *(temp->data) && temp->r != NULL)
      {
        temp = temp->r;
      }

      while(x < *(temp->data) && temp->l != NULL)
      {
        temp = temp->l;
      }
    }

    if(x > *(temp->data) && temp->r == NULL)
    {
      temp->r = new BTN<generic>;
      temp->r->p = temp;
      temp->r->l = NULL;
      temp->r->r = NULL;
      temp->r->data = new generic;
      *(temp->r->data) = x;
      m_size++;
    }

    if(x < *(temp->data) && temp->l == NULL)
    {
      temp->l = new BTN<generic>;
      temp->l->p = temp;
      temp->l->l = NULL;
      temp->l->r = NULL;
      temp->l->data = new generic;
      *(temp->l->data) = x;
      m_size++;
    }
  }
}

template<typename generic>
void BST<generic>::remove(generic x)
{
  if(m_root != NULL)
  {
    BTN<generic>* temp = m_root;

    while(temp != NULL && *(temp->data) != x)
    {
      if(x > *(temp->data))
      {
        temp = temp->r;
      }
      if(x < *(temp->data))
      {
        temp = temp->l;
      }
    }

    if(temp == NULL)
    {
      return;
    }

    if(*(temp->data) == x)
    {
      if(temp->l == NULL && temp->r == NULL && temp->p == NULL)
      {
        delete temp->data;
        delete temp;
        m_root = NULL;
        m_size--;
      }

      else if(temp->l == NULL && temp->r == NULL)
      {
        if(temp->p->l == temp)
        {
          temp->p->l = NULL;
          delete temp->data;
          delete temp;
          m_size--;
        }
        else
        {
          temp->p->r = NULL;
          delete temp->data;
          delete temp;
          m_size--;
        }
      }

      else
      {
        BTN<generic>* temp2;

        if(temp->l != NULL)
        {
          temp2 = temp->l;
          while(temp2->r != NULL)
          {
            temp2 = temp2->r;
          }

          *(temp->data) = *(temp2->data);

          if(temp2->l != NULL && temp2->p->r == temp2)
          {
            temp2->p->r = temp2->l;
            temp2->l->p = temp2->p;
          }
          else if (temp2->l == NULL && temp2->p->r == temp2)
          {
            temp2->p->r = NULL;
          }

          if(temp2->l != NULL && temp2->p->l == temp2)
          {
            temp2->l->p = temp2->p;
            temp2->p->l = temp2->l;
          }
          else if (temp2->l == NULL && temp2->p->l == temp2)
          {
            temp2->p->l = NULL;
          }
        }
        else if (temp->r != NULL)
        {
          temp2 = temp->r;

          *(temp->data) = *(temp2->data);
          if(temp2->l != NULL)
          {
            temp2->l->p = temp2->p;
            temp2->p->l = temp2->l;
          }
          else
          {
            temp2->p->l = NULL;
          }

          if(temp2->r != NULL)
          {
            temp2->r->p = temp2->p;
            temp2->p->r = temp2->r;
          }
          else
          {
            temp2->p->r = NULL;
          }
        }

          delete temp2->data;
          delete temp2;
          m_size--;
      }
    }
  }
}

template<typename generic>
bool BST<generic>::search(generic x) const
{
  bool found = false;

  if(m_root != NULL)
  {
    BTN<generic>* temp = m_root;

    while(temp != NULL && *(temp->data) != x)
    {
      if(x > *(temp->data))
      {
        temp = temp->r;
      }
      if(x < *(temp->data))
      {
        temp = temp->l;
      }
    }

    if(temp != NULL && *(temp->data) == x)
    {
      found = true;
    }
  }

  return found;
}

template<typename generic>
void BST<generic>::clear()
{
  while(m_root != NULL)
  {
    remove(*(m_root->data));
  }
}

template<typename generic>
bool BST<generic>::empty() const
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
unsigned int BST<generic>::size() const
{
  return m_size;
}

