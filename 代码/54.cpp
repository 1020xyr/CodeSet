#include<iostream>

using namespace std;
int ans[30];
bool marked[30];
int n;
bool IsPrime(int num) {
	if (num == 2) return true;
	int maxn = num / 2 + 1;
	for (int i = 2;i <= maxn;i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
void CheckAndPrint() {
	if (IsPrime(ans[1] + ans[n])) {
		for (int i = 1;i < n;i++) {
			cout << ans[i] << " ";
		}
		cout << ans[n];
		cout << endl;
	}
}
void DFS(int num) {
	if (num > 1) {
		if (!IsPrime(ans[num] + ans[num - 1])) {
			return;
		}
		if (num == n) {
			CheckAndPrint();
			return;
		}
	}
	for (int i = 2;i <= n;i++) {
		if (!marked[i]) {
			ans[num + 1] = i;
			marked[i] = true;
			DFS(num + 1);
			marked[i] = false;
		}
	}
}
void func() {
	int cnt = 1;
	while (cin >> n) {
		cout << "Case " << cnt << ":" << endl;
		cnt++;
		ans[1] = 1;
		for (int i = 2;i <= n;i++) {
			marked[i] = false;
		}
		DFS(1);
		cout << endl;
	}
}
int main() {
	func();
	return 0;
}
