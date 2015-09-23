#include <iostream>
#include <cstdlib>
#include <string>
#include "Btree.h"
namespace wastegas {
    template class Btree<int>;
    template class Btree<char>;
    template class Btree<float>;
    template class Btree<double>;
    template class Btree<std::string>;

    template<class T>
    Btree<T>::Btree()
    {
      root = nullptr;
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
      n->left = nullptr;
      n->right = nullptr;

      return n;
    }

    template<class T>
    void Btree<T>::AddKey(const T& key)
    {
      AddNode(key, root);
    }

    template<class T>
    void Btree<T>::AddNode(const T& key, Btree<T>::node* ptr)
    {
      if (root == nullptr) {
        root = CreateLeaf(key);
      }
      else if(key < ptr->key) {
        if(ptr->left != nullptr) {
          AddNode(key, ptr->left);
        }
        else {
          ptr->left = CreateLeaf(key);
        }
      }
      else if(key > ptr->key) {
        if(ptr->right != nullptr) {
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
      if (root != nullptr) {
        if(ptr->left != nullptr) {
          PrintTree(ptr->left);
        }
        std::cout << ptr->key << " ";
        if(ptr->right != nullptr) {
          PrintTree(ptr->right);
        }
      }
      else {
        std::cout << "Tree is empty.\n";
      }
    }
    }
