#include<iostream>

using namespace std;

const int Max = 1000000;

int ans[120][120];

void func() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				ans[i][j] = Max;
			}
		}
		for (int i = 0;i < m;i++) {
			int p, q, cost;
			cin >> p >> q >> cost;
			ans[p][q] = cost;
			ans[q][p] = cost;
		}
		for (int k = 1;k <= n;k++) {
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= n;j++) {
					if (ans[i][k] + ans[k][j] < ans[i][j]) {
						ans[i][j] = ans[i][k] + ans[k][j];
					}
				}
			}
		}
		cout << ans[1][n] << endl;

	}
}

int main() {
	func();
	return 0;
}
