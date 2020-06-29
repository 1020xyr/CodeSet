#include<iostream>

using namespace std;

int hanio(int x) {
	if (x == 1) return 2;
	else return hanio(x - 1) * 3 + 2;
}

void func() {
	int n;
	while(cin>>n){
		int ans = hanio(n);
		cout << ans << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
