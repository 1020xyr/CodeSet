#include<iostream>
#include<map>
#include<iostream>
using namespace std;

int in[2002];								// 可以直接理解成被打败的次数
map<string, int> M;
int n;

void func() {
	string a, b;
	while (cin >> n && n != 0) {
		for (int i = 0;i < 2 * n;i++) {
			in[i] = 0;
		}
		M.clear();
		int start = 0;
		int cnt = 0;
		for (int i = 0;i < n;i++) {
			cin >> a >> b;
			if (M.find(a) == M.end()) {
				M[a] = start;
				start++;
			}
			if (M.find(b) == M.end()) {
				M[b] = start;
				in[start]++;
				start++;
			}
			else {
				in[M[b]]++;
			}
		}
		for (int i = 0;i < start;i++) {
			if (in[i] == 0) {
				cnt++;
			}
		}
		if (cnt == 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
