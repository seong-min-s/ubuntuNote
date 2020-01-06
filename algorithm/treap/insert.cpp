#include<iostream>
#include<utility>
using namespace std;
typedef int KeyType;
struct Node{
	KeyType key;
	int priority, size;
	Node *left, *right;
	Node(const KeyType& _key):priority(rand()),size(1),key(_key),left(NULL),right(NULL){}

	void SetLeft(Node *newLeft){
		left=newLeft;
	}
	void SetRight(Node *newRight){
		right=newRight;
	}
	void calcSize(){
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
	
	if(root->key<key){
		NodePair rs=split(root->right,key);
		root->SetRight(rs.first);
		return NodePair(root,rs.second);
	}else{
		NodePair ls=split(root->left,key);
		root->SetLeft(ls.second);
		return NodePair(ls.first, root);
	}
}
Node* insert(Node* root, Node* node)
{
	if(root==NULL)
		return node;

	if(root->priority<node->priority)
	{
		NodePair splitted=split(root, node->key);
		return node;
	}else if(root->key>node->key){
		root->SetLeft(insert(root->left,node));
	}else{
		root->SetRight(insert(root->right, node));
	}
	return root;
}

int main()
{
	Node *root=insert(NULL, new Node(10));
	insert(root, new Node(3));
	insert(root, new Node(15));


	return 0;
}
