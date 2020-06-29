#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct {
	string user;
	int grade;
}people;
bool cmp(people p1,people p2,int method) {
	if (method) {
		return p1.grade > p2.grade;
	}
	else {
		return p1.grade < p2.grade;
	}
}
void exch(people& p1, people& p2) {
	people tmp;
	tmp = p1;
	p1 = p2;
	p2 = tmp;
}
void func() {
	int n;
	int method;
	cin >> n >> method;
	vector<people> peoples(n);
	for (int i = 0;i < n;i++) {
		cin >> peoples[i].user >> peoples[i].grade;
	}
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - i - 1;j++) {
			if (cmp(peoples[j], peoples[j+1], method)) {
				exch(peoples[j], peoples[j+1]);
			}
		}
	}
	cout<<"½á¹û"<<endl; 
	for (int i = 0;i < n;i++) {
		cout << peoples[i].user << " " << peoples[i].grade << endl;
	}
}
int main(){
	func();
	return 0;
}
