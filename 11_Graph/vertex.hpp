/*
  File:vertex.hpp
  Programmer: Oliver Thompson
  Creates vertecies
*/

Vertex::Vertex()
{}

Vertex::Vertex(string a_name)
{
  m_name = a_name;
}

Vertex::~Vertex()
{
  v_clear();
}

void Vertex::v_clear()
{
  m_name.clear();
}

Vertex& Vertex::operator=(Vertex& rhs)
{
  m_name = rhs.m_name;

  return *this;
}

bool Vertex::operator==(Vertex& rhs)
{
  if(m_name == rhs.m_name)
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool Vertex::operator!=(Vertex& rhs)
{
  if(m_name != rhs.m_name)
  {
    return true;
  }

  else
  {
    return false;
  }
}

