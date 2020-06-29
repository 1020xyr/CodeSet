#include<iostream> 
#include<vector>

using namespace std;


struct node {
	int index;
	int number;
};
struct union_find {
	node* tree;	
	int size;								// 连通分量的个数
	int maxNum;								// 最大的连通分量
	union_find(int n) {
		tree = new node[n];
		for (int i = 1;i <= n;i++) {
			tree[i].index = i;
			tree[i].number = 1;
		}
		size = n;
		maxNum = 1;
	}
	void init(int n) {
		for (int i = 1;i <= n;i++) {
			tree[i].index = i;
			tree[i].number = 1;
		}
		size = n;
		maxNum = 1;
	}
	int findRoot(int p) {
		if (tree[p].index == p) {
			return p;
		}
		else {
			int tmp = findRoot(tree[p].index);
			tree[p].index = tmp;
			return tmp;
		}
	}
	bool isConnection(int p, int q) {
		int pRoot = findRoot(p);
		int qRoot = findRoot(q);
		return (pRoot == qRoot);
	}
	void unions(int p, int q) {
		int pRoot = findRoot(p);
		int qRoot = findRoot(q);
		if (pRoot != qRoot) {
			tree[pRoot].index = qRoot;
			tree[qRoot].number += tree[pRoot].number;
			size--;
			maxNum = maxNum > tree[qRoot].number ? maxNum : tree[qRoot].number;
		}
	}
};
union_find s(10000000);
void func() {
	int n;
	while (cin >> n) {
		s.init(10000000);
		for (int i = 0;i < n;i++) {
			int p, q;
			cin >> p >> q;
			s.unions(p, q);
		}
		cout << s.maxNum << endl;

	}
}
int main() {
	func();
	return 0;
}

