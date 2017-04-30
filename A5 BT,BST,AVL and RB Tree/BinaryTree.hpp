#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1
#include <limits.h>
#include "queue.hpp"
#include <iostream>
using namespace std;
using namespace cs202;

enum Color { RED, BLACK };


template <class Key,class Value>
class BinaryNode
{
public:
	Key key;
  Color color;
	Value val;
  //bool visited;
	BinaryNode<Key,Value> *left,*right,*parent;
    /*Default constructor. Should assign the default value to key and value
     */
	BinaryNode();
	/*This contructor should assign the key and val from the passed parameters
     */
	BinaryNode(Key key, Value value);
};

template <class Key,class Value>
BinaryNode<Key,Value>::BinaryNode()
{
this->key=(Key)0;
this->val=(Value)0;
this->left=NULL;
this->right=NULL;
this->parent=NULL;
}


template <class Key,class Value>
BinaryNode<Key,Value>::BinaryNode(Key key, Value value)
{
this->key=key;
this->val=value;
this->left=NULL;
this->right=NULL;
this->parent=NULL;
}


template<class Key,class Value>
class BinaryTree
{
	/* You can implement your own helper functions whenever required.
	 */
protected:
	BinaryNode<Key,Value> *root;

public:
  BinaryTree()
  {
    this->root=NULL;
  }
  virtual Value get(const Key& key);
  
  virtual void remove(const Key& key) ;
  virtual bool has(const Key& key) ;	
  virtual void put(const Key& key, const Value& value) ;
   virtual void print_in_order();
  virtual void print_pre_order();
  void removeutil(BinaryNode<Key,Value> *root,const Key& key);
  virtual void print_post_order();
  virtual Key minimum();
  virtual Key maximum();
  /*
   *This method returns the successor, i.e, the next larget element in the
   *binary tree, after Key.
   */
  virtual Key successor(const Key& key);
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * binary tree, after Key.
   */
  virtual Key predecessor(const Key& key);
};







template <class Key,class Value>
void inorderutil(BinaryNode<Key,Value> * root)
{    if(root==NULL) return;
      inorderutil(root->left);
     cout<<root->key<<" "<<root->val<<endl;
     inorderutil(root->right);
}
template <class Key,class Value>
void BinaryTree<Key,Value>::print_in_order()
   {
     inorderutil(this->root);
   }


template <class Key,class Value>
void postorderutil(BinaryNode<Key,Value> * root)
{
    if(root==NULL) return;
     postorderutil(root->left);
     postorderutil(root->right);
     cout<<root->key<<" "<<root->val<<endl;
}
   template <class Key,class Value>
void BinaryTree<Key,Value>::print_post_order()
   {
    postorderutil(this->root); 
   }

template <class Key,class Value>
void preorderutil(BinaryNode<Key,Value> * root)
{
    if(root==NULL) return;
     cout<<root->key<<" "<<root->val<<endl;
     preorderutil(root->left);
     preorderutil(root->right);
}

   template <class Key,class Value>
void BinaryTree<Key,Value>::print_pre_order()
   {
   preorderutil(this->root);
   }

template <class Key,class Value>
void getutil(BinaryNode<Key,Value> *root,const Key& key,Value& value)
{
     if(root==NULL) return;
     if(key==root->key) 
     {value=root->val;return;}
     getutil(root->left,key,value);
     getutil(root->right,key,value);
}
template <class Key,class Value>
Value BinaryTree<Key,Value>::get(const Key& key)
   {
     Value value=(Value)0;
     getutil(this->root,key,value);
     return value;
   }

template <class Key,class Value>
void BinaryTree<Key,Value>::removeutil(BinaryNode<Key,Value> *root,const Key& key)
{
     if(root==NULL) return;
     if(key==root->key) 
     {
       
       if(root->left && root->right)
          {
            BinaryNode<Key,Value> *temp=root;
            while(temp->left!=NULL)
            {
              temp=temp->left;
            }
            //cout<<temp->key<<" "<<temp->val<<endl;
            Value tval=(Value)0;
            Key tkey=(Key)0;
            tval=temp->val;
            temp->val=root->val;
            root->val=tval;
            tkey=temp->key;
            temp->key=root->key;
            root->key=tkey;
            removeutil(root,temp->key);
            return;
          }
      else if(root->left) 
            { 
              if(root==this->root)
              {
                delete this->root;
                this->root=root->left;
                return;
              }
              else if(root->parent->left==root) 
              {
                root->parent->left=root->left;
                root->left->parent=root->parent;
                delete root;
                return;
                }
              else 
              {
                root->parent->right=root->left;
                root->left->parent=root->parent;
                delete root;
                return;
              }
            }

      else if(root->right) 
            { 
              if(root==this->root)
              {
                delete this->root;
                this->root=root->right;
                return;
              }
              else if(root->parent->left==root) 
              {
                root->parent->left=root->right;
                root->right->parent=root->parent;
                delete root;
                return;
              }

              else 
              {
                root->parent->right=root->right;
                root->right->parent=root->parent;
                delete root;
                return;
              }
            }

      else 
      {
        if(root==this->root)
        {
        delete this->root;
        this->root=NULL;
        return;
        }        
        else if(root->parent->left==root) 
        {
          root->parent->left=NULL;
          delete root;
          return;
        }

        else 
        {
          root->parent->right=NULL;
          delete root;
          return;
        }

      }      
       return;
     }
     removeutil(root->left,key);
     removeutil(root->right,key);
}

