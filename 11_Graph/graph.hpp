/*
  File: graph.hpp
  Programmer: Oliver Thompson
  Creates graphs.
*/

Graph::Graph()
{}

Graph::Graph(const Graph& copy)
{
  *this = copy;
}

Graph::~Graph()
{
  clear();
}

Graph& Graph::operator=(const Graph& copy)
{
/*  GraphVertexIterator vertz(copy.v_begin());
  for(int i=0; i<v_size(); i++)
  {
    m_vertex.push_back(*vertz);
    vertz++;
  }

  GraphEdgeIterator edgez(copy.e_begin());
  for(int i=0; i<e_size(); i++)
  {
    m_edge.push_back(*edgez);
    edgez++;
  }
*/}

void Graph::add_vertex(Vertex& insert)
{
  m_vertex.push_back(insert);
}

void Graph::add_edge(Edge& insert)
{
  m_edge.push_back(insert);
}

void Graph::remove_vertex(unsigned int index)
{
  if(index < m_vertex.size())
  {
    m_vertex.erase(m_vertex.begin()+(index-1));
  }

  else
  {
    throw out_of_range("Index is out of bounds");
  }
}

void Graph::remove_edge(unsigned int index)
{
  if(index < m_edge.size())
  {
    m_edge.erase(m_edge.begin()+(index-1));
  }

  else
  {
    throw out_of_range("Index is out of bounds");
  }
}

void Graph::clear()
{
  m_vertex.clear();
  m_edge.clear();
}

vector<Vertex> Graph::quickest_path(Vertex& start, Vertex& end, 
                                  vector<Vertex> vertecies)
{/*
  vector<Edge> start_edges;
  vector< vector<Vertex> > path;

//Finds all edges connected to the starting point
  for(int i=0; i<m_edge.size(); i++)
  {
    if((m_edge[i]).get_start() == start || (m_edge[i]).get_end() == start)
    {
      start_edges.push_back(m_edge[i]);
    }
  }

//Adds all vertecies that are not the starting vertex and not previously used
  for(int i=0; i<start_edges.size(); i++)
  {
    if(start_edges[i].get_start() == start)
    {
      bool add = true;

      for(int j=0; j<vertecies.size(); j++)
      {
        if(start_edges[i].get_end() == vertecies[j])
        {
          add = false;
        }
      }

      if(add == true)
      {
        path.push_back(vertecies);
        path[i].push_back(start_edges[i].get_end());
      }
    }

    else
    {
      bool add = true;

      for(int j=0; j<vertecies.size(); j++)
      {
        if(start_edges[i].get_start() == vertecies[j])
        {
          add = false;
        }
      }

      if(add == true)
      {
        path.push_back(vertecies);
        path[i].push_back(start_edges[i].get_start());
      }
    }
  }

//Recursively calls function to find all possible paths
  for(int i=0; i<path.size(); i++)
  {
    if(path[i][path[i].size()-1] != end)
    {
//THIS LINE IS WHY THE FUNCTION IS COMMENTED!!!!!!!!!!
      path[i] = quickest_path(path[i][path[i].size()-1], end, path[i]);
    }
  }

//Finds the shortest path from all available options
  int shortestIndex=0;

  for(int i=0; i<path.size(); i++)
  {
    if(total_time(path[i]) < total_time(path[shortestIndex]))
    {
      shortestIndex = i;
    }
  }

//Returns the shortest path
  return path[shortestIndex];
*/}

float Graph::total_time(vector<Vertex> vertecies)
{
  vector<Edge> edges;
  float time = 0;
  for(int i=0; i<(vertecies.size()-1); i++)
  {
    for(int j=0; j<m_edge.size(); j++)
    {
      if((vertecies[i] == m_edge[j].get_start() || 
          vertecies[i] == m_edge[j].get_end())  && 
         (vertecies[(i+1)] == m_edge[j].get_start() || 
          vertecies[(i+1)] == m_edge[j].get_end()))
      {
        edges.push_back(m_edge[j]);
      }
    }
  }

  for(int i=0; i<edges.size(); i++)
  {
    time += edges[i].time();
  }

  return time;
}

Vertex Graph::v_begin()
{
  if(m_vertex.size() != 0)
  {
    return m_vertex[0];
  }
}

Edge Graph::e_begin()
{
  if(m_edge.size() != 0)
  {
    return m_edge[0];
  }
}

int Graph::v_size()
{
  return m_vertex.size();
}

int Graph::e_size()
{
  return m_edge.size();
}
