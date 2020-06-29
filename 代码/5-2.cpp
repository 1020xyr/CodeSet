#include<iostream>
#include<vector>
#include<stdio.h>
#define OFFSET 500000
using namespace std;

vector<int> a(1000001, 0);
void func() {
	int n, m;
	while (scanf ("%d %d",&n,&m) != EOF) {
		int temp;
		for (int i = 0;i < n;i++) {
			scanf("%d",&temp);
			a[temp + OFFSET] =  1;
		}
		for (int i = 500000; i >= -500000; i --) { 
			if (a[i + OFFSET] == 1) { 
				printf("%d",i); 
				m --; 
				if (m != 0) printf(" "); 
			
				else {
					printf("\n"); 
					break;
				}
			}
		}
	}
}
int main() {
	func();
	return 0;
}
