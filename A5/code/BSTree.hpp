#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "BinaryTree.hpp"
#include <iostream>
using namespace std;
template <class Key,class Value>
class BSTree : public BinaryTree<Key, Value> {

/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
 public:
 BSTree();

  virtual int getHeight();
  virtual int size();
  virtual void print();
  virtual void remove(const Key& key);
  virtual bool has(const Key& key);	  
  virtual void put(const Key& key, const Value& value) ;
 virtual Value get(const Key& key);
  virtual Key minimum();
  virtual Key maximum();
  virtual Key successor(const Key& key);
  virtual Key predecessor(const Key& key);
  BinaryNode<Key,Value>* deleteNode(BinaryNode<Key,Value>* root,const Key& key);
};


template <class Key, class Value>
  BSTree<Key,Value>::BSTree()
  {
    this->root=NULL;
  }

template <class Key,class Value>
int heightutil(BinaryNode<Key,Value> *node)
{
  if (node==NULL) 
       return 0;
   else
   {
       int ld = heightutil(node->left);
       int rd = heightutil(node->right);
 
       if (ld > rd) 
           return(ld+1);
       else return(rd+1);
   }
}
template <class Key, class Value>
  int BSTree<Key,Value>::getHeight()
  {
    return heightutil(this->root);
  }
template <class Key,class Value>
  int sizeutil(BinaryNode<Key,Value> *node)
  {
    if (node==NULL) 
    return 0;
  else    
    return(sizeutil(node->left) + 1 + sizeutil(node->right));
  }

  template <class Key,class Value>
  int BSTree<Key,Value>::size()
  {
    return sizeutil(this->root);  
  }

template <class Key, class Value>
   void BSTree<Key,Value>::print()
   {
     this->print_in_order();
   }

  template <class Key,class Value>
BinaryNode<Key,Value>* BSTree<Key,Value>::deleteNode(BinaryNode<Key,Value>* root,const Key& key)
{
  if (root == NULL) 
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else
    {
        if (root->left == NULL)
        {
            BinaryNode<Key,Value>* temp = root->right;
            //root->right->parent=root->parent;
              if(root==this->root)
              {}
            else if(root->parent->left==root) 
            {   
                root->parent->left=root->right;
                if(root->right) root->right->parent=root->parent;
            }
            else if(root->parent->right==root) 
            {
              root->parent->right=root->right;
              if(root->right) root->right->parent=root->parent; 
            }
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            BinaryNode<Key,Value>* temp = root->left;
              if(root==this->root)
              {}
            else if(root->parent->left==root) 
              {
                root->parent->left=root->left;
                if(root->left) root->left->parent=root->parent;
                }
              else if(root->parent->right==root)
              {
                root->parent->right=root->left;
                if(root->left) root->left->parent=root->parent;
              }
            delete root;
            return temp;
        }
        BinaryNode<Key,Value> *tmp=root->right;
        while(tmp->left!=NULL)
        {
            tmp=tmp->left;
        }
        root->key = tmp->key;
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->key);
    }
    return root;
}

template <class Key,class Value>
   void BSTree<Key,Value>::remove(const Key& key)
   {
      this->root=deleteNode(this->root,key);
   }

   template <class Key,class Value>
   void findutil(BinaryNode<Key,Value> *root,const Key& key,Value& value)
   {
    if(root==NULL) return;
     if(key==root->key) 
     {value=root->val;return;}
     else if(key<root->key) findutil(root->left,key,value);
     else findutil(root->right,key,value);
   }

  template <class Key,class Value>
   bool BSTree<Key,Value>::has(const Key& key)
   {
     Value value=(Value)0;
     findutil(this->root,key,value);
     if(value==(Value)0) return false;
     return true;
   }
   template <class Key, class Value>
  Value BSTree<Key,Value>::get(const Key& key)
  {
     Value value=(Value)0;
     findutil(this->root,key,value);
     return value;
  } 
  template <class Key, class Value>
  void pututil(BinaryNode<Key,Value> **root,const Key& key, const Value& value,BinaryNode<Key,Value> *last)
  {
    if(*root == NULL) 
    {
    *root = new BinaryNode<Key,Value>(key,value);
    (*root)->parent=last;
    return;
    }
     if (key < (*root)->key)
            pututil(&((*root)->left), key,value,*root);
    else if (key > (*root)->key)
            pututil(&((*root)->right), key,value,*root);   
  }

  template <class Key, class Value>
  void BSTree<Key,Value>::put(const Key& key, const Value& value)
  {
    pututil(&(this->root),key,value,this->root);
  }

  template <class Key, class Value>
  Key BSTree<Key,Value>::minimum()
  { 
    BinaryNode<Key,Value> *tmp=this->root;
    while(tmp->left!=NULL)
    {
      tmp=tmp->left;
    }
    return tmp->key;
  }

template <class Key, class Value>
  Key BSTree<Key,Value>::maximum()
  {
    BinaryNode<Key,Value> *tmp=this->root;
    while(tmp->right!=NULL)
    {
      tmp=tmp->right;
    }
    return tmp->key;
  }
template <class Key, class Value>
void successorutil(BinaryNode<Key,Value> *root ,const Key& key,Key& k)
{
  if(root==NULL) return;
     if(key==root->key) 
     {
        if (root->right != NULL)
        {
            BinaryNode<Key,Value>* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            k = tmp->key ;
        }
       return;
      }
     else if(key<root->key) {k=root->key;successorutil(root->left,key,k);}
     else successorutil(root->right,key,k);
}

template <class Key, class Value>
  Key BSTree<Key,Value>::successor(const Key& key)
  {
    Key k=(Key)0;
     successorutil(this->root,key,k);
     return k;
  }
template <class Key, class Value>
void predecessorutil(BinaryNode<Key,Value> *root,const Key& key,Key& k)
{
  if(root==NULL) return;
     if(key==root->key) 
     {
       if (root->left != NULL)
        {
            BinaryNode<Key,Value>* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            k = tmp->key;
        }
       return;
     }
     else if(key<root->key) predecessorutil(root->left,key,k);
     else {k=root->key;predecessorutil(root->right,key,k);}
}

template <class Key,class Value>
  Key BSTree<Key,Value>::predecessor(const Key& key)
  {
    Key k=(Key)0;
     predecessorutil(this->root,key,k);
     return k;
  }

#endif /* ifndef BSTREE_HPP */