//Bradley Thompson
//This file is the implementation file for a binary tree.
//It doesn't have a main and must be included in the
//header file so that the compiler can "see" the member
//methods' implementations. Outside of that, specific
//method instantiations for each type would be necessary.


template <class T>
BinaryTree<T>::BinaryTree(): root(NULL){}


/* Iterators */


/* Capacity */

template <class T>
bool BinaryTree<T>::empty()
{
  if (!root)
    return true;
  return false;
}


/* Element Access & Modifiers */

//Recursive function for insert(T)
//Note: type T must have functioning < and > operators
template<class T>
int BinaryTree<T>::insert_helper(node* & root, T to_insert)
{
  if (!root)
  {
    root = new node;
    root->data = to_insert; //Assumption: = deep copies 
    left = NULL;
    right = NULL; 
    return 1;
  }
  if (to_insert < root->data)
    return insert_helper(root->left, to_insert);
  return insert_helper(root->right, to_insert);
}

//Insert wrapper
template <class T>
int BinaryTree<T>::insert(T to_insert)
{
  return insert_helper(root, to_insert);
}

