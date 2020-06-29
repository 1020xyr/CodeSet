#include<iostream>
#include<vector>
using namespace std;
void func() {
	int n;
	while (cin >> n && n != 0) {
		vector<int> a(n);
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}
		int x;
		cin >> x;
		int flag = 0;
		for (int i = 0;i < n;i++) {
			if (a[i] == x) {
				cout << i << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << -1 << endl;
		}
	}
}
int main() {
	func();
	return 0;
}

