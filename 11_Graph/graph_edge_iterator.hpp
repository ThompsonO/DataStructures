/*
  File: graph_edge_iterator.hpp
  Programmer: Oliver Thompson
  Makes iterators for edges of graphs.
*/

GraphEdgeIterator::GraphEdgeIterator()
{}

GraphEdgeIterator::GraphEdgeIterator(Edge x):m_current(x)
{}

const Edge& GraphEdgeIterator::operator*() const
{
  return m_current;
}

GraphEdgeIterator& GraphEdgeIterator::operator++()
{
/*  int index = 0;

  for(int i=0; i<m_edge.size(); i++)
  {
    if(m_current == m_edge[i])
    {
      index = i;
    }
  }

  if(index < m_edge.size())
  {
    m_current = m_edge[(index+1)];
  }
*/
  return *this;
}

GraphEdgeIterator& GraphEdgeIterator::operator++(int)
{
  return ++(*this);
}

bool GraphEdgeIterator::operator==(const GraphEdgeIterator& rhs) const
{
//  return m_current == *rhs;
}

bool GraphEdgeIterator::operator!=(const GraphEdgeIterator& rhs) const
{
//  return m_current != *rhs;
}

