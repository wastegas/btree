#ifndef BTREE_H
#define BTREE_H
namespace wastegas {
    template<class T>
    class Btree
    {
    private:
      struct node {
          T key;
          node* left;
          node* right;
      };
      node* root;
      node* CreateLeaf(const T&);
      void AddNode(const T&, node*);
      void PrintTree(node*);
    public:
      Btree();
      ~Btree();
      void AddKey(const T&);
      void Print();
    };
}
#endif
