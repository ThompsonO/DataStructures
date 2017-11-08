/*  
  File: btn.h
  Author: Oliver Thompson
  Struct for binary tree nodes
*/

#ifndef BTN_H
#define BTN_H

template<typename generic>
struct BTN
{
    BTN* p;
    BTN* l;
    BTN* r;
    generic* data;
};

#endif

