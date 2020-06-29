#include<iostream>


using namespace std;
const int INF = 1000000;
const int OFFSET = 2000;
int dp[110][4010];
int list[101];
void process() {
	for (int j = -2000;j <= 2000;j++) {
		dp[0][j+OFFSET] = -INF;
	}
	dp[0][OFFSET] = 0;
}

void func() {
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++) {
		int n;
		cin >> n;
		bool Zero =false;
		int cnt = 0;
		for (int j = 1;j <= n;j++) {
			cin >> list[++cnt];
			if (list[cnt] == 0) {
				Zero = true;
				cnt--;
			}
		}
		n = cnt;
		process();
		for (int x = 1;x <= n;x++) {
			for (int y = -2000;y <= 2000;y++) {
				int tmp1 = -INF;
				int tmp2 = -INF;
				if (y - list[x] >= -2000 && dp[x - 1][y - list[x] + OFFSET] != -INF) {
					tmp1 = dp[x - 1][y - list[x] + OFFSET] + list[x];
				}
				if (y + list[x] <= 2000 && dp[x - 1][y + list[x] + OFFSET] != -INF) {
					tmp2 = dp[x - 1][y + list[x] + OFFSET] + list[x];
				}
				if (tmp2 > tmp1) {
					tmp1 = tmp2;
				}
				if (dp[x - 1][y + OFFSET] > tmp1) {
					tmp1 = dp[x - 1][y + OFFSET];
				}
				dp[x][y + OFFSET] = tmp1;
			}
		}
		
		cout << "Case " << i << ": ";
		if (dp[n][OFFSET] == 0) {
			if (Zero == true) {
				cout << 0 << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else {
			cout << dp[n][OFFSET] / 2 << endl;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
