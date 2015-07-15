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
  node* CreateLeaf(const int&);
  void AddNode(const int&, node*);
  void PrintTree(node*);
public:
  btree();
  ~btree();
  void AddKey(const int&);
  void Print();
};

#endif
