#include<iostream>

using namespace std;
struct Node
{
	int val;
	Node* rchild;
	Node* lchild;
	Node(){
		rchild = NULL;
		lchild = NULL;
	}
};
Node* addNode(Node* p,int val){
	if(p==NULL){
		p = new Node();
		p->val = val;
		return p;
	}
	if(p->val>val){
		p->lchild = addNode(p->lchild,val);
	}
	else{
		p->rchild = addNode(p->rchild,val);
	}
	return p;
}
void previsit(Node* root){
	cout<<root->val<<" ";

	if(root->lchild){
		previsit(root->lchild);
	}

	if(root->rchild){
		previsit(root->rchild);
	}
}
void midvisit(Node* root){
	if(root->lchild){
		midvisit(root->lchild);
	}

	cout<<root->val<<" ";

	if(root->rchild){
		midvisit(root->rchild);
	}
}
void behvisit(Node* root){
	if(root->lchild){
		behvisit(root->lchild);
	}

	if(root->rchild){
		behvisit(root->rchild);
	}

	cout<<root->val<<" ";
}
void func(){
	int n;
	int value;
	while(cin>>n){
		Node* root = NULL;
		for(int i=0;i<n;i++){
			cin>>value;
			root = addNode(root,value);
		}
		previsit(root);
		cout<<endl;
		midvisit(root);
		cout<<endl;
		behvisit(root);
		cout<<endl;
	}
}
int main(){
	func();
	return 0;
}
