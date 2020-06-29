#include<iostream>

const int N = 10000001;
using namespace std;
int tree[N];
int sum[N];
int Max;
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
void unions(int p, int q) {
	int pRoot = findRoot(p);
	int qRoot = findRoot(q);
	if (pRoot != qRoot) {
		tree[pRoot] = qRoot;
		sum[qRoot] += sum[pRoot];
		Max = Max > sum[qRoot] ? Max : sum[qRoot];
	}
}

void func() {
	int n;
	while (cin >> n) {
		for (int i = 1;i <= N;i++) {
			tree[i] = i;
			sum[i] = 1;
		}
		Max = 1;
		for (int i = 0;i < n;i++) {
			int p, q;
			cin >> p >> q;
			unions(p, q);
		}
		cout << Max << endl;
	}
}
int main() {
	func();
	return 0;
}
