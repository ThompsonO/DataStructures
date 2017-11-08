/*
  Programmer: Oliver Thompson
  File: priority_queue.hpp
  Creates Priority Queues
*/

template<typename generic>
Priority_queue<generic>::Priority_queue() : BT<generic>()
{
  m_root = NULL;
  m_push = NULL;
  m_pop = NULL;
  m_size = 0;
}

template<typename generic>
Priority_queue<generic>::Priority_queue(const Priority_queue<generic>& c) : BT<generic>(c)
{
  *this = c;
}

template<typename generic>
Priority_queue<generic>& Priority_queue<generic>::operator=(const Priority_queue<generic>& rhs)
{
  BT<generic>::operator=(rhs);
  locate_pointers();
  return *this;
}

template<typename generic>
void Priority_queue<generic>::push(generic x)
{
  if(m_root == NULL)
  {
    m_root = new BTN<generic>;
    m_root->p = NULL;
    m_root->l = NULL;
    m_root->r = NULL;
    m_root->d = new generic;
    *(m_root->d) = x;
    m_size++;
    m_push = m_root;
    m_pop = m_root;
  }

  else
  {
    if(m_push->l == NULL)
    {
      m_push->l = new BTN<generic>;
      m_push->l->p = m_push;
      m_push->l->d = new generic;
      *(m_push->l->d) = x;
      m_push->l->l = NULL;
      m_push->l->r = NULL;
      m_size++;
      m_pop = m_push;

      if(*m_push->d < *(m_push->l->d))
      {
        heapPush();
      }
    }
    else
    {
      m_push->r = new BTN<generic>;
      m_push->r->p = m_push;
      m_push->r->d = new generic;
      *(m_push->r->d) = x;
      m_push->r->l = NULL;
      m_push->r->r = NULL;
      m_size++;

      if(*m_push->d < *(m_push->r->d))
      {
        heapPush();
      }

      locate_pointers();
    }  
  }
}

template<typename generic>
void Priority_queue<generic>::pop()
{
  if(m_root != NULL)
  {
    if(m_pop->r == NULL && m_pop->l == NULL)
    {
      m_pop = NULL;
      m_push = NULL;
      delete m_root->d;
      delete m_root;
      m_root = NULL;
      m_size--;
    }

    else if(m_pop->r != NULL)
    {
      *(m_root->d) = *(m_pop->r->d);
      delete m_pop->r->d;
      delete m_pop->r;
      m_pop->r = NULL;
      m_size--;
      heapPop();
      locate_pointers();
    }

    else
    {
      *(m_root->d) = *(m_pop->l->d);
      delete m_pop->l->d;
      delete m_pop->l;
      m_pop->l = NULL;
      m_size--;
      heapPop();
      locate_pointers();
    }
  }
}

template<typename generic>
const generic& Priority_queue<generic>::top() const
{
  if(m_root != NULL)
  {
    return *m_root->d;
  }
}

template<typename generic>
void Priority_queue<generic>::heapPush()
{
  BTN<generic>* temp = m_push;
  generic swap;

  while(temp != NULL)
  {
    if(*(temp->l->d) > *(temp->d))
    {
      swap =*(temp->d);
      *(temp->d) = *(temp->l->d);
      *(temp->l->d) = swap;
    }

    else if(*(temp->r->d) > *(temp->d))
    {
      swap =*(temp->d);
      *(temp->d) = *(temp->r->d);
      *(temp->r->d) = swap; 
    }

    temp = temp->p;
  }
}

template<typename generic>
void Priority_queue<generic>::heapPop()
{
  BTN<generic>* temp = m_root;
  generic swap;
  bool finished = false;

  while(!finished)
  {
    finished = true;

    if(temp->l != NULL && temp->r == NULL)
    {
      if(*(temp->l->d) > *(temp->d))
      {
        swap =*(temp->d);
        *(temp->d) = *(temp->l->d);
        *(temp->l->d) = swap;

        temp = temp->l;
        finished = false;
      }
    }

    else if(temp->l != NULL && temp->r != NULL)
    {
      if(*(temp->l->d) > *(temp->r->d) && 
         *(temp->l->d) > *(temp->d))
      {
        swap =*(temp->d);
        *(temp->d) = *(temp->l->d);
        *(temp->l->d) = swap;

        temp = temp->l;
        finished = false;
      }

      else if(*(temp->r->d) > *(temp->l->d) && 
              *(temp->r->d) > *(temp->d))
      {
        swap =*(temp->d);
        *(temp->d) = *(temp->r->d);
        *(temp->r->d) = swap;

        temp = temp->r;
        finished = false;
      }
    }
  }
}

template <typename generic>
void Priority_queue<generic>::locate_pointers()
{
  m_push = find_pointers(m_root, (m_size+1));
  m_pop = find_pointers(m_root, m_size);
}

template <typename generic>
BTN<generic>* Priority_queue<generic>:: find_pointers(BTN<generic>* x, int n)
{
  if((n/2) > 1)
  {
    if(((n/2) % 2) == 0)
    {
      return(find_pointers(x, n/2))->l;
    }

    else
    {
      return(find_pointers(x, n/2))->r;
    }
  }

  else
  {
    return x;
  }
}
