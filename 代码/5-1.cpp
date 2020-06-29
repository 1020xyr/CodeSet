#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
void func() {
	int n, m;
	while(scanf ("%d %d",&n,&m) != EOF){
		vector<int> a(n);
		for (int i = 0;i < n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a.begin(), a.end(), cmp);
		for (int i = 0;i < m-1;i++) {
			printf("%d ",a[i]);
		}
		printf("%d",a[m-1]);
		printf("\n");
	}
}
int main() {
	func();
	return 0;
}
