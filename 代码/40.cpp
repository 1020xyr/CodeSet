#include<iostream>
#define ll long long
using namespace std;
void func() {
	int n;
	cin >> n;
	ll f1 = 1;
	ll f2 = 2;
	int len = 3;
	if (n <= 1) {
		cout << 1 << endl;
		return;
	}
	while (len <= n) {
		ll tmp = f2;
		f2 = f1 + f2;
		f1 = tmp;
		len++;
	}
	cout << f2 << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
}
