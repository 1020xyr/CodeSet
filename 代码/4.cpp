#include<iostream>
#include<vector>

using namespace std;
int main(){
	int n;
	int grade;
	int res;
	while(cin>>n){
		if(n==0) break;
		vector<int> a(101,0);
		for(int i =0;i<n;i++){
			cin>>grade;
			a[grade]++;
		}
		cin>>res;
		cout<<a[res]<<endl;
	}
	return 0;
} 

