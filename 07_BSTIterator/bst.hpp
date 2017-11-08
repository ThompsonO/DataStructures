/*  
  File: bst.hpp
  Author: Oliver Thompson
  Creates Binary Search Trees of data
*/

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
BTPreorderIterator<generic> BST<generic>::pre_search(generic x)
{
  bool found = false;

  BTPreorderIterator<generic> search = BT<generic>::pre_begin();

  while(search != BT<generic>::pre_end() && found == false)
  {
    if(*search == x)
    {
      found = true;
    }

    else
    {
      search++;
    }
  }

  return search;
}

template<typename generic>
BTInorderIterator<generic> BST<generic>::in_search(generic x)
{
  bool found = false;

  BTInorderIterator<generic> search = BT<generic>::in_begin();

  while(search != BT<generic>::in_end() && found == false)
  {
    if(*search == x)
    {
      found = true;
    }

    else
    {
      search++;
    }
  }

  return search;
}

template<typename generic>
BTPostorderIterator<generic> BST<generic>::post_search(generic x)
{
  bool found = false;

  BTPostorderIterator<generic> search = BT<generic>::post_begin();

  while(search != BT<generic>::post_end() && found == false)
  {
    if(*search == x)
    {
      found = true;
    }

    else
    {
      search++;
    }
  }

  return search;
}

