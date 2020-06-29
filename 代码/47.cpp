#include<iostream>

using namespace std;
int max(int a, int b) {
	return (a > b ? a : b);	
}
int dp[1001];
int value[101];
int times[101];
void func() {
	int T, M;
	while (cin >> T >> M) {
		for (int i = 1;i <= M;i++) {
			cin >> times[i] >> value[i];
		}
		for (int i = 0;i <= T;i++) {
			dp[i] = 0;
		}
		for (int i = 1;i <= M;i++) {
			for (int j = T;j>=times[i];j--) {
				dp[j] = max(dp[j], dp[j - times[i]] + value[i]);
			}
		}
		cout << dp[T] << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
