#include<iostream>
#include<utility>
using namespace std;
struct Node;
typedef pair<Node*, Node*> NodePair;
typedef int KeyType;
struct Node{
	int priority, size;
	KeyType key;
	Node *left,*right;

	Node(const KeyType _key):size(1),key(_key),priority(rand()),left(NULL),right(NULL)
	{}
	
	void setLeft(Node* leftNode){
		left=leftNode;
		calcSize();
	}
	void setRight(Node* rightNode){
		right=rightNode;
		calcSize();
	}
	void calcSize(){
		size=1;
		if(left)size+=left->size;
		if(right)size+=right->size;
	}
};
NodePair split(Node* root, KeyType key)
{
	if(root==NULL)
		return NodePair(NULL,NULL);

	if(key>root->key){
		NodePair rs=split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls=split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first,root);
}
Node* insert(Node* root, Node* newNode)
{
	if(root==NULL)
		return newNode;

	if(newNode->priority > root->priority){
		NodePair splitted=split(root, newNode->key);
		newNode->setLeft(splitted.first);
		newNode->setRight(splitted.second);
		return newNode;
	}else if(newNode->key > root->key){
		root->setRight(insert(root->right, newNode));
	}else{
		root->setLeft(insert(root->left, newNode));
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
Node* erase(Node* root, Node* node)
{
	if(root==NULL)
		return root;

	if(node->key==root->key){
		Node* rs=merge(root->left, root->right);
		delete root;
		return rs;
	}
	if(node->key < root->key)
	{
		root->setLeft(erase(root->left,node));
	}else if(node->key > root->key){
		root->setRight(erase(root->right,node));
	}
	return root;
}
Node* find(Node* root, int k)
{
	int ls=0;
	if(root->left!=NULL){
		ls=root->left->size;
	}
	if(k<=ls){
		return find(root->left,k);
	}else if(k==ls+1){
		return root;
	}

	return find(root->right,k-ls-1);
	
}
void inOrder(Node* root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<root->key;
		inOrder(root->right);
	}
}

int countLessThan(Node *root, int x)
{
	if(root==NULL)
		return 0;
	if(x<=root->key){
		return countLessThan(root->left,x);
	}
	
	int ls=(root->left?root->left->size:0);
	return ls+1+countLessThan(root->right,x);
}

int main()
{
	Node* root=NULL;
	root=insert(root,new Node(7));
	root=insert(root,new Node(3));
	root=insert(root,new Node(2));
	root=insert(root,new Node(4));
	root=insert(root,new Node(1));
	root=insert(root,new Node(15));
	root=insert(root,new Node(13));

	inOrder(root);
	Node* node=find(root,3);
	cout<<node->key<<endl;
	return 0;
}
