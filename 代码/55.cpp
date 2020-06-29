#include<iostream>
using namespace std;

bool marked[101][101];
int a[101][101];
int ans;
int m, n;

int go[8][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1, 
	1,1,
	1,-1,
	-1,1,
	-1,-1
};
bool leagl(int i, int j) {
	if (i<1 || i>m)return false;
	if (j<1 || j>n)return false;
	return true;
}
void DFS(int i, int j) {
	for (int k = 0;k < 8;k++) {
		int newi = i + go[k][0];
		int newj = j + go[k][1];
		if (leagl(newi, newj)&&a[newi][newj]==1&& !marked[newi][newj]) {
			marked[newi][newj] = true;
			DFS(newi, newj);
		}
	}
}
void func() {
	char tmp;
	while (cin >> m >> n) {
		if (m == 0)break;
		ans = 0;
		for (int i = 1;i <= m;i++) {
			for (int j = 1;j <= n;j++) {
				marked[i][j] = false;
				cin>>tmp;
				if (tmp == '@') {
					a[i][j] = 1;
				}
				else {
					a[i][j] = 0;
				}
			}
		}
		for (int i = 1;i <= m;i++) {
			for (int j = 1;j <= n;j++) {
				if (marked[i][j] == false && a[i][j] == 1) {
					marked[i][j] = true;
					DFS(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
int main() {
	func();
	return 0;
}
