#include<iostream>

const int INF = 1000000000;
using namespace std;
int min(int a, int b) {
	return a < b ? a : b;
}
int dp[10001];

int P[501];
int W[501];

void func() {
	int T;
	cin >> T;
	for (int t = 0;t < T;t++) {
		int E, F;
		cin >> E >> F;
		int N;
		cin >> N;
		int sub = F - E;
		for (int i = 1;i <= N;i++) {
			cin >> P[i] >> W[i];
		}
		for (int i = 1;i <= sub;i++) {
			dp[i] = INF;
		}
		dp[0] = 0;
		for (int i = 1;i <= N;i++) {
			for (int j = W[i]; j <= sub;j++) {
				if (dp[j - W[i]] != INF) {
					dp[j] = min(dp[j], dp[j - W[i]] + P[i]);
				}
			}
		}
		if (dp[sub] != INF) {
			cout << "The minimum amount of money in the piggy-bank is ";
			cout << dp[sub];
			cout << "." << endl;
		}
		else {
			cout << "This is impossible." << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
