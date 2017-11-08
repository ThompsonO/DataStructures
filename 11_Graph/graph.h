/*
  File: graph.h
  Author: Oliver Thompson
  Creates graphs.

  Class: Graph
  A graph of vertecies and edges.
  
  Constructor: Graph()
  Creates a new graph with empty vectors of edges and vertecies.

  Constructor: Graph(const Graph& copy)
  Creates a new graph that is identical to copy.

    Parameters:
    copy - The graph to be copied.
    
  Destructor: ~Graph()
  Clears out m_vertex and m_edge and destroys the graph.
  
  Function: Graph& operator=(const Graph& copy)
  Checks if the member vectors are equivalent.
  
    Parameters:
    copy - The graph to be compared to.

  Function: void add_vertex(Vertex& insert)
  Adds insert to the vector of vertecies in the graph.

    Parameters:
    insert - The vertex to be inserted.

  Function: void add_edge(Edge& insert)
  Adds insert to the vector of edges in the graph.

    Parameters:
    insert - The edge to be inserted.

  Function: void remove_vertex(unsigned int index)
  Removes the vertex at the given index.

    Parameters:
    index - The index of the vertex to be removed.

  Function: remove_edge(unsigned int index)
  Removes the edge at the given index.

    Parameters:
    index - The index of the edge to be removed.

  Function: void clear()
  Clears the member variables.

  Function: vector<Vertex> quickest_path(Vertex& start, Vertex& end, 
                                         vector<Vertex> vertecies)
  Returns a vector of vertecies that represent the quickest path from the 
  start parameter to the end parameter.

    Parameters:
    start - The first vertex in the path.
    end - The destination.
    vertecies - A vector of vertecies that contains the start vertex.

  Function: float total_time(vector<Vertex> vertecies)
  Returns the total time to travel along a path of vertecies.

    Parameters:
    vertecies - A vector listing the path of vertecies to follow.

  Function: Vertex v_begin()
  Returns the first vertex in m_vertex.

  Function: Edge e_begin()
  Returns the first edge in m_edge.

  Function: int v_size()
  Returns the size of m_vertex.

  Function: int e_size()
  Returns the size of m_edge.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"
#include "graph_vertex_iterator.h"
#include "graph_edge_iterator.h"
#include<vector>
using namespace std;
class Graph
{
 public:
  Graph();
  Graph(const Graph& copy);
  ~Graph ();
  Graph& operator=(const Graph& copy);
  void add_vertex(Vertex& insert);
  void add_edge(Edge& insert);
  void remove_vertex(unsigned int index);
  void remove_edge(unsigned int index);
  void clear();
  vector<Vertex> quickest_path(Vertex& start, Vertex& end, 
                               vector<Vertex> vertecies);
  float total_time(vector<Vertex> vertecies);
  Vertex v_begin();
  Edge e_begin();
  int v_size();
  int e_size();

// private:
  vector<Vertex> m_vertex;
  vector<Edge> m_edge;
};

#include "graph.hpp"
#endif

