typedef int KeyType;
struct Node {
	//노드에 저장된 원소
	KeyType key;
	//이 노드의 우선 순위
	//이 노드를 루트로 하는 서브트리의 크기
	int priority, size;
	//두 자식 노드의 포인터
	Node *left, *right;
	//생성자에서 난수 우선순위를 생성하고 size와 left/right를 초기화 한다.
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL){}
	void setLeft(Node* newLeft){ left=newLeft; calcSize();}
	void setRight(Node* newRight){ right=newRight; calcSize();}
	//size멤버를 갱신한다.
	void calcSize(){
		size=1;
		if(left) size += left->size;
		if(right) size += right->size;
	}
};
