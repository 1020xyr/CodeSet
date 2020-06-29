#include<iostream>
#include<string>

using namespace std;

typedef struct node {
	struct node* lchild;
	struct node* rchild;
	char c;
	node() {
		lchild = NULL;
		rchild = NULL;
	}
}Node,*LinkNode;
void create(string front, string mid, LinkNode& root,int type) {		// 构建二叉树
	char c = front[0];
	LinkNode p = new Node();
	p->c = c;
	if (type == 0) {
		root->lchild = p;
	}
	else {
		root->rchild = p;
	}
	int index = mid.find(c);
	if (index > 0) {								// 存在左子树
		string left_mid = mid.substr(0, index);
		string left_front = front.substr(1, index); 
		create(left_front, left_mid, p, 0);
	}

	if (index < mid.length() - 1) {					// // 存在右子树
		int len = mid.length() - 1 - index;
		string right_mid = mid.substr(index + 1, len);
		string right_front = front.substr(index + 1, len);
		create(right_front, right_mid, p, 1);
	}
}
LinkNode create_another(string front, string mid) {			// 以另一种方式构建二叉树
	char c = front[0];
	LinkNode p = new Node();
	p->c = c;
	int index = mid.find(c);
	if (index > 0) {
		string left_mid = mid.substr(0, index);
		string left_front = front.substr(1, index);
		p->lchild = create_another(left_front, left_mid);
	}

	if (index < mid.length() - 1) {
		int len = mid.length() - 1 - index;
		string right_mid = mid.substr(index + 1, len);
		string right_front = front.substr(index + 1, len);
		p->rchild = create_another(right_front, right_mid);
	}
	return p;
}
void visit(LinkNode root) {						// 后序遍历
	if(root->lchild!=NULL)
		visit(root->lchild);
	if(root->rchild!=NULL)
		visit(root->rchild);
	if(root!=NULL)
		cout << root->c;
}
void func() {
	string front;
	string mid;
	while (cin >> front >> mid) {
		LinkNode vir = new Node();
		//create(front, mid, vir, 0);
		//visit(vir->lchild);
		vir = create_another(front, mid);
		visit(vir);
		cout << endl;
	}
}
int main() {
	func();
}
