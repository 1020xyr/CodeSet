#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int p, q;
	int weight;
	node(int p1, int q1, int w1) {
		p = p1;
		q = q1;
		weight = w1;
	}
	node(){
		p = 0;
		q = 0;
		weight =0;
	}
};
int village[120];
int sum;										// 生成树权重之和
int findRoot(int p) {							// 找到根节点
	if (village[p] == p) {
		return p;
	}
	else {
		int tmp = findRoot(village[p]);
		village[p] = tmp;
		return tmp;	
	}
}

void unions(node n) {							// 连接节点
	int pRoot = findRoot(n.p);
	int qRoot = findRoot(n.q);
	if (pRoot != qRoot) {
		village[pRoot] = qRoot;
		sum += n.weight;
	}
}
bool compare(node n1, node n2) {				// 比较函数
	return n1.weight < n2.weight;
}

void func() {
	int n;
	while (cin >> n && n != 0) {
		int len = n * (n - 1) / 2;
		vector<node> tmp(len);
		for (int i = 0;i < len;i++) {			// 接受输入，得到边-权重数组
			int p, q, weight;
			cin >> p >> q >> weight;
			tmp[i] = node(p, q, weight);
		}
		sort(tmp.begin(), tmp.end(), compare);	// 按权重从小到大排序
		sum = 0;	
		for (int i = 1;i <= n;i++) {			// 初始化
			village[i] = i;
		}
		for (int i = 0;i < len;i++) {
			unions(tmp[i]);
		}
		cout << sum << endl;
	}
}
int main() {
	func();
	return 0;
}
