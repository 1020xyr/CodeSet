#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;

struct Dot {					// 点
	double x, y;
	int index;
	double getDistance(Dot d1) {	// 取两点 
		double ans = (d1.x - x) * (d1.x - x) + (d1.y - y) * (d1.y - y);
		ans = sqrt(ans);
		return ans;
	}
}dot[120];

struct Edge {				// 边
	int p, q;
	double cost;

}edge[5200];

int tree[120];
double sum;

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
void unions(Edge e) {
	int pRoot = findRoot(e.p);
	int qRoot = findRoot(e.q);
	if (pRoot != qRoot) {
		tree[pRoot] = qRoot;
		sum += e.cost;
	}
}

bool compare(Edge e1, Edge e2) {
	return e1.cost <= e2.cost;
}
void func() {
	int n;
	while (cin >> n) {
		for (int i = 1;i <= n;i++) {
			cin >> dot[i].x >> dot[i].y;
			dot[i].index = i;
		}
		int len = 0;
		for (int i = 1;i <= n;i++) {
			for (int j =i+1 ;j <= n;j++) {
				edge[len].cost = dot[i].getDistance(dot[j]);
				edge[len].p = i;
				edge[len].q = j;
				len++;
			
			}
		}
		sort(edge, edge + len, compare);
		for (int i = 1;i <= n;i++) {
			tree[i] = i;
		}
		sum = 0;
		for (int i = 0;i < len;i++) {
			unions(edge[i]);
		}
		printf("%.2f",sum);
	}
}

int main() {
	func();
	return 0;
}
