#include<iostream>
#include<stack>
#include<string>
using namespace std;
int getPro(char function) {
	if (function == '*' || function == '/') {
		return 3;
	}
	else if (function == '+' || function == '-') {
		return 2;
	}
	else if(function == 'a'){
		return 1;
	}
	else {
		return 0;
	}
}
double count(double a, double b, char func) {
	switch (func) {
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	}
	return 0;
}
bool process_stack(stack<double>& numbers, stack<char>& functions, char func) {
	int top_pro;
	int func_pro;
	char top;
	top = functions.top();
	top_pro = getPro(top);
	func_pro = getPro(func);
	if (top_pro >= func_pro) {
		functions.pop();
		double a, b;
		b = numbers.top();
		numbers.pop();
		a = numbers.top();
		numbers.pop();
		double ans = count(a, b, top);
		numbers.push(ans);
		return true;
	}
	functions.push(func);
	return false;
}
typedef pair<int, int> mytype;
mytype GetNumber(string s, int index) {
	int ans = 0;
	while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
		ans = ans * 10 + s[index] - '0';
		index++;
	}
	mytype value(ans, index);
	return value;
}
int main() {
	string s;
	stack<double> nums;
	stack<char> operators;
	while (getline(cin,s)) {
		if (s[0] == '0' && s.length() == 1) {
			break;
		}
		while (!operators.empty()) operators.pop();
		operators.push('z');
		char oper;
		double num;
		int index = 0;
		while (true) {
			mytype value = GetNumber(s, index);
			nums.push(value.first);
			if (value.second == s.length()) {
				while (process_stack(nums, operators, 'a')) {}
				double ans = nums.top();
				nums.pop();
				printf("%.2f\n", ans);
				break;
			}
			oper = s[value.second+1];
			index = value.second + 3;
			while (process_stack(nums, operators, oper)) {}
		}
	}
}
