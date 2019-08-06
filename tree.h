//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

#include <iostream>

//This file contains the Binary Search Tree class definition.

/* Eventually, generic tree(?):
template <typename T>
class tree
*/

/*
First phase container methods to provide:
begin, end, (maybe)rbegin, rend, 
(maybe) const operators, erase, swap, 
*/

template <class T>
class BinaryTree;

template <class T>
class BinaryIterator
{
  public:
  BinaryIterator();
  ~BinaryIterator();
  T*& operator*();
  T& operator->();
  BinaryIterator<T>& operator++();
  BinaryIterator<T>& operator--();
  private:
    friend class BinaryTree<T>;
    struct node {
      T data;
      node* parent = NULL;
      node* left = NULL;
      node* right = NULL;
    } *cur;
};

template <class T>
class BinaryTree
{
  public:
    BinaryTree(); 
    ~BinaryTree();
    BinaryTree<T>& operator=(BinaryTree<T> *&);

    BinaryIterator<T>& find(T to_find);
    BinaryIterator<T>& begin();
    BinaryIterator<T>& end();
    bool empty(); 
    int size();
    int max_size();
    int insert(T); 
    int clear();

    void test_display();

  private:
    struct node { //T needs default constructor/destructor.
      T data;
      node* parent = NULL;
      node* left = NULL;
      node* right = NULL;
    } *root;
    int num_nodes;

    int find(node*& root, node*& to_set, T to_find);
    int copy_tree(node*& filled, node* parent, node*& copied);
    int insert(node*& current, node* parent, T);
    int height(node*);
    int clear(node*&);
    void test_display(node*);
};

#include "tree.cpp"
