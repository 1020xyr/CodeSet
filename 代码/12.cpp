#include<iostream>
#include<string>

using namespace std;

bool find(string& s, int index) {
	while (index > 0) {
		index--;
		if (s[index] == '(') {
			s[index] = 'a';
			return true;
		}
	}
	return false;
}
int main() {
	string data;
	while (cin >> data) {
		cout << data << endl;
		for (int i = 0;i < data.length();i++) {
			if (data[i] == ')') {
				if (find(data, i)) {
					data[i] = 'a';
				}
			}
		}
		for (int i = 0;i < data.length();i++) {
			if (data[i] == '(') {
				cout << "$";
			}
			else if (data[i] == ')') {
				cout << "?";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

