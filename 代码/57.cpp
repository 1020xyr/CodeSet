#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

void func() {
	string tar,example,output;
	cin >> tar;
	transform(tar.begin(), tar.end(), tar.begin(), ::tolower);	// 转换为小写，注意::.明确命名空间
	int len = tar.size();
	char tmp[100];
	while (gets(tmp)) {										    // 读取整行
		example = tmp;											// example为全部小写的字符串，output为输入字符串
		output = example;
		transform(example.begin(), example.end(), example.begin(), ::tolower);
		int index;
		while ((index = example.find(tar)) != string::npos) {	// 如果可以找到
			example.erase(index, len);
			output.erase(index, len);
		}
		while ((index = example.find(' ')) != string::npos) {
			example.erase(index, 1);
			output.erase(index, 1);
		}
		cout << output << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	func();
	return 0;
}
