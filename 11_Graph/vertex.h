/*
  File: vertex.h
  Author: Oliver Thompson
  Creates vertecies

  Class: Vertex
  A vertex in a graph.
  
  Constructor: Vertex()
  Creates a new vertex with an empty name.

  Constructor: Vertex(string a_name).
  Creates a new vertex with name = a_name.
  
    Parameters:
    a_name - the name of the vertex.
    
  Destructor: ~Vertex()
  Clears the name and destroys the vertex.
  
  Function: void v_clear()
  Clears name.

  Function: Vertex& operator=(Vertex& rhs)
  Sets *this vertex equal to rhs.
  
    Parameters:
    rhs - The vertex to be copied.
  
  Function: bool operator==(Vertex& rhs)
  Returns true if the name variable is the same for both vertecies.
  
    Parameters:
    rhs - The vertex to be compared to.

  Function: bool operator!=(Vertex& rhs)
  Returns true if the name variable is different for both vertecies.

    Parameters:
    rhs - The vertex to be compared to.
*/
#ifndef VERTEX_H
#define VERTEX_H

#include<string>
#include<stdexcept>
using namespace std;

class Vertex
{
 public:
  Vertex();
  Vertex(string a_name);
  ~Vertex ();
  void v_clear();
  Vertex& operator=(Vertex& rhs);
  bool operator==(Vertex& rhs);
  bool operator!=(Vertex& rhs);
  string m_name;
};

#include "vertex.hpp"
#endif

