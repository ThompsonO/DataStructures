template<typename generic>
Block<generic>::Block():m_data(NULL), m_size(0), m_max_size(3), m_front(0),
                        m_ffull(false), m_bfull(false)
{
  m_data = <generic>[m_max_size];
}

template<typename generic>
Block<generic>::Block(unsigned int n):m_data(NULL), m_size(0), m_max_size(n), 
                                      m_front(0), m_ffull(false), m_bfull(false)
{
  m_data = <generic>[m_max_size];
}

template<typename generic>
Block<generic>::Block(Block& b)
{}

template<typename generic>
Block& Block<generic>::operator= (const Block& b);
{}

template<typename generic>
Block<generic>::~Block()
{}

template<typename generic>
void Block<generic>::push_front(generic x)
{
  if(!ffull() && m_size < m_max_size)
  {
    if(m_size == 0)
    {
      m_front = m_max_size - 1;
      m_bfull = true;
    }
    m_data[m_front] = x;
    m_size++;
    m_front --;
    if(m_front = (-1))
    {
      m_ffull = true;
    }
  }
}

template<typename generic>
void Block<generic>::pop_front()
{
  if(m_size > 0)
  {
    m_size--;
    m_front++;
    m_ffull = false;
  }
}

template<typename generic>
void Block<generic>::push_back(generic x)
{
  if(!bfull && m_size < m_max_size)
  {
    if(m_size == 0)
    {
      m_front = (-1);
      m_ffull = true;
    }
    m_data[(m_size + m_front + 1)] = x;
    m_size++;
    if((m_size + m_front + 1) == m_max_size)
    {
      m_bfull = true;
    }
  }
}

template<typename generic>
void Block<generic>::pop_back()
{
  m_size--;
  m_bfull = false;
}

template<typename generic>
void Block<generic>::clear()
{
  m_size = 0;
}

template<typename generic>
generic& Block<generic>::operator[](unsigned int p)
{
  return m_data[(m_front+1+p)];
}

template<typename generic>
const generic& Block<generic>::operator[](unsigned int p) const
{
  return m_data[(m_front+1+p)];
}

template<typename generic>
unsigned int Block<generic>::size() const
{
  return m_size;
}

template<typename generic>
unsigned int Block<generic>::max_size() const
{
  return m_max_size;
}

template<typename generic>
bool Block<generic>::ffull() const
{
  return m_ffull;
}

template<typename generic>
bool Block<generic>::bfull() const
{
  return m_bfull;
}

template<typename generic>
bool Block<generic>::empty() const
{
  return (m_size == 0);
}

