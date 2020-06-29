#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct goods {
	double rate;
	double j;
	double f;
};
bool cmp(goods g1, goods g2) {
	return g1.rate > g2.rate;
}

void func() {
	int n;
	double m;
	while ((cin >> m >> n) && (n != -1 && m != -1)) {
		vector<goods> a(n);
		for (int i = 0;i < n;i++) {
			cin >> a[i].j >> a[i].f;
			a[i].rate = a[i].j / a[i].f;
		}
		sort(a.begin(), a.end(), cmp);
		double ans = 0;
		double sum = 0;
		for (int i = 0;i < n;i++) {
			if (sum + a[i].f <= m) {
				sum += a[i].f;
				ans += a[i].j;
			}
			else {
				ans += (m - sum) * a[i].rate;
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
}
int main() {
	func();
	return 0;
}
