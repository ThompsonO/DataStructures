/*
  File: edge.h
  Author: Oliver Thompson
  Creates edges

  Class: Edge
  An edge.
  
  Constructor: Edge()
  Initialzes m_start and m_end to NULL and m_length and m_speed to 0.

  Constructor: Edge(Vertex start, Vertex end, float length, float speed)
  Initializes m_start to start, m_end to end, m_length to length, and m_speed
  to speed
  
    Parameters:
    start - The vertex at which the edge starts.
    end - The vertex at which teh edge ends.
    length - The length of the edge.
    speed - The speed traveled along the edge.

  Destructor: ~Edge()
  Clears all data in the edge and deletes it.

  Function: float time()
  Returns the time required to travel along the edge.

  Function: void set_start(Vertex& begin)
  Sets m_start to begin.

    Parameters:
    begin - the vertex where the edge begins.

  Function: Vertex& get_start() const
  Returns the vertex where the edge starts.

  Function: void set_end(Vertex& final)
  Sets m_end to final.

    Parameters:
    final - the vertex where the edge ends.

  Function: Vertex& get_end() const
  Returns the vertex where the edge ends.

  Function: void set_length(float distance)
  Sets m_length to distance.

    Parameters:
    distance - The new length of the edge.

  Function: float get_length() const
  Returns the value of m_length.

  Function: void set_speed(float rate)
  Sets m_speed to rate.

    Parameters:
    rate - The new speed of the edge.

  Function: float get_speed() const
  Returns the value of m_speed.

  Function: void clear()
  Clears all variables.

  Function: Edge& operator=(Edge& rhs)
  Sets all variables in this object equal to rhs.

    Parameters:
    rhs - The edge to copy.

  Function: bool operator==(Edge& rhs)
  Returns true if the member variables are equal to those of rhs.

    Parameters:
    rhs - The edge to compare to.
*/
#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"
class Edge
{
 public:
  Edge();
  Edge(Vertex& start, Vertex& end, float length, float speed);
  ~Edge ();
  float time();
  void set_start(Vertex& begin);
  Vertex& get_start();
  void set_end(Vertex& final);
  Vertex& get_end();
  void set_length(float distance);
  float get_length() const;
  void set_speed(float rate);
  float get_speed() const;
  void clear();
  Edge& operator=(Edge& rhs);
  bool operator==(Edge& rhs);

 private:
  Vertex m_start;
  Vertex m_end;
  float m_length;
  float m_speed;
};

#include "edge.hpp"
#endif

