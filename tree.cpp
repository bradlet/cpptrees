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
BinaryIterator<T>& BinaryIterator<T>::operator=(BinaryIterator<T> & copy)
{
  cur = copy.cur;
  return *this;
}

template <class T>
bstNode<T>& BinaryIterator<T>::operator*()
{
  return cur;
}

template <class T>
bstNode<T>* BinaryIterator<T>::operator->()
{
  return cur;
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


/* Binary Tree */


template <class T>
BinaryTree<T>::BinaryTree(): root(NULL), num_nodes(0){}

template <class T>
BinaryTree<T>::~BinaryTree()
{
  clear();
}

//Destructive -- overwrites this object's contents
template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> & copy)
{
  if (this == &copy)
    return *this;
  clear();
  if (copy_tree(root, NULL, copy.root) != copy.num_nodes)
    cerr << "Assignment Failed.\n"; 
  else
    num_nodes = copy.num_nodes;
  
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
  bstNode<T>* cur = root;
 
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
  bstNode<T>* cur = root;  
  
  if (cur)
  {
    while(cur->right)
      cur = cur->right;
  }
  end->cur = cur;
  return *end;
}

template <class T>
BinaryIterator<T>& BinaryTree<T>::cbegin() const
{
  return begin();
}

template <class T>
BinaryIterator<T>& BinaryTree<T>::cend() const
{
  return end();
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

//Return number of bstNodes currently in the tree.
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

//swaps tree with another BinaryTree class.
template <class T>
void BinaryTree<T>::swap(BinaryTree<T> & swap_with)
{
  bstNode<T> *hold = swap_with.root;

  SWAP(num_nodes, swap_with.num_nodes);
  swap_with.root = root;
  root = hold;
}

//Deletes all bstNodes in the tree
//returns # of bstNodes deleted.
template <class T>
void BinaryTree<T>::clear()
{
  num_nodes -= clear(root);
  if (num_nodes != 0)
    cerr << "Nodes deleted != previous tree size\n";
}

//returns number of nodes containing the same data of
//type T as the argument.
template <class T>
int BinaryTree<T>::count(T & data) const
{
  return count(root, data);
}

//Removal functions, can take args of type T, an iterator, or
//a range of elements to erase via a start and end iterator.
template <class T>
int erase(T & to_remove)
{
  //find the node containing to remove (gives iterator)
  //  If it aint there return 0
  //if !right : left goes here
  //else if right but !right->left : right goes here
  //else : go to right's left till ->left == NULL and that goes here.
}


/* Helpers */

template <class T>
int BinaryTree<T>::find(bstNode<T>* & root, bstNode<T>* & iter_ptr, T to_find)
{
  if (!root)
    return 0;
  if (root->data == to_find) //Assumption: T has == operator 
  {
    iter_ptr = root;
    return 1;
  }
  return find(root->left, iter_ptr, to_find) + 
         find(root->right, iter_ptr, to_find);
}

template <class T>
int BinaryTree<T>::copy_tree(bstNode<T>* & root, bstNode<T>* parent, bstNode<T>* & copy)
{
  if (copy == NULL)
  {
    root = NULL;
    return 0;
  }
  root = new bstNode<T>;
  root->data = copy->data;
  root->parent = parent; 
  return 1 + copy_tree(root->left, root, copy->left) 
           + copy_tree(root->right, root, copy->right);
}

//Recursive helper for insert(T)
template<class T>
int BinaryTree<T>::insert(bstNode<T>* & root, bstNode<T>* parent, T to_insert)
{
  if (root == NULL)
  {
    root = new bstNode<T>;
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
int BinaryTree<T>::height(bstNode<T>* root)
{
  if (root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right)); 
} 

//Recursive helper for clear()
template <class T>
int BinaryTree<T>::clear(bstNode<T>* & root)
{
  if (root == NULL)
    return 0;
  int ret = clear(root->left) + clear(root->right);
  delete root;
  root = NULL;
  return ret + 1;
}

//Recursive helper for count()
//Returns the number of times the arg T data appears in the tree.
template <class T>
int BinaryTree<T>::count(bstNode<T>* root, T & data) const
{
  if (root == NULL)
    return 0;
  if (data == root->data)
    return 1 + count(root->left, data) + count(root->right, data);
  return count(root->left, data) + count(root->right, data);
}


/* Testing */

//Outputs contents of tree in-order to standard out.
template <class T>
void BinaryTree<T>::test_display(bstNode<T>* root)
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



