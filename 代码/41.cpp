#include<iostream>
#define ll long long

using namespace std;

ll f[21];

void process() {
	f[1] = 0;
	f[2] = 1;
	for (int i = 3;i <= 20;i++) {
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	}
}
void func() {
	process();
	int n;
	while (cin >> n) {
		cout << f[n] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
}
