#include<stdio.h>
#include<vector>

using namespace std;

struct Edge {
	int to;
	int cost;
	int len;
};
int dist[1001];
int cost[1001];
bool marked[1001];
vector<Edge> edge[1000];

void func() {
	int n, m;
	while (scanf("%d %d",&n,&m)) {
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 1;i <= n;i++) {
			dist[i] = -1;
			marked[i] = false;
			edge[i].clear();
		}
		for (int i = 0;i < m;i++) {
			int a, b, d, p;
			scanf("%d %d %d %d", &a, &b, &d, &p);
			Edge tmp;
			tmp.cost = p;
			tmp.len = d;
			tmp.to = a;
			edge[b].push_back(tmp);
			tmp.to = b;
			edge[a].push_back(tmp);
		}
		int s, t;
		scanf("%d %d", &s, &t);
		int  v = s;

		marked[v] = true;
		dist[v] = 0;
		cost[v] = 0;
		for (int i = 0;i < n - 1;i++) {
			for (int j = 0;j < edge[v].size();j++) {
				int to = edge[v][j].to;
				int newLen = dist[v] + edge[v][j].len;
				int newCost = cost[v] + edge[v][j].cost;
				if (marked[to]) continue;
				if (dist[to] == -1 || newLen <dist[to] || (dist[to] == newLen && newCost < cost[to])) {
					dist[to] = newLen;
					cost[to] = newCost;
				}
			}
			int minLen=100000000;
			int minCost= 100000000;
			for (int j = 1;j <= n;j++) {
				if (marked[j] || dist[j] == -1) continue;
				if (dist[j] < minLen || (dist[j] == minLen && cost[j] < minCost)) {
					minLen = dist[j];
					minCost = cost[j];
					v = j;
				}
			}
			marked[v] = true;
			if (v == t) {
				break;
			}
		}
		printf("%d %d\n", dist[t], cost[t]);
	}
}
int main() {
	func();
	return 0;
}
