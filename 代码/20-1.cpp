#include<iostream>
#include<string>
using namespace std;

void func() {
	string num1, num2;
	while (cin >> num1 && cin >> num2) {
		int sum = 0;
		for (int i = 0;i < num1.length();i++) {
			for (int j = 0;j < num2.length();j++) {
				sum += (num1[i] - '0') * (num2[j] - '0');
			}
		}
		cout << sum << endl;

	}
}
int main() {
	func();
	return 0;
}
