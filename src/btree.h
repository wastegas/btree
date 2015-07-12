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
public:
  btree();
  void AddKey(int);
};
