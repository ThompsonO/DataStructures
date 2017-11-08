/*
  File: node.h
  Author: Oliver Thompson
  Node Class with two pointers

  Class: Node
  A doubly-linked node.

    Variable: f
    Provides the front-link by pointing to the node in front of this node.

    Variable: b
    Provides the back-link by pointing to the node back behind this node.

    Variable: data
    The contents of the node.
*/
#ifndef NODE_H
#define NODE_H

template<typename generic>
struct Node
{
  Node<generic>* f;
  Node<generic>* b;
  generic data;
};

#endif 


