#include<iostream>
#include<utility>

typedef int KeyType;
struct Node{
	int priority, size;
	KeyType key;
	Node *left,*right;

	Node(const KeyType& key):priority(rand()),size(1),left(NULL),right(NULL){}

	void setRight(Node *newNode){right=newNode;calcsize();}
	void setLeft(Node *newNode{left=newNode;calcsize();}

	void calcsize()
	{
		size=1;
		if(left)size+=left->size;
		if(right)size+=right->size;
	}
};
typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, KeyType key)
{
	if(root==NULL)
		return NodePair(NULL,NULL);
	
	if(root->key<key)
	{
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root,rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
		
}
Node* addNode(Node* root, Node* node)
{
	if(root==NULL)
	{
		return node;
	}

	if(root->priority < node->priority)
	{
		NodePair splitted=split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}else if(root->key > node->key)
	{
		root->setLeft(addNode(root->left,node));
	}else{
		root->setRight(addNode(root->right,node));
	}
	return root;
}
Node* merge(Node* a, Node* b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;

	if(a->priority > b->priority){

		a->setRight(merge(a->right, b));
		return a;
	}else{
		b->setLeft(merge(b->left,a));
		return b;
	}
}
Node* deleteNode(Node* root, Keytype key)
{
	if(root==NULL)
	{
		return root;
	}

	if(key==root->key)
	{
		Node* ret=merge(root->left,root->right);
		delete root;
		return ret;
	}
	if(key<root->key)
	{
		root->setLeft(deleteNode(root->left,key));
	}else{
		root->setRight(deleteNode(root->right,key));
	}
	return root;
}
