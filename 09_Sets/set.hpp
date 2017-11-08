/*
  Programmer: Oliver Thompson
  File: set.hpp
  Creates sets of data
*/

template<typename generic>
Set<generic>::Set()
{}

template<typename generic>
Set<generic>::Set(const Set<generic>& px)
{
  *this = px;
}


template<typename generic>
Set<generic>& Set<generic>::operator=(const Set<generic>& px)
{
  BTInorderIterator<generic> temp;
  for(temp = px.begin(); temp != px.end(); temp++)
  {
    insert(*temp);
  }
  return *this;
}

template<typename generic>
Set<generic> Set<generic>::operator+(const Set<generic>& rhs) const
{
  BTInorderIterator<generic> temp;
  Set<generic> result;

  for(temp = rhs.begin(); temp != rhs.end(); temp++)
  {
    result.insert(*temp);
  }

  for(temp = begin(); temp != end(); temp++)
  {
    result.insert(*temp);
  }

  return result;
}

template<typename generic>
Set<generic> Set<generic>::operator*(const Set<generic>& rhs) const
{
  Set<generic> result, compare;
  BTInorderIterator<generic> temp;
  compare = rhs;

  for(temp = begin(); temp != end(); temp++)
  {
    if(compare.find(*temp) != NULL && *(compare.find(*temp)) == *temp)
    {
      result.insert(*temp);
    }
  }

  return result;
}

template<typename generic>
Set<generic> Set<generic>::operator-(const Set<generic>& rhs) const
{
  Set<generic> result, compare;
  BTInorderIterator<generic> temp;
  compare = rhs;

  for(temp = begin(); temp!= end(); temp++)
  {
    if(compare.find(*temp) == NULL || *(compare.find(*temp)) != *temp)
    {
      result.insert(*temp);
    }
  }

  return result;
}

template<typename generic>
void Set<generic>::insert(generic px)
{
  AVL<generic>::insert(px);
}

template<typename generic>
void Set<generic>::erase(generic px)
{
  AVL<generic>::remove(px);
}

template<typename generic>
bool Set<generic>::empty() const
{
  return AVL<generic>::empty();
}

template<typename generic>
unsigned int Set<generic>::size() const
{
  return AVL<generic>::size();
}

template<typename generic>
void Set<generic>::clear()
{
  AVL<generic>::clear();
}

template<typename generic>
BTInorderIterator<generic> Set<generic>::find(generic px)
{
  return AVL<generic>::in_search(px);
}

template<typename generic>
BTInorderIterator<generic> Set<generic>::begin() const
{
  return AVL<generic>::in_begin();
}

template<typename generic>
BTInorderIterator<generic> Set<generic>::end() const
{
  return AVL<generic>::in_end();
}

