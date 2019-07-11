//Bradley Thompson
//This file contains the generic tree class definition.


template <typename T>
class tree
{
  public:
    //tree(); ~tree();
    void set_data();

  protected:
    struct node
    {
      T data;
      node* next;     
    } *root;

  private:

};

template <typename T>
class subtree : public tree<T>
{
  public:
    void set_data();

  private:

};

#include "tree.cpp"
