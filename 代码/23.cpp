#include<iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void func() {
	int a, b;
	while (cin >> a >> b) {
		int ans = gcd(a, b);
		cout << ans << endl;
	}
}

int main() {
	func();
	return 0;
}