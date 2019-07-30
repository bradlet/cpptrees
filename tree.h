//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

#include <iostream>

//This file contains the generic tree class definition.

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
    BinaryTree(); 
    ~BinaryTree();
    //operator=

    bool empty(); 
    int size();
    int max_size();
    int insert(T);  
    int clear();

    void test_display();

  private:
    struct node {  //T needs default constructor/destructor.
      T data;
      node* left = NULL;
      node* right = NULL;
    } *root;
    int num_nodes;

    int insert(node*&, T);
    int height(node*);
    int clear(node*&);
    void test_display(node*);
};

#include "tree.cpp"
