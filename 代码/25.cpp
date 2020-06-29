#include<iostream>
#include<math.h>
using namespace std;

bool IsPrime(int n) {
	if (n <= 1) return false;
	int len = sqrt(n);
	for (int i = 2;i <= len;i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void func() {
	int n;
	while (cin >> n) {
		bool res = IsPrime(n);
		if (res) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}
int main() {
	func();
	return 0;
}
