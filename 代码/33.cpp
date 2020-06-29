#include<iostream> 
#include<algorithm>
#include<vector>

using namespace std;

struct union_find {
	vector<int> tree;
	int size;
	union_find(int n) {
		tree = vector<int>(n+1);
		for (int i = 1;i <= n;i++) {
			tree[i] = i;
		}
		size = n;
	}
	int findRoot(int p) {
		if (tree[p] == p) {
			return p;
		}
		else {
			int tmp = findRoot(tree[p]);
			tree[p] = tmp;
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
			tree[pRoot] = qRoot;
			size--;
		}
	}
};

void func() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0) break;
		union_find s(n);
		for (int i = 0;i < m;i++) {
			int p, q;
			cin >> p >> q;
			s.unions(p, q);
		}
		cout << s.size - 1 << endl;
	}
}
int main() {
	func();
	return 0;
}
