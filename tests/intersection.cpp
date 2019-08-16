//Bradley Thompson

/*  This program is released under the "MIT Lecense".
    Please refer to the file LICENSE for more information. */ 

//This is a test to show general functionality of a BinaryTree,
//which can be seen, essentially, as an STL set. So, this test
//shows the intersection of two sets.

#include "../tree.h"
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#define USAGE_ABORT(c) {printf("Usage: ./intersect.o [num_elements] [upper_bound] [num_tests]\n"); return -1;}

int main(int argc, char* argv[])
{
  BinaryTree<int> Tree1;
  BinaryTree<int> Tree2;
  BinaryTree<int> Tree3;
  BinaryIterator<int> Iter1;
  BinaryIterator<int> Iter1End;
  BinaryIterator<int> Iter2;
  BinaryIterator<int> Iter2End;
 
  if (argc != 4)
    USAGE_ABORT(argv[0]); 

  int up_bound = atoi(argv[2]);
  int num_elements = atoi(argv[1]);
  int num_tests = atoi(argv[3]);
  time_t tm;  
  time(&tm); 
  srand((int)tm); 


  //Runs the test however many times was decided via the command line arg
  for (int i = 0; i < num_tests; ++i)
  {
    //Load Trees 
    for (int i = 0; i < num_elements; ++i)
      Tree1.insert(rand() % up_bound);
    for (int i = 0; i < num_elements; ++i)
      Tree2.insert(rand() % up_bound);

    //Get Iterators
    Iter1 = Tree1.begin();
    Iter1End = Tree1.end();
    Iter2 = Tree2.begin();
    Iter2End = Tree2.end();
   
    Tree1.test_display();
    Tree2.test_display(); 
    while (Iter1 < Iter1End)
    {
      while (Iter2 < Iter2End)
      {
        if ((Iter1 == Iter2) && (Tree3.count(Iter1->data) == 0))
          Tree3.insert(Iter1->data);
        ++Iter2;
      }
      //Ugly, but do it one more time cuase I currently don't handle
      //The very last entry in the tree
      if ((Iter1 == Iter2) && (Tree3.count(Iter1->data) == 0))
        Tree3.insert(Iter1->data);
        
      ++Iter1; 
    }
    //Ugly, but do it one more time cuase I currently don't handle
    //The very last entry in the tree
    if ((Iter1 == Iter2) && (Tree3.count(Iter1->data) == 0))
      Tree3.insert(Iter1->data);
    
    cout << "Intersection:\n"; 
    Tree3.test_display();

    Tree1.clear();
    Tree2.clear();
    Tree3.clear();
  }

  return 0;
}
