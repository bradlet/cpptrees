//Bradley Thompson
//This file contains the generic tree class definition.

#include <iostream>
#include <cstdlib>

/* Eventually, generic tree(?):
template <typename T>
class tree
*/

/*
First phase container methods to provide:
constructor, destructor, operator=, begin, end,
(maybe)rbegin, rend, (maybe) const operators,
empty, size, max_size, insert, erase, swap, 
clear, emplace, clear, front, back.
beyond those, maybe more of the list methods.
*/

template <class T>
class BinaryTree
{
  public:
    BinaryTree(); ~BinaryTree();
    //Iterators

    //Capacity
    bool empty(); 
  
    //Element Access & Modifiers
    int insert(T);  

  private:
    struct node {
      T data;
      node* left = NULL;
      node* right = NULL;
    } *root;

    //Helper Functions:
    int insert_helper(node*&, T);
};

#include "tree.cpp"
