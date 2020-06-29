#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Node {
	int val;
	Node* lchild;
	Node* rchild;
};
bool compare(vector<int> t1, vector<int> t2) {
	if (t1.size() != t2.size()) return false;
	for (int i = 0;i < t1.size();i++) {
		if (t1[i] != t2[i]) {
			return false;
		}
	}
	return true;
}
Node* create(Node* root, int val) {
	if (root == NULL) {
		root = new Node();
		root->val = val;
	}
	else if (root->val >= val) {
		root->lchild = create(root->lchild, val);
	}
	else {
		root->rchild = create(root->rchild, val);
	}
	return root;
}
void previsit(Node* root,vector<int>& ans) {
	ans.push_back(root->val);
	if (root->lchild) {
		previsit(root->lchild, ans);
	}
	if (root->rchild) {
		previsit(root->rchild, ans);
	}
}
void convert(string s, vector<int>& mid) {
	int len = s.length();
	for (int i = 0;i < len;i++) {
		int val = s[i] - '0';
		mid.push_back(val);
	}
}
void print_all(vector<int> res){
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
void func() {
	int n;
	while (cin >> n&&n>0) {
		vector<int> pre;
		vector<int> mid;
		Node* root = NULL;
		string tmp;
		cin >> tmp;
		convert(tmp, mid);
		for (int i = 0;i < mid.size();i++) {
			root = create(root, mid[i]);
		}
		previsit(root, pre);
		sort(mid.begin(), mid.end());
		print_all(pre);
		print_all(mid);
		for (int i = 0;i < n;i++) {
			Node* root_test = NULL;
			vector<int> mid_test;
			vector<int> pre_test;
			cin >> tmp;
			convert(tmp, mid_test);
			for (int i = 0;i < mid_test.size();i++) {
				root_test = create(root_test, mid_test[i]);
			}
			previsit(root_test, pre_test);
			sort(mid_test.begin(), mid_test.end());
			print_all(pre_test);
			print_all(mid_test);
			if (compare(mid, mid_test) && compare(pre, pre_test)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}
int main() {
	func();
	return 0;
}
