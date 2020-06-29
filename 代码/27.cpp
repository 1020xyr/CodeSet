#include<iostream>
#include<vector>

using namespace std;
vector<int> tmp(1000001, 0);
int len = 1000000;
void precess() {
	int n = len;
	for (int i = 2;i <=n ;i++) {
		if (tmp[i] == 0) {
			for (int j = i * i;j <= n;j = j + i) {
				tmp[j] = 1;
			}
		}
	}
}
void func(int n) {
	int ans = 0;
	int min = n > len ? len : n;
	for (int i = 2;i <= min;i++) {
		if (tmp[i] == 0) {
			while (n % i == 0) {
				ans++;
				n = n / i;
			}
		}
	}
	if (n != 1) {				//如果仍未除尽，则只存在一个质因数
		ans++;
	}
	cout << ans << endl;
}

int main() {
	int n;
	while (cin >> n) {
		func(n);
	}
	return 0;
}
