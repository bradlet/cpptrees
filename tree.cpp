//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

using namespace std;

/*
This file is the implementation file for a binary tree.
It doesn't have a main and must be included in the
header file so that the compiler can "see" the member
methods' implementations. Outside of that, specific
method instantiations for each type would be necessary.

This file also contains the implementation for a BinaryIterator,
which is the type of iterator supplied by many methods contained
within the BinaryTree class template.
*/


template <class T>
BinaryIterator<T>::BinaryIterator(): cur(NULL){}

template <class T>
BinaryIterator<T>::~BinaryIterator()
{
  cur = NULL;
}

template <class T>
T*& BinaryIterator<T>::operator*()
{
  return &(cur->data);
}

template <class T>
T& BinaryIterator<T>::operator->()
{
  return cur->data;
}

template <class T>
BinaryIterator<T>& BinaryIterator<T>::operator++()
{
  if (cur->right)
    cur = cur->right;
  else
  {
    if (cur->parent && (cur->parent->data >= cur->data))
      cur = cur->parent;
  }
  return *this;   
}

template <class T>
BinaryIterator<T>& BinaryIterator<T>::operator--()
{
  if (cur->left)
    cur = cur->left;
  else
  {
    if (cur->parent && (cur->parent->data <= cur->data))
      cur = cur->parent;
  }
  return *this;
}


template <class T>
BinaryTree<T>::BinaryTree(): root(NULL), num_nodes(0){}

template <class T>
BinaryTree<T>::~BinaryTree()
{
  clear(root); 
}

//Destructive -- overwrites this object's contents
template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> *& copy)
{
  if (this == copy)
    return *this;
  clear(root);

  if (copy_tree(root, NULL, copy->root) != copy->num_nodes)
    cerr << "Assignment Failed.\n"; 
  else
    num_nodes = copy->num_nodes;
  
  return *this;
}

/* Iterators */

template <class T>
BinaryIterator<T>& BinaryTree<T>::find(T to_find)
{
  BinaryIterator<T>* search = new BinaryIterator<T>;
  
  find(root, search->cur, to_find);
  return *search;
}

template <class T>
BinaryIterator<T>& BinaryTree<T>::begin()
{
  BinaryIterator<T>* begin = new BinaryIterator<T>;
  node* cur = root;
 
  if (cur)
  { 
    while(cur->left)
      cur = cur->left; 
  }
  begin->cur = cur;
  return *begin;
}

template <class T>
BinaryIterator<T>& BinaryTree<T>::end()
{
  BinaryIterator<T>* end = new BinaryIterator<T>;
  node* cur = root;  
  
  if (cur)
  {
    while(cur->right)
      cur = cur->right;
  }
  end->cur = cur;
  return *begin;
}

/* Capacity */

//Returns true if empty, false if not.
template <class T>
bool BinaryTree<T>::empty()
{
  if (!root)
    return true;
  return false;
}

//Return number of nodes currently in the tree.
template <class T>
int BinaryTree<T>::size()
{
  return num_nodes;
}

//Return size the tree would be if full.
template <class T>
int BinaryTree<T>::max_size()
{
  int sum = 2;
  for (int i = 1; i < height(root); ++i)
    sum = (2*sum); 
  return sum - 1;
}


/* Element Access & Modifiers */

//Insert an object of type T into the tree.
//Returns 1 on success, 0 on failure.
//Note: type T must have functioning < and > operators
template <class T>
int BinaryTree<T>::insert(T to_insert)
{
  return insert(root, NULL, to_insert);
}

//Deletes all nodes in the tree
//returns # of nodes deleted.
template <class T>
int BinaryTree<T>::clear()
{
  int deleted = clear(root);
  num_nodes -= deleted;
  if (num_nodes > 0)
    cerr << "Nodes deleted != previous tree size\n";
  return deleted;
}


/* Helpers */

template <class T>
int BinaryTree<T>::find(node* & root, node* & to_set, T to_find)
{
  if (!root)
    return 0;
  if (root->data == to_find) //Assumption: T has == operator 
  {
    to_set = root;
    return 1;
  }
  return find(root->left, to_set, to_find) + 
         find(root->right, to_set, to_find);
}

template <class T>
int BinaryTree<T>::copy_tree(node* & root, node* parent, node* & copy)
{
  if (copy == NULL)
  {
    root == NULL;
    return 0;
  }
  root = new node;
  root->data = copy->data;
  root->parent = parent; 
  return 1 + copy_tree(root->left, root, copy->left) 
           + copy_tree(root->right, root, copy->right);
}

//Recursive helper for insert(T)
template<class T>
int BinaryTree<T>::insert(node* & root, node* parent, T to_insert)
{
  if (!root)
  {
    root = new node;
    root->data = to_insert; //Assumption: = deep copies 
    root->parent = parent; 
    root->left = NULL;
    root->right = NULL; 
    ++num_nodes;
    return 1;
  }
  if (to_insert < root->data)
    return insert(root->left, root, to_insert);
  return insert(root->right, root, to_insert);
}

//Returns the tree's height.
template<class T>
int BinaryTree<T>::height(node* root)
{
  if (root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right)); 
} 

//Recursive helper for clear()
template <class T>
int BinaryTree<T>::clear(node* & root)
{
  if (root == NULL)
    return 0;
  int ret = clear(root->left) + clear(root->right);
  delete root;
  root = NULL;
  return ret + 1;
}


/* Testing */

//Outputs contents of tree in-order to standard out.
template <class T>
void BinaryTree<T>::test_display(node* root)
{
  if (root == NULL)
    return;
  test_display(root->left);
  cout << " -> " << root->data;
  test_display(root->right);
}

template <class T>
void BinaryTree<T>::test_display()
{
  cout << "In-order traversal";
  test_display(root);
  cout << endl;
}



