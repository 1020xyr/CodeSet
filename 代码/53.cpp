#include<iostream>
using namespace std;

int tmp[36];
void process() {
	tmp[1] = 2;
	for (int i = 2;i <= 35;i++) {
		tmp[i] = tmp[i - 1] * 3 + 2;
	}
}
void func() {
	int n;
	process(); 
	while (cin >> n) {
		cout << tmp[n] << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
