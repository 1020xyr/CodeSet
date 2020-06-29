#include<iostream>
#include<string>
#include<algorithm> 

using namespace std;

string IntToX(int num, int radix) {
	string res = "";
	do {
		int t = num % radix;
		if (t <= 9 && t >= 0) {
			res += t + '0';
		}
		else {
			res += t - 10 + '0';
		}
		num = num / radix;
	} while (num != 0);
	reverse(res.begin(), res.end());
	return res;
}
string add(string a, string b,int radix ) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int len_a = a.length();
	int len_b = b.length();
	a += string((50 - len_a) ,'0');
	b += string((50 - len_b), '0');
	int flag = 0;
	for (int i = 0;i < 50;i++) {
		int sum = a[i] + b[i] - '0' - '0' + flag;
		flag = 0;
		if (sum >= radix) {
			sum = sum - radix;
			flag = 1;
		}
		a[i] = sum + '0';
	}
	int len = len_a > len_b ? len_a : len_b;
	while (a[len] != '0') {
		len++;
	}
	string ans = a.substr(0, len);
	reverse(ans.begin(), ans.end());
	return ans;
}
void func() {
	int a, b, r;
	while (cin >> r >> a >> b) {
		string a1 = IntToX(a, r);
		string b1 = IntToX(b, r);
		string ans = add(a1, b1, r);
		cout << ans << endl;
	}
}

int main() {
	func();
	return 0;
}
