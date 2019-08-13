//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

//cpptrees - a tree structure library.
//Dev start date: 07/03/2019

#include <cpptrees.so>
using namespace std;

void testBinaryTree()
{
  BinaryTree<int> testTree;
  BinaryTree<int> testTree2;
  BinaryIterator<int> testIter;

  //Test Insert
  testTree.insert(1);
  testTree.insert(4);
  testTree.test_display();
  //Test assignment
  cout << "Copying tree 1 to tree 2 and printing tree 2:\n";
  testTree2 = testTree;
  testTree2.test_display();
  //Test max_size
  cout << "Current size: " << testTree.size() << endl;
  cout << "If full, size: " << testTree.max_size() << endl;
  //Test Swap
  cout << "Add 3 to one, Swap then display.\n";
  testTree2.insert(3);
  testTree.swap(testTree2);
  testTree.test_display();
  //Test Iterators
  testIter = testTree.begin();
  cout << "Got iterator, data at begin(): " << testIter->data << endl;
  testIter = testTree.end();
  cout << "Got iterator, data at end(): " << testIter->data << endl;
  --testIter;
  cout << "--iterator, data at that point: " << testIter->data << endl;
  
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
