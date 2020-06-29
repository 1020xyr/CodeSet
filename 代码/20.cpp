#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void print_all(vector<int> res){
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
vector<int> convert(int num) {
	num = abs(num);
	vector<int> res;
	while (num != 0) {
		res.push_back(num % 10);
		num = num / 10;
	}
	//print_all(res);
	return res;
}

void func() {
	int num1, num2;
	while (cin >> num1 && cin >> num2) {
		bool f1 = (num1 < 0);
		bool f2 = (num2 < 0);
		int flag = 1;
		if ((!f1 && f2) || (f1 && !f2)) {
			flag = -1;
		}
		vector<int> tmp1 = convert(num1);
		vector<int> tmp2 = convert(num2);
		int sum = 0;
		for (int i = 0;i < tmp1.size();i++) {
			for (int j = 0;j < tmp2.size();j++) {
				sum += tmp1[i] * tmp2[j];
			}
		}
		sum = sum * flag;
		cout << sum << endl;
	}
}
int main() {
	func();
	return 0;
}
