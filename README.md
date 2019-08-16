cpptrees
=======
A tree data structure library for c++, made to be
compatible with the GNU compiler.

Copyright © 2019 Bradley Thompson


## Overview

This library will contain tree structure class templates.
These should mimic the C Standard Template Library's 
Containers.

The end product should provide most of the common
functionality in an STL container. Therefore, the 
end goal will be efficiently implemented tree class
templates that should be easy to utilize in any project.

## How to install
*Note*: I followed [this video](https://www.youtube.com/watch?v=nnP81fMdWcg&t=264s)
when figuring out how to make a shared library. Don't know if that counts as plagiarism
when followed so I am including this just in case.

1. Clone or download the contents of the repo.
2. Type "make" to make the shared object (.so) file and tests, or just "make cpptrees" to
make the .so file alone.
3. Find where in your system libraries are stored (I used one of the four places in linux
systems: usr/lib) and mv the .so file there.
> Note: This likely requires administrator privileges.
4. Include the library in whatever .cpp file you'd like to use it in. 

**ALTERNATIVELY JUST #include "tree.h" WITH tree.cpp AND tree.h IN THE CWD IF YOU WANT
TO USE THIS WITHOUT THE HASTLE OF INSTALLING AS A LIBRARY (OR DON'T HAVE ADMIN PRIVELEGES)**

## How to use

If you know how to use the average STL container, you can use cpptrees.
The BST class "BinaryTree" is essentially a set and has the same functionality.

* Objects of this class template require a type to be denoted, which is the
type of data that will be stored in the node structures within the tree.

> Example: BinaryTree\<int\> numTree;

* find, begin, end, cbegin and cend all return BinaryIterator objects by
reference. Use these if you want to be able to iterate through the tree
using a for...each loop.

* empty reports whether a given tree object has data in it.

* size reports the current number of data entries in the tree.

* max_size reports the potential size of the tree, were it a full tree.

* insert adds an object of type T into the tree.

* swap exchanges the contents of one tree object with another.

* clear deletes all contents of a tree.

* count reports the number of times some piece of data occurs in the tree.



## Roadmap

* BST complete by end of term
---
#### Development planned to be implemented after Summer 2019:
* Refactor to use a single-inheritance hierarchy
* 2-3-4 Trees implemented.


## License

Licensed under the "MIT license", please reference LICENSE for more details.
