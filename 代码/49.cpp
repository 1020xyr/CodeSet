#include<iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int dp[101];
int P[2001];
int H[2001];
void func() {
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> n >> m;
		int p,h,k;
		int cnt = 0;
		for (int i = 1;i <= m;i++) {
			cin >> p >> h >> k;
			int c = 1;
			while (k - c > 0) {
				k -= c;
				P[++cnt] = c * p;
				H[cnt] = c * h;
				c *= 2;
			}
			P[++cnt] = k * p;
			H[cnt] = k * h;
		}
		for (int i = 0;i <= n;i++) {
			dp[i] = 0;
		}
		for (int i = 1;i <= cnt;i++) {
			for (int j = n;j >= P[i];j--) {
				dp[j] = max(dp[j], dp[j - P[i]] + H[i]);
			}
		}
		cout << dp[n]<<endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}