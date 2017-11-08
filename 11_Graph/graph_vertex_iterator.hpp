/*
  File: graph_vertex_iterator.hpp
  Programmer: Oliver Thompson
  Makes iterators for verticies of graphs.
*/

GraphVertexIterator::GraphVertexIterator()
{}

GraphVertexIterator::GraphVertexIterator(Vertex x):m_current(x)
{}

const Vertex& GraphVertexIterator::operator*() const
{
  return m_current;
}

GraphVertexIterator& GraphVertexIterator::operator++()
{
/*  int index = 0;

  for(int i=0; i<m_vertex.size(); i++)
  {
    if(m_current == m_vertex[i])
    {
      index = i;
    }
  }

  if(index < m_vertex.size())
  {
    m_current = m_vertex[(index+1)];
  }
*/
  return *this;
}

GraphVertexIterator& GraphVertexIterator::operator++(int)
{
  return ++(*this);
}

bool GraphVertexIterator::operator==(const GraphVertexIterator& rhs) const
{
//  return m_current == *rhs;
}

bool GraphVertexIterator::operator!=(const GraphVertexIterator& rhs) const
{
//  return m_current != *rhs;
}

