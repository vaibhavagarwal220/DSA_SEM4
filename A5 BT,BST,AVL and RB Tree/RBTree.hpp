#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"

template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {

	
	/*It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	public:
	RBTree()
	{
		this->root=NULL;
	}
	void insertRBFixup(BinaryNode<Key,Value>* root);

	void insert(Key k,Value v);

/* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(BinaryNode<Key,Value>* root);

	void deletek(Key k);

	BinaryNode<Key,Value>* rightRotate(BinaryNode<Key,Value> *z);

	BinaryNode<Key,Value>* leftRotate(BinaryNode<Key,Value> *z);

	int blackHeight();	

};

template <class Key, class Value>
void findk(BinaryNode<Key,Value> *root,Key& key,BinaryNode<Key,Value> **ret)
   {
    if(root==NULL) *ret=NULL;
     if(key==root->key) 
     {
		 *ret=root;
		 return;
	 }
     else if(key<root->key) findk(root->left,key,ret);
     else findk(root->right,key,ret);
   }

template <class Key, class Value>
void RBTree<Key,Value>::insert(Key k,Value v)
{
pututil(&(this->root),k,v,this->root);
BinaryNode<Key,Value> *ptr;
findk(this->root,k,&ptr);
//cout<<ptr->val;
ptr->color=RED;
insertRBFixup(ptr);
}

template <class Key, class Value>
BinaryNode<Key,Value>* uncle(BinaryNode<Key,Value> *root)
   {
    if(root==NULL) 
	return NULL;

	else if(root->parent==NULL) 
	return NULL;

	else if(root->parent->parent==NULL) 
	return NULL;
	
	else
	{
		if(root->parent->parent->left==root->parent)
			return root->parent->parent->right;
		else
			return root->parent->parent->left;
	}
   }


template <class Key, class Value>
void RBTree<Key,Value>::insertRBFixup(BinaryNode<Key,Value>* root)
{
if(root==this->root)
	root->color=BLACK;
else if(root->parent->color!=BLACK)
{
	BinaryNode<Key,Value> *unc=uncle(root);
	Color col;
	if(unc)
	{
	
		if(unc->color==RED)
		{
			unc->color=BLACK;
			root->parent->color=BLACK;
			root->parent->parent->color=RED;
			insertRBFixup(root->parent->parent);
		}
			else if(unc->color==BLACK)
		{	
			BinaryNode<Key,Value>* x=root;
			BinaryNode<Key,Value>* p=root->parent;
			BinaryNode<Key,Value>* g=root->parent->parent;
			if(p==g->left && x==p->left)
			{
				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->left && x==p->right)
			{	
				leftRotate(p);

				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->right)
			{
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->left)
			{
				rightRotate(p);
				
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}

		}

	}
	else
	{
		BinaryNode<Key,Value>* x=root;
			BinaryNode<Key,Value>* p=root->parent;
			BinaryNode<Key,Value>* g=root->parent->parent;
			if(p==g->left && x==p->left)
			{
				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->left && x==p->right)
			{	
				leftRotate(p);

				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->right)
			{
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->left)
			{
				rightRotate(p);
				
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}

	}	
		
}

}

template <class Key, class Value>
void RBTree<Key,Value>::deletek(Key k)
{

}

template <class Key, class Value>
void RBTree<Key,Value>::deleteRBFixup(BinaryNode<Key,Value>* root)
{

}

template <class Key, class Value>
int bh(BinaryNode<Key,Value>* root)
{
if(root==NULL)
			return 0;
else if(root->left == NULL || root->right ==NULL)
			return 1;
else if(root->left->color == BLACK)
	return (1+bh(root->left));
else
	return bh(root->left);
}

template <class Key, class Value>
int RBTree<Key,Value>::blackHeight()
{
  return bh(this->root);
}




    template <class Key,class Value>
    BinaryNode<Key,Value>* RBTree<Key,Value>::rightRotate(BinaryNode<Key,Value> *z)
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
    BinaryNode<Key,Value>* RBTree<Key,Value>::leftRotate(BinaryNode<Key,Value> *z)
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

#endif /* ifndef RBTree_HPP_ */