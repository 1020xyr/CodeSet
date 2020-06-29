#include<iostream>

using namespace std;

void func() {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		int ans = 1;
		while (b != 0) {
			if (b % 2 == 1) {
				ans *= a;
				ans = ans % 1000;  // 消去取余的两行则变成了正常的求幂的过程
			}
			b = b / 2;
			a *= a;
			a = a % 1000;
		}
		cout << ans << endl;
	}
}
int main() {
	func();
	return 0;
}
