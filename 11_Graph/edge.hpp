/*
  File: edge.hpp
  Programmer: Oliver Thompson
  Creates edges
*/

Edge::Edge():m_start(NULL),m_end(NULL),m_length(0),m_speed(0)
{}

Edge::Edge(Vertex& start, Vertex& end, float length, float speed)
{
  m_start = start;
  m_end = end;
  m_length = length;
  m_speed = speed;
}

Edge::~Edge()
{
  clear();
}

float Edge::time()
{
  return(m_length/m_speed);
}

void Edge::set_start(Vertex& begin)
{
  m_start = begin;
}

Vertex& Edge::get_start()
{
  return m_start;
}

void Edge::set_end(Vertex& final)
{
  m_end = final;
}

Vertex& Edge::get_end()
{
  return m_end;
}

void Edge::set_length(float distance)
{
  m_length = distance;
}

float Edge::get_length() const
{
  return m_length;
}

void Edge::set_speed(float rate)
{
  m_speed = rate;
}

float Edge::get_speed() const
{
  return m_speed;
}

void Edge::clear()
{
  m_length = 0;
  m_speed = 0;
  m_start.v_clear();
  m_end.v_clear();
}

Edge& Edge::operator=(Edge& rhs)
{
  m_length = rhs.get_length();
  m_speed = rhs.get_speed();
  m_start = rhs.get_start();
  m_end = rhs.get_end();

  return *this;
}

bool Edge::operator==(Edge& rhs)
{
  if(m_start == rhs.get_start() && m_end == rhs.get_end() && 
     m_length == rhs.get_length() && m_speed == rhs.get_speed())
  {
    return true;
  }

  else
  {
    return false;
  }
}

