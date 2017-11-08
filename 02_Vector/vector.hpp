/*
  File: vector.hpp
  Author: Oliver Thompson
  Dynamicly manages arrays of data
*/

template <typename generic>
Vector<generic> :: Vector() : m_size(0), m_max_size(1), m_data(NULL)
{
  m_data = new generic[m_max_size];
}

template <typename generic>
Vector<generic> :: Vector(const Vector& v) : m_size(0),
                                             m_max_size(1),
                                             m_data(NULL)
{
  m_max_size = v.max_size();
  m_data = new generic[m_max_size];
  for(int i = 0; i < v.size(); i++)
  {
    push_back(v[i]);
  }
}

template <typename generic>
Vector<generic> :: ~Vector()
{
  delete [] m_data;
}

template <typename generic>
void Vector<generic> :: push_back(generic x)
{
  if(m_size >= m_max_size)
  {
    generic* temp = m_data;
    m_max_size *= 2;
    m_data = new generic[m_max_size];

    for(int i = 0; i < m_size; i++)
    {
      m_data[i] = temp[i];
    }
    delete [] temp;
  }
  m_data[m_size++] = x;
}

template <typename generic>
void Vector<generic> :: pop_back()
{
  if( m_size > 0)
  {
    m_size--;

    if( m_size < (m_max_size/4))
    {
      generic* temp = m_data;
      m_max_size /= 2;
      m_data = new generic[m_max_size];

      for(int i = 0; i < m_size; i++)
      {
        m_data[i] = temp[i];
      }
      delete [] temp;
    }
  }
}

template <typename generic>
void Vector<generic> :: clear()
{
  m_size = 0;
  m_max_size = 1;
  delete [] m_data;
  m_data = new generic[m_max_size];
}

template <typename generic>
unsigned int Vector<generic> :: size() const
{
  return m_size;
}

template <typename generic>
unsigned int Vector<generic> :: max_size() const
{
  return m_max_size;
}

template <typename generic>
Vector<generic>& Vector<generic> :: operator=(const Vector<generic>& v)
{
  clear();
  m_max_size = v.max_size();
  delete [] m_data;
  m_data = new generic[m_max_size];
  for(int i = 0; i < v.size(); i++)
  {
    push_back(v[i]);
  }
  return *this;
}

template <typename generic>
generic& Vector<generic> :: operator[](unsigned int p)
{
  if ( p >= m_size )
  {
    throw out_of_range
    (
      "Index is out of bounds"
    );
  }
  return m_data[p]; 
}

template <typename generic>
const generic& Vector<generic> :: operator[](unsigned int p) const
{
  if ( p >= m_size )
  {
    throw out_of_range
    (
      "Index is out of bounds"
    );
  }
  return m_data[p];
}

