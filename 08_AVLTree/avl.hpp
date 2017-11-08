/*
  File: avl.hpp
  Author: Oliver Thompson
  Makes AVL trees
*/

template<typename generic>
void AVL<generic>::insert(generic x)
{
  BTN<generic>* temp = p_insert(x);

  while(temp != NULL)
  {
    if(unbalanced(temp))
    {
      rotate(temp);
    }
    temp = temp->p;
  }
}

template<typename generic>
void AVL<generic>::remove(generic x)
{
  BTN<generic>* temp = p_remove(x);

  while(temp != NULL)
  {
    if(unbalanced(temp))
    {
      rotate(temp);
    }

    temp = temp->p;
  }
}

template<typename generic>
bool AVL<generic>::unbalanced(BTN<generic>* temp)
{
  int difference = balance(temp);

  if(difference >= 2 || difference <= (-2))
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename generic>
int AVL<generic>::level(BTN<generic>* lvl)
{
  BTN<generic>* temp = lvl;
  int depthLeft, depthRight, depth;
  depthLeft = depthRight = 0;

  if(temp->l != NULL)
  {
    depthLeft = level(temp->l);
  }

  if(temp->r != NULL)
  {
    depthRight = level(temp->r);
  }

  if(depthLeft >= depthRight)
  {
    depth = depthLeft+1;
  }
  else
  {
    depth = depthRight+1;
  }

  return depth;
}

template<typename generic>
int AVL<generic>::balance(BTN<generic>* x)
{
  int left, right, difference;
  left = right = 0;

  if(x->l != NULL)
  {
    left = level(x->l);
  }

  if(x->r != NULL)
  {
    right = level(x->r);
  }

  difference = right - left;

  return difference;
}

template<typename generic>
void AVL<generic>::rotate(BTN<generic>* x)
{
  if(balance(x) > 0)
  {
    if(x->r != NULL)
    {
      if(balance(x->r) > 0)
      {
        rotate_pospos(x);
      }
      else
      {
        rotate_posneg(x);
      }
    }
  }

  else
  {
    if(x->l != NULL)
    {
      if(balance(x->l) > 0)
      {
        rotate_negpos(x);
      }
      else
      {
        rotate_negneg(x);
      }
    }
  }
}

template<typename generic>
void AVL<generic>::rotate_pospos(BTN<generic>* x)
{
  BTN<generic>* y = x->r;
  BTN<generic>* z = y->r;

  y->p = x->p;

  if(y->p == NULL)
  {
      m_root = y;
  }
  else
  {
    if(y->p->l == x)
    {
      y->p->l = y;
    }
    else
    {
      y->p->r = y;
    }
  }

  x->r = y->l;

  if(x->r != NULL)
  {
    x->r->p = x;
  }

  y->l = x;
  x->p = y;
}

template<typename generic>
void AVL<generic>::rotate_posneg(BTN<generic>* x)
{
  BTN<generic>* y = x->r;
  BTN<generic>* z = y->l;

  z->p = x->p;

  if(z->p == NULL)
  {
      m_root = z;
  }
  else
  {
    if(z->p->l == x)
    {
      z->p->l = z;
    }
    else
    {
      z->p->r = z;
    }
  }

  x->r = z->l;

  if(x->r != NULL)
  {
    x->r->p = x;
  }

  z->l = x;
  x->p = z;
  y->l = z->r;

  if(y->l != NULL)
  {
    y->l->p = y;
  }

  z->r = y;
  y->p = z;

}

template<typename generic>
void AVL<generic>::rotate_negneg(BTN<generic>* x)
{
  BTN<generic>* y = x->l;
  BTN<generic>* z = y->l;

  y->p = x->p;

  if(y->p == NULL)
  {
      m_root = y;
  }
  else
  {
    if(y->p->l == x)
    {
      y->p->l = y;
    }
    else
    {
      y->p->r = y;
    }
  }

  x->l = y->r;

  if(x->l != NULL)
  {
    x->l->p = x;
  }

  y->r = x;
  x->p = y;
}

template<typename generic>
void AVL<generic>::rotate_negpos(BTN<generic>* x)
{
  BTN<generic>* y = x->l;
  BTN<generic>* z = y->r;

  z->p = x->p;

  if(z->p == NULL)
  {
      m_root = z;
  }
  else
  {
    if(z->p->l == x)
    {
      z->p->l = z;
    }
    else
    {
      z->p->r = z;
    }
  }

  x->l = z->r;

  if(x->l != NULL)
  {
    x->l->p = x;
  }

  z->r = x;
  x->p = z;
  y->r = z->l;

  if(y->r != NULL)
  {
    y->r->p = y;
  }

  z->l = y;
  y->p = z;
}

