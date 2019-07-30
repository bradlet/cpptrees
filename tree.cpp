//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

using namespace std;

//This file is the implementation file for a binary tree.
//It doesn't have a main and must be included in the
//header file so that the compiler can "see" the member
//methods' implementations. Outside of that, specific
//method instantiations for each type would be necessary.


template <class T>
BinaryTree<T>::BinaryTree(): root(NULL), num_nodes(0){}

template <class T>
BinaryTree<T>::~BinaryTree()
{
  clear(root); 
}


/* Iterators */


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

//Returns the tree's height.
template<class T>
int BinaryTree<T>::height(node* root)
{
  if (root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right)); 
} 


/* Element Access & Modifiers */

//Recursive helper for insert(T)
template<class T>
int BinaryTree<T>::insert(node* & root, T to_insert)
{
  if (!root)
  {
    root = new node;
    root->data = to_insert; //Assumption: = deep copies 
    root->left = NULL;
    root->right = NULL; 
    ++num_nodes;
    return 1;
  }
  if (to_insert < root->data)
    return insert(root->left, to_insert);
  return insert(root->right, to_insert);
}

//Insert an object of type T into the tree.
//Returns 1 on success, 0 on failure.
//Note: type T must have functioning < and > operators
template <class T>
int BinaryTree<T>::insert(T to_insert)
{
  return insert(root, to_insert);
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



