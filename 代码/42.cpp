#include<iostream>

using namespace std;

int f[30];
int a[30];
void func() {
	int k;
	while (cin >> k) {
		for (int i = 1;i <= k;i++) {
			cin >> a[i];
		}
		f[1] = 1;
		for (int i = 2;i <= k;i++) {
			int max = 1;
			for (int j = 1;j < i;j++) {
				if (a[j] >= a[i]) {
					max = max > f[j] + 1 ? max : f[j] + 1;
				}
			}
			f[i] = max;
		}
		int ans = 0;
		for (int i = 1;i <= k;i++) {
			ans = ans > f[i] ? ans : f[i];
		}
		cout << ans << endl;
			
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}