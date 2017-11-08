/*
  File: queue.hpp
  Author: Oliver Thompson
  Queue Class
*/
template<typename generic>
Queue<generic>::Queue()
{}

template<typename generic>
Queue<generic>::Queue(const Queue& q):List<generic>(q)
{}

template<typename generic>
Queue<generic>::~Queue()
{
  List<generic>::clear();
}

template<typename generic>
Queue<generic>& Queue<generic>::operator=(const Queue& q)
{
  return List<generic>::operator=(q);
}

template<typename generic>
bool Queue<generic>::empty() const
{
  return List<generic>::empty();
}

template<typename generic>
unsigned int Queue<generic>::size() const
{
  return List<generic>::size();
}

template<typename generic>
generic& Queue<generic>::front()
{
  return List<generic>::front();
}

template<typename generic>
generic& Queue<generic>::back()
{
  return List<generic>::back();
}

template<typename generic>
const generic& Queue<generic>::front() const
{
  return List<generic>::front();
}

template<typename generic>
const generic& Queue<generic>::back() const
{
  return List<generic>::back();
}

template<typename generic>
void Queue<generic>::push(generic x)
{
  return List<generic>::push_back(x);
}

template<typename generic>
void Queue<generic>::pop()
{
  return List<generic>::pop_front();
}

template<typename generic>
void Queue<generic>::clear()
{
  return List<generic>::clear();
}

