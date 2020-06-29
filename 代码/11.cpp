#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct show {
	int start;
	int end;
	bool operator <(const show& s) {
		return end < s.end;
	}
};
vector<show> a(100);
int main() {
	int n;
	while (cin >> n && n != 0) {
		for (int i = 0;i < n;i++) {
			cin >> a[i].start >> a[i].end;
		}
		sort(a.begin(), a.begin() + n);
		int now = 0;
		int ans = 0;
		for (int i = 0;i < n;i++) {
			if (a[i].start >= now) {
				now = a[i].end;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
