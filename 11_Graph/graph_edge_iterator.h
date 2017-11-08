/*
  File: graph_edge_iterator.h
  Programmer: Oliver Thompson
  Makes iterators for edges of graphs.

  Class: GraphEdgeIterator
  Iterates through edges.

  Constructor: GraphEdgeIterator()
  Makes a new iterator.

  Constructor: GraphEdgeIterator(Edge x);
  Makes a new iterator with m_current at x.

    Parameters:
    x - The vertex to start at.

  Function: const Edge& operator*() const
  Returns the Edge that m_current is currently at.

  Function: GraphEdgeIterator& operator++()
  Pre increment that moves to the next edge in the graph.

  Function: GraphEdgeIterator& operator++(int)
  Post increment that moves to the next edge in the graph.

    Parameters:
    int - A dummy variable to distinguish between pre and post increments.

  Function: bool operator==(const GraphEdgeIterator& rhs) const
  Returns true if m_current the same as rhs m_current.

    Parameters:
    rhs - The iterator to be compared to.

  Function: bool operator!=(const GraphEdgeIterator& rhs) const
  Returns true if m_current is different than rhs m_current.

    Parameters:
    rhs - The iterator to be compared to.
*/

#ifndef GRAPH_EDGE_ITERATOR_H
#define GRAPH_EDGE_ITERATOR_H

#include<stdexcept>
using std::out_of_range;
#include"graph.h"

class GraphEdgeIterator
{
 public:
  friend class Graph;
  GraphEdgeIterator();
  GraphEdgeIterator(Edge x);
  const Edge& operator*() const;
  GraphEdgeIterator& operator++();
  GraphEdgeIterator& operator++(int);
  bool operator==(const GraphEdgeIterator& rhs) const;
  bool operator!=(const GraphEdgeIterator& rhs) const;

 private:
  Edge m_current;
};

#include"graph_edge_iterator.hpp"
#endif

