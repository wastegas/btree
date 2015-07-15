#include <iostream>
#include <cstdlib>
#include "btree.h"

template class btree<int>;
template class btree<float>;
template class btree<double>;

template<class T>
btree<T>::btree()
{
  root = NULL;
}

template<class T>
btree<T>::~btree()
{
}

template<class T>
typename btree<T>::node* btree<T>::CreateLeaf(const T& key)
{
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;

  return n;
}

template<class T>
void btree<T>::AddKey(const T& key)
{
  AddNode(key, root);
}

template<class T>
void btree<T>::AddNode(const T& key, typename btree<T>::node* ptr)
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
void btree<T>::Print()
{
  PrintTree(root);
}

template<class T>
void btree<T>::PrintTree(typename btree<T>::node* ptr)
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
