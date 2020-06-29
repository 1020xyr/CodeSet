#include<iostream>
#include<algorithm>

using namespace std;

struct Edge { 
	int a, b;									//边两个顶点的编号
	int cost;									//该边的权值
}edge[6000];

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

void unions(Edge e) {							// 连接节点
	int pRoot = findRoot(e.a);
	int qRoot = findRoot(e.b);
	if (pRoot != qRoot) {
		village[pRoot] = qRoot;
		sum += e.cost;
	}
}
bool compare(Edge e1, Edge e2) {				// 比较函数
	return e1.cost < e2.cost;
}

void func() {
	int n;
	while (cin >> n && n != 0) {
		int len = n * (n - 1) / 2;
		for (int i = 0;i < len;i++) {			// 接受输入，得到边-权重数组
			cin >>edge[i].a>> edge[i].b >> edge[i].cost;
		}
		sort(edge + 1, edge + 1 + n * (n - 1) / 2,compare);
		sum = 0;
		for (int i = 1;i <= n;i++) {			// 初始化
			village[i] = i;
		}
		for (int i = 0;i < len;i++) {
			unions(edge[i]);
		}
		cout << sum << endl;
	}
}
int main() {
	func();
	return 0;
}
