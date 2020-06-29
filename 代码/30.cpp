#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int len_a = a.length();
	int len_b = b.length();
	a += string(10010 - len_a, '0');
	b += string(10010 - len_b, '0');
	int max = len_a > len_b ? len_a : len_b;
	max += 2;
	int flag = 0;
	for (int i = 0;i < max;i++) {
		int sum = a[i] - '0' + b[i] - '0' + flag;
		flag = 0;
		if (sum >= 10) {
			sum -= 10;
			flag = 1;
		}
		a[i] = sum + '0';
	}
	int len = max - 2;
	while (a[len] != '0') {
		len++;
	}
	string ans = a.substr(0, len);
	reverse(ans.begin(), ans.end());
	return ans;

}
void func() {
	string a, b;
	while (cin >> a >> b) {
		string ans = add(a, b);
		cout << ans << endl;;
	}
}
int main() {
	func();
	return 0;
}