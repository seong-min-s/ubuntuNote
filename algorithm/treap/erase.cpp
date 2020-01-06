#include<iostream>
using namespace std;
Node* merge(Node* a, Node* b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	
	if(a->priority<b->priority){
		b->setLeft(merge(b->left,a);
		return b;
	}else{
		a->setRight(merge(a->right, b);
		return a;
	}
}

Node* erase(Node* root, KeyType key)
{
	if(root==NULL)
		return root;
	
	if(root->key==key){
		Node* ret=merge(root->left, root->right);
		free(root);
		return ret;
	}
	if(root->key < key)
	{
		root->setRight(erase(root->right,key));
	}else{
		root->setLeft(erase(root->left,key));
	}
	return root;
}

		
