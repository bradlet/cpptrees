//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

#include <iostream>

//This file contains the Binary Search Tree class definition,
//as well as the Iterator for that class template. That iterator,
//BinaryIterator, is essentially a smart pointer that knows how to
//iterate through tha tree.

#define SWAP(x,y) {x=x+y; y=x-y; x=x-y;}

template <class T>
class BinaryTree;

template <class T>
struct bstNode 
{
  T data;
  bstNode<T>* parent = NULL;
  bstNode<T>* left = NULL;
  bstNode<T>* right = NULL;
};

template <class T>
class BinaryIterator
{
  public:
    BinaryIterator();
    ~BinaryIterator();
    BinaryIterator<T>& operator=(BinaryIterator<T> &);
    BinaryIterator<T>& operator++();
    BinaryIterator<T>& operator--();
    bstNode<T>& operator*();
    bstNode<T>* operator->();
  private:
    friend class BinaryTree<T>;
    bstNode<T>* cur;
};

template <class T>
class BinaryTree
{
  public:
    BinaryTree(); 
    ~BinaryTree();
    BinaryTree<T>& operator=(BinaryTree<T> &);

    BinaryIterator<T>& find(T to_find);
    BinaryIterator<T>& begin();
    BinaryIterator<T>& end();
    BinaryIterator<T>& cbegin() const;
    BinaryIterator<T>& cend() const;
    bool empty(); 
    int size();
    int max_size();
    int insert(T); 
    void swap(BinaryTree<T>&);
    void clear();
    //int erase(T & to_remove);
    //BinaryIterator<T>& erase(BinaryIterator<T> & to_delete);
    //BinaryIterator<T>& erase(BinaryIterator<T> & start, 
    //                         BinaryIterator<T> & end);
    int count(T&) const;
     
    void test_display();
  private:
    bstNode<T>* root;
    int num_nodes;

    int find(bstNode<T>*& root, bstNode<T>*& iter_ptr, T to_find);
    int copy_tree(bstNode<T>*& filled, 
                  bstNode<T>* parent, bstNode<T>*& copied);
    int insert(bstNode<T>*& current, bstNode<T>* parent, T);
    int height(bstNode<T>*);
    int clear(bstNode<T>*&);
    int count(bstNode<T>*, T&) const;
    void test_display(bstNode<T>*);
};

#include "tree.cpp"
