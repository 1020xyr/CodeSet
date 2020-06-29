#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool compare(int a, int b) {
	return a < b;
}
void func(int n) {
	priority_queue<int, vector<int>, greater<int> > Q;
	int tmp = 0;
	int sum_node = 0;            // 叶子节点权值之和
	int sum_all = 0;			 // 所有节点权值之和
	for (int i = 0;i < n;i++) {
		cin >> tmp;
		sum_node += tmp;
		Q.push(tmp); 
	}
	int first, second;
	while (!Q.empty()) {
		first = Q.top();
		Q.pop();
		sum_all += first;
		if (Q.empty()) {
			break;
		}
		second = Q.top();
		Q.pop();
		sum_all += second;
		Q.push(first + second);
	}
	cout << sum_all - sum_node << endl;
	return;

}
int main() {
	int n;
	while (cin >> n) {
		func(n);
	}
	return 0;
}
