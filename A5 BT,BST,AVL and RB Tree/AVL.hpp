#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"
template <class Key, class Value>
class AVL : public BSTree<Key, Value> {
public:
    int getBalance(BinaryNode<Key,Value>*);
    //doBalance(node);
    AVL()
    {
      this->root=NULL;
    };
    BinaryNode<Key,Value>* rightRotate(BinaryNode<Key,Value>*);
    BinaryNode<Key,Value>* leftRotate(BinaryNode<Key,Value>*);
    void put(const Key& key, const Value& value);
    void remove(const Key& key);
    BinaryNode <Key,Value>* deleteNode(BinaryNode <Key,Value> * root,const Key& key);
    BinaryNode <Key,Value>* insertNode(BinaryNode <Key,Value> * root ,Key key,Value value);
  /*
   * Apart from that, your code should have the following four functions:
   * getBalance(node) -> To get the balance at any given node;
   * doBalance(node) -> To fix the balance at the given node;
   * rightRotate(node) -> Perform a right rotation about the given node.
   * leftRotate(node) -> Perform a left rotation about the given node.
   */
};
template <class Key,class Value>
    int AVL<Key,Value>::getBalance(BinaryNode<Key,Value> *root)
    { 
      if (root == NULL)
        return 0;
      return heightutil(root->left)-heightutil(root->right);
    }

    
/*
    template <class Key,class Value>
    BinaryNode<Key,Value>* AVL<Key,Value>::rightRotate(BinaryNode<Key,Value> *z)
    {
        BinaryNode<Key,Value>  * y;
        y=z->left;
        y->parent=z->parent;
        if(z->parent==NULL)
        {
           this-> root=y;
        }
       else if(z->parent->left==z)
            z->parent->left=y;
        else
            z->parent->right=y;
        z->parent=y;
        z->left=y->right;
        y->right=z;
        return y;
    }

    template <class Key,class Value>
    BinaryNode<Key,Value>* AVL<Key,Value>::leftRotate(BinaryNode<Key,Value> *z)
    {
        BinaryNode<Key,Value>  * y;
        y=z->right;
        y->parent=z->parent;
        if(z->parent==NULL)
          {
              this->root=y;
          }
        else if(z->parent->left==z)
            z->parent->left=y;
        else
            z->parent->right=y;

        z->parent=y;
        z->right=y->left;
        y->left=z;
        return y;
    }

*/


    template <class Key,class Value>
    BinaryNode<Key,Value>* AVL<Key,Value>::rightRotate(BinaryNode<Key,Value> *z)
    {
    BinaryNode<Key,Value> *y = z->left;
    BinaryNode<Key,Value> *T2 = y->right;
    y->parent = z->parent;

    if(z->parent==NULL) {this->root=y;}
    else if(z->parent->left==z) {z->parent->left=y;}
    else if(z->parent->right==z) {z->parent->right=y;}
    
    
    if(T2) T2->parent=z;

    z->parent= y;
    z->left = T2;
    y->right = z;
    return y;
    }

    template <class Key,class Value>
    BinaryNode<Key,Value>* AVL<Key,Value>::leftRotate(BinaryNode<Key,Value> *z)
    {
    BinaryNode<Key,Value> *y = z->right;
    BinaryNode<Key,Value> *T2 = y->left;
    y->parent = z->parent;
    
    if(z->parent==NULL) {this->root=y;}
    else if(z->parent->left==z) {z->parent->left=y;}
    else if(z->parent->right==z) {z->parent->right=y;}
    
    
    
    if(T2) T2->parent=z;

    z->parent= y;
    z->right = T2;
    y->left = z;

    return y;
    }



template <class Key, class Value>
    BinaryNode <Key,Value>* AVL<Key,Value>::insertNode(BinaryNode <Key,Value> * root ,Key key,Value value)
   {
      BinaryNode <Key,Value> * ptr;
      if(root==NULL)
        {
            ptr=new BinaryNode <Key,Value>(key,value);
            return ptr;

        }
      if(root->key>key)
        {
            ptr=insertNode(root->left,key,value);
            ptr->parent=root;
    		    root->left=ptr;
        }

      else if(root->key<key)
        {
            ptr=insertNode(root->right,key,value);
            ptr->parent=root;
            root->right=ptr;
        }

        int bal=getBalance(root);
        if (bal>1 &&key<root->left->key)
        {
            return rightRotate(root);
        }
        if (bal < -1 && key > root->right->key) {
			return leftRotate(root);
		}
        if(bal>1 && key>root->left->key)
        {
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
        if(bal<-1&&key<root->right->key)
        {
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
            return root;
   }

template <class Key, class Value>
  void AVL<Key,Value>::put(const Key& key, const Value& value)
  {
      this->root =insertNode(this->root,key,value);
  }
template <class Key, class Value>
BinaryNode <Key,Value>* AVL<Key,Value>::deleteNode(BinaryNode <Key,Value> * root,const Key& key)
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
     int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

  }
template <class Key, class Value>
  void AVL<Key,Value>::remove(const Key& key)
  {
       this->root= deleteNode(this->root,key);
  }



#endif /* ifndef AVL_HPP */
