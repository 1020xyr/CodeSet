#include<stack>
#include<iostream>

using namespace std;

typedef pair<int, int> mytype;
int getPro(char function) {
	if (function == '*' || function == '/') {
		return 3;
	}
	else if (function == '+' || function == '-') {
		return 2;
	}
	else if (function == 'a') {
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
mytype GetNumber(string s, int index, int right) {
	int ans = 0;
	while (index < right && s[index] >= '0' && s[index] <= '9') {
		ans = ans * 10 + s[index] - '0';
		index++;
	}
	mytype value(ans, index);
	return value;
}
double process(string s, int left, int right) {
	stack<double> nums;
	stack<char> operators;
	operators.push('z');
	char oper;
	double num;
	int index = left;
	while (true) {
		nums.push(value.first);
		if (value.second == s.length()) {
			while (process_stack(nums, operators, 'a')) {}
			double ans = nums.top();
			nums.pop();
			return ans;
		}
		oper = s[value.second + 1];
		index = value.second + 3;
		while (process_stack(nums, operators, oper)) {}
		
	}
}


int main() {
	stack<int> brackets;
	string s;
	cin >> s;
	for (int i = 0;i < s.length();i++) {
		if (s[i] == '(') {
			brackets.push(i);
		}
		else if (s[i] == ')') {
			int left = brackets.top() + 1;
			brackets.pop();
			int right = i - 1;
			double ans = process(s, left, right);
		}
	}
}