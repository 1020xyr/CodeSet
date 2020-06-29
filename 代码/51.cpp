#include<iostream> 
#include<queue>
using namespace std;
/*坐标变换数组 , 由坐标 (x,y,z) 扩展得到的新坐标均可
通过(x + go[i][0],y + go[i][1],z + go[i][2])得到*/
int go[][3] = { 
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
struct state {
	int x, y, z;
	int t;
	state(int x1, int y1,int z1,int t1) {
		x = x1;
		y = y1;
		z = z1;
		t = t1;
	}
};
const int maxn = 51;

int A, B, C, T;
queue<state> Q;
int maze[maxn][maxn][maxn];
bool marked[maxn][maxn][maxn];

void add(int x, int y, int z,int t) {
	if (x >= A || x < 0) return;		// 非法的下标
	if (y >= B || y < 0) return;
	if (z >= C || z < 0) return;
	if (marked[x][y][z] || maze[x][y][z] == 1) return;
	Q.push(state(x, y, z, t + 1));
	marked[x][y][z] = true;

}
void func() {
	int k;
	cin >> k;
	while (k--) {
		cin >> A >> B >> C >> T;
		for (int i = 0;i < A;i++) {
			for (int j = 0;j < B;j++) {
				for (int k = 0;k < C;k++) {
					cin >> maze[i][j][k];
					marked[i][j][k] = false;
				}
			}
		}
		while (!Q.empty()) Q.pop();			// 清空队列

		Q.push(state(0,0,0,0));
		while (!Q.empty()) {
			state s = Q.front();
			int x, y, z, t;
			x = s.x;
			y = s.y;
			z = s.z;
			t = s.t;
			Q.pop();
			if (t > T) {			// 提前结束遍历
				cout << -1 << endl;
				break;
			}
			if (x == A - 1 && y == B - 1 && z == C - 1) {
				cout <<t << endl;
				break;
			}
			marked[x][y][z] = true;
			add(x+1, y, z, t);
			add(x-1, y, z, t);
			add(x, y+1, z, t);
			add(x, y-1, z, t);
			add(x, y, z+1, t);
			add(x, y, z-1, t);
		}
	}
}
int main(){
	cin.tie(0);						// cin cout 加速
	ios::sync_with_stdio(false);
	func();
	return 0;
}
