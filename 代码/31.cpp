#include<iostream>

using namespace std; 
struct bigdigit {
	int digit[1000];
	int size;
	bigdigit() {
		for (int i = 0;i < 1000;i++) {
			digit[i] = 0;
		}
		size = 0;
	}
	void set(int x) {
		do {
			int t = x % 1000;
			digit[size] = t;
			size++;
			x = x / 1000;
		} while (x != 0);
	}
	void output() {
		for (int i = size - 1;i >= 0;i--) {
			if (i == size - 1) {
				printf("%d", digit[i]);
			}
			else {
				printf("%03d", digit[i]);
			}
		}
		cout << endl;
	}
};

void func() {
	int n;
	while (cin >> n) {
		bigdigit s;
		s.set(1);
		for (int i = 1;i <= n;i++) {
			int flag = 0;
			for (int j = 0;j < s.size;j++) {
				int sum = s.digit[j] * i + flag;
				flag = sum / 1000;
				sum = sum % 1000;
				s.digit[j] = sum;
 			}
			if (flag != 0) {
				s.size++;
				s.digit[s.size-1] = flag;
			}
		}
		s.output();
	}
}
int main() {
	func();
	return 0;
}
