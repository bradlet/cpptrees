//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

//cpptrees - a tree structure library.
//Dev start date: 07/03/2019

//This is my personal testing file

#include "../tree.h"
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
  //Test Swap
  cout << "Add 3 to tree 2, Swap then display tree 1.\n";
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
  testTree.clear();
  cout << "Current size: " << testTree.size() << endl;
  //Test count, size, max_size
  cout << "Inserting 8 six times, testing count:\n";
  int x = 8;
  for (int i = 0; i < 6; ++i)
    testTree.insert(x);
  cout << "Current size: " << testTree.size() << endl;
  cout << "If full, size: " << testTree.max_size() << endl;
  cout << "8 occurs in the tree " << testTree.count(x) <<  " times.\n";
}

void testSwap()
{
  BinaryTree<int> testTree;
  BinaryTree<int> testTree2;

  testTree.insert(1);
  testTree.insert(4);
  cerr << "SWAP:\n";
  testTree.swap(testTree2);
  cout << "size: " << testTree.size() << endl;
  cout << "clear: ";
  testTree.clear();
  cout << "size: " << testTree.size() << endl;
  cout << "clear: ";
  testTree2.clear();
  cerr << "END" << endl;
}

int main()
{
  testBinaryTree();
  //testSwap();

  return 0;
}
