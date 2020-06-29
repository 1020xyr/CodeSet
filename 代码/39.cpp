#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> edge[101];
int indegree[101];
queue<int> Q;
void func() {
	int n, m;
	while (cin >> n >> m && n != 0) {
		while (!Q.empty()) {
			Q.pop();
		}
		for (int i = 0;i < n;i++) {
			indegree[i] = 0;
			edge[i].clear();
		}
		for (int i = 0;i < m;i++) {
			int x, y;
			cin >> x >> y;
			edge[x].push_back(y);
			indegree[y]++;
		}
		for (int i = 0;i < n;i++) {
			if (indegree[i] == 0) {
				Q.push(i);
			}
		}
		int size = 0;
		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			size++;
			for (int i = 0;i < edge[v].size();i++) {
				int to = edge[v][i];
				indegree[to]--;
				if (indegree[to] == 0) {
					Q.push(to);
				}
			}
		}
		if (size == n) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
int main() {
	func();
	return 0;
}