#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void func() {
	int n;
	priority_queue<int, vector<int>, greater<int>> Q;
	while (cin >> n && n != 0) {
		int NodeSum = 0;
		int AllSum = 0;
		int tmp;
		for (int i = 0;i < n;i++) {
			cin >> tmp;
			NodeSum += tmp;
			Q.push(tmp);
		}
		int first, second;
		while (Q.size() > 1) {
			first = Q.top();
			Q.pop();
			second = Q.top();
			Q.pop();
			AllSum += first + second;
			Q.push(first + second);
		}
		AllSum += Q.top();
		Q.pop();
		cout << AllSum - NodeSum << endl;
	}
}

int main() {
	func();
	return 0;
}