template <class Key,class Value>
   void BinaryTree<Key,Value>::remove(const Key& key)
   {
     removeutil(this->root,key);
   }

  template <class Key,class Value>
   bool BinaryTree<Key,Value>::has(const Key& key)
   {
     Value value=(Value)0;
     getutil(this->root,key,value);
     if(value==(Value)0) return false;
     return true;

   } 


  template <class Key, class Value>
  void BinaryTree<Key,Value>::put(const Key& key, const Value& value)
  {
    if(this->root == NULL) {
    this->root = new BinaryNode<Key,Value>(key,value);
        return;
    }
    BinaryNode<Key,Value> *node;
    node = new BinaryNode<Key,Value>(key,value);
    queue< BinaryNode<Key,Value> *> q;
    q.push(this->root);

    while(true) {
        BinaryNode<Key,Value> *n = q.pop();
        if(n->left == NULL) {
            node->parent=n;
            n->left = node;
          
            break;
        } else {
            q.push(n->left);
        }           

        if(n->right == NULL) {
            node->parent=n;
            n->right = node;
            break;
        } else {
            q.push(n->right);
        }
    }
  }



  template<class Key,class Value>
  void minUtil(BinaryNode<Key,Value> *root,Key &temp)
  {
      if(root == NULL)
        return;
      if(root->val < temp)
      {
        temp = root->key;
      }
      minUtil(root->left,temp);
      minUtil(root->right,temp);
  }

  template <class Key, class Value>
  Key BinaryTree<Key,Value>::minimum()
  {
      Key temp;
      temp=this->root->key;
      minUtil(this->root,temp);
      return temp;
  }
  
template <class Key, class Value>
  void maxUtil(BinaryNode<Key,Value> * root,Key& temp)
  {
    if(root == NULL)
        return;
      if(root->key > temp)
      {
        temp= root->key;
      }
      maxUtil(root->left,temp);
      maxUtil(root->right,temp);
  }

template <class Key, class Value>
  Key BinaryTree<Key,Value>::maximum()
  {
      Key temp;
      temp=this->root->key;
      maxUtil(this->root,temp);
      return temp;
  }

  template<class Key,class Value>
  void sucUtil(BinaryNode<Key,Value> *root,BinaryNode<Key,Key> &temp,Key rkey)
  {
      if(root == NULL)
        return;
      if( (root->key - rkey) < temp.val && (root->key - rkey)>0 )
      {
        temp.val = root->key - rkey;
        temp.key = root->key;
      }
      sucUtil(root->left,temp,rkey);
      sucUtil(root->right,temp,rkey);
  }

template <class Key, class Value>
  Key BinaryTree<Key,Value>::successor(const Key& key)
  {
      BinaryNode<Key,Value> temp;
      temp.val=maximum();
      sucUtil(this->root,temp,key);
      return temp.key;
  }

  template<class Key,class Value>
  void preUtil(BinaryNode<Key,Value> *root,BinaryNode<Key,Key> &temp,Key rkey)
  {
      if(root == NULL)
        return;
      if( (rkey - root->key) < temp.val && (rkey - root->key)>0 )
      {
        temp.val = rkey - root->key;
        temp.key = root->key;
      }
      preUtil(root->left,temp,rkey);
      preUtil(root->right,temp,rkey);
  }

template <class Key,class Value>
  Key BinaryTree<Key,Value>::predecessor(const Key& key)
  {
      BinaryNode<Key,Key> temp;
      temp.val=maximum();
      preUtil(this->root,temp,key);
      return temp.key;
  }


#endif /* ifndef BINARYTREE_HPP */
