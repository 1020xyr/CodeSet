#include<iostream>
#include<vector>
using namespace std;

struct mytype {
	int number;
	int count;
	mytype(int num, int c) {
		number = num;
		count = c;
	}
};
vector<int> tmp(1001, 0);
void proprocess() {
	for (int i = 2;i < 1000;i++) {
		if (tmp[i] == 0) {
			for (int j = i * i;j <= 1000;j = j + i) {
				tmp[i] = 1;
			}
		}
	}
}
vector<mytype> find_factor(int n) {
	vector<mytype> res;
	int another = n;
	for (int i = 2;i <= n;i++) {
		if (tmp[i] == 0) {
			int count = 0;
			while (another % i == 0) {
				count++;
				another = another / i;
			}
			if (count != 0) {
				res.push_back(mytype(i, count));
			}
		}
	}
	return res;
}
int getNum(int n, int p) {
	int ans = 0;
	for (int i = p;i <= n;i = i * p) {
		ans += n / i;
	}
	return ans;
}
void func() {
	int n, a;
	cin >> n >> a;
	vector<mytype> ans = find_factor(a);
	int min=100000;
	int len = ans.size();
	for (int i = 0;i < len;i++) {
		int num = getNum(n, ans[i].number);
		int count = num / ans[i].count;
		min = min > count ? count : min;
	}
	cout << min << endl;
}
int main() {
	func();
	return 0;
}
