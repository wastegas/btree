#include <iostream>
#include "btree.h"

int main()
{
  btree tree;

  int key[5] = {3, 6, 1, 10, 5};

  for (int i = 0; i < 5; i++)
    {
      tree.AddKey(key[i]);
    }
  tree.Print();

  std::cout << std::endl;

  return 0;
}
