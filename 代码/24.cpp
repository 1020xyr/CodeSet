#include<iostream>
using namespace std; 
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void func() {
	int a, b;
	while (cin >> a >> b) {
		int max = gcd(a, b);
		int res = a / max * b;
		cout << res << endl;
	}
}
int main() {
	func();
	return 0;
}
