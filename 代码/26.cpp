#include<iostream>
#include<math.h>
#include<vector> 
using namespace std;

void func(int n) {
	if (n < 12) {
		cout << -1 << endl;
		return;
	}
	vector<int> tmp(n, 0);
	for (int i = 2;i < n;i++) {
		if (tmp[i] == 0) {
			for (int j = i * i;j < n;j=j+i) {
				tmp[j] = 1;
			}
			if (i % 10 == 1) {
				cout << i << " ";
			}
		}
	}
	cout << endl;
}
int main() {
	int n;
	while (cin >> n) {
		func(n);
	}
	return 0;
}
