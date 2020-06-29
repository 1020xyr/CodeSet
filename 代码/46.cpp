#include<iostream>
#include<vector>

using namespace std;

const int maxn = 100005;
const int INF = 1000000000;
struct Edge {
	int from;
	int to;
	int cost;
}edge[maxn];
vector<int> g[maxn], gre[maxn];

int order[maxn];
int belong[maxn];
bool visit[maxn];
int color;
int no;
int n, m;
int p, q;
int P[maxn], Q[maxn];
void dfs1(int u) {
	visit[u] = true;
	int len = g[u].size();
	for (int i = 0;i < len;i++) {
		int v = g[u][i];
		if (!visit[v]) {
			dfs1(v);
		}
	}
	order[no++] = u;
}
void dfs2(int u) {
	visit[u] = true;
	belong[u] = color;
	int len = gre[u].size();
	for (int i = 0;i < len;i++) {
		int v = gre[u][i];
		if (!visit[v]) {
			dfs2(v);
		}
	}
}
void kosaraju() {
	color = 1, no = 1;
	for (int i = 1;i <= n;i++) {
		visit[i] = false;
	}
	for (int i = 1;i <= n;i++) {
		if (!visit[i]) {
			dfs1(i);
		}
	}
	for (int i = 1;i <= n;i++) {
		visit[i] = false;
	}
	for (int i = no - 1;i >= 1;i--) {
		int v = order[i];
		if (!visit[v]) {
			dfs2(v);
			color++;
		}
	}
}
void func() {
	cin >> n >> m >> p >> q;
	for (int i = 0;i < p;i++) {
		cin >> P[i];
	}

	for (int i = 0;i < q;i++) {
		cin >> Q[i];
	}
	Edge tmp;
	int u, v, w;
	for (int i = 0;i < m;i++) {
		cin >> u >> v >> w;
		tmp.from = u;
		tmp.to = v;
		tmp.cost = w;
		edge[i] = tmp;
		g[u].push_back(v);
		gre[v].push_back(u);
	}
	kosaraju();
	//	for (int i = 1;i <=n;i++) {
	//		cout << belong[i] << endl;
	//	}
	int ans[color + 1][color + 1];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			ans[i][j] = -1;			//对邻接矩阵初始化,我们用-1代表无穷
		}
		ans[i][i] = 0;				//自己到自己的路径长度设为0
	}
	Edge e;
	int from, to, cost;
	for (int i = 0;i < m;i++) {
		e = edge[i];
		from = belong[e.from];
		to = belong[e.to];
		cost = e.cost;
		if (from != to && (ans[from][to] == -1 || cost < ans[from][to])) {
			ans[from][to] = cost;
			/*cout << from << "  " << to << "  " << cost << endl;*/
		}
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (ans[i][k] == -1 || ans[k][j] == -1) continue;
				if (ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j])
					ans[i][j] = ans[i][k] + ans[k][j];
			}
		}
	}
	/*for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cout << ans[i][j] << endl;
		}
	}*/
	for (int i = 0;i < p;i++) {
		int target = belong[P[i]];
		int min = INF;
		for (int j = 0;j < q;j++) {
			int begin = belong[Q[j]];
			if (ans[begin][target] != -1) {
				min = min < ans[begin][target] ? min : ans[begin][target];
			}
		}
		if (min == INF) cout << -1 << endl;
		else cout << min;

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}