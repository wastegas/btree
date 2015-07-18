#include <iostream>
#include <cstdlib>
#include "Btree.h"

template class Btree<int>;
template class Btree<float>;
template class Btree<double>;

template<class T>
Btree<T>::Btree()
{
  root = NULL;
}

template<class T>
Btree<T>::~Btree()
{
}

template<class T>
typename Btree<T>::node* Btree<T>::CreateLeaf(const T& key)
{
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;

  return n;
}

template<class T>
void Btree<T>::AddKey(const T& key)
{
  AddNode(key, root);
}

template<class T>
void Btree<T>::AddNode(const T& key, typename Btree<T>::node* ptr)
{
  if (root == NULL) {
    root = CreateLeaf(key);
  }
  else if(key < ptr->key) {
    if(ptr->left != NULL) {
      AddNode(key, ptr->left);
    }
    else {
      ptr->left = CreateLeaf(key);
    }
  }
  else if(key > ptr->key) {
    if(ptr->right != NULL) {
      AddNode(key, ptr->right);
    }
    else {
      ptr->right = CreateLeaf(key);
    }
  }
  else
   std::cout << "Key " << key << " already exist in tree.\n"; 
}

template<class T>
void Btree<T>::Print()
{
  PrintTree(root);
}

template<class T>
void Btree<T>::PrintTree(typename Btree<T>::node* ptr)
{
  if (root != NULL) {
    if(ptr->left != NULL) {
      PrintTree(ptr->left);
    }
    std::cout << ptr->key << " ";
    if(ptr->right != NULL) {
      PrintTree(ptr->right);
    }
  }
  else {
    std::cout << "Tree is empty.\n";
  }
}
