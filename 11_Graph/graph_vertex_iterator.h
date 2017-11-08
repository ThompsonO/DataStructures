/*
  File: graph_vertex_iterator.h
  Programmer: Oliver Thompson
  Makes iterators for vertecies of graphs.

  Class: GraphVertexIterator
  Iterates through vertexes.

  Constructor: GraphVertexIterator()
  Makes a new iterator.

  Constructor: GraphVertexIterator(Vertex x);
  Makes a new iterator with m_current at x.

    Parameters:
    x - The vertex to start at.

  Function: const Vertex& operator*() const
  Returns the vertex that m_current is currently at.

  Function: GraphVertexIterator& operator++()
  Pre increment that moves to the next vertex in the graph.

  Function: GraphVertexIterator& operator++(int)
  Post increment that moves to the next vertex in the graph.

    Parameters:
    int - A dummy variable to distinguish between pre and post increments.

  Function: bool operator==(const GraphVertexIterator& rhs) const
  Returns true if m_current the same as rhs m_current.

    Parameters:
    rhs - The iterator to be compared to.

  Function: bool operator!=(const GraphVertexIterator& rhs) const
  Returns true if m_current is different than rhs m_current.

    Parameters:
    rhs - The iterator to be compared to.
*/
#ifndef GRAPH_VERTEX_ITERATOR_H
#define GRAPH_VERTEX_ITERATOR_H

#include<stdexcept>
using std::out_of_range;
#include"graph.h"

class GraphVertexIterator
{
 public:
  friend class Graph;
  GraphVertexIterator();
  GraphVertexIterator(Vertex x);
  const Vertex& operator*() const;
  GraphVertexIterator& operator++();
  GraphVertexIterator& operator++(int);
  bool operator==(const GraphVertexIterator& rhs) const;
  bool operator!=(const GraphVertexIterator& rhs) const;

 private:
  Vertex m_current;
};

#include"graph_vertex_iterator.hpp"
#endif

