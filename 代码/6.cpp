#include<iostream>
using namespace std;

void func() {
	int h;
	cin >> h;
	int max = 3 * h - 2;
	int now = 2 * h - 2;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < max;j++) {
			if (j < now) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		now -= 2;
		cout << endl;
	}
}
int main() {
	func();
	return 0;
}
