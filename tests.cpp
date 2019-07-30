//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

//cpptrees - a tree structure library.
//Dev start date: 07/03/2019

#include "tree.h"
using namespace std;

void testBinaryTree()
{
  BinaryTree<int> testTree;

  //Test Insert
  testTree.insert(1);
  testTree.insert(4);
  testTree.test_display();

  //Test max_size
  cout << "Current size: " << testTree.size() << endl;
  cout << "If full, size: " << testTree.max_size() << endl;

  //Test Clear
  cout << "Clearing tree...\n";
  cout << testTree.clear() << " nodes deleted.\n";
  testTree.test_display();
  
  
}

int main()
{
  testBinaryTree();
  return 0;
}
