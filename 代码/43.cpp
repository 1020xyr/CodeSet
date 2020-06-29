#include<iostream>
#include<string>

using namespace std;
int max(int a, int b) {
	return (a > b ? a : b);
}
int dp[120][120];

void func() {
	string a, b;
	cin >> a >> b;
	int len1 = a.length();
	int len2 = b.length();
	for (int i = 0;i < len1;i++) {
		dp[i][0] = 0;
	}
	for (int i = 0;i < len2;i++) {
		dp[0][i] = 0;
	}
	for (int i = 1;i<=len1;i++) {
		for (int j = 1;j <= len2;j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[len1][len2] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
