#ifndef BTREE_H
#define BTREE_H

class btree
{
private:
  struct node {
      int key;
      node* left;
      node* right;
  };
  node* root;
  node* CreateLeaf(int);
  void AddNode(int, node*);
  void PrintTree(node*);
public:
  btree();
  void AddKey(int);
  void Print();
};

#endif
