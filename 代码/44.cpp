#include<iostream>
#include<algorithm>
using namespace std;

int dp[1020][2010];
int a[2010];

int min(int a, int b) {
	return a < b ? a : b;
}
void process() {
	for (int j = 0;j < 2010;j++) {
		dp[0][j] = 0;
	}
}

void func() {
	int n, k;
	process();
	while (cin >> n >> k) {
		for (int i = 1;i <= n;i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = 1;i <= k;i++) {
			for (int j = 2 * i;j <= n;j++) {
				int tmp = (a[j] - a[j - 1]) * (a[j] - a[j - 1]);
				if (2 * i == j) {
					dp[i][j] = dp[i - 1][j - 2]+ tmp;
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 2] + tmp, dp[i][j - 1]);
				}
			}
		}
		cout << dp[k][n] << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}