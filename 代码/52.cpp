#include<iostream>
#include<queue>
using namespace std;
struct state {
	int capacity[3];									// 为了方便赋值 分别表示各种现有饮料量
	int cnt;
	state(int s1, int m1, int n1, int cnt1) {
		capacity[0] = s1;
		capacity[1] = m1;
		capacity[2] = n1;
		cnt = cnt1;
	}
};
int go[][2] = {											// 从哪个瓶子倒入哪个瓶子
	 0,1,
	 0,2,
	 1,0,
	 1,2,
	 2,0,
	 2,1
};
const int maxn = 101;
bool marked[maxn][maxn][maxn];
queue<state> Q;
int S, M, N;
int MaxCapacity[3];										// 3个容器的最大容量
void printState(state st) {
	cout << st.capacity[0] << " " << st.capacity[1] << " " << st.capacity[2];
	cout << " " << st.cnt << endl;
}
void add(int from, int to, state st) {
	state st1 = st;										// 倒完之后的状态
	if (st1.capacity[from] == 0) return;				// 如果前一个瓶子是空的
	if (st1.capacity[to] == MaxCapacity[to]) return;	// 如果后一个瓶子是满的
	int sum = st1.capacity[from] + st1.capacity[to];	
		if (sum <= MaxCapacity[to]) {					// 前一个瓶全部倒入后一个瓶子
			st1.capacity[to] = sum;
			st1.capacity[from] = 0;
		}
		else {											// 倒满为止
			st1.capacity[to] = MaxCapacity[to];
			st1.capacity[from] = sum - MaxCapacity[to];
		}
		st1.cnt++;
		int s = st1.capacity[0];
		int m = st1.capacity[1];
		int n = st1.capacity[2];
		if (!marked[s][m][n]) {
			marked[s][m][n] = true;
			Q.push(st1);
		}
}
void func() {
	while (cin >> S >> M >> N) {
		if (S + M + N == 0) {
			break;
		}
		if (M == N) {								// 若两个容器相等均为可乐瓶的一半,随便往一个杯子里倒即可
			cout << 1 << endl;
			continue;
		}
		if (S % 2 != 0) {							// 可乐瓶为奇数不可能均分
			cout << "NO" << endl;
			continue;
		}
		if (M < N) {								// 保持M大于N，便于判断是否成功 (一定是M杯和可乐瓶各一半）
			int tmp = M;
			M = N;
			N = tmp;
		}
		MaxCapacity[0] = S;							// 数组下标 0 可乐瓶 1 M杯子 2 N杯子
		MaxCapacity[1] = M;							// 用下标代表可避免很多相似代码
		MaxCapacity[2] = N;
		for (int i = 0;i <= S;i++) {
			for (int j = 0;j <= M;j++) {
				for (int k = 0;k <= N;k++) {
					marked[i][j][k] = false;
				}
			}
		}
		while (!Q.empty()) Q.pop();					// 清空队列
		Q.push(state(S, 0, 0, 0));
		marked[S][0][0] = true;
		int flag = false;							// 记录是否找到方法均分可乐瓶
		while (!Q.empty()) {
			state st = Q.front();
			Q.pop();
			int m = st.capacity[1];
			int n = st.capacity[2];	
			if (m == S / 2 && n == 0) {				// 均分的唯一可能
				cout << st.cnt << endl;
				flag = true;
				break;
			}
			for (int i = 0;i < 6;i++) {				// 枚举六种情况
				add(go[i][0], go[i][1], st);
			}
		}
		if (flag == false) {
			cout << "NO" << endl;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	func();
	return 0;
}
