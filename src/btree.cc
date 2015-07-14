#include <iostream>
#include <cstdlib>
#include "btree.h"

btree::btree()
{
  root = NULL;
}

btree::node* btree::CreateLeaf(const int& key)
{
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;

  return n;
}

void btree::AddKey(const int& key)
{
  AddNode(key, root);
}

void btree::AddNode(const int& key, node* ptr)
{
  if (root == NULL)
    {
      root = CreateLeaf(key);
    }
  else if(key < ptr->key)
    {
      if(ptr->left != NULL)
        {
          AddNode(key, ptr->left);
        }
      else
        {
         ptr->left = CreateLeaf(key);
        }
    }
  else if(key > ptr->key)
    {
     if(ptr->right != NULL)
       {
        AddNode(key, ptr->right);
       }
     else
       {
        ptr->right = CreateLeaf(key);
       }
    }
  else
   std::cout << "Key " << key << " already exist in tree.\n"; 
}

void btree::Print()
{
  PrintTree(root);
}

void btree::PrintTree(node* ptr)
{
  if (root != NULL)
    {
      if(ptr->left != NULL)
        {
          PrintTree(ptr->left);
        }
      std::cout << ptr->key << " ";
      if(ptr->right != NULL)
        {
          PrintTree(ptr->right);
        }
    }
  else
    {
      std::cout << "Tree is empty.\n";
    }
}
