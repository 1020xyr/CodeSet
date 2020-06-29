#include<iostream>
#include<string>
#include<algorithm>

#define ll long long
using namespace std;

ll XToInt(string num, int radix) {
	ll ans = 0;
	int len = num.length();
	for (int i = 0;i < len;i++) {
		if (num[i] >= '0' && num[i] <= '9') {
			ans = ans * radix + num[i] - '0';
		}
		else {
			ans = ans * radix + num[i] +10 - 'A';
		}
	}
	return ans;
}
string IntToX(ll num, int radix) {
	string res = "";
	do{
		int t = num % radix;
		if (t >= 0 && t <= 9) {
			res += t + '0';
		}
		else {
			res += t + 'A' - 10;
		}
		num = num / radix; 
	} while (num != 0);
	reverse(res.begin(), res.end());
	return res;
}
void func() {
	int a, b;
	string n;
	cin >> a >> n >> b;
	ll num = XToInt(n, a);
	string ans = IntToX(num, b);
	cout << ans << endl;
}
int main() {
	func();
	return 0;
}
