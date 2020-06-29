#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct student {
	string num;
	string name;
	string sex;
	int age;
};

bool cmp(student s1, student s2) {
	return s1.num < s2.num;
}

void func() {
	int n;
	cin >> n;
	vector<student> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].num >> a[i].name >> a[i].sex >> a[i].age;
	}
	sort(a.begin(), a.end(), cmp);
	int m;
	cin >> m;
	string find_num;
	for (int i = 0;i < m;i++) {
		cin >> find_num;
		int hi = n - 1;
		int lo = 0;
		int mid = (hi + lo) / 2;
		int flag = 0;
		while (hi >= lo) {
			if (a[mid].num < find_num) {
				lo = mid + 1;
				mid = (hi + lo) / 2;
			}
			else if (a[mid].num > find_num) {
				hi = mid - 1;
				mid = (hi + lo) / 2;
			}
			else {
				flag = 1;
				cout << a[mid].num << " " << a[mid].name << " " << a[mid].sex << " " << a[mid].age << endl;
				break; 
			}
		}
		if (flag == 0) {
			cout << "No Answer!" << endl;
		}
	}
}
int main() {
	func();
	return 0;
}
