#include<iostream>

using namespace std;

int a[10][10];							// 0为起点，1为终点，2为墙，3为空地
bool marked[10][10];
int n, m;
int sx, sy, ex, ey;						// 起点坐标与终点坐标
int ans;
int go[4][2] = { 0,1,0,-1,1,0,-1,0 };	// 转移矢量
bool legal(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m)return false;
	return true;
}
void DFS(int x,int y,int t) {
	if (x == ex && y == ey && t == 0) { // 如果恰好到达终点
		ans = 1;
		return;
	}
	if (t <= 0) {						 // 剪枝操作1
		return;
	}
	if ((((x + y) % 2 + t % 2)) % 2 != (ex + ey) % 2) { // 剪枝操作2
		return;
	}
	for (int k = 0;k < 4;k++) {
		if (ans == 1) return;
		int newx = x + go[k][0];
		int newy = y + go[k][1];
		if (legal(newx, newy) && !marked[newx][newy] && a[newx][newy] != 2) {
			marked[newx][newy] = true;
			DFS(newx, newy, t - 1);
			marked[newx][newy] = false;			// 回溯
		}
	}
}
void func() {
	char tmp;
	int t;
	while (cin >> n >> m >> t) {
		if (n == 0)break;
		ans = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				marked[i][j] = false;
				cin >> tmp;
				if (tmp == 'S') {
					sx = i;
					sy = j;
					a[i][j] = 0;
				}
				else if (tmp == 'D') {
					ex = i;
					ey = j;
					a[i][j] = 1;
				}
				else if (tmp == 'X') {
					a[i][j] = 2;
				}
				else {
					a[i][j] = 3;
				}
			}
		}
		if ((((sx + sy) % 2 + t % 2)) % 2 != (ex + ey) % 2) {
			cout << "NO" << endl;
		}
		else {
			marked[sx][sy] = true;
			DFS(sx, sy, t);
			if (ans == 1) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}
int main() {
	func();
	return 0;
}
