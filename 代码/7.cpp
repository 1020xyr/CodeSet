#include<iostream>

using namespace std;
void border(int n,char inner,char  outer) {
	cout << " ";
	for (int i = 1;i < n - 1;i++) {
		if ((n / 2) % 2 == 0) {
			cout << inner;
		}
		else {
			cout<<outer;
		}
	}
	cout << " " << endl;
}
void func() {
	int n;
	char center, outside;
	bool firstline = true;
	while (cin >> n >> center >> outside) {
		if (firstline == true) {
			firstline = false;
		}
		else {
			cout << endl;
		}
		if (n == 1) {
			cout << center;
		}
		else {
			border(n, center, outside);
			int now = n - 2;
			int dir = -1;
			int flag;
			for (int i = 0;i < n - 2;i++) {
				flag = ((n / 2) % 2 + 1) % 2;
				for (int j = 0;j < n;j++) {
					if (flag == 0) {
						cout << outside;
					}
					else {
						cout << center;
					}
					if (j < (n - now) / 2 || j >= (n + now) / 2 - 1) {
						flag = (flag + 1) % 2;
					}
				}
				cout << endl;
				now = now + dir * 2;
				if (now == 1) dir = 1;
			}
			border(n, center, outside);
		}
	}
}
int main() {
	func();
	return 0;
}
