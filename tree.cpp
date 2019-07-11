//Bradley Thompson

#include <iostream>

//This file is the implementation file for a generic tree.
//It doesn't have a main and must be included in the
//header file so that the compiler can "see" the member
//methods' implementations. Outside of that, specific
//method instantiations for each type would be necessary.

/*
void tree::set_data()
{
  data = 7;
  cout << data << endl;
}
*/

template<typename T>
void subtree<T>::set_data()
{
  tree<T>::root = new typename tree<T>::node; 
  tree<T>::root -> data = 6;
  cout << tree<T>::root->data << endl;
  delete tree<T>::root;
} 

